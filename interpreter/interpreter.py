expression = input("expression:")

x = float()

z = float()

x, y, z = expression.split(" ")

if y == "+":
    print(x+z)
elif y == "-":
    print(x-z)
if y == "*":
    print(x*z)
if y == "/":
    print(x/z)
