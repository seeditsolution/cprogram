#include<stdio.h>
int main()
{
 int matrix[100][100];
 int m,n,i,j;
 printf("Enter row and columns of matrix: ");
 scanf("%d%d",&m,&n);
 
 /* Enter m*n array elements */
 printf("Enter matrix elements: \n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&matrix[i][j]);
  }
 }
 
 /* matrix after the 90 degrees rotation */
 printf("Matrix after 90 degrees roration \n");
 for(i=0;i<n;i++)
 {
  for(j=m-1;j>=0;j--)
  {
   printf("%d  ",matrix[j][i]);
  }
  printf("\n");
 }
 
 return 0;
 
}
