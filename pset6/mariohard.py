from cs50 import get_int

height = get_int("Type Ur from 1 to 8 Height : ")
i=1
if height>0 and height<=8 :
    for i in range( height + 1 ):
        print(" "*( height - i ) + "#"*(i) +"  "+"#"*(i))

else :
    print("Not invalid number")