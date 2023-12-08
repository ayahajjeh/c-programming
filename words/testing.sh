# zero argument from stdin
./words
# note: testing1.txt and testing2.txt have instances where words are separated by non-alphabetical characters 
#and have a bunch of numbers thrown over the text file
# note: testing3.txt is just an empty file input
# one argument from a file that is not empty
./words testing1.txt
# one argument from a file that is empty
./words testing3.txt
# one argument from stdin using the dash "-" symbol
./words -
# two arguments a file and the dash
./words testing1.txt -
# three arguments a file, a dash, and another file
./words testing1.txt - testing2.txt
# input for words is from a pipe
./words < testing1.txt