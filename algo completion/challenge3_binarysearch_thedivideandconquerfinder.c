#include<stdio.h>
void display(int arr[], int size);
int binarySearch(int arr[], int size, int target);

int main(void){
    int arr[6] = {1, 3, 5, 7, 9, 11};
    display(arr, 6);
    printf("%d\n", binarySearch(arr, 6, 11));
    printf("%d\n", binarySearch(arr, 6, 100));
}

void display(int arr[], int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int target){
    int lowerNdx = 0;
    int upperNdx = size - 1;
    int midNdx = size / 2;
    while(lowerNdx <= upperNdx && arr[midNdx] != target){
        if(arr[midNdx] < target){
            lowerNdx = midNdx + 1;
        }else if(arr[midNdx] > target){
            upperNdx = midNdx - 1;
        }
        midNdx = (lowerNdx + upperNdx) / 2;
    }
    return lowerNdx <= upperNdx ? midNdx : -1;
}