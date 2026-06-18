#include<stdio.h>
// #include<stdlib.h>
void display(int arr[], int size);
void merge(int arr[], int left, int mid, int right);
void merge_sort_recursion(int arr[], int left, int right);
void merge_sort_iterative(int arr[], int size);

int main(void){
    int arr[8] = {0, 7, 4, 0, 4, 1, 4, 8};
    display(arr, 8);
    merge_sort_recursion(arr, 0, 7);
    display(arr, 8);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right){
    //process: create temporary arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + 1 + i];
    }
    //merge the temporary arrays into the original array
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    };
    //copy remaining elements into the array
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void merge_sort_recursion(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        //divide the array into 2 parts recursively
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        //combine the arrays
        merge(arr, left, mid, right);
    }
}

void merge_sort_iterative(int arr, int size){
    
}