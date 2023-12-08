/*
*
* words.c breaks its input into a series of words, one per line.
*
* input: stdin or files whose names are listed as arguments.
* output: sequence of lines, with exactly one word on each output line
*
* compile: mygcc -o words words.c ...
* usage: ./words words [filename]...
*
* Aya Hajjeh, Sep 22, 2022
* CS50, Fall22
*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <string.h>
 #include <ctype.h>

  
  // purpose: reads a file character by character to print a series of lines with only one word on each line
  // parameters: file pointer
  // output: sequence of lines, with exactly one word on each output line
  void fileProcessor (FILE * fp){

    //wordPrinted is used to make sure we don't print out empty lines each time we reach a nonalphabetical character since that
    // one time is enough. (for example: hello&&&&&world)
    bool wordPrinted = false;
    
    char charReached = (char)fgetc(fp);
    
    //read char by char
    while(!feof(fp)) {
   
       //if the character is not alphabetical
        if (!isalpha(charReached)){
            //we print a new line only if we are not on a new line already
            if (wordPrinted){
                printf("\n");
                wordPrinted = false;
            }
        }

        //if the character is alphabetical
        else{
            printf("%c",charReached);
            wordPrinted = true;
        }
        charReached = (char)fgetc(fp);
    }
    fclose(fp);
  }
  
  int main(int argc, char *argv[]) {
    
    //num of parameters is zero
    if (argc == 1) {
        //read from stdin
        fileProcessor(stdin);
    }

    //num of parameters is greater than zero
    else{
        int count = 1;
        while (count < argc){
        //read from the files entered by the user
        //the special character - refers to stdin
        if (!(strcmp(argv[count],"-")))
            fileProcessor(stdin);
        else{
            FILE * fp = fopen(argv[count],"r");
            if (fp == NULL) {
            fprintf(stderr,"Unable to open %s\n", argv[count]);
            return 1;
            }
            fileProcessor(fp);
        }
        count++;
        }

    }
    
    return 0;
  }