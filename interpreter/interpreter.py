expression = input("expression:")

x, y, z = expression.split(" ")

newx = float(x)
newz = float(z)

if y == "+":
    print(newx + newz)
elif y == "-":
    print(newx - newz)
if y == "*":
    print(newx * newz)
if y == "/" and newz != "0":
    print(newx / newz)
