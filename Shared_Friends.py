########################################################################
##
## CS 101
## Program #11
## Henry Madriles
## hmx7n@mail.umkc.edu
##
## PROBLEM : Need to open and read a file that contains a list of friends. Will return for the user the shared/unique friends based on what the user
##           option from the menu.
##
## ALGORITHM : 
##      1. Open and read the file
##      2. Ask user for option from the menu, making sure they input a valid option
##      3. Ask the user for two names so that you can get their shared friends
##      4. Based on their option, call the appropriate function that either gets the intersection, difference, or symmetric difference from the shared names
##      5. Print out for the user the shared friends
##      6. Keep printing the menu until user inputs "Q"
## 
## ERROR HANDLING:
##      Any Special Error handling to be noted.  Wager not less than 0. etc
##
## OTHER COMMENTS:
##      Any special comments
##
########################################################################

def shared_friends_by_2(friends_dict):
    '''This will ask the user for two people to compare and make sure they are in the network, then will find the intersection of friends between those two.'''
    a = True
    while a == True:
        try:
            person1 = input('Enter a valid person (Capitalize first letter of name) ==> ')
            friends_dict[person1]
            a = False
        except KeyError:
            print(person1, 'is not part of this network, enter another name.\n')
            continue
    b = True
    while b == True:
        try:
            person2 = input('Enter a valid person (Capitalize first letter of name) ==> ')
            friends_dict[person2]
            b = False
        except KeyError:
            print(person2, 'is not part of this network, enter another name.\n')
            continue
    people = friends_dict[person1].intersection(friends_dict[person2])
    print(person1, 'and', person2, 'share these people:')
    for name in people:
        print(name)
def friends_of_x(friends_dict):
    '''This will ask teh user for two names, making sure they exist in the network, then will take the difference (friends with one but not the other) and will return that to the user.'''
    a = True
    while a == True:
        try:
            person1 = input('Enter a valid person (Capitalize first letter of name) ==> ')
            friends_dict[person1]
            a = False
        except KeyError:
            print(person1, 'is not part of this network, enter another name.\n')
            continue
    b = True
    while b == True:
        try:
            person2 = input('Enter a valid person (Capitalize first letter of name) ==> ')
            friends_dict[person2]
            b = False
        except KeyError:
            print(person2, 'is not part of this network, enter another name.\n')
            continue
    people = friends_dict[person1].difference(friends_dict[person2])
    print('These people are friends with', person1, 'but not with', person2 + '.')
    for name in people:
        print(name)
def all_friends(friends_dict):
    '''This will ask the user for two names, making sure they are in the network, then will return the unique friends that each person has but does not share with the other.'''
    a = True
    while a == True:
        try:
            person1 = input('Enter a valid person (Capitalize first letter of name) ==> ')
            friends_dict[person1]
            a = False
        except KeyError:
            print(person1, 'is not part of this network, enter another name.\n')
            continue
    b = True
    while b == True:
        try:
            person2 = input('Enter a valid person (Capitalize first letter of name) ==> ')
            friends_dict[person2]
            b = False
        except KeyError:
            print(person2, 'is not part of this network, enter another name.\n')
            continue
    people = friends_dict[person1].symmetric_difference(friends_dict[person2])
    print('These people are friends with', person1, 'and', person2 +',', 'but not both.')
    for name in people:
        print(name)
    

if __name__=="__main__":

    with open("friends.txt", 'r') as f:
        friends = f.readlines()
        new_friends = []
        friends_dict = {}
        for friend in friends:
            friend = friend.strip()
            first, second = friend.split(' ')
            if first in friends_dict.keys():
                friends_dict[first].add(second)
            else:
                friends_dict[first] = {second}
        
    while True:
        print('\nSocial Network \n')
        print('I. Find all friends shared by 2 people')
        print('D. Find all friends of X, that person Y does not have')
        print('S. Find all friends that X and Y have, but do not share with each other')
        print('Q. Quit \n')
        choice = input('Input option ==> ')
        if choice == 'I' or choice == 'i':
            shared_friends_by_2(friends_dict)
        elif choice == 'D' or choice == 'd':
            friends_of_x(friends_dict)
        elif choice == 'S' or choice == 's':
            all_friends(friends_dict)
        elif choice == 'Q' or choice == 'q':
            break
        else:
            print('Input valid option \n')
            continue
