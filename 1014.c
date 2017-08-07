#include <stdio.h>
   
//declaring global variable and methods
float area(int a);
float circumference(int a);
#define PI 3.14 //declare pi as constant as it will not change
int main()
{
    //declaring variables for use
    int r1 =0, r2=0, i;
    float sumofareas, sumofcircumferences;
    //read in input
    scanf("%d %d", &r1, &r2);
       
    //for loop to calculate each circles area and circumference
    for(i=r1; i<=r2; i++){
        //add to sum of areas by calling method
        sumofareas = sumofareas + area(i);
        //add to sum of areas by calling method
        sumofcircumferences = sumofcircumferences + circumference(i);
    }
       
    //print output to 3dp
    printf("%.3f\n", sumofareas);
    printf("%.3f\n", sumofcircumferences);
       
    return 0;
}
   
    //method to calculate area
    float area(int a){
            return PI*(a*a);
        }
    //method to calculate circumference
        float circumference(int a){
            return 2 * PI * a;
        }
/**************************************************************
    Problem: 1014
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/