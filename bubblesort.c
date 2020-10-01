#include <stdio.h>
int is_Array_Sorted(int [], int);

int main()
{
  int a[100], n, c;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &a[c]);

  if (is_Array_Sorted(a, n))
    printf("The array is sorted.\n");
  else
    printf("The array isn't sorted.\n");

  return 0;
}

int is_Array_Sorted(int a[], int n) {
  int c, d, sorted = 1, t;

  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (a[d] > a[d+1]) {
        t = a[d];
        a[d] = a[d+1];
        a[d+1] = t;
        return 0;
      }
    }
  }
  return 1;
}
