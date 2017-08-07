#include <stdio.h>
#include <stdlib.h>
int main()
{
    //Declaring variables of integer type including the matrices
    int n,m,p,i,**matrix1, **matrix2, **matrix3, counter, counter2, counter3, counter4, counter5;
    //Getting input of 3 numbers
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);
 
     
    //Allocating memory using the inputted rows and columns to the first matrix
    matrix1 = malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        matrix1[i] = malloc(m*sizeof(int));
    }   
    //Allocating memory using the inputted rows and columns to the second matrix
    matrix2 = malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        matrix2[i] = malloc(p*sizeof(int));
    } 
     
    //Allocating memory using the inputted rows and columns to the third matrix
    matrix3 = malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        matrix3[i] = malloc(p*sizeof(int));
    }
     
    //Nested for loop to accept input of the first matrix
    for(counter=0; counter<n; counter++)
    {
        for(counter2=0; counter2<m; counter2++)
        {
            scanf("%d", &(matrix1[counter][counter2]));
        }
    }
     
    //Nested for loop to accept input of the second matrix
    for(counter=0; counter<m; counter++)
    {
        for(counter2=0; counter2<p; counter2++)
        {
            scanf("%d", &(matrix2[counter][counter2]));
        }
    }   
             
    //3 Nested loops to calculate the product matrix and assign to the third matrix
    //Loop from 0 to number of rows
    for(counter3=0; counter3<n; counter3++)
    {
        //Loop from 0 to number of colums
        for(counter4=0; counter4<p; counter4++)
        {
            for(counter5=0;counter5<m; counter5++)
            {
            //Add to the current total, the 2 array elements multiplied
            matrix3[counter3][counter4] += matrix1[counter3][counter5] * matrix2[counter5][counter4];
            }
        }   
    }           
         
    //Nested loop to print out the product matrix
    for(counter3=0; counter3<n; counter3++)
    {
        for(counter4=0; counter4<p; counter4++)
        {
            if(counter4 == p-1)
            {
                printf("%d", matrix3[counter3][counter4]);
            } else
            {
            printf("%d ", matrix3[counter3][counter4]);
            }
        }
        printf("%s\n", "");
    }
    //Freeing the matrices memory
    for(counter=0;counter<n;counter++)
    {
        free(matrix1[counter]);
    }
    free(matrix1);
     
    //Freeing the matrices memory
    for(counter=0;counter<m;counter++)
    {
        free(matrix2[counter]);
    }
    free(matrix2);
     
    //Freeing the matrices memory
    for(counter=0;counter<n;counter++)
    {
        free(matrix3[counter]);
    }
    free(matrix3);
     
    return 0;
 
 
}
/**************************************************************
    Problem: 1041
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:980 kb
****************************************************************/