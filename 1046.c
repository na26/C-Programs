#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m,row,column,counter,counter2;
    scanf("%d", &n);
    while(n<1 ||  n>100){
        //printf("Enter a valid number between 1 and 100");
        scanf("%d", &n);
    }
    scanf("%d", &m);
    while(m<1 || m>n){
        //printf("Enter a valid number between 1 and n");
        scanf("%d", &m);
    }
    int **array;
    //int sumArray[3*n*n];
    int *sumArray;
    sumArray = malloc(1*sizeof(int));
    array = malloc(n*sizeof(int*));
    for(counter=0;counter<n;counter++){
        array[counter] = malloc(n*sizeof(int));
    }
     
    for(counter=0;counter<n;counter++){
        for(counter2=0;counter2<n;counter2++){
            scanf("%d", &(array[counter][counter2]));
            while(array[counter][counter2]<0 || array[counter][counter2]>100){
                //printf("Invalid!");
                scanf("%d", &(array[counter][counter2]));
            }
                 
        }
    }
     
    //for(counter=0;counter<3*n*n;counter++){
    //  sumArray[counter] = 0;
    //}
    int sumCounter = 0;
    for(row=0;row<n;row++){
        for(column=0;column<n;column++){
                //if(m==1){
                //  sumArray[sumCounter] = array[row][column];
                //  sumCounter++;
                //  sumArray = realloc(sumArray, (sumCounter+1)*sizeof(int));
                //} else{
                     
                //if(column!=n-1){
                if(n-(column+1) >= m-1){
                    //printf("%d", array[row][column]);
                    //printf("first ");
                 sumArray[sumCounter] = array[row][column];
                 for(counter=1;counter<m;counter++){
                 sumArray[sumCounter] += array[row][column+counter];
                 }
                 sumCounter++;
                 sumArray = realloc(sumArray, (sumCounter+1)*sizeof(int));
                }
                //}
                //if(row!=n-1){
                 if(n-(row+1)>=m-1){
                    //printf("%d", array[row][column]);
                    //printf("second ");
                 sumArray[sumCounter] = array[row][column];
                 for(counter=1;counter<m;counter++){
                 sumArray[sumCounter] += array[row+counter][column];
                 }
                 sumCounter++;
                 sumArray = realloc(sumArray, (sumCounter+1)*sizeof(int));
                 }
                //}
                //if(column!=n-1 && row!=n-1){
                 if(n-(column+1) >= m-1 && n-(row+1)>=m-1){
                    //printf("%d", array[row][column]);
                    //printf("third ");
                 sumArray[sumCounter] = array[row][column];
                 for(counter=1;counter<m;counter++){
                 sumArray[sumCounter] += array[row+counter][column+counter];
                 }
                 sumCounter++;
                 sumArray = realloc(sumArray, (sumCounter+1)*sizeof(int));
                 }
                //}
                //if(row!=n-1){
                 if(column>=m-1 && n-(row+1)>=m-1){
                    // printf("%d", array[row][column]);
                    //printf("fourth ");
                 sumArray[sumCounter] = array[row][column];
                 for(counter=1;counter<m;counter++){
                 sumArray[sumCounter] += array[row+counter][column-counter];
                 }
                 sumCounter++;
                 sumArray = realloc(sumArray, (sumCounter+1)*sizeof(int));
                 }
                //}
            //}
        }
             
        }
        //printf("sum counter is:");
        //printf("%d", sumCounter);
    //if(n==1){
    //  sumArray[0] = array[0][0];
    //}
     
    int highest = 0;
    //if(n==1){
    //  highest = array[0][0];
    //} else{
    for(counter=0;counter<sumCounter;counter++){
        //printf("%d ", sumArray[counter]);
        if(sumArray[counter]>highest){
            highest = sumArray[counter];
        }
    }
    //}
     
    printf("%d", highest);
    //printf("%d", sumCounter+1);
     
     
     
     
     
    return 0;
     
     
     
     
     
     
}
/**************************************************************
    Problem: 1046
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/