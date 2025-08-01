#include <stdio.h>
#include <stdlib.h> // for rand() and srand()

//Function to perform linear search 
int main() {
    int A[500];
    int i, key, found = 0;

    //Fill array with random numbers
    for(i = 0; i < 500; i++){
        A[i] = rand()% 1000; //Random numbers from 0 to 999
        printf(A[i]);


    }
    printf("Enter the number to search:");
    scanf("%d",&key);


    //Linear search
    for(i = 0; i < 500; i++){
        if(A[i] == key){
            printf("Element found at index %d|n", i);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Element not found in the array.\n");
    }

    return 0;
}
