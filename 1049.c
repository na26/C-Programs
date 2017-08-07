#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_MAX 19999
#define NUM_MIN 10000
#define PRIORITY_MAX 10 //defining constants
#define PRIORITY_MIN 1
 
//Declare struct for node
typedef struct node
{
    //Declare all variables for that struct
    int number;
    int priority;
    struct node *next;
}node;
 
//Declare the 2 methods
void insert(int numInput, int inputPriority);
void pop();
 
//Create the front node of the queue and set it to null
node *front = NULL;
 
int main()
{
    //Declare variables for the input
    char input[100];
    int numberInput;
    int priorityInput;
     
    //Accept input whilst it isn't the end of file
    while (scanf("%s", &input) != EOF)
    {
        //Check if the input equals 'Insert;
        if(strcmp(input,"Insert") ==0)
        {
            //Read in the number input whilst checking its validity
            scanf("%d", &numberInput);
            while(numberInput<NUM_MIN  || numberInput>NUM_MAX)
            {
            scanf("%d", &numberInput);
            }
            //Read in the priority input whilst checking its validity
            scanf("%d", &priorityInput);
            while(priorityInput<PRIORITY_MIN  || priorityInput>PRIORITY_MAX)
            {
            scanf("%d", &priorityInput);
            }
             
            //Call insert function
            insert(numberInput, priorityInput);
             
            //Check if the input equals 'Pop'
        } 
        else if(strcmp(input,"Pop") ==0)
        {
            //Call pop function
            pop();
             
        }
         
         
    }   
     
}
 
//Insert method - takes the number and priority input as params
void insert(int numInput, int inputPriority)
{
    //Create temporary nodes
    node *temp, *temp2;
     
    //Allocate memory to the temporary node
    temp = malloc(sizeof(node));
    //Assign the paramaters to correspoding variables of the node
    temp->number = numInput;
    temp->priority = inputPriority;
     
    //Check if the queue is empty or the priority of the new node is greater than the front node
    if(front==NULL || inputPriority > front->priority )
    {
        //Assign the front to the temp's next
        temp->next = front;
        //Make the temp node the front
        front = temp;
    } 
    else
    {
        //Assign the front to a temporary node
        temp2 = front;
         
        //Perform whilst the temp2's next isnt empty and the input priority is less or equal to it
        while(temp2->next !=NULL && inputPriority<=temp2->next->priority)
        {
            //Move it to the next node
            temp2 = temp2->next;     
        }
             
        //Assign temp2's next to the new nodes next
        temp->next = temp2->next;
        //Assign the new node to the current nodes next
        temp2->next = temp;
    }
                     
         
}
 
//Pop function
void pop()
{
    //Create a temporary node
    node *temp;
     
    //Check if the queue is empty
    if(front==NULL)
    {
        //Print out -1
        printf("%d\n", -1);
         
    } 
    else
    {
        //Assign the front of the queue to the temp
        temp = front;
        //Make the 2nd in queue to the front
        front = front->next;
         
        //Print out the value which has been popped
        printf("%d\n", temp->number);
         
        //Free the node which has been popped
        free(temp);
         
    }
}
 
/**************************************************************
    Problem: 1049
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/