def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")


def dollars_to_float(d):
    d_rmv_sign = d.replace("$","")
    return float(d_rmv_sign)


def percent_to_float(p):
    p_rmv_sign = p.replace("%", "")
    p_convert = float(p_rmv_sign) / 100
    return p_rmv_sign


main()