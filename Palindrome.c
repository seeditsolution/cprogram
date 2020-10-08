#include<stdio.h>
void main()
{
    int n,rev=0,rem,p;
    printf("Enter a number:");
    scanf("%d",&n);
    p=n;
    while(n!=0)
    {
        rem=n%10;
        rev=(rev*10)+rem;
        n=n/10;
    }
    if(rev==p)
    {
        printf("The given number %d is palindrome",p);
    }
    else
    {
        printf("The given number %d is not palindrome",p);
    }
}
