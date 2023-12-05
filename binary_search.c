#include <stdio.h>
#include <math.h>

int search_list(int *haystack, int needle, int size) {
  int start = 0, end = size - 1, mid;

  do
  {
    mid = start + (end - start) / 2;
    printf("%d\n", mid);

    int value = haystack[mid];

    if (value == needle)
      return 0;
    
    if (value < needle)
      start = mid + 1;
    else
      end = mid - 1;

  } while (start <= end);
  

  printf("\n");
  return -1;
}

int main() {
  int my_array[10] = {1,2,3,4,5};
  int target;

  printf("Please enter a number to search: ");
  scanf("%d", &target);
  int size = sizeof(my_array) / sizeof(my_array[0]);

  int is_there = search_list(my_array, target, size);


  printf("%s", is_there == 0 ? "yes" : "no");
  return 0;
}