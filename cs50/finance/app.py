import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    purchases = db.execute("SELECT * FROM purchases WHERE user_id = ?", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    total_value = cash

    for purchase in purchases:
        symbol = purchase["symbol"]
        stock = lookup(symbol)
        purchase["name"] = stock["name"]
        purchase["total"] = stock["price"] * purchase["shares"]
        total_value += purchase["total"]

    return render_template("index.html", purchases=purchases, cash=cash, total_value=total_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        symbol = request.form.get("symbol")

        if not symbol:
            return apology("Please enter stock symbol")

        stock = lookup(symbol)

        if not stock:
            return apology("Stock not found")

        shares = request.form.get("shares")

        if int(shares) < 1:
            return apology("Shares be greater than 0")

        user_id = session["user_id"]

        user = db.execute("SELECT * FROM users WHERE id = ?", user_id)[0]

        cash = user["cash"]

        total_cost = stock["price"] * int(shares)

        if total_cost > cash:
            return apology("Insufficient funds")

        new_cash = cash - total_cost

        # Update the user's cash balance in the database
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        db.execute(
            "INSERT INTO purchases (user_id, symbol, price, shares) VALUES (?, ?, ?, ?)",
            user_id, symbol, stock["price"], int(shares))

        flash("Bought!")
        return redirect("/")

    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        stock = lookup(request.form.get("symbol"))
        return render_template("quoted.html", stock=stock)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":

        if not request.form.get("username"):
            return apology("must create a username", 403)

        elif not request.form.get("password"):
            return apology("must create a password", 403)

        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("Passords do not match", 403)

        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        if len(rows) >= 1:
            return apology("username already exists")

        db.execute("INSERT INTO users (username, hash) VALUES (?,?)", request.form.get("username"), generate_password_hash(request.form.get("password")))

        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        session["user_id"] = rows[0]["id"]

        flash("Registered!")
        return redirect("/")

    else:
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        stock = lookup(request.form.get("symbol"))

        if stock == None:
            return apology("invalid symbol",400)

        shares_req = int(request.form.get("shares"))

        if shares_req <= 0:
            return apology("can't sell 0 or < 0 shares", 400)

        # Check the actual stock symbol being posted
        shares = db.execute("SELECT SUM(shares) FROM purchases where user_id = ? AND symbol = ?", session["user_id"], request.form.get("symbol"))

        if len(shares) <= 0 or len(shares) < shares_req:
            return apology("you can't sell more shares than you own or less than 0")

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        purchases = db.execute("SELECT * FROM purchases WHERE user_id = ?", session["user_id"])

        total_cost = int(shares_req) * stock["price"]

        new_cash = cash + total_cost

        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        db.execute("DELETE FROM purchases (shares) VALUES (?)", int(shares))






        return render_template("sell.html")
    else:

        #purchases = db.execute("SELECT * FROM purchases WHERE user_id = ?", session["user_id"])

        shares = db.execute("SELECT symbol FROM purchases where user_id = ? GROUP BY symbol HAVING shares > 0", session["user_id"])

        return render_template("sell.html", shares=shares)
