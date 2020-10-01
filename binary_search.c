#include<stdio.h>
#define size 10
int binary_search(int x[], int n, int key)
{
	int beg, end, mid;
	beg = 0;
	end = n-1;
	while(beg <= end)
	{
		mid = (beg + end) / 2;
		if(key == x[mid])
			return mid;
		else if(key < x[mid])
			end = mid - 1;
		else
			beg = mid + 1;
	}
	return -1;
}

int main()
{
	int key, i, flag, n;
	int a[size];
	printf("Please enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Please enter the elements\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	printf("Please enter the element to be searched\n");
	scanf("%d",&key);
	
	flag = binary_search(a, n, key);
	if(flag == -1)
		printf("\nThe element is not present");
	else
		printf("\nThe element is at %d location",flag+1);
	return 0;
}
