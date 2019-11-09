from cs50 import get_int

print("input height betwen 1 and 8 \n")

height = get_int("Height : ")

i=1
space=" "

if height>0 and height<=8 :
    for  i in range(height+1):
       print((height - i) * " " + (i) * "#")


else :
    print("Not invalid number")



