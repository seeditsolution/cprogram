#include<stdio.h>
#include<conio.h>
void main()
{
    int p,n,r,si;
    clrscr();
    printf("Enter Principle, Rate of interest & Time :");
    scanf("%d%d%d",&p,&r,&n);
    si=(p*r*n)/100;
    printf("Simple Interest is :%d",si);
    getch();
}
