
#include<stdio.h>

int main(){
    int arr[100];
    int size , n;
    printf("\n Enter the size of array \n");
    scanf("%d",&size);
    printf("\n Enter the elements of array \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for(int j=i+1; j<size; j++){
            if (arr[i]>arr[j])
            {
                n = arr[i];
                arr[i] = arr[j];
                arr[j] = n;
            }
            
        }
    }
    printf("\n The numbers arranged in ascending order is \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
    
    
    return 0;
}
