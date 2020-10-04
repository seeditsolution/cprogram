#include <stdio.h>
#include <conio.h>

int sqsum (int n)
{
    int r,s=0;
    while(n!=0)
    {
        r=n%10;
        s+=r*r;
        n/=10;
    }
    return s;
}
int psqsum(int n)
{
    int r,s=0;
    while(n!=0)
    {
        r=n%10;
        s+=r*r;
        n/=10;
        printf("%d+",r*r);
    }
    printf("=%d\n",s);
    return s;
}
int main()
{
    int num,sum,ch,n1,n2,i;
    printf("Select the method : 1.Easy 2.Medium 3.Hard\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :
                printf("Enter the number : ");
                scanf("%d",&num);
                sum = num ;
                while(sum>1)
                {
                   sum = sqsum(sum);
                   if (sum == 4)
                       break;

                }
                if (sum==1)
                    printf("%d is Happy number",num);
                if (sum==4)
                    printf("%d is Unhappy number",num );
                break;
        case 2 :
                printf("Enter the range : \n");
                scanf("%d%d",&n1,&n2);
                printf("Happy numbers in the given range are : ");
                for(i=n1;i<=n2;i++)
                {
                    sum = i ;
                    while(sum>1)
                    {
                       sum = sqsum(sum);
                       if (sum == 4)
                           break;

                    }
                    if (sum==1)
                        printf("%d ",i);
                }
                break;
        case 3 :
                printf("Enter the number : ");
                scanf("%d",&num);
                sum = num ;
                while(sum>1)
                {
                   sum = psqsum(sum);
                   if (sum == 4)
                       break;

                }
                if (sum==1)
                    printf("\n%d is Happy number",num);
                if (sum==4)
                    printf("\n%d is Unhappy number",num );
        default :
                printf("Wrong choice!!!..... Please try again");
                break;
    }


    return 0;
}


