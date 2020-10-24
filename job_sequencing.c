//program to solve jobsequencing problem

#include<stdio.h>
#include<conio.h>
void jobseq(int d[],int j[],int n)
{
int k=1,i,r,l;
 d[0]=j[0]=0;
 j[1]=1;

 for(i=2;i<n;i++)
 {
  r=k;
  while(d[j[r]]>d[i] && d[j[r]]!=r)
  {
    r=r-1;
  }
  if(d[j[r]]<=d[i] && d[i]>r)
  {
   for(l=k;l<r+1;l=l-1)
    {
     j[l+1]=j[l];
     j[r+1]=i;
      k=k+1;
    }
  }
 }
  for(i=1;i<=n;i++)
  {
    printf("\n%d",j[i]);
  }
  printf("\n%d",k);
}
void main()
{
 int i,n,j[100],d[100];
 clrscr();
 printf("Enter the size of array");
 scanf("%d",&n);
 printf("\n Enter the jobs and their deadlines");
 for(i=1;i<=n;i++)
 {
  scanf("%d %d",&j[i],&d[i]);
 }
jobseq(d,j,n);

 getch();
}
