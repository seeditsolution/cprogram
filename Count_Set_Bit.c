#include<stdio.h>
int set_bit_fast(int n)
{
    int ans=0;
    while(n>0)
    {
        n=n&(n-1);
        //removing every set bit from right to left
        ans++;
    }
    return ans;
}
int main()
{
	//c program to calculate the number of set bits in number
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	int ans=set_bit_fast(n);
    printf("%d\n",ans);
 
	return 0;
}
