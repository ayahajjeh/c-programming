/*
*
* chill.c calculates “wind chill” based on temperature and wind speed.
*
* input: a first optioanl parameter of temperature, and a second optional parameter of wind speed
* output: in case of zero arguments:
 it should print out a table of temperatures (from -10 to +40 by 10’s) 
 and and wind speeds (from 5 to 15 by 5’s).
 in case of one argument:
 prints a table of wind speeds (from 5 to 15 by 5’s) and the calculated wind chills for the one entered temperature only.
 in case of two arguments:
 the program calculates and prints the wind chill for the entered temperature and velocity only.
*
* compile: mygcc -o chill chill.c ...
* usage: ./chill [temperature] [windVelocity]
*
* Aya Hajjeh, Sep 22, 2022
* CS50, Fall22
*/

 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>

 // purpose: a function that calculates the wind chill
 // parameters: temperature and velocity
 // output: wind chill
 double windChill (double temperature, double velocity){
        //we check temperature and velcity bounds before passing them to windChill in the main function
                return 35.74 + 0.6215 * temperature - 35.75 * (pow(velocity, 0.16)) + 
                0.4275 * temperature * (pow(velocity, .16));
        
 } 

 int main(int argc, char *argv[]) {
        char usage[] = "./chill [temperature] [windVelocity]";

        // if the user provides zero arguments
        if (argc == 1){
                printf(" Temp   Wind  Chill\n");
                printf("-----  -----  -----\n");
        
                for (double temp = -10; temp <= 40.0; temp+=10){
                        for (double velocity = 5; velocity <= 15.0; velocity+=5){
                                printf("%5.1f  %5.1f  %5.1f\n", temp, velocity, windChill(temp, velocity));
                        }
                        printf("\n");
                }
                
        }

        // if the user provides one argument
        if (argc == 2){
                double temp = atof(argv[1]);
                if (temp < 50 && temp > -99){
                        printf(" Temp   Wind  Chill\n");
                        printf("-----  -----  -----\n");
                        
                        for (double velocity=5.0; velocity <= 15.0; velocity+=5){
                                printf("%5.1f  %5.1f  %5.1f\n", temp, velocity, windChill(temp, velocity));
                        }
                        printf("\n");
                }
                else
                printf("Temperature must be less than or equal to 50.0 degrees Fahrenheit and greater than -99.0\n");
        }

        // if the user provides two arguments
        if (argc == 3){
                double temp = atof(argv[1]);
                double velocity = atof(argv[2]);
                        if (temp < 50 && temp > -99) 
                                if (velocity >= 0.5){
                                printf(" Temp   Wind  Chill\n");
                                printf("-----  -----  -----\n");
                                printf("%5.1f  %5.1f  %5.1f\n", temp, velocity, windChill(temp, velocity));
                                printf("\n");
                                }
                                else
                                        printf("Wind velocity must be greater than or equal to 0.5 MPH\n");
                        else
                                printf("Temperature must be less than or equal to 50.0 degrees Fahrenheit\n");

        }

        // if the user provides more than two arguments
        if (argc > 3){
                printf("%s\n", usage);
                return 1;
        }

        return 0;
 }