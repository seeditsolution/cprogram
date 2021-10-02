#include <stdio.h>
// using recursive approach to find the catalan number
unsigned long int catalan(unsigned int n) {
   // Base case
   if (n <= 1) return 1;
   // catalan(n) is sum of catalan(i)*catalan(n-i-1)
   unsigned long int res = 0;
   for (int i=0; i<n; i++)
      res += catalan(i)*catalan(n-i-1);
   return res;
}
//Main function
int main() {
   int n = 6;
   printf("catalan is :%ld\n", catalan(n));
   return 0;
}
