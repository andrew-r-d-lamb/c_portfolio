/*************************************************************************************************

*RELEASE NOTES FOR PROGRAM PORTFOLIO
*Authors: Andrew Lamb
*Student No: 01421662
*Email Address: andrew.r.d.lamb@gmail.com
*Phone No: 0877774746
*Last Modified: 24/12/2012

*************************************************************************************************/


/************************ EDITOR, COMPILER AND SYSTEM INFORMATION ***************************************/
* Programs were written and compiled on Windows XP 32bit Edition Service Pack 3
* All programs were written using Notepad++ v6.1.6 for Windows
* Programs were compiled using MinGW GCC compiler 4.6.2
* ALL PROGRAMS COMPILE AND RUN ON THIS SYSTEM WITHOUT WARNING OR ERROR MESSAGES


/********************************* NOTES ON PROGRAMS ********************************************/
// PROGRAM 1 - helloworld.c
Program displays: 
hello, world

// PROGRAM 2 - helloworldnewline.c
Program displays:
hello,
world

// PROGRAM 3 - add.c
Program assigns values to two variables - one and two, assigns the sum of those to 
another variable - three, and displays the contents of all three.

// PROGRAM 4 - size_of.c
Program displays the size of: 
an int, 
a char, 
a float and 
a double, 
an int array with 3 elements
a char array with 4 elements
a float array with 5 elements and
a double array with 6 elements

// PROGRAM 5 - colour.c
Program asks user what their favourite colour is, stores it in an array and displays it back to the user

// PROGRAM 6 - colourfirstletter.c / colourfirstletteralt.c
Program asks user to input their favourite colour and prints back the first letter
2 versions:
colourfirstletter.c prints out just the first character of the array
colourfirstletteralt.c sets second character of array to '\0' and then prints out array

// PROGRAM 7 - colouroverflow.c
Program is an example of bad coding practice causing an overflow in memory and crashing program

// PROGRAM 8 - addandsubtracttwonumbers.c
Program adds and subtracts 2 numbers entered by the user

// PROGRAM 9 - addsubtractintoarray.c
Program adds and subtracts 2 numbers entered by the user, stored in an array

// PROGRAM 10 - largestnumberfromthree.c
User inputs three numbers and program outputs largest number

// PROGRAM 11 - pp11.c
Program gets word from user using scanf and character from user using getchar()
do-while loop used to remove '\n' character from getchar()

// PROGRAM 12 - simplecalculator.c
Program is a simple calculator

// PROGRAM 13 - simplecalculatorloop.c / sclTutor.c
Program is a simple calculator that loops until user enters q to quit
2 versions:
simplecalculatorloop.c uses a do while loop
sclTutor.c uses a while loop

// PROGRAM 14 - unsignedint.c
Program is an example of what happens when you try to put a negative value into an unsigned integer

// PROGRAM 15 - whileloop10000.c
Program initialises a char as a byte.
Loop runs 10000 times - what's largest value output?
(Loop cycles around from -128 to 127)

// PROGRAM 16 - wCC.c
User inputs a word, program counts number of characters

// PROGRAM 17 - wordCountCharForLoop.c
User inputs a word, program counts characters using a for loop

// PROGRAM 18 - guessTheWord.c
Program loops until user guesses correct word

// PROGRAM 19 - threeGuesses.c
Program gives user 3 chances to guess correct word
Program loops the correct answer multiple times if user answers incorrectly 3 times

// PROGRAM 20 - fgetsExample.c / scanfExample.c
Programs take input from user and display them back.
fgetsExample.c stores a sentence
scanfExample.c stores a word
NOTE: when printing out stored input from fgets contains a newline character

// PROGRAM 21 - reverser.c / reverserAlternative.c
Programs that reversed the order of the letters in words, 
but not the whole sentence, 
and then prints them backwards
reverserAlternative.c uses a temporary char to switch letters

// PROGRAM 22 - replaceVowels.c
Program replaces vowels from user-input with & signs

// PROGRAM 23 - threeGuessesUsingFunction.c
Program gives user 3 chances to guess correct word. Separate Function Used to receive User Input and modify array in Main
Program loops the correct answer multiple times if user answers incorrectly 3 times

// PROGRAM 24 - reverserFunc.c
Program that reverses the order of the letters in words, function reverses characters for the individual words

// PROGRAM 25 - countEachLetterSimple.c / countEachLetterExperimentalCleaned.c
Programs take sentence from user and count number of each letter of alphabet entered in sentence
NOTE: Programs only counts lower-case letters
ADDITIONAL NOTE ON countEachLetterExperimentalCleaned.c
Program was used as practice for functions and also additional loops were used

// PROGRAM 26 - secondMain.c
Example of the second main() - copied from L5 Slide 28

// PROGRAM 27 - mallocPractice.c
Program allocates memory using malloc, gets input from user, prints output and memory address

// PROGRAM 28 - arrayContents.c
Program stores user input in an array, displays memory location and contents

// PROGRAM 29 - calcWithArgs.c / calcWithArgsAlt.c / calcWithArgsSscanf.c
Programs take user-input from cmd-line arguments and runs a simple calculator
calcWithArgs.c and calcWithArgsAlt.c use atoi to convert char to int. (Accessed slightly differently)
calcWithArgsSscanf.c uses sscanf to copy from char arguments in integer array

// PROGRAM 30 - pointers.c
Pointers practice, program takes input from user, modifies it slightly and outputs altered content

// PROGRAM 31 - guessWordFromFile.c
Secret word stored in file. user has three attempts to guess the word
Program loops the correct answer multiple times if user answers incorrectly 3 times
NOTE: Secret word stored in secretword.txt

// PROGRAM 32 - textfilecopy.c
Program copies text from one file to another

// PROGRAM 33 - guesses20words.c
20 secret words in a text file. 
User gets 3 guesses per secret word. 
If user guesses correctly, next word is selected.
NOTE: Secret words stored in secretword.txt

// PROGRAM 34 - fileCompare.c
Program compares 2 files to see if they are the same
NOTE: txt docs used one.txt, sameAsOne.txt and differentToOne.txt

// PROGRAM 35 - fileReader.c
Program reads contents of a file 20 lines at a time
NOTE: Tested with longfile.txt

// PROGRAM 36 - checkbrackets.c
Program counts number of brackets ()[]{} and informs user if there are a different number of left and right brackets
NOTE: Tested with this file (checkbrackets.c) and also testfileDifferentNumberOfBrackets.c

// PROGRAM 37 - readWriteToStructFileC.c
Program asks user if they want to read a file or overwrite the details in the file.
Based on chosen options, functions are called to read file, change details in struct
and write to file.

// PROGRAM 38 - studentFile.c
For More than one Student:
Program asks user if they want to: 
-read student file, 
-overwrite it with multiple students,  
-add multiple new students to the file or
-edit existing students.
Based on chosen options, functions are called to read file, change details in struct
and write to file.
If edit function is requested, file is read into an array of structs, user can amend as
required, and then new information from array is sent back to file, overwriting the file.
NOTE: file used: studentDetails.txt

// PROGRAM 39 - studentLLfile2.c
Program stores students in file students.txt and automatically retrieves this information when run
User is given option to add students, edit students, delete students, display all students or quit
While program is running, student information is stored in a linked list
NOTE: file used: students.txt
