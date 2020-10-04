#include <stdio.h>
#include <stdlib.h>
int merge_two_sorted_arrays(int arr1[], int arr2[], int arr3[], int m, int n)
{
int i,j,k;
i = j = k = 0;
for(i=0;i < m && j < n;)
{
if(arr1[i] < arr2[j])
{
arr3[k] = arr1[i];
k++;
i++;
}
else
{
arr3[k] = arr2[j];
k++;
j++;
}
}
while(i < m)
{
arr3[k] = arr1[i];
k++;
i++;
}
while(j < n)
{
arr3[k] = arr2[j];
k++;
j++;
}
}
int main()
{
int n,m;
printf("\nEnter the size of Array 1 : ");
scanf("%d",&m);
printf("\nEnter the size of Array 2 : ");
scanf("%d",&n);
int arr1[m],arr2[n];
int arr3[m+n];
int i;
printf("\nInput the Array 1 elements : ");
for(i = 0; i < m; i++)
{
scanf("%d",&arr1[i]);
}
printf("\nInput the Array 2 elements : ");
for(i = 0;i<n;i++)
{
scanf("%d",&arr2[i]);
}
merge_two_sorted_arrays(arr1,arr2,arr3,m,n);
printf("\nThe Merged Sorted Array : ");
for(i = 0; i < n + m; i++)
{
printf("%d ",arr3[i]);
}
printf("\n");
return 0;
}
