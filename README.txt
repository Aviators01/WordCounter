Timothy Queva
CS2010 Lab4
October 6, 2020

Description: This program counts the number of times a word appears in a file or when typed via keyboard and displays the results
as a word frequency total and histogram.

Limitation: Program is unable differentiate between file vs keyboard input. Words bigger than 15 characters will mess up alignment.

Instructions: Navigate to the correct file folder.
	1. Compile and link by typing: make
	2. Run by typing: ./WordCounter
		a. While program is running, type words (hit enter after each word) and then ctrl + d when finished
		   (to signify end of input). 

Note: There is another method of data input which is file input. To use this method, type the following:
./WordCounter < <put_your_filename_here>.txt	<--(.txt for text file)