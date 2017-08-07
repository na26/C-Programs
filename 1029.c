#include <stdio.h>
int main()
{
    //Declaring variables for use, 2 strings and integer
    char string[100];
    char newString[100];
    int counter = 0;
     
    //Read in input using fgets
    fgets(string, 100, stdin);
     
    //While loop until the last character
    while(string[counter] != '\0')
    {
    //Check if the current character is between a and z
    if(string[counter] >= 'a' && string[counter] <= 'z')
    {
    //If it is then shift by 3 within the confines of the 26 lowercase alphabet
    //And assign to the new string
        newString[counter] = ((string[counter] - 'a' + 3) % 26)+ 'a';
    //Check if the current character is between A and Z
    } else if(string[counter] >= 'A' && string[counter] <= 'Z')
    {
    //If it is then shift by 3 within the confines of the 26 uppercase alphabet
    //And assign to the new string
        newString[counter] = ((string[counter] - 'A' + 3) % 26) + 'A';
         
    } else
    {
        //If it is none of the above cases, it remains the same
        newString[counter] = string[counter];
    }
        //increment the counter
        counter++;
     
    }
     
    //print out the new shifted string
    printf("%s", newString);
    return 0;   
}
/**************************************************************
    Problem: 1029
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/
한