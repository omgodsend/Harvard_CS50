expression = input("expression:")

x, y, z = expression.split(" ")



if y == "+":
    print(str(float(x+z)))
elif y == "-":
    print(float(x-z))
if y == "*":
    print(x*z)
if y == "/":
    print(x/z)
