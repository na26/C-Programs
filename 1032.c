#include <stdio.h>
//Declare calculate method
int calculate(char string[], char string2[]);
int main()
{
    //Declare 3 character arrays
    char input1[100];
    char input2[100];
    char input3[100];
 
    //Use fgets to get the 3 inputs which can have spaces
    fgets(input1, 100, stdin);
    fgets(input2, 100, stdin);
    fgets(input3, 100, stdin);
     
    //Print and call the calculate method with the strings as parameters.
    printf("%d ", calculate(input1, input2));
    printf("%d", calculate(input1, input3));
     
    return 0;
         
}
    //Method to calculate the occurrences
    int calculate(char string[], char string2[])
    {
         
        //Declare a letter and string occurence variable
        int letterOccurence =0;
        int stringOccurence =0; 
        int stringLength = 0, string2Length=0, counter, counter2;
        //Calculate the lengths of the 2 input strings
        for(stringLength=0; string[stringLength]!='\0'; stringLength++);
        stringLength = stringLength -1;
 
        for(string2Length=0; string2[string2Length]!='\0'; string2Length++);
        string2Length = string2Length -1;
 
        //Check if the 1st length is less than the 2nd
        if(stringLength<string2Length)
        {
            return 0;       //Return 0, as it cant occur
        } else
        {
         
            //For loop from 0 to the difference in length of the 2 strings
            for(counter=0; counter<(stringLength - string2Length + 1); counter++)
            {
                //Loop from 0 to the length of the substring
                for(counter2=0; counter2<string2Length; counter2++)
                {
                    //Checks if the 2 current characters match
                    if(string2[counter2] == string[counter+counter2])
                    {
                        //Increase the letter counter
                        letterOccurence++;
                    }
                }
                //Check if the letter counter equals the length
                if(letterOccurence == string2Length)
                {
                //If it does it means the string has occurred, increment the string counter
                    stringOccurence++;
                }
                letterOccurence = 0;
            }
                //Return the string counter
                return stringOccurence;
        }
    }
/**************************************************************
    Problem: 1032
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/