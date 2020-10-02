#include<stdio.h>
int main ()
{
    int i, prime, up, low, n;
    printf ("ENTER THE LOWER LIMIT : ");
    scanf ("%d", &low);
    printf ("ENTER THE UPPER LIMIT : ");
    scanf ("%d", &up);
    if(low>=2)
    {
        printf ("PRIME NUMBERS ARE : ");
        for (n = low + 1; n < up; n++)
        {
            prime = 1;
            for (i = 2; i < n/2; i++)
                if (n % i == 0)
                {
                    prime = 0;
                    break;
                }
            if (prime)
                printf ("\t %d", n);
        }
    }
    else
    {
        printf("Enter lower number must be greater than 1");
    }
}
