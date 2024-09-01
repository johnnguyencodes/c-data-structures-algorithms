#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10

int initialize_array(int *array_numbers, int limit) {
  srand(time(NULL));
  int i = 0;
  for (i = 0; i < limit; i++) {
    array_numbers[i] = rand();
    printf("Array initialized at index %d\n", i);
  };
  i = 0;
  for (i = limit; i < MAX_ELEMENTS; i++) {
    array_numbers[i] = 0;
  }
  return 0;
}

int check_if_index_within_bounds(int index) {
  if (index >= MAX_ELEMENTS) {
    printf("Index is out of bounds: Index %d\n", index);
    return -1;
  } else {
    return 0;
  }
}

int read_array(int *array_numbers) {
  int i = 0;
  for (i = 0; i < MAX_ELEMENTS; i++) {
    printf("Value at index %d: %d\n", i, array_numbers[i]);
  };
  return 0;
}

int get_value_at_index(int *array_numbers, int index) {
  int check = check_if_index_within_bounds(index);
  if (check == 0) {
    printf("Here is the value at index %d: %d\n", index, array_numbers[index]);
    return 0;
  }
}

int update_element(int *array_numbers, int index, int element) {
  int check = check_if_index_within_bounds(index);
  if (check == 0) {
    array_numbers[index] = element;
    printf("Element %d updated at index %d\n", element, index);
    return 0;
  }
}

int remove_element(int *array_numbers, int index) {
  int check = check_if_index_within_bounds(index);
  if (check == 0) {
    printf("Element removed at Index %d\n", index);

    // start at index and shift values down one place
    while (index < MAX_ELEMENTS) {
      array_numbers[index] = array_numbers[index + 1];
      index++;
    }
    // after the loop, set last element to 0
    array_numbers[MAX_ELEMENTS - 1] = 0;
    return 0;
  }
}

int add_element(int *array_numbers, int index, int element) {
  int check = check_if_index_within_bounds(index);
  if (check == 0) {
    // start at end of array and go down
    int i = MAX_ELEMENTS - 1;
    while (i >= index) {
      // if at index, update value
      if (i == index) {
        array_numbers[i] = element;
        // else, shift values up one place
      } else {
        array_numbers[i] = array_numbers[i - 1];
      } 
      i--;
    }
    printf("Element %d has been added to array in Index %d\n", element, index);
    return 0;
  }
}


int main() {
  int array_numbers[MAX_ELEMENTS];

  initialize_array(array_numbers, MAX_ELEMENTS);

  read_array(array_numbers);

  update_element(array_numbers, 2, 100);

  get_value_at_index(array_numbers, 2);

  read_array(array_numbers);
  
  remove_element(array_numbers, 4);

  get_value_at_index(array_numbers, 4);

  read_array(array_numbers);  
  
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);
  add_element(array_numbers, 2, 1984);

  get_value_at_index(array_numbers, 8);

  read_array(array_numbers);  
  
  add_element(array_numbers, 8, 2024);

  get_value_at_index(array_numbers, 8);

  read_array(array_numbers);  

  return 0;
}
