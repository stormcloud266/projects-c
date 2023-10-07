#include <stdio.h>

void repeat(char letter, int count) {
  if (count < 1) 
    return;

  putchar(letter);
  repeat(letter, count - 1);
}

int main() {
  int steps;
  printf("%s", "How many steps should I print?: ");
  scanf("%d", &steps);

  for(int i=1;i<=steps;i++)
  {
    repeat(' ', steps - i);
    repeat('X', i);
    putchar('\n');
  }
}