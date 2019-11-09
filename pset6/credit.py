from cs50 import get_string

print("Input Ur Serial of Credit")
num = get_string("Number : ")


def kinda():
    if len(str(num)) == 15:
        print("AMEX")
    elif len(str(num)) == 13:
        print("Vise")
    elif len(str(num)) == 16:
        print("MasterCard")
    else :
        print("invalid")


def lun_algo():

    i= 2
    l= 1
    sum = 0
    while (len(num)-i) >= 0 :
        res=int(num[len(num)-i])*2
        if res > 9:
            res = str(res)
            double = (int(res[0])) + (int(res[1]))
            sum += double
        else :
            sum+=res
        i += 2
    while (len(num)-l) >= 0:
        numb = (int(num[len(num)-l]))
        sum += numb
        l+=2
    if (sum%10)==0 :

        return True
    else:

        return False






if lun_algo() == True :
    kinda()
else :
    print("Invalid")
