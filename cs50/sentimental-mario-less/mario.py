def main():
    height = get_height()
    for i in range(height):
        print(" " * (height - i - 1), end="")
        # print hashes for the current row
        for j in range(i + 1):
            print("#", end="")
        # move to next line for the next row
        print()

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not and integer")

main()