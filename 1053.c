#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//Declare struct for node
typedef struct node
{
    //Declare variables for struct
    int number;
    struct node *next;
}node;
 
 
//Declare methods
void push(int data);
void pop();
 
//Create top node and make it null
node *top = NULL;
int main()
{
    //Declare variables for the input
    char input[100];
    int number;
     
     
    //Accept input whilst it hasn't reached end of file
    while (scanf("%s", input) != EOF)
    {
        //Check if input is equal to 'Push'
        if(strcmp(input, "Push") ==0)
        {
            //Scan number
            scanf("%d", &number);
            //Call push function
            push(number);
             
            //Check if input is equal to 'Pop'
        } 
        else if(strcmp(input, "Pop") ==0)
        {
            //Check if first node is empty
            if(top == NULL)
            {
                //Print out -1
                printf("%d", -1);
                printf(" %s\n", "popped");
 
            } 
            else
            {
                //Call pop function
                pop();
                 
            }
             
        }
    }
 
    return 0;
 
}
 
//Push function
void push(int data){
    //Create temporary node
    node *temp;
    //Check if first node is empty
     
    if(top == NULL)
    {
        //Allocate memory for that node
        top = malloc(1*sizeof(node));
        //Assign its next to null
        top->next = NULL;
        //Assign data to the nodes variable
        top->number = data;
    } 
    else
    {
        //Allocate memory for that node
        temp = malloc(1*sizeof(node));
        //Assign the top node to the temp's next node
        temp->next = top;
        //Assign data to the nodes variavle
        temp->number = data;
        //Make the temp node, the first node
        top = temp;
    }
     
    //Output the number which has been pushed
    printf("%d ", data);
    printf("%s\n", "pushed");
 
}
 
//Pop function
void pop()
{
    //Create a temporary node.
    node *temp2;
    //Assign the top node to this temp.
    temp2 = top;
    //Make the next node after top, the top.
    top = top->next;
 
    //Output the number which has been popped.
    printf("%d ", temp2->number);
    printf("%s\n", "popped");
     
    //Free the memory for the popped node.
    free(temp2);
     
}
/**************************************************************
    Problem: 1053
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/