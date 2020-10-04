#include<stdio.h>
int main() {
   int r, s, rows=0;
   int t=0;
   clrscr();
   printf("Enter number of rows to print the pyramid: ");
   scanf("%d", &rows);
   printf("\n");
   printf("The Pyramid Pattern for the number of rows are:");
   printf("\n\n");
   for(r=1;r<=rows;++r,t=0) {
      for(s=1; s<=rows-r; ++s){
         printf(" ");
      }
      while (t!=2*r-1) {
         printf("* ");
         ++t;
      }
      printf("\n");
   }
   getch();
   return 0;
}
