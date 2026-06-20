#include<stdio.h>

void merge_sort_recursive(int arr[], int left, int right);
void merge_sort_iterative(int arr[], int size);
void combine(int arr[], int left, int mid, int right);
void display(int arr[], int size);

int main(void){
    int arr[8] = {10, 20, 11, 23, 32, 321, 1, 3};
    display(arr, 8);
    // merge_sort_recursive(arr, 0, 7);
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
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        combine(arr, left, mid, right);
    }
}

void combine(int arr[], int left, int mid, int right){
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

    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void merge_sort_iterative(int arr[], int size){
    for(int curr_size = 1; curr_size < size; curr_size = curr_size * 2){
        for(int left_start = 0 ; curr_size + left_start < size; left_start = left_start + curr_size * 2){
            int mid = left_start + curr_size -1;
            int right = (size-1 < left_start + curr_size * 2 - 1) ? (size-1) : (left_start + curr_size * 2 - 1);
            combine(arr, left_start, mid, right);
        }
    }
}


