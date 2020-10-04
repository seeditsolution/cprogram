#include <stdio.h>
int isNeon(int num)
{
    //storing the square of x
    int square = 0;
    //Store sum of digits (square number)
    int sum_digits = 0;
    //Calculate square of given number
    square = (num * num);
    while (square != 0)
    {
        sum_digits = (sum_digits + (square % 10));
        square = (square / 10);
    }
    return (sum_digits == num);
}
int main()
{
    int data = 0;
    int isNeonNumber = 0;
    //Ask to enter the number
    printf("Enter the number = ");
    scanf("%d",&data);
    // if is isNeonNumber is 1, then neon number
    isNeonNumber = isNeon(data);
    (isNeonNumber)? printf("neon number\n\n"):printf("Not a neon number\n\n");
    return 0;
}
