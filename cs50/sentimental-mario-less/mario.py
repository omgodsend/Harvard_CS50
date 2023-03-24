def main():
    height = get_height()
    for i in range(height//2 + 1):  # Only iterate half of the height
        # print spaces before hashes
        print(" " * (height - i - 1), end="")
        # print left half of hashes
        print("#" * (i + 1), end="")
        # print middle gap
        print("  ", end="")
        # print right half of hashes
        print("#" * (i + 1))

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not and integer")

main()