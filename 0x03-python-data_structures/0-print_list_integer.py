#!/usr/bin/python3

def print_list_integer(my_list=[]):
    for num in my_list:
        print("{:d}".format(num))

if __name__ == "__main__":
    import sys
    print_list_integer(eval(sys.argv[1]))
