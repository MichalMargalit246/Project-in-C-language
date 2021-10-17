#include "declaration.h"
/*Transition 1: We built an array with structs. 1. Name of label. 2. Line 3.Entry 4. External*/
/*Transition 2: We built an array with union and with structs. Transition 2 is based on a bit field*/
char line[MAX_LINE]; 
arr pass1[MAX_MEMORY];
arr pass1_var[MAX_MEMORY];
line_type pass2[MAX_MEMORY];

int main(int argc, char* argv[])
{
    char* fileName;
    char inputFileName[80];
    char temp[80];
    int i;
    FILE *file;
    if(argc==1)
    {
        printf("\n%s\n","There is no input file to compile");
        return 0;
    }
    /* read file by file and compile them */
    for(i=1; i<2; i++)
    {
        fileName = argv[i];
        strcpy(inputFileName,argv[i]);
        strcat(inputFileName,".as");
        file = fopen (inputFileName, "r");
        if (!file)
        {
            return 0;
        }
        else
        {
           printf("\n%s\n","the file is open");
        }
        transfer(file);
        /*Delete temp file*/
        strcpy(temp, fileName);
        strcat(temp,".ex");
        remove(temp);
        strcpy(temp, fileName);
        strcat(temp,".en");
        remove(temp);
        fclose(file);
    } 
    return 0;
}
