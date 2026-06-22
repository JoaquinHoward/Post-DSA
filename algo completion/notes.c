#include<stdio.h>
#include<stdlib.h>

void countingSort(int arr[], int size);
void display(int arr[], int size);

int main(void){
    int arr[8] = {1, 23, 2, 3, 12, 0, 2, 3};
    display(arr, 8);
    countingSort(arr, 8);
    display(arr, 8);
}

void countingSort(int arr[], int size){
    //Step 1: Find the largest number in the original array
    if(size > 1){
        int max = arr[0];
        for(int i = 1; i < size; i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }
        //Step 2: Create the bit-vector-like array and keep track of elements' frequency
        int* count = (int*) calloc (max + 1, sizeof(int));
        if(count != NULL){
            for(int i = 0; i < size; i++){
                count[arr[i]]++;
            }
        }
        //Step 3: Evolve from elem frequency to counting the number of elements before it
        for(int i = 1; i <= max; i++){
            count[i] = count[i] + count[i-1];
        }
        //Step 4: Create the sorted/output array to store the elements
        int* sorted = (int*) malloc (sizeof(int) * size);
        if(sorted != NULL){
            for(int i = size - 1; i >= 0; i--){
                int elem = arr[i];
                int position = --count[elem];
                sorted[position] = elem;
            }
            
            //Step 5: Transfer to the original array
            
            for(int i = 0; i < size; i++){
                arr[i] = sorted[i];
            }
        }
        free(sorted);
        free(count);
    }
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
