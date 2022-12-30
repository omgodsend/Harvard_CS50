expression = input("expression:")

x, y, z = expression.split(" ")

newx = float(x)
newz = float(z)

if y == "+":
    result = (newx + newz)
elif y == "-":
    result = (newx - newz)
if y == "*":
    result = (newx * newz)
if y == "/" and newz != "0":
    result = (newx / newz)
print(round(result,1))
