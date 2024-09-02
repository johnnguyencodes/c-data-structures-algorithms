#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define INVALID_INDEX -1

int initialize_array(int *array_numbers, int limit) {
  srand(time(NULL));
  for (int i = 0; i < limit; i++) {
    array_numbers[i] = rand();
    printf("Array initialized at index %d with value %d\n", i, array_numbers[i]);
  };
  return 0;
}

int check_if_index_within_bounds(int index) {
  if (index >= MAX_ELEMENTS || index < 0) {
    printf("Index is out of bounds: Index %d\n", index);
    return INVALID_INDEX;
  } 
  return 0;
}

int read_array(int *array_numbers) {
  for (int i = 0; i < MAX_ELEMENTS; i++) {
    printf("Value at index %d: %d\n", i, array_numbers[i]);
  };
  return 0;
}

int get_value_at_index(int *array_numbers, int index) {
  if (check_if_index_within_bounds(index) == INVALID_INDEX) return INVALID_INDEX;
  
  printf("Here is the value at index %d: %d\n", index, array_numbers[index]);
  return 0;
}

int update_element(int *array_numbers, int index, int element) {
  if (check_if_index_within_bounds(index) == INVALID_INDEX) return INVALID_INDEX;
 
  array_numbers[index] = element;
  printf("Element %d updated at index %d\n", element, index);
  return 0;
}

int remove_element(int *array_numbers, int index) {
  if (check_if_index_within_bounds(index) == INVALID_INDEX) return INVALID_INDEX;

  printf("Element removed at Index %d\n", index);
  // start at index and shift values down one place
  while (index < MAX_ELEMENTS - 1) {
    array_numbers[index] = array_numbers[index + 1];
    index++;
  }

  // after the loop, set last element to 0
  array_numbers[MAX_ELEMENTS - 1] = 0;
  return 0;
}

int add_element(int *array_numbers, int index, int element) {
  if (check_if_index_within_bounds(index) == INVALID_INDEX) return INVALID_INDEX;
  
  // start at end of array and go down
  for (int i = MAX_ELEMENTS - 1; i > index; i--) {
      array_numbers[i] = array_numbers[i - 1];
  }
  // update value at index
  array_numbers[index] = element;
  printf("Element %d has been added to array in Index %d\n", element, index);
  return 0;
}


int main() {
  // Initialize array with zeros
  int array_numbers[MAX_ELEMENTS] = {0};

  initialize_array(array_numbers, MAX_ELEMENTS);

  update_element(array_numbers, 2, 100);

  get_value_at_index(array_numbers, 2);

  read_array(array_numbers);
  
  remove_element(array_numbers, 4);

  get_value_at_index(array_numbers, 4);

  read_array(array_numbers);

  add_element(array_numbers, 2, 1984);

  get_value_at_index(array_numbers, 2);

  add_element(array_numbers, 8, 2024);

  get_value_at_index(array_numbers, 8);

  read_array(array_numbers);  

  return 0;
}
