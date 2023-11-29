#include <stdio.h>
#include <math.h>

int search_list(int *haystack, int needle, int size) {
  int lo = 1;
  int hi = size;

  do
  {
    int middle = (int)(lo + (hi - lo) / 2);
    int value = haystack[middle];

    if (value == needle) {
      return 0;
    }
    else if (value > needle) {
      hi = middle;
    }
    else {
      lo = middle + 1;
    }
  } while (lo < hi);
  

  printf("\n");
  return -1;
}

int main() {
  int my_array[10] = {1,2,3,4,5,6,7,8,9,10};
  int target;

  printf("Please enter a number to search: ");
  scanf("%d", &target);
  int size = sizeof(my_array) / sizeof(my_array[0]);

  int is_there = search_list(my_array, target, size);


  printf("%s", is_there == 0 ? "yes" : "no");
  return 0;
}