//Given an array, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

void moveZeroes(int* nums, int numsSize)
{
    int i;
    int next = 0;
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[next++] = nums[i];
        }
    }
    for (i = next; i < numsSize; i++) {
        nums[i] = 0;
    }
}
