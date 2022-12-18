def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")


def dollars_to_float(d):
    dollars_conv = d.replace ("$","")
    return float(dollars_conv)


def percent_to_float(p):
    percent_conv = p.replace ("%", "")
    return float(percent_conv) / 100


main()