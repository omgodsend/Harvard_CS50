
def main():
    answer = input("Enter time: ")
    time = convert(answer)

    if nhours >= 7 and nhours <= 8:
        print("Breakfast time")
    if nhours >= 12 and nhours <= 13:
        print("Lunch time")
    if nhours >= 18 and nhours <= 19:
        print("Dinner time")

def convert(time):
    hours, minutes = time.split(":")

    nhours = float(hours)
    nminutes = int(minutes)/60
    return float(hours) + nminutes


if __name__ == "__main__":
    main()