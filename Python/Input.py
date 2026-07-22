def numput(s, type):
    while True:
        try:
            return type(input(s))
        except:
            print("Invalid input! Try again.")

def main():
    print(input("Enter your name: "))
    print(numput("Enter your age: ", int))
    print(numput("Enter your height: ", float))

if __name__ == "__main__":
    main()