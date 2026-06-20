#include<stdio.h>

void display(int arr[], int size);
void reset(int arr[]);
void bubble(int arr[], int size);
void selection(int arr[], int size);
void insertion(int arr[], int size);
void gnome(int arr[], int size);

void merge_iterative(int arr[], int size);
void merge_recursive(int arr[], int left, int right);
void combine(int arr[], int left, int mid, int right);

int main(void){
    int arr[8] = {10, 321, 23 ,213 ,213 ,11, 2, 99};
    display(arr, 8);
    bubble(arr, 8);
    display(arr, 8);
    reset(arr);
    display(arr, 8);
    selection(arr, 8);
    display(arr, 8);
    reset(arr);
    display(arr, 8);
    insertion(arr, 8);
    display(arr, 8);
    reset(arr);
    display(arr, 8);
    gnome(arr, 8);
    display(arr, 8);
    reset(arr);
    display(arr, 8);
    merge_iterative(arr, 8);
    display(arr, 8);
    reset(arr);
    display(arr, 8);
    printf("\nMerge recursive: \n");
    merge_recursive(arr, 0, 7);
    display(arr, 8);
    reset(arr);
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reset(int arr[]){
    arr[0] = 10;
    arr[1] = 321;
    arr[2] = 23;
    arr[3] = 213;
    arr[4] = 213;
    arr[5] = 11;
    arr[6] = 2;
    arr[7] = 99;
    printf("\nArray has been reset.\n");
}

void bubble(int arr[], int size){
    printf("\nBubble Sort:\n");
    for(int i = 0; i < size-1; i++){
        for(int j = 0 + 1; j < size-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection(int arr[], int size){
    printf("\nSelection Sort:\n");
    for(int i = 0; i < size-1; i++){
        int minNdx = i;
        int j;
        for(j = i+1; j < size; j++){
            if(arr[j] < arr[minNdx]){
                minNdx = j;
            }
        }
        if(i != minNdx){
            int temp = arr[minNdx];
            arr[minNdx] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertion(int arr[], int size){
    printf("\nInsertion sort:\n");
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void gnome(int arr[], int size){
    printf("\nGnome sort: \n");
    int pos = 0;
    while(pos < size){
        if(pos == 0 || arr[pos] >= arr[pos-1]){
            pos++;
        }else{
            int temp = arr[pos];
            arr[pos] = arr[pos-1];
            arr[pos-1] = temp;
            pos--;
        }
    }
}

void merge_iterative(int arr[], int size){
    printf("\nMerge iterative: \n");
    for(int curr_size = 1; curr_size < size; curr_size = curr_size * 2){
        for(int left_start = 0; left_start + curr_size < size; left_start = left_start + curr_size * 2){
            int mid = left_start + curr_size -1;
            int right = size - 1 < left_start + curr_size * 2 - 1 ? size - 1 : left_start + curr_size * 2 - 1;
            combine(arr, left_start, mid, right);
        }
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
    int k =  left;

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

void merge_recursive(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_recursive(arr, left, mid);
        merge_recursive(arr, mid+1, right);
        combine(arr, left, mid, right);
    }
}