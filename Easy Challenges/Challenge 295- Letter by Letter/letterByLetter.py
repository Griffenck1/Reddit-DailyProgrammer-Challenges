index = 0
while index == 0:
    string1 = list(input("Please enter the first sentence:"))
    string2 = list(input("Please enter the second sentence:"))
    if len(string1) == len(string2):
        print("".join(string1))
        for i in range(len(string1)):
            string1[i] = string2[i]
            print(str("".join(string1)))
    else:
        print("Please enter two sentences of equal length")
    choice = ""
    while choice not in {"n", "N", "y", "Y"}:
        choice = input("Would you like to go again(Y/N)?")
        if choice == "n" or choice == "N":
            index += 1
            break 