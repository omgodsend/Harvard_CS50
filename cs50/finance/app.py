import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, get_flashed_messages
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
    purchases = db.execute("SELECT symbol, SUM(shares) AS total_shares FROM purchases WHERE user_id = ? AND shares != 0 GROUP BY symbol", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    total_value = cash

    for purchase in purchases:
        symbol = purchase["symbol"]
        stock = lookup(symbol)
        purchase["name"] = stock["name"]
        purchase["price"] = stock["price"]
        purchase["shares"] = purchase["total_shares"]
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
            return apology("Please enter stock symbol", 400)

        stock = lookup(symbol)

        if not stock:
            return apology("Stock not found", 400)

        shares = request.form.get("shares")

        try:
            int(shares)
        except ValueError:
            return apology("please enter a positive, whole number", 400)
        if not shares:
            return apology("Please enter shares amount", 400)

        if int(shares) < 1:
            return apology("Shares must be greater than 0")

        user_id = session["user_id"]

        user = db.execute("SELECT * FROM users WHERE id = ?", user_id)[0]

        cash = user["cash"]

        total_cost = stock["price"] * int(shares)

        if total_cost > cash:
            return apology("Insufficient funds")

        new_cash = cash - total_cost

        buy_time = datetime.datetime.now()

        # Update the user's cash balance in the database
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

                # Check if the user has previously purchased the stock
        existing_purchase = db.execute("SELECT * FROM purchases WHERE user_id = ? AND symbol = ?", user_id, symbol)

        if existing_purchase:
            current_shares = existing_purchase[0]["shares"]
            new_shares = int(shares) + int(current_shares)
            # Update the existing row
            db.execute("UPDATE purchases SET price = ?, shares = ? WHERE user_id = ? AND symbol = ?", stock["price"], int(new_shares), user_id, symbol)
        else:
            # Insert a new row
            db.execute("INSERT INTO purchases (user_id, symbol, price, shares) VALUES (?, ?, ?, ?)", user_id, symbol, stock["price"], int(shares))


        db.execute(
            "INSERT INTO history (user_id, symbol, price, shares, shares_bought, shares_sold, timestamp) VALUES (?, ?, ?, ?, ?, ?, ?)",
            user_id, symbol, stock["price"], int(shares), int(shares), 0, buy_time)

        flash("Bought!")
        return redirect("/")

    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    rows = db.execute("SELECT * FROM history WHERE user_id = ? ORDER BY timestamp DESC", session["user_id"])

    return render_template("history.html", rows=rows)


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

        if not request.form.get("symbol"):
            return apology("Must enter stock symbol", 400)

        stock = lookup(request.form.get("symbol"))

        if not stock:
            return apology("Check symbol and try again", 400)

        return render_template("quoted.html", stock=stock)


    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":

        if not request.form.get("username"):
            return apology("must create a username", 400)

        elif not request.form.get("password"):
            return apology("must create a password", 400)

        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("Passwords do not match", 400)

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

@app.route("/account", methods=["GET", "POST"])
@login_required
def account():
    """Display user's account"""

    if request.method == "POST":

        old_password = request.form.get("old_pass")
        new_password = request.form.get("new_pass")
        confirmation = request.form.get("confirmation")

        if not old_password:
            return apology("Must enter old Password", 400)

        elif not new_password:
            return apology("Must create a new password", 400)

        user = db.execute("SELECT hash FROM users WHERE id = ?", session["user_id"])

        if not check_password_hash(user[0]["hash"], old_password):
            return apology("Old Password incorrect", 403)

        elif new_password != confirmation:
            return apology("New Passwords do not match", 403)

        elif new_password == old_password:
            return apology("New password cannot be the same as old password", 403)

        db.execute("UPDATE users SET hash = ? WHERE id = ?", generate_password_hash(new_password), session["user_id"])

        flash("Password changed Successfully")

        return redirect("/password_success")

    else:
        name = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])
        return render_template("account.html", name=name)

@app.route("/password_success")
def password_success():
    flash_messages = get_flashed_messages()
    return render_template("password_success.html", flash_messages=flash_messages)


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":

        symbol = request.form.get("symbol")

        shares_req = request.form.get("shares")

        if not symbol or not shares_req:
            return apology("Check symbol and shares", 400)

        try:
            shares_req = int(shares_req)
            if shares_req <= 0:
                return apology("Can't sell 0 or less than 0 shares", 400)
        except ValueError:
            return apology("Shares must be a positive integer", 400)

        stock = lookup(symbol)
        if stock is None:
            return apology("Invalid symbol", 400)

        shares = db.execute("SELECT SUM(shares) FROM purchases where user_id = ? AND symbol = ?", session["user_id"], symbol)[0]["SUM(shares)"]

        if shares < shares_req:
            return apology("you can't sell more shares than you own")

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        remaining_shares = shares - shares_req

        if remaining_shares > 0:
            db.execute("UPDATE purchases SET shares = ? WHERE user_id = ? AND symbol = ?", remaining_shares, session["user_id"], symbol)
        else:    # Update the shares in the purchases table with the remaining_shares value
            db.execute("DELETE FROM purchases WHERE symbol = ? AND user_id = ?", symbol, session["user_id"])

        total_cost = int(shares_req) * stock["price"]

        new_cash = cash + total_cost

        sell_time = datetime.datetime.now()

        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, session["user_id"])

        db.execute("INSERT INTO history (user_id, symbol, price, shares, shares_bought, shares_sold, timestamp) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   session["user_id"], symbol, stock["price"], shares_req, 0, shares_req, sell_time)

        flash("Sold!")

        return redirect("/")

    else:

        shares = db.execute("SELECT symbol FROM purchases where user_id = ? GROUP BY symbol HAVING shares > 0", session["user_id"])

        return render_template("sell.html", shares=shares)
