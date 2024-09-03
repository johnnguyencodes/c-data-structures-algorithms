#include <stdio.h>

#define INITIAL_CAPACITY 3

typedef struct {
  int* array;
  int length;
  int capacity;
} stack_t;

int initialize_stack(stack_t *pS) {
  // Allocate memory for integer array inside struct
  pS->stack = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
  if (pS->stack == NULL) {
    printf("Memory allocation for for struct contents failed\n");
    return -1;
  } 
  pS->length = 0;
  pS->capacity = INITIAL_CAPACITY;
  ps->stack[0] = -1;

  printf("Stack initialized\n");
  return 0;
}

int check_if_empty_stack() {

}

int peek_top_of_stack() {

}

int push_to_stack() {

}

int pop_from_stack() {

}

int main() {

  // Allocate memory for stack structure
  stack_t *stack = (int stack_t *)malloc(sizeof(stack_t));
  if (stack == NULL) {
    printf("Memory allocation for struct stack_t failed");
    return -1;
  }

  initialize_stack(stack);

  // Free memory of integer array inside struct 
  free(stack->stack);
  // Free memory of the stack struct
  free(stack);
}
