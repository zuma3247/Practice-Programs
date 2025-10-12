#****************************************************************************************************
#
#   Name:         Muazuddin Mohammed
#   Course:       COSC 2110 Computer Languages: Python
#   Assignment:   population.py
#   Due Date:     01/29/2025
#   Description:
#       This program sks the user to enter five test scores. The program displays a letter grade
#       for each score and the average test score.
#
#****************************************************************************************************

MIN_SCORE = 0
MAX_SCORE = 100
NUM_OF_SCORES = 5
A_MIN = 90
B_MIN = 80
C_MIN = 70
D_MIN = 60

#****************************************************************************************************

def calc_average(s1, s2, s3, s4, s5):

    sum_nums = s1 + s2 + s3 + s4 + s5
    avg = sum_nums / NUM_OF_SCORES

    return avg

#****************************************************************************************************

def determine_grade(score):

    if A_MIN <= score <= MAX_SCORE:
        grade = "A"
    elif B_MIN <= score < A_MIN:
        grade = "B"
    elif C_MIN <= score < B_MIN:
        grade = "C"
    elif D_MIN <= score < C_MIN:
        grade = "D"
    else:
        grade = "F"

    return grade

#****************************************************************************************************

def get_grade():

    score = float(input("Enter score: "))
    while score > MAX_SCORE or score < MIN_SCORE:
        print(f"Score must be between {MIN_SCORE} and {MAX_SCORE}: ")
        score = float(input("Enter score: "))

    return score

#****************************************************************************************************

def main():

    print("Please enter ", NUM_OF_SCORES, " scores.")

    score1 = get_grade()
    score2 = get_grade()
    score3 = get_grade()
    score4 = get_grade()
    score5 = get_grade()

    avg = calc_average(score1, score2, score3, score4, score5)

    grade1 = determine_grade(score1)
    grade2 = determine_grade(score2)
    grade3 = determine_grade(score3)
    grade4 = determine_grade(score4)
    grade5 = determine_grade(score5)
    avg_grade = determine_grade(avg)

    print(f'{"Score":<30}{"Numeric Grade:":<20}{"Letter Grade":<10}')
    print('-' * 70)

    print(f'{"score 1:":<30}{score1:<20.2f}{grade1:<10}')
    print(f'{"score 2:":<30}{score2:<20.2f}{grade2:<10}')
    print(f'{"score 3:":<30}{score3:<20.2f}{grade3:<10}')
    print(f'{"score 4:":<30}{score4:<20.2f}{grade4:<10}')
    print(f'{"score 5:":<30}{score5:<20.2f}{grade5:<10}')

    print(f'{"Average score:":<30}{avg:<20.2f}{avg_grade:<10}')


if __name__ == '__main__':
    main()

#****************************************************************************************************

"""
Please enter  5  scores.
Enter score: 95
Enter score: 190
Score must be between 0 and 100: 
Enter score: -200
Score must be between 0 and 100: 
Enter score: 90
Enter score: 40
Enter score: 80
Enter score: 70
Score                         Numeric Grade:      Letter Grade
----------------------------------------------------------------------
score 1:                      95.00               A         
score 2:                      90.00               A         
score 3:                      40.00               F         
score 4:                      80.00               B         
score 5:                      70.00               C         
Average score:                75.00               C         

"""