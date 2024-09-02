#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_SIZE 10

// Structure initialization
typedef struct {
  int *array;   // Pointer to the array of integers
  int length;   // Current number of elements in the array
  int capacity; // Total capacity of the array
} dynamic_array_t;

// Initialize the integer array
void initialize_array(dynamic_array_t *pA) {
  pA->array = (int *)malloc(sizeof(int) * INITIAL_SIZE); // Allocate memory within the structure for the integer array based on the initial capacity
  if (pA->array == NULL) { // If malloc fails, exit 
    printf("Memory allocation failed\n");
    exit(1);
  }
  pA->length = 0; // Initially, the array is empty;
  pA->capacity = INITIAL_SIZE; // Total capacity of the array
}

// Read entire array
void read_array(dynamic_array_t *dynamic_array) {
  if (dynamic_array->length == 0) {
    printf("Array is empty\n");
  } else {
    for (int i = 0; i < dynamic_array->length; i++) {
      printf("Value at index %d: %d\n", i, dynamic_array->array[i]);
    }
    printf("End of array\n");
  }
}

// Read element at array index
int read_element(dynamic_array_t *dynamic_array, int index) {
  if (dynamic_array->length <= 0) {
    printf("Unable to remove element since the array is empty.\n");
    return -1;
  }
  if (index >= dynamic_array->length || index < 0) {
    printf("Index is out of bounds: Index %d\n", index);
    return -1;
  } 
  printf("Reading value at index %d: %d\n", index, dynamic_array->array[index]);
  return 0;
}

// Resize the array
int resize_the_array(dynamic_array_t *dynamic_array) {
  // Resize the array if it is full by doubling it
  if (dynamic_array->length == dynamic_array->capacity) {
    // The realloc function already handles copying the old memory contents to the new block and freeing the old memory if needed.
    int *temp = (int *)realloc(dynamic_array->array, dynamic_array->capacity * 2 * sizeof(int)); // assigning the realloc result to a temp variable in case realloc fails
    if (temp == NULL) {
      printf("Memory reallocation failed\n");
      return -1;
    }
    // if realloc doesn't fail, assign the reallocation result back ta dynamic_array->array
    dynamic_array->array = temp;
    dynamic_array->capacity *= 2;
    printf("Array capacity reached its limit and now has been doubled to %d\n", dynamic_array->capacity);
  }
  return 0;
}

// Remove element from array
int remove_element(dynamic_array_t *dynamic_array, int index) {
  if (dynamic_array->length <= 0) {
    printf("Unable to remove element since the array is empty.\n");
    return -1;
  }
  if (index >= dynamic_array->length || index < 0) {
    printf("Index is out of bounds: Index %d\n", index);
    return -1;
  } 
  printf("Removed element %d from index %d\n", dynamic_array->array[index], index);
  for (int i = index; i < dynamic_array->length; i++) {
    dynamic_array->array[i] = dynamic_array->array[i + 1];
  }
  dynamic_array->length--;
  return 0;
}

// Push element to array
void push_to_array(dynamic_array_t *dynamic_array, int element) {
  int resize_the_array_result = resize_the_array(dynamic_array);
  if (resize_the_array_result == 0) {
    dynamic_array->array[dynamic_array->length] = element;
    printf("Added integer %d at position %d\n", element, dynamic_array->length);
    dynamic_array->length++;
  } else {
    printf("Exiting push_to_array function, memory reallocation failed\n");
  }
}

// Pop element from array
int pop_from_array(dynamic_array_t *dynamic_array) {
  if (dynamic_array->length <= 0) {
    printf("Unable to remove element since the array is empty.\n");
    return -1;
  }
  printf("Array length before popping: %d\n", dynamic_array->length);
  printf("Popped element %d from from end of array\n", dynamic_array->array[dynamic_array->length - 1]);
  dynamic_array->length--; 
  printf("Array length is now %d\n", dynamic_array->length);

  return 0;
}

int main() {
  // Memory is being allocated in the size and shape of the dynamic_array_t structure.  This memory allocation returns a void * pointer, which is then typecasted to a pointer of type `dynamic_array_t`. 
  // This tells the compiler that this memory should be treated as the dynamic_array_t structure type. This ensures that the pointer on the right side will match the pointer type expected by the variable on the left side.  
  // The result of this memory allocation and type casting is being assigned to the `array` pointer, which is being specified as being of type `dynamic_array_t`.  
  // This pointer will now point to the beginning of the memory chunk allocated for the `dynamic_array_t` structure.
  // The use of `dynamic_array_t *` on both sides of the assignment ensures that the variable `array` is of the correct type, and the memory it points to is treated as the correct type of structure. 
  dynamic_array_t *array = (dynamic_array_t *)malloc(sizeof(dynamic_array_t)); // Allocate memory for the structure
  if (array == NULL) { // checking of malloc was successful before using the pointer
    printf("Memory allocation failed\n");
    return 1;
  }

  initialize_array(array); // Initialize the dynamic array
  
  read_array(array);
  
  srand(time(NULL));
  for (int i = 0; i < 11; i++) {
    push_to_array(array, rand());
  };

  read_array(array);

  remove_element(array, 3);
  remove_element(array, 3);
  remove_element(array, 3);
  remove_element(array, 3);
  
  read_array(array);

  pop_from_array(array);
  pop_from_array(array);
  pop_from_array(array);
  pop_from_array(array);

  read_array(array);

  read_element(array, 14);

  read_element(array, 0);
  // Free the allocated memory
  free(array->array);  // Free the integer array inside the structure
  free(array); // Free the structure itself

  array = NULL; // Set the pointer to NULL to avoid dangling pointers 

  return 0;

}
