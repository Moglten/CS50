from cs50 import get_string


def main():
    file = open("banned.txt","r")
    content = file.read()
    phrase = get_string("Say something dirty : \n")
    the_array = phrase.split(' ')
    for item in the_array :
        if item in content:
            print("*"*len(item),end=' ')
        else :
            print(item,end=' ')



if __name__ == "__main__":
    main()
