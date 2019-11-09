from cs50 import get_float

change=get_float("Change Owed : ")

def cash(change):
    if change >= 1:
        a = change//1
        print(f"flos : {a}")
    elif change < 1 and change >= .25:
        b = change//.25
        print(f"flos : {b}")
    elif change < .25 and change >= .1:
        c = change//.1
        print(f"flos : {c}")
    elif change < .1  :
        e = int(change // .01)


if change > 0 :
    cash(change)

else:
    print("Not invalid number")
    cash(change)