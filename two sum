#include <stdio.h>
#include <stdlib.h>

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	/*
	A better way of doing it is to use hash table
	loop through the list and see if it's complement is in the hash
	has to find a C compatible one
	 */

    int *result = (int *)malloc(sizeof(int) * 2);
    int i, j;
    int a, b;
    // looping twice will not be efficient
    for (i=0; i<numsSize; ++i) {
    	a = nums[i];
    	for (j=i+1; j<numsSize; ++j) {
    		b = nums[j];

    		printf("a:%d\n", a);
    		printf("b:%d\n", b);

    		if ((a + b) == target) {
    			result[0] = i;
    			result[1] = j;
    			return result;
    		}
    	}
    }
    return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	int nums[] = {3, 2, 4};

	int *data = twoSum(nums, 3, 6);

	printf("First: %d, second: %d\n", data[0], data[1]);

	free(data);
	return 0;
}
