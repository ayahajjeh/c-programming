/*
*
* histo.c reads a series of positive integers from stdin, and prints out a histogram.
*
* input: series of positive integers
* output: a histogram of 16 bins that encompasses the entered integers
*
* compile: mygcc -o histo histo.c ...
* usage: There are no command-line arguments.
*
* Aya Hajjeh, Sep 22, 2022
* CS50, Fall22
*/

 #include <stdio.h>
 #include <stdlib.h>


 int binSize = 1;
 const int binNum = 16;
 int histogramMax;

 //declaring an int array that will represent the 16 bins of the histogram
    int histogram[binNum];


 // purpose: compresses the current values of the histogrm into the first half of it. 
 // It then assigns zero values to the second half.
 // parameters: none
 // output: none
 void compressHistogram(){
    int binIndex = 0;
    //compute the new values for the lower half of the bins (each bin receiving the sum of two bins’ counts)
    for (int i=0; i<binNum/2; i++){
        histogram[i] = histogram[binIndex] + histogram[binIndex+1];
        binIndex += 2;
    }

    //another loop to assign the new value (0) to the upper half of the bins.
    for (int i=binNum/2; i<binNum; i++)
        histogram[i] = 0;

 }
 
 // purpose: rescales the histogram by compressing its current values and doubling each bin size
 // parameters: none
 // output: none
 void rescaleHistogram (){
        //compress the current 16 bins into the first 8 bins
        compressHistogram();

        //double bin size
        binSize *= 2;

        //double histogram range
        histogramMax = (histogramMax + 1) * 2 - 1;
 }

 // purpose: adding a new value to the histogram in its appropriate bin
 // parameters: a value that needs to be added to the histogram
 // output: none
 void addValueToHisto (int number){

      if (number <= histogramMax){
        int thisBinMax = binSize - 1;
        for (int i=0; i<binNum; i++){
            if (number <= thisBinMax){
                histogram[i]++;
                break;
            }
            thisBinMax += binSize;
        }
      }
 }

 // purpose: prints the low and high range of a specific bin in the histogram
 // parameters: index of a bin
 // output: prints the low and high range of a specific bin in the histogram
 void printRange( int binIndex ){
    //we can assume that the width of the [low:high] field is always 6 digits
    //the low range of the bin indexed binIndex is binSize * binIndex
    //the high range of the bin indexed binIndex is binSize * (binIndex + 1) -1
    printf("[%03d:%03d] ", binSize * binIndex, binSize * (binIndex + 1) -1);
 }

 // purpose: prints the correspoding number of stars in a specific bin
 // parameters: index of a bin
 // output: prints the correspoding number of stars in a specific bin
 void printStars( int binIndex ){
    for (int i=0; i<histogram[binIndex]; i++){
        printf("*");
    }
        
    printf("\n");
 }

 // purpose: describes the current state of the histogram in terms of bin number, bin size, and range of the histogram
 // parameters: none
 // output: prints out the bin number, bin size, and range of the histogram
 void describeHisto(){
    printf("%d bins of size %d for range [0,%d)\n", binNum, binSize, histogramMax + 1);
 }

  int main(int argc, char *argv[]) {

    //initializing the histogram array with zero values
    for (int i=0; i<binNum; i++)
        histogram[i] = 0;

    //initializing the max value of the histogram
    histogramMax = binNum * binSize - 1;

    int number;
    describeHisto();
    //reading input from the user
    while (scanf("%d", &number) == 1){
        //If the integer is a value outside the range of the histogram
        while (number > histogramMax){
            //it keeps rescaling the histogram until the entered value falls in the range of the histogram
            rescaleHistogram();
            describeHisto();
        }
        
        //if the integer is inside the range of the histogram and is greater than or equal to zero
        //if the entered integer is negative we just ignore its value
        if (number >= 0)
            addValueToHisto(number);

    }

    //printing out the histogram in the specified format
    for (int i=0; i<binNum; i++){
        printRange(i);
        printStars(i);
    }

    return 0;
 }