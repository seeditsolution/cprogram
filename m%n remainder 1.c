#include<stdio.h>



void main()

{

  int m,n;

  scanf("%d",&m);

  scanf("%d",&n);

  

  int rem = m%n;  //% is used to find the remainder.

  

  if(rem==1)

    printf("1");

  else 

    printf("0");

  

}
