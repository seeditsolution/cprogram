#include<stdio.h>
#include<string.h>
// program to generate a magic square for a odd given input
main()
{
	int n,i,j,r,c;
	printf("Enter the size of magic square: \n");
	scanf("%d",&n);
	int a[n][n];
	memset(a,0,sizeof(a));
	
	if(n%2!=0)
	{
	
		r=n/2;
		c=n-1;
		
		for(i=1;i<=n*n;i++)
		{
		
		
		    if(r==-1 && c==n)
				{
					r=0;
					c=n-2;
				
				 } 
		
		
			else if(r==-1)
			   {
			   		r=n-1;
			   }
			else if(c==n)
				{
				c=0;
			    }
				
			if(a[r][c])
			{
				r=(r+1)%n;
				c=c-2;
				if(c==-1)
					c=n-1;
				else if (c==-2)
				     c=1;	
				a[r][c]=i;
				r--;
				c++;
			}
			else
			{
				a[r][c]=i;
				r--;
				c++;
				}	
				   
			   
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%5d",a[i][j]);
				printf("\n");		
				
				}		
		
	}
	else
	printf("Enter the odd size for magic square \n");
}
