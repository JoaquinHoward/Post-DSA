#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int size);
void countingSort(int arr[], int size);

int main(void){
    int arr[8] = {10, 20, 30, 1, 2, 34, 4, 0};
    display(arr, 8);
    countingSort(arr, 8);
    display(arr, 8);
}

void countingSort(int arr[], int size){
    // get the biggest number
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    //create the count or frequency array
    int* count = (int*) calloc (max + 1, sizeof(int));
    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    //count the number of elements before it
    for(int i = 1; i <= max; i++){
        count[i] += count[i-1];
    }
    //building the output array
    int* output = (int*) malloc (sizeof(int) * size);
    for(int i = size - 1; i >= 0; i--){
        // output[--count[arr[i]]] = arr[i];  one liner

        int elem = arr[i];
        int targetIndex = --count[elem];
        output[targetIndex]= elem;
    }

    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
    Step 1) Find the largest value in the original array.
    Step 2) Create a count array with size of the largest value in the original array + 1.
    Step 3) Use the count array to keep track of the frequency of each element. (Use the array like a bit vector array)
    Step 4) Evolve the count array from tracking frequency of elems to tracking the number of elements before it.
    Step 5) Create a sorted array with the same size as the original array.
    Step 6) Place the elements from the original array to the sorted array, use the count array to determine the position of each element.
    Step 7) Transfer the elements in the sorted array to the original array.
*/