#include <stdio.h>
int main()
{
    //Declaring variables before use
    char deleteChar;
    char string[100];
    char newString[100];
    int i, counter=0;
     
    //Read in a character and store in deleteChar
    scanf("%s", &deleteChar);
     
    //Read in a character and store in string
    scanf("%s", string);
     
    //For loop runs from 0-7
    for(i=0;string[i]!=0;i++)
    {
        //Check if the character doesnt match
        if(deleteChar != string[i]){
            //Assign to a new string
            newString[counter] = string[i];
            //Increment the other counter
            counter++;
        }
    }
    //Print the edited string
    printf("%s\n", newString);
    return 0;
}
/**************************************************************
    Problem: 1026
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/