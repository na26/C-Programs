#include <stdio.h>
#include <math.h> 
int main()
{
    //Declaring variables for use
    float a=0, b=0, n=0;
    //Reading in input
    scanf("%f %f %f", &a, &b, &n);
 
    //calculate a divided by b
    float output = a/b;
 
    //calculate the nth digit
    int result = output * pow(10, n);
    result = result%10;
     
    //print output
    printf("%d\n", result);
     
    return 0;
 
}
/**************************************************************
    Problem: 1030
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1068 kb
****************************************************************/