def main():
    height = get_height()
    for i in range(height):
        print("#", end="")
        for i in range(height):
            print("#", end="")


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not and integer")

main()