#include <stdio.h>

void dec_to_bin_recursive(int dec) {
  if (dec / 2 > 0) {
      dec_to_bin_recursive(dec / 2);
    }
  printf("%d", dec % 2);
}

void rec(int a) {

  if (a > 0) {
      rec(a - 1);
    }
  printf("%3d", a);

}

int main()
{
  dec_to_bin_recursive(6);
//  rec(10);
  printf("\n");
  return 0;
}
