#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0         //Defining constants
#define MAX_SIZE 10000
#define MIN_SIZE 2
 
//Declare method for search - params 2 integers(cities)
void search(int startCity, int goalCity);
//Declare integers
int cityCounter=0, finished=0, exists =0, numCities, finish;
//Declare 1D array to track visited cities
int *visitedArray;
//Declare 1D array for each city which shows if all possibilities are checked.
int *emptyRowArray;
//Declare 2D array to accept input of connections
int **cityArray;
 
int main()
{
    //Declare integers
    int numConnections, first=0, second=0, counter, column, row, start;
 
    //Read in number of cities whilst checking validity
    scanf("%d", &numCities);
    while(numCities<MIN_SIZE || numCities>MAX_SIZE)
    {
        scanf("%d", &numCities);
    }
     
    //Read in number of connections whilst checking validity
    scanf("%d", &numConnections);
    while(numConnections<MIN_SIZE || numConnections>MAX_SIZE)
    {
    scanf("%d", &numConnections);
    }
     
    //Allocate memory for the visited array and row check array
    visitedArray = malloc(numCities*sizeof(int));
    emptyRowArray = malloc(numCities*sizeof(int));
    //Instantiate all elements to 0
    for(counter=0;counter<numCities;counter++)
    {
        visitedArray[counter] =0;
        emptyRowArray[counter] =0;
    }
     
    //Allocate memory for number of rows, to be number of cities -1
    cityArray = malloc((numCities-1)*sizeof(int*));
    //Each row has a different number of columns - memory is allocated
    //This array doesnt store more than needed
    for(row=0; row<(numCities-1);row++)
    {
        cityArray[row] = malloc(((numCities -1) - row) * sizeof(int));  
    }
     
    //Initialising all array elements to 0
    for(row=0;row<(numCities-1);row++)
    {
        for(column=0; column<((numCities -1) - row);column++)
        {
            cityArray[row][column] = FALSE;
        }
    }
     
     
    //For loop to read in the conncetions
    for(counter=0;counter<numConnections;counter++)
    {
        scanf("%d", &first);
        scanf("%d", &second);
        //Check if the first city is greater, to get the correct array element
        if(first>second)
        {
        //Assign the element as having a connection (true)
        cityArray[second-1][numCities-first] = TRUE;    
        } 
        //Check if the second city is greater, to get the correct array element
        else
        {
            //Assign the element as having a connection (true)
            cityArray[first -1][numCities-second] = TRUE;
        }
         
    }
     
    //Read in the search cities
    scanf("%d %d", &start, &finish);
     
    //Call the search function using the search elements as paramaters
    search(start, finish);
    //Check if a path exists
    if(exists==TRUE)
    {
        //Output yes
        printf("Yes");
    } else
    {
        //Otherwise output no, as there is no path
        printf("No");
    }
     
    //Freeing the array holding connections
    for(row=0; row<(numCities-1);row++)
    {
        free(cityArray[row]);   
    }
    //Freeing the 2 1D arrays
    free(visitedArray);
    free(emptyRowArray);
     
    return 0;
         
}
 
//Search method
void search(int startCity, int goalCity)
{
    int counter, counter2;
    //While loop, whilst the search hasnt finished and a path hasnt been found
    while(finished==FALSE && exists==FALSE)
    {
        //Assign the current city as visited
        visitedArray[startCity-1] = TRUE;
                //If statement checks if at the current city, there is a connection to the finish city
                if(finish!=1 && ((numCities-finish)<(numCities-startCity)))
                {
                    if(cityArray[startCity-1][numCities-finish] ==TRUE)
                    {
                        //If there is stop the search and change exists to true
                        exists = TRUE;
                        finished =TRUE;
                        break;
                    }
                    //If statement checks if at the current city, there is a connection to the finish city
                } 
                else if(finish!=numCities &&(finish<(startCity-1)))
                {
                    if(cityArray[finish-1][numCities-startCity])
                    {
                        //If there is stop the search and change exists to true
                        exists = TRUE;
                        finished =TRUE;
                        break;
                    }
                }
                 
                if(startCity!=numCities)
                {       
                    //For each column of the current city
                    for(counter=0; counter<((numCities -1) - (startCity-1)); counter++)
                    {
                        //Check if there is a connection at city determined by the counter
                        if(cityArray[startCity-1][counter] == TRUE && visitedArray[numCities-counter-1] ==FALSE)
                        {
                            //If there is then call the search function with that city as the start
                            search((numCities-counter), goalCity);
                            //Increase the counter for this city, it shows it has been searched
                            emptyRowArray[startCity-1]++;
                        }
                    }
                }   
                //For each row of the current city
                if(startCity!=1)
                {
                    for(counter2=0;counter2<(startCity-1);counter2++)
                    {
                        //Check if there is a connection at city determined by the counter
                        if (cityArray[counter2][numCities-startCity] == TRUE &&visitedArray[counter2] ==FALSE)
                        {
                            //If there is then call the search function with that city as the start
                            search((counter2+1), goalCity);
                            //Increase the counter for this city, it shows it has been searched
                            emptyRowArray[startCity-1]++;
                        }
                     }
                }
                 
                //Check if for a city, if there were no connections at all for that city 
                if(emptyRowArray[startCity-1]==FALSE)
                {
                    //Then there is no path and the search is finished
                    finished=TRUE;
                    break;
                } 
                else
                {
                    //Counts how many cities have been searched
                    cityCounter++;
                     
                    //If all cities have been searched
                    if(cityCounter==numCities)
                    {
                        //Then end the search
                        finished = TRUE;
                        break;
                    }
                }
             
     
    }
}
/**************************************************************
    Problem: 1050
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:980 kb
****************************************************************/