#include <stdio.h>
int main()
{
    //Declaring variables before use
    int input[10], counter1, counter2, minimum, temp, printcounter;
      
    //read in input for 10 items.
    for(printcounter=0; printcounter<10; printcounter++){
        scanf("%d", (input+printcounter));
    }
      
    //sort for the even numbers only
    for(counter1=0; counter1<9; counter1++){
        //check if its even
        if(input[counter1]%2==0){
        //assign as minimum
        minimum = counter1;
        //loop checks if even and if lower than minimum
            for(counter2 = counter1 + 1; counter2<10; counter2++){
                if(input[counter2] < input[minimum] && (input[minimum]%2==0) && (input[counter2]%2==0)){
                    //assigns the counter to minimum if it is.
                    minimum = counter2;
                }
            }
        //assign to temp    
        temp = input[counter1];
        //minimum to the element which was assigned to temp
        input[counter1] = input[minimum];
        //temp to minimum
        input[minimum] = temp;
        }
    }
      
    //for loop to print out input
    for(printcounter=0; printcounter<10; printcounter++){
        printf("%d ", input[printcounter]);
    }
      
    return 0;
}
/**************************************************************
    Problem: 1060
    User: u4nea
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:976 kb
****************************************************************/