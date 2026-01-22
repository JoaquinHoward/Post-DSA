void insertionSort(int a[], int s){
    for(int i=1; i<s; i++){
        int elem = a[i];
        int j = i-1;
        while(j>=0 && elem < a[j]){
            a[j+1] = a[j];
            j = j - 1
        }
        a[j+1] = elem;
    }
}