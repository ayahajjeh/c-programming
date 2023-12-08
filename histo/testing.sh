# all numbers inside the range of 0-15
./histo
# inputting numbers outside the original range of 0-15
./histo
# inputting a number outside the original range of 0-15
#that is big enough that the program has to double the bin size multiple times
./histo
# an example using bash syntax to generate a list of numbers, and piping the output to histo
echo {1..16} 150 | ./histo