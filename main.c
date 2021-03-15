#include <stdio.h>

void dec_to_bin_recursive(int dec) {
  if (dec / 2 > 0) {
      dec_to_bin_recursive(dec / 2);
    }
  printf("%d", dec % 2);
}

int power(int a, int b) {
  int result = 1;

  for (int i = 0; i < b; i++) {
      result = result * a;
    }

  return result;
}

int power_recoursive(int a, int b) {
  if (b == 0) {
      return 1;
    }
  if (b > 1) {
      b--;
      a = a * power_recoursive(a, b);
    }

  return a;
}

int main()
{
  dec_to_bin_recursive(6);

  printf("\n%3d\n", power_recoursive(2, 8));
  return 0;
}
