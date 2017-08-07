#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GREATER_THAN -1     //Defining constants
#define LESS_THAN 1
#define EQUAL_TO 0
//Declare compare function
typedef int (*compfn)(const void*, const void*);
 
//Declare struct for a date
typedef struct date
{
    //Declare variables for day, month, year for the struct
    char month[100];
    int monthNum;
    int day;
    int year;
    int yearTemp;
}date;
 
//Compare function to sort dates
int compare(date *date1,  date *date2)
{
       //Check if the year of the first is greater than the second
       if(date1->year>date2->year)
       {
           return GREATER_THAN;
       }
       //Check if the year of the first is less than the second
       else if(date1 ->year<date2->year)
       {
           return LESS_THAN;
       } 
        
       //Check if the month of the first is greater than the second
       if(date1->monthNum >date2->monthNum)
       {
           return GREATER_THAN;
       }
       //Check if the month of the first is less than the second
       else if(date1->monthNum <date2->monthNum)
       {
           return LESS_THAN;
       }
        
       //Check if the day of the first is greater than the second
       if(date1->day > date2->day)
       {
           return GREATER_THAN;
       }
       //Check if the day of the first is less than the second
       else if(date1->day < date2->day)
       {
           return LESS_THAN;
       } 
       //In this case the 2 dates are equal
       else
       {
           return EQUAL_TO;
       }
    
}
 
 
 
int main()
{
        //Declare integer variables
        int numOfDates,counter;
        //Declare a struct for the search item
        date *dateSearch;
        //Read in number of dates to fllow
        scanf("%d", &numOfDates);
        //Check validity
        while(numOfDates<1||numOfDates>10000)
        {
            scanf("%d", &numOfDates);
        }
         
        //Declare array of dates
        date *dates;
        dateSearch = malloc(1* sizeof( date));
         
        //Allocate memory for the array of dates
        dates = malloc(numOfDates * sizeof( date));
         
        //For loop for number of dates to be read in
        for(counter=0;counter<numOfDates;counter++)
        {
                //Read in month, day and year
                scanf("%s", dates[counter].month);
                scanf("%d", &dates[counter].day);
                scanf("%d", &dates[counter].yearTemp);
        }
             
        //Read in day, month and year for the search date
        scanf("%d", &dateSearch[0].day);
        scanf("%d", &dateSearch[0].monthNum);
        scanf("%d", &dateSearch[0].yearTemp);
             
        //For the search date
        //If statements to convert the 2 digit year to a 4 digit year
        //If the value is 90-99
        if(dateSearch[0].yearTemp >=90 && dateSearch[0].yearTemp <=99)
        {
            dateSearch[0].year = 1900 + dateSearch[0].yearTemp;
        }
        //If the values is 0-12
        else if(dateSearch[0].yearTemp >=0 && dateSearch[0].yearTemp <=12)
        {
            dateSearch[0].year = 2000 + dateSearch[0].yearTemp;
        }
         
         
        //For loop for each date in the array
        for(counter=0;counter<numOfDates;counter++)
        {
            //If statements to convert 2 digit year to 4 digits
            if(dates[counter].yearTemp >=90 && dates[counter].yearTemp <=99)
            {
                dates[counter].year = 1900 + dates[counter].yearTemp;
            } 
            else if(dates[counter].yearTemp >=0 && dates[counter].yearTemp <=12)
            {
                dates[counter].year = 2000 + dates[counter].yearTemp;
            }
             
            //Set of if statements to assign a number for each month
            if(strcmp(dates[counter].month, "January") == EQUAL_TO)
            {
                dates[counter].monthNum = 1;
            }
            else if(strcmp(dates[counter].month, "February") == EQUAL_TO)
            {
                dates[counter].monthNum = 2;
            }
            else if(strcmp(dates[counter].month, "March") == EQUAL_TO)
            {
                dates[counter].monthNum = 3;
            }
            else if(strcmp(dates[counter].month, "April") == EQUAL_TO)
            {
                dates[counter].monthNum = 4;
            }
            else if(strcmp(dates[counter].month, "May") == EQUAL_TO)
            {
                dates[counter].monthNum = 5;
            }
            else if(strcmp(dates[counter].month, "June") == EQUAL_TO)
            {
                dates[counter].monthNum = 6;
            }
            else if(strcmp(dates[counter].month, "July") == EQUAL_TO)
            {
                dates[counter].monthNum = 7;
            }
            else if(strcmp(dates[counter].month, "August") == EQUAL_TO)
            {
                dates[counter].monthNum = 8;
            }
            else if(strcmp(dates[counter].month, "September") == EQUAL_TO)
            {
                dates[counter].monthNum = 9;
            }
            else if(strcmp(dates[counter].month, "October") == EQUAL_TO)
            {
                dates[counter].monthNum = 10;
            }
            else if(strcmp(dates[counter].month, "November") == EQUAL_TO)
            {
                dates[counter].monthNum = 11;
            }
            else if(strcmp(dates[counter].month, "December") == EQUAL_TO)
            {
                dates[counter].monthNum = 12;
            }
        }
         
         
         
        //Call the quicksort on the array of dates, using the compare function
        qsort(dates, numOfDates, sizeof( date), (compfn)compare);
        int item;
        //For loop to print out the sorted array of dates
        for(item=0;item<numOfDates;item++)
        {
            printf("%s ", dates[item].month);
            printf("%d ", dates[item].day);
            //Seperate check and if statement to output with correct format
            if(dates[item].yearTemp >=0 && dates[item].yearTemp <=9)
            {
                printf("0%d\n", dates[item].yearTemp);
            } 
            else
            {
            printf("%d\n", dates[item].yearTemp);
            }
        }
         
        //Struct date for the bsearch to use
         date *searchDate;
        //Call the bsearch using the search item, array of dates and the compare function
        searchDate = (date*) bsearch(dateSearch, dates, numOfDates, sizeof(date), (compfn)compare);
         
        //Check if it has been found
        if(searchDate !=NULL)
        {
            //Ouput yes
            printf("Yes");
        }
        else
        {
            //Otherwise it hasn't been found and output no.
            printf("No");
        }
         
        //Free the array of dates
        free(dates);
        //Free search date
        free(dateSearch);
         
        return 0;
 
}
/**************************************************************
    Problem: 1048
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:980 kb
****************************************************************/