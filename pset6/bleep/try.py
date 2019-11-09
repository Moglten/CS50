from cs50 import get_string
from sys import argv

file = open("banned.txt","r")
content = file.read()
print(content)