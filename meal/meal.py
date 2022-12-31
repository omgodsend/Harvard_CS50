
def main():
    answer = input("Enter time: ")
    time = convert(answer)

    if nhours >= 7 and nhours <= 8:
        print("Breakfast time")
    elif nhours >= 12 and nhours <= 13:
        print("Lunch time")
    elif nhours >= 1 and nhours <= 13:
        print("Lunch time")

def convert(time):
    hours, minutes = time.split(":")

    nhours = float(hours)
    nminutes = int(minutes)/60
    return float(hours) + nminutes


if __name__ == "__main__":
    main()