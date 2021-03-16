#include <stdio.h>

//01. Рекурсивная функиця перевода десятичного числа в двоичное
void dec_to_bin_recursive(int dec) {
  if (dec / 2 > 0) {
      dec_to_bin_recursive(dec / 2);
    }
  printf("%d", dec % 2);
}

//02. Итерационная функция возведения числа в степень
int power(int a, int b) {
  int result = 1;

  for (int i = 0; i < b; i++) {
      result = result * a;
    }

  return result;
}

//03. Рекурсивная функция возведения числа в степень
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

//04. Рекурсивная функция возведения числа в степень с использованием свойства чётности
int power_even(int a, int b) {
  if (b / 2 != 0) {
      if (b % 2 == 0) {
          a = power_even(a * a, b / 2);
        }
      else {
          a = a * power_even(a, b - 1);
        }
    }

  return a;
}

//05. Функция расчёта количества путей короля с препятствиями
enum checker {EMPTY = '_', WALL = '#'};

char field[5][5];

void init_field(){
  for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
          field[x][y] = EMPTY;
        }
    }
}

void print_field(){
  for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
          printf("%4c", field[x][y]);
        }
      printf("\n");
    }
  printf("\n");

}

int king_way(int x, int y) {
  if (x == 0 && y == 0) {
      return 0;
    }
  else if (x == 0 || y == 0) {
      return 1;
    }
  else {
      if (field[x - 1][y] == WALL) {//Если клетка слева занята
          return king_way(x, y -1);//Обойти сверху
        }
        else if (field[x][y - 1] == WALL) {//Если клетка сверху занята
          return king_way(x -1, y);//Обойти слева
        }
      else {//Иначе идти по обоим направлениям
          return  king_way(x, y -1) + king_way(x -1, y);
        }
    }
}

int main()
{
  init_field();

  field[3][3] = WALL;

  print_field();

  for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
          printf("%4d", king_way(x, y));
        }
      printf("\n");
    }

  return 0;
}
