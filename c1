#include<stdio.h>
#include<string.h>
int main (){
   char txt[80], pat[80];
   int q;
   printf ("Enter the container string \n");
   scanf ("%s", &txt);
   printf ("Enter the pattern to be searched \n");
   scanf ("%s", &pat);
   int d = 256;
   printf ("Enter a prime number \n");
   scanf ("%d", &q);
   int M = strlen (pat);
   int N = strlen (txt);
   int i, j;
   int p = 0;
   int t = 0;
   int h = 1;
   for (i = 0; i < M - 1; i++)
      h = (h * d) % q;
   for (i = 0; i < M; i++){
      p = (d * p + pat[i]) % q;
      t = (d * t + txt[i]) % q;
   }
   for (i = 0; i <= N - M; i++){
      if (p == t){
         for (j = 0; j < M; j++){
            if (txt[i + j] != pat[j])
            break;
         }
         if (j == M)
            printf ("Pattern found at index %d \n", i);
      }
      if (i < N - M){
         t = (d * (t - txt[i] * h) + txt[i + M]) % q;
         if (t < 0)
            t = (t + q);
      }
   }
   return 0;
}
