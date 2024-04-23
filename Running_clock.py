########################################################################
##
## CS 101
## Program #13
## Henry Madriles
## hmx7n@mail.umkc.edu
##
## PROBLEM : Ask user for current hour, minute, and seconds and return clock with updated values every second (i.e. display clock).
##
## ALGORITHM : 
##      1. Import time module and create Clock class
##      2. Initialize hours, minutes, seconds and clock type to default to 0
##      3. Define str functin to print the clock
##      4. Define tick function to update hours, minutes, and seconds with consideration to how real time works with 59 going into 60 restarts the clock to 0 for the seconds and minutes.
##      As for hours, either 12 will change to 1 or 23 will change to 0, whether it is a 12 hour clock or 24 clock respectively.
##      5. Ask user for hours, minutes, and seconds while making sure that each input is valid with how time works.
##      6. Ask user for clock type.
##      7. Create the instance for their inputs by passing their inputs to the class and return clock each time the clock updates (i.e. every second).
## 
## ERROR HANDLING:
##      Making sure that user inputs for hours, minutes, and seconds are valid in the sense of how real time works.
##
## OTHER COMMENTS:
##      Any special comments
##
########################################################################


# Clock will go on infinitely. I don't have it set to stop at any time

import time

class Clock():
    def __init__(self, hour = 0, minute = 0, second = 0, clock_type = 0):
        '''Initializes hours, minutes, seconds, and the clock type.'''
        self.hour = hour
        self.minute = minute
        self.second = second
        self.clock_type = clock_type
    def __str__(self):
        '''Checks whether user wanted a 24 hour clock or 12 hour clock then outputs the clock. If user chose 12 hour clock but put in 24 hour clock based time, then their hour would automatically change to a 12 hour clock type. Otherwise, it will do the 24 hour clock.'''
        if self.clock_type == 1:
            if self.hour > 12:
                self.hour -= 12
                return('{:02}:{:02}:{:02} PM'.format(self.hour,self.minute,self.second))
            elif self.hour < 13 and self.hour > 0:
                return('{:02}:{:02}:{:02} AM'.format(self.hour,self.minute,self.second))
            elif self.hour == 0:
                self.hour += 12
                return('{:02}:{:02}:{:02} AM'.format(self.hour,self.minute,self.second))
        elif self.clock_type == 0:
            if self.hour > 11:
                return('{:02}:{:02}:{:02} PM'.format(self.hour,self.minute,self.second))
            elif self.hour < 12:
                return('{:02}:{:02}:{:02} AM'.format(self.hour,self.minute,self.second))

    def tick(self):
        '''Updates the hours, minutes, and seconds. And checks if seconds or minutes is at 59, then it will change to 0. For hours, based on whether user wanted a 24 clock or 12 hour clock will change from 23 to 0 or 12 to 1 respectively.'''
        if self.clock_type == 1:
            if self.second == 59:
                self.second = 0
                if self.minute == 59:
                    self.minute = 0
                    if self.hour == 12:
                        self.hour = 1
                    elif self.hour != 12:
                        self.hour += 1
                elif self.minute != 59:
                    self.minute +=1
            else:
                self.second += 1
        elif self.clock_type == 0:
            if self.second == 59:
                self.second = 0
                if self.minute == 59:
                    self.minute = 0
                    if self.hour == 23:
                        self.hour = 0
                    elif self.hour != 23:
                        self.hour += 1
                elif self.minute != 59:
                    self.minute +=1
            else:
                self.second += 1
            

if __name__ == "__main__":
    '''Asks user for hour, minute, and seconds and will check to see if they are valid, if not then will ask user for valid inputs. Then asks user for valid clock type.'''
    while True:
        hour = int(input('What is the current hour ==> '))
        minute = int(input('What is the current minute ==> '))   
        second = int(input('What is the current second ==> '))
        if hour > 23 or hour < 0:
            print('Value for hour must be valid')
            continue
        elif minute > 59 or minute < 0:
            print('Value for minute must be valid')
            continue
        elif second > 59 or second < 0:
            print('Value for second must be valid')
            continue
        a = True
        while a == True:
            choice = int(input('For 24 hour clock, press 0. For 12 hour clock, press 1 ==> '))
            if choice == 1 or choice == 0:
                clock_type = choice
                clock = Clock(hour, minute, second, clock_type)
                while True:
                    print(clock)
                    clock.tick()
                    time.sleep(1) 
            else:
                print('Input valid value for type of clock.')
                continue
                
    
    
                        
