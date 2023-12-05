#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Using size_t for array indexing and loop counting
    int numbers[] = {10, 20, 30, 40, 50};
    // `sizeof` returns `size_t`
    size_t n = sizeof(numbers) / sizeof(numbers[0]); // Calculate the number of elements in the array

    printf("Array elements:\n");
    /** 
     * `size_t` has a wider range that `int` in most systems. If `i` were an 
     * `int` and `n` is larger than the max value `int` can represent, 
     * `i` might never each the value of `n` and cause an infinite loop 
     * or other errors.
    */
    for (size_t i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    /**
     * `malloc` expects to receive `size_t` as an argument. It could be an int
     * in this case, but a `size_t` ensures it won't be a negative number.
    */
    size_t num_elements = 10;
    /**
     * `malloc` allocates a specified number of bytes of memory and returns a
     * pointer to the first byte of this memory block. The memory allocated by
     * malloc is uninitialized, meaning it contains whatever data was
     * previously at that location in memory.
    */
    int* dynamic_array = (int*) malloc(num_elements * sizeof(int));

    // Initialize the allocated array
    for (size_t i = 0; i < num_elements; i++) {
        dynamic_array[i] = i * 2;
    }

    // Using size_t with the strlen function
    const char* message = "Hello, world!";
    // `strlen` returns `size_t`
    size_t message_length = strlen(message);

    printf("Message: %s\n", message);
    printf("Message length: %zu\n", message_length);

    // Cleanup
    free(dynamic_array);

    return 0;
}

