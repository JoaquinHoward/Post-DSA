#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void shellSort(int arr[], int size);
void insertionSort(int arr[], int size);

void combSort(int arr[], int size);
void bubbleSort(int arr[], int size);

void countingSort(int arr[], int size);
void selectionSort(int arr[], int size);

void gnomeSort(int arr[], int size);
void mergeSortRecursive(int arr[], int left, int right);
void mergeSortIterative(int arr[], int size);
void combine(int arr[], int left, int mid, int right);
void mergeSortIterativeV2(int arr[], int size);

void display(int arr[], int size);

void strandSort(int arr[], int size);
void radixSort(int arr[], int size);
void bucketSort(int arr[], int size);
void tournamentSort(int arr[], int size);
void quickSort(int arr[], int size);

int main(void){
    int arr[8] = {10, 2, 3, 5, 7, 3, 6, 7};
    display(arr, 8);
    // shellSort(arr, 8);
    // insertionSort(arr, 8);
    // combSort(arr, 8);
    // bubbleSort(arr, 8);
    // countingSort(arr, 8);
    // selectionSort(arr, 8);
    // gnomeSort(arr, 8);
    // mergeSortIterative(arr, 8);
    // mergeSortRecursive(arr, 0, 7);
    mergeSortIterativeV2(arr, 8);
    display(arr, 8);
}

void mergeSortIterativeV2(int arr[], int size){
    for(int curr_size = 1; curr_size < size; curr_size = curr_size * 2){
        for(int left_start = 0; left_start < size; left_start = left_start + curr_size * 2){
            int mid = left_start + curr_size - 1;
            int right_end = size - 1 < left_start + curr_size * 2 - 1 ? size - 1: left_start + curr_size * 2 - 1;
            
            int n1 = mid - left_start + 1;
            int n2 = right_end - mid;

            int L[n1];
            int R[n2];

            for(int i = 0; i < n1; i++){
                L[i] = arr[left_start + i];
            }

            for(int i = 0; i < n2; i++){
                R[i] = arr[mid + 1 + i];
            }

            int i = 0;
            int j = 0;
            int k = left_start;

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
    }
}

void mergeSortRecursive(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        combine(arr, left, mid, right);
    }
}


void mergeSortIterative(int arr[], int size){
    for(int curr_size = 1; curr_size < size; curr_size = curr_size * 2){
        for(int left_start = 0; left_start < size; left_start = left_start + curr_size * 2){
            int mid = left_start + curr_size - 1;
            int right_end = size - 1 < left_start + curr_size * 2 - 1 ? size - 1 : left_start + curr_size * 2 - 1;
            combine(arr, left_start, mid, right_end);
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

void gnomeSort(int arr[], int size){
    int pos = 0;
    while(pos < size){
        if(pos == 0 || arr[pos] <= arr[pos+1]){
            pos++;
        }else{
            int temp = arr[pos];
            arr[pos] = arr[pos+1];
            arr[pos+1] = temp;
            pos--;
        }
    }
}

void selectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int minNdx = i;
        int j;
        for(j = i; j < size - 1; j++){
            if(arr[minNdx] > arr[j]){
                minNdx = j;
            }
        }
        if(minNdx != i){
            int temp = arr[minNdx];
            arr[minNdx] = arr[i];
            arr[i] = temp;
        }
    }
}

void countingSort(int arr[], int size){
    if(size > 1){
        int max = arr[0];
        for(int i = 1; i < size; i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }
        int* count = (int*) calloc (max + 1, sizeof(int));
        if(count != NULL){
            for(int i = 0; i < size; i++){
                count[arr[i]]++;
            }
            for(int i = 1; i <= max; i++){
                count[i] = count[i] + count[i - 1];
            }
            int output[size];
            for(int i = size - 1; i >= 0; i--){
                int elem = arr[i];
                int position = --count[elem];
                output[position] = elem;   
            }
            for(int i = 0; i < size; i++){
                arr[i] = output[i];
            }
        }
        free(count);
    }
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void combSort(int arr[], int size){
    bool sorted = false;
    for(int gap = size / 1.3; gap > 1 || sorted == false; gap = gap / 1.3){
        if(gap < 1){
            gap = 1;
        }
        sorted = true;
        for(int i = 0; i+gap < size; i++){
            if(arr[i] > arr[i + gap]){
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i+gap] = temp;
                sorted = false;
            }
        }
    }
}

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 1 && key < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int size){
    for(int gap = size / 2; gap >=1; gap = gap / 2){
        for(int i = gap; i < size; i++){
            int key = arr[i];
            int j;
            for(j = i; j - gap >= 0 && key < arr[j-gap]; j = j - gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}