# zero arguments                                                                    
./chill
# one argument as integer                                                                   
./chill 10
# one argument as double                                                                   
./chill 10.7
# two arguments, the second as integer                                                                 
./chill 10.9 5
# two arguments, the second as double                                                                 
./chill 10.9 5.5
# temp out of range                                                                 
./chill 100
# wind out of range                                                                 
./chill 20 0
# too many arguments
./chill 20 10 10 10