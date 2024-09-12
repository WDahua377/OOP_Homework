import sys
import string

sum = 0
number = 0  # number is the number of scores read
flag = 0    # flag is used to record whether it is the first calculation
while(7 == 7):  # Program will keep calculating, unless the input is "-1"
    if(flag == 0):
        str = input('Please input the score : ')    # first time
    else:
        str = input('Please input the score of next set : ')

    if(str == "-1"):      # when input is "-1", calculate the average
        if(number == 0):    # if there is no input
            flag = 1
            print('Average score is : 0.0')
        else:
            average = sum/number
            print('Average score is : {0}'.format(average) )
            sum = 0         # Initialize number and sum to 0 before starting.
            number = 0
            flag = 1       # and change the flag to 1 to indicate that it is not the first calculation after

    else:
        for i in range (0, len(str)):     # check if input is legal
            if( not str.isdigit() ):       # The isdigit() function checks whether a character is numeric character (0-9) or not.
                sys.exit('illegal input, ending the program...')    # if it is not integer, which means that it is illegal, end program.

        score = int(str)
        if(score >= 0 and score <= 100):     # Then check is score is 0~100
            sum += score      # Add new score into sum
            number += 1
        else:       # score > 100 or score < 0
            sys.exit('illegal input, ending the program...')
sys.exit()


#num2 = input('Enter second number: ')
# Add two numbers
#sum = float(num1) + float(num2)
# The zero argument is the name of the program file when using command line
# sum = float (sys.argv[1]) + float (sys.argv[2])
# Display the sum
#print('The sum of {0} and {1} is {2}'.format(num1, num2, sum))