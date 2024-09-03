#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 3

typedef struct {
  int* array;
  int length;
  int capacity;
} stack_t;

int initialize_stack(stack_t *pS) {
  // Allocate memory for integer array inside struct
  pS->array = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
  if (pS->array == NULL) {
    printf("Memory allocation for for struct contents failed\n");
    return -1;
  } 
  pS->length = 0;
  pS->capacity = INITIAL_CAPACITY;

  printf("Stack initialized\n");
  return 0;
}

int check_if_empty_stack(stack_t *pS) {
 if (pS->length <= 0) {
    printf("Stack is empty\n");
    return -1;
  }
  printf("Stack has contents\n");
  return 0;
}

int check_if_full_stack(stack_t *pS) {
  if(pS->length == pS->capacity) {
    int *temp = (int *)realloc(pS->array, pS->capacity * 2 * sizeof(int));
    if (temp == NULL) {
      printf("Memory reallocation failed, could not double stack's capacity\n");
      return -1;
    }
    pS->array = temp;
    pS->capacity *= 2;
    printf("Stack capacity reached its limit and now has been doubled to %d\n", pS->capacity);
  }
  return 0;
}

int peek_top_of_stack(stack_t *pS) {
  int empty_status = check_if_empty_stack(pS);
  if (empty_status == 0) {
    printf("Value at top of stack: %d\n", pS->array[pS->length]);
    return 0;
  } else {
    printf("Stack is empty, cannot peek top of stack\n");
    return -1;
  }
}

int push_to_stack(stack_t *pS, int element) {
  int check_full_stack_result = check_if_full_stack(pS);
  if (check_full_stack_result == 0) {
    pS->array[pS->length - 1] = element;
    printf("Element %d has been pushed to top of stack at index %d\n", element, pS->length);
    pS->length++;
    printf("Stack length is now %d\n", pS->length);
    return 0;
  } else {
    printf("Can't push element to top of stack due to memory reallocation error\n");
    return -1;
  }
}

int pop_from_stack(stack_t *pS) {
  int check_if_empty_stack_result = check_if_empty_stack(pS);
  if (check_if_empty_stack_result == 0) {
    printf("Element %d has been popped off the stack\n", pS->array[pS->length - 1]);
    pS->length--;
    printf("Stack length is now %d\n", pS->length);
    return 0;
  } else {
    printf("Stack is empty, can't pop from stack");
    return -1;
  }
}

int clear_stack(stack_t *pS) {
  int check_if_empty_stack_result = check_if_empty_stack(pS);
  if (check_if_empty_stack_result == 0) {
    for (int i = pS->length; i > 0; i--) {
      pop_from_stack(pS);
    }
    int check_if_empty_stack_result = check_if_empty_stack(pS);
    if (check_if_empty_stack_result == 0) {
      printf("Stack is now empty after clearing it");
      return 0;
    } else {
      printf("Error clearing stack");
      return -1;
    }
  } else {
    printf("Stack is already empty, no need to clear");
    return 0;
  }
}

int main() {
  int incrementor = 1;

  // Allocate memory for stack structure
  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
  if (stack == NULL) {
    printf("Memory allocation for struct stack_t failed");
    return -1;
  }

  initialize_stack(stack);

  check_if_empty_stack(stack);
  push_to_stack(stack, incrementor);
  incrementor++;
  peek_top_of_stack(stack);
  push_to_stack(stack, incrementor);
  incrementor++;
  peek_top_of_stack(stack);
  push_to_stack(stack, incrementor);
  incrementor++;
  peek_top_of_stack(stack);
  check_if_empty_stack(stack);
  push_to_stack(stack, incrementor);
  incrementor++;
  peek_top_of_stack(stack);
  push_to_stack(stack, incrementor);
  incrementor++; 
  peek_top_of_stack(stack);
  clear_stack(stack);
  check_if_empty_stack(stack);
  // Free memory of integer array inside struct 
  free(stack->array);
  // Free memory of the stack struct
  free(stack);

  return 0;
}
