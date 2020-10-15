#include<stdio.h>
#include<conio.h>

void main()
{
int a[55],i,j,n,temp;
clrscr();

printf("Enter the number of elements:\n");
scanf("%d",&n);

for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=1;i<n;i++)
{temp=a[i];
j=i-1;
while(j>=0&&a[j]>temp)
{
a[j+1]=a[j];
j--;
}
a[j+1]=temp;
}
for(i=0;i<n;i++)
printf("\n%d",a[i]);
getch();
}
