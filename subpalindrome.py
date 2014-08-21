# --------------
# User Instructions
#
# Write a function, longest_subpalindrome_slice(text) that takes 
# a string as input and returns the i and j indices that 
# correspond to the beginning and end indices of the longest 
# palindrome in the string. 
#
# Grading Notes:
# 
# You will only be marked correct if your function runs 
# efficiently enough. We will be measuring efficency by counting
# the number of times you access each string. That count must be
# below a certain threshold to be marked correct.
#
# Please do not use regular expressions to solve this quiz!
import pdb

def longest_subpalindrome_slice(text):
    "Return (i, j) such that text[i:j] is the longest palindrome in text."
    # Your code here
    text = text.lower()
    length = len(text)
    isPalindrome = [[True if x is y else False for x in range(length)] 
                    for y in range(length)]
    for x in range(1,length):
        for i in range(length-x):
            if (x is 1 or isPalindrome[i+1][i+x-1]) and text[i] is text[i+x]:
                isPalindrome[i][i+x] = True
    max_D, longest_slice = 0, (0,0)
    for i in range(length):
        for j in range(length-i):
            if isPalindrome[i][i+j] and j > max_D:
                max_D = j
                longest_slice = (i,i+j+1)    
    return longest_slice
                
def test():
    L = longest_subpalindrome_slice
    assert L('racecar') == (0, 7)
    assert L('Racecar') == (0, 7)
    assert L('RacecarX') == (0, 7)
    assert L('Race carr') == (7, 9)
    assert L('') == (0, 0)
    assert L('something rac e car going') == (8,21)
    assert L('xxxxx') == (0, 5)
    assert L('Mad am I ma dam.') == (0, 15)
    return 'tests pass'

print test()