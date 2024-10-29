import random
# student_scores = {
#     "Harry":81,
#     "Ron":78,
#     "Her":  99,
#     "Draco": 74,
#     "Nevile":62,    
# }

# student_grades = {}

# for i in student_scores:
#     if student_scores[i] >= 91 and student_scores[i] <= 100:
#         student_grades[i] = "Outstanding"
#     elif student_scores[i] >= 81 and student_scores[i] <= 90:
#         student_grades[i] = "Exceed Expectations"
#     elif student_scores[i] >= 71 and student_scores[i] <= 80:
#         student_grades[i] = "Acceptable"
#     else:
#         student_grades[i] = "Fail"

# print(student_grades)


# travel_log = {
#     "France" : {"cities visited" : ["Paris","Lille","Dijon"]},
#     "Germany" : ["Berlin","ham","stut"]
# }

# print(travel_log)

# logo = '''
#                          ___________
#                          \         /
#                           )_______(
#                           |"""""""|_.-._,.---------.,_.-._
#                           |       | | |               | | ''-.
#                           |       |_| |_             _| |_..-'
#                           |_______| '-' `'---------'` '-'
#                           )"""""""(
#                          /_________\\
#                        .-------------.
#                       /_______________\\
# '''



# print (logo)

# print("Welcome to the auction")

# choice = ""
# dic = {}

# while choice != "no":
#     name = input("What is your name : ")
#     bid = int(input("What's your bid : "))
#     dic[name] = bid
#     choice = input("yes or no\n")
#     os.system('clear')
    
# max_name = ""
# max_bid = 0

# for i in dic:
#     if dic[i] > max_bid:
#         max_name = i
#         max_bid = dic[i]
    
# print("The winner is " + max_name + " with the bid of $" + str(max_bid))


print("choose 1 - 100")

ran = random.randint(1,100)
ez = input("ez or wp\n")

if ez == "ez":
    for i in range(10):
        print("Attempt "+str(i+1))
        c = int(input("Enter : "))
        if c > ran:
            print("High")
        elif c < ran:
            print("Low")
        elif c == ran:
            print("You won")
            break
else:
    for i in range(5):
        print("Attempt "+str(i+1))
        c = int(input("Enter : "))
        if c > ran:
            print("High")
        elif c < ran:
            print("Low")
        elif c == ran:
            print("You won")
            break