#include<stdio.h>

void display(int arr[], int size);
void merge_sort_recursive(int arr[], int left, int right);
void combine(int arr[], int left, int mid, int right);
void merge_sort_iterative(int arr[], int size);

int main(void){
    int arr[8] = {10, 20, 23, 3, 4, 2, 34, -3};
    display(arr, 8);
    merge_sort_iterative(arr, 8);
    display(arr, 8);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge_sort_recursive(int arr[], int left, int right){
    //check if the array is still dividable
    if(left < right){
        //find the middle index
        int mid = (left + right) / 2;
        //divide the array into two parts
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        //combine the arrays;
        combine(arr, left, mid, right);
    }
}

void combine(int arr[], int left, int mid, int right){
    //create the temporary arrays by first finding the sizes for the left and right arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    //put the values into the temp left and temp right 

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + 1 + i];
    }

    //combine 

    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++]; 
        }else{
            arr[k++] = R[j++];
        }
    }
    //copy remaining elements
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void merge_sort_iterative(int arr[], int size){
    //size tracker which doubles each round
    for(int curr_size = 1; curr_size < size; curr_size*=2){
        //move from left to right in the array
        for(int left_start = 0; left_start + curr_size< size; left_start += curr_size * 2){
            int mid = left_start + curr_size -1; // last index of the left chunk
            int right_end = size - 1 < curr_size*2 + left_start -1 ? size-1 : 2*curr_size + left_start - 1;

            combine(arr, left_start, mid, right_end);

        }
    }
}