#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //Declare variables (integers) for use
    int n, m, stringLength, counter,tempLength,tempLength2;
    //Char array for input, and 2D array for strings
    char string[100];
    char **strings;
    //read in input
    scanf("%d", &n);
    //allocate memory to the inputted value
    strings = malloc(n*sizeof(char*));
     
    //Accept n number of strings using for loop
    for(counter=0; counter<n; counter++)
    {
        scanf("%s", string);
        //Calculate length of string
        for(stringLength=0; string[stringLength]!='\0'; stringLength++);
        //Allocate memory for that string
        strings[counter] = malloc((stringLength+1)* sizeof(char));
        //Assign string into the array
        strncpy(strings[counter], string, stringLength);
        strings[counter][stringLength] = '\0';
        stringLength=0;
    }
     
    //Get input of m
    scanf("%d", &m);
    //Reallocate memory for string array to new value
    strings = realloc(strings, (sizeof(char*)*(n+m)));
     
    //Accept m number of strings using for loop
    for(counter=n; counter<m+n; counter++)
    {
        scanf("%s", string);
        //Calculate length of string
        for(stringLength=0; string[stringLength]!='\0'; stringLength++);
        //Allocate memory for that string
        strings[counter] = malloc((stringLength+1)* sizeof(char));
        //Assign string into the array
        strncpy(strings[counter], string, stringLength);
        strings[counter][stringLength] = '\0';
        stringLength=0;
    }
     
    char temp[100];
    int tempLength3, counter2;
    //Nested for loops to perform the sort
    //2 Loops from 0 to total number of strings-1
    for(counter=0; counter<m+n-1; counter++)
    {
        for(counter2=0; counter2<m+n-1; counter2++){
            //Calculate lengths of the current string and the next
            for(tempLength=0; strings[counter2][tempLength]!='\0'; tempLength++);
            for(tempLength2=0; strings[counter2+1][tempLength2]!='\0'; tempLength2++);
            //Check if the next strings length is bigger than the current
            if(tempLength2>tempLength)
            {
                //Copy into a temp variable
                strcpy(temp, strings[counter2]);
                 
                //Reallocate memory as the next string will be put into this element
                strings[counter2] = realloc(strings[counter2], (tempLength2+1)* sizeof(char));
                //Copy the next string into the current
                strcpy(strings[counter2], strings[counter2 +1]);
                //Add in the end character
                strings[counter2][tempLength2] = '\0';
                 
                //Calculate length of temp variable
                for(tempLength3=0; temp[tempLength3]!='\0'; tempLength3++);
                //Reallocate the next string element to the length of the temp
                strings[counter2+1] = realloc(strings[counter2+1], (tempLength3+1)* sizeof(char));
                //Copy the temp in
                strcpy(strings[counter2 +1], temp);
                //Add in the end character
                strings[counter2+1][tempLength3] = '\0';
                 
            }
        }
    }
         
    //Print out first string
    printf("%s", strings[0]);
    //Print out the rest
    for(counter=1; counter<(m+n); counter++)
    {
        printf("\n%s", strings[counter]);
    }
     
    //For loop to free memory of array
    for(counter=0;counter<(m+n);counter++)
    {
        free(strings[counter]);
    }
    free(strings);
    return 0;
}
 
/**************************************************************
    Problem: 1043
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:984 kb
****************************************************************/