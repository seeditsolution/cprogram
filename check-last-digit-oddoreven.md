#include<stdio.h>
#include<conio.h>
void main()
{
int n,a;
clrscr();
printf("enter any number");
scanf("%d",&n);
a=n%10;
if(a%2==0)
{
printf("last digit is even");
}
else
{
printf("lasat digit is odd");
}
getch();
}
