
l = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def encode (msg , shift):
    emp = ""
    for i in msg:
        if i.islower(): 
            lol = l.index(i)
            lol = (lol + int(shift))%26
            emp = emp + l[lol]
        else:
            emp = emp + i
    return emp

def decode (msg , shift):
    emp = ""
    for i in msg:
        if i.islower():
            lol = l.index(i)
            lol = (lol - int(shift) + 26) % 26
            emp = emp + l[lol]
        else:
            emp = emp + i
    return emp
choice = ""

while choice != "no":
    choice2 = input("Type encode or decode\n")
    if choice2 == "encode":
        message = input("Enter message : ")
        shift = input("Enter Shift : ")
        print("Your encoded message is " + encode(message,shift))
    else:
        message = input("Enter message : ")
        shift = input("Enter Shift : ")
        print("Your Decoded message is " + decode(message,shift))
    
    choice = input("You wanna go again ?\n")






# age = input("What is your current age ? \n")


# rem = 90-int(age)

# print(f"You have {rem * 365} days, {rem * 52} weeks, and {rem * 12} months left.")