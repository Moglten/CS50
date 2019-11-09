from cs50 import get_string
from sys import argv


def caeser():
    b = int(argv[1])
    s = get_string("plain text : ")
    cyphered_word =[]
    i = 0
    for c in s :
        cyphered_word += [chr(ord(c)+b)]
    print("ciphertext : ",end="")
    for i in cyphered_word :
        if (ord(i)>ord("A") and ord(i)<ord("Z"))or(ord(i)>ord("a") and ord(i)<ord("z")) :
            print(i, end="")
        else :
            print(i, end="")


if len(argv)==2   :
    caeser()

else:
    print("u do it wrong i need word and cypher code")
    caeser()