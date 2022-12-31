
def main():
    asnwer = input("Enter time: ")
    time = convert(answer)


    if nhours >= 7 and nhours <= 8:
        print("Breakfast time")
    elif


def convert(time):
    hours, minutes = time.split(":")

    nhours = float(hours)
    nminutes = int(minutes)/30
    return n


if __name__ == "__main__":
    main()