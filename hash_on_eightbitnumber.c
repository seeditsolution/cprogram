#include<stdio.h>
int main()
{
 char ch, input[9], s[9];
 int i, len=0;
 
 printf("Enter your input bits:");
 scanf("%s",input);
  
 printf("Enter your key S (8 bits):");
 scanf("%s",s);
 
 printf("Your hash code is:");
 for(i=0; i<8; i++)
 {
  ch=input[i]^s[i];
  printf("%d",ch); 
 }
 return 0;
}
