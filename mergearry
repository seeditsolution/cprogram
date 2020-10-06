#include<stdio.h>
 
int main() {
 int arr1[30], arr2[30], res[60];
 int i, j, k, n1, n2;
 
 printf("\nEnter no of elements in 1st array :");
 scanf("%d", &n1);
 for (i = 0; i < n1; i++) {
 scanf("%d", &arr1[i]);
 }
 
 printf("\nEnter no of elements in 2nd array :");
 scanf("%d", &n2);
 for (i = 0; i < n2; i++) {
 scanf("%d", &arr2[i]);
 }
 
 i = 0;
 j = 0;
 k = 0;
 
 // Merging starts
 while (i < n1 && j < n2) {
 if (arr1[i] <= arr2[j]) {
 res[k] = arr1[i];
 i++;
 k++;
 } else {
 res[k] = arr2[j];
 k++;
 j++;
 }
 }
 
 /* Some elements in array 'arr1' are still remaining
 where as the array 'arr2' is exhausted */
 
 while (i < n1) {
 res[k] = arr1[i];
 i++;
 k++;
 }
 
 /* Some elements in array 'arr2' are still remaining
 where as the array 'arr1' is exhausted */
 
 while (j < n2) {
 res[k] = arr2[j];
 k++;
 j++;
 }
 
 //Displaying elements of array 'res'
 printf("\nMerged array is :");
 for (i = 0; i < n1 + n2; i++)
 printf("%d ", res[i]);
 
 return (0);
 
}
