#include <stdio.h>
int main()
{
    //Declaring variables before use
    int int1, int2, multiple, factor=1, i, j, counter1=0, counter2=0;
    //Reading in input
    scanf("%d %d", &int1, &int2);
      
    //Assigning highest and lowest
    if(int1>int2){
        i=int1; //if first integer is higher
        j=int2;
    }       else{   //if first integer is lower
                i=int2;
                j=int1;
    }
      
    //for loop to find highest common factor
    for(counter1 = i; counter1>=1; counter1--){
        //check if the current counter divides into both
        if(int1%counter1==0 && int2%counter1==0){
            factor = counter1;  //becomes highest common factor
            break;  //break out of loop
        }
    }
      
    //for loop to find lowest common multiple
    for(counter2 =j; counter2<=int1*int2; counter2++){
        //check if the 2 inputs divided into the current counter
        if(counter2%int1==0 && counter2%int2==0){
            multiple = counter2;    //becomes the lowest common multiple
            break;      //breaks out of loop
        }
    }
      
    //print out the results
    printf("%d", factor);
    printf(" %d\n", multiple);
      
    return 0;
      
}
/**************************************************************
    Problem: 1025
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/