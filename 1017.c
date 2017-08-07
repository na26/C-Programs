#include <stdio.h>
#include <stdlib.h>
int main()
{
    //NOTE: To make the problem easier for me, the columns and rows are 
    // flipped once they are input
    //Declaring integer variables to be used below
    int N, highest=0, counter, counter2;
    //Get input of N
    scanf("%d", &N);
    //Create 2 arrays using value N
    int numberOfColumns[N];
    int product[N];
    //Create 2D array
    int **array;
 
    //Get input of first N values
    for(counter=0; counter<N; counter++)
    {
        scanf("%d", &(numberOfColumns[counter]));   
        //Check if greater than current highest
        if((numberOfColumns[counter]) >= highest)
        {
        //If it is assign that value to be the new highest
            highest = numberOfColumns[counter];
        }   
    }
     
    //Allocate memory for rows
    array = malloc(N*sizeof(int*));
    //Allocate memory for number of columns for each row
    for(counter=0;counter<N;counter++)
    {
        array[counter] = malloc(numberOfColumns[counter]*sizeof(int));
    }
     
     
    //Loop to highest value of rows
    for(counter=0;counter<highest;counter++)
    {
        //Loop to number of rows
        for(counter2=0;counter2<N;counter2++)
        {
            //Check if value should be read
            if(counter<numberOfColumns[counter2])
            {
            //Read into array position
            scanf("%d", &(array[counter2][counter]));
            }
        }
    }
     
 
     
    //Loop to number of rows
    for(counter=0;counter<N;counter++)
    {
        //initialise array element
        product[counter] = 1;
        //Loop for number of columns for particular row
        for(counter2=0;counter2<numberOfColumns[counter];counter2++)
        {
            //Multiply to product
            product[counter]=product[counter] * array[counter][counter2];
        }
    }
     
    //Print out product array
    for(counter=0;counter<N;counter++)
    {
            printf("%d ", product[counter]);
    }
     
    //Loop to free memory of each row of array
    for(counter=0;counter<N;counter++)
    {
            free(array[counter]);
    }   
     
    //Freeing memory of array
    free(array);
     
    return 0;
}
/**************************************************************
    Problem: 1017
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/