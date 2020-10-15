#include<stdio.h>

int quickSort(int *arr, int start, int end){
    if(start>=end) return -1;
    int index = partition(arr, start, end);
    quickSort(arr, start, index-1);
    quickSort(arr, index+1, end);
}
int partition(int *arr, int start, int end){
    int pivotIndex = start;
    int pivotValue = arr[end];
    for(int i=start; i<end; i++){
        if(arr[i]<pivotValue){
            swap(arr, i, pivotIndex);
            pivotIndex++;
        }
    }
    swap(arr, end, pivotIndex);
    return pivotIndex;
}
void swap(int *arr, int a, int b){ 
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void main(){
    int arr[10] = {10, 1, 12, 13, 4, 6, 9, 11, 20, 21};
    quickSort(arr, 0, 9);
    printArray(arr, 10);
}
