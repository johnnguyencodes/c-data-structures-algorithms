#include <stdio.h>

#define MAX_IDS 32

// Define a union to view the bit representation of an integer
typedef union {
  int int_value;            // Integer value
  unsigned char bytes[4];   // Array of bytes representing the integer
} int_u;

// Function to print the bit values of an integer
void printBitValues(int value) {
  int_u u; // Create a union instance
  u.int_value = value; // Assign the value to the union
  
  printf("Bit values of %d (0x%x):\n", u.int_value, u.int_value);
  for (int i = 0; i < 4; i++) {
    printf("Byte %d: 0x%02x (", i, u.bytes[i]);
    for (int bit = 7; bit >= 0; bit--) {
      printf("%d", (u.bytes[i] >> bit) & 1); // Print each bit
    };
    printf(")\n");
  };
};

int main() {
  int ids[MAX_IDS] = {400000000,1003849,300};

  // Print memory addresses of the first three elements
  for (int i = 0; i < 3; i++) {
    printf("Memory address of array index %d: %p\n", i, &ids[i]);
  }

  // Print the bit values for each element in the array
  for (int i = 0; i < 3; i++) { // Adjust this to MAX_IDS if you want to print for all elements
    printf("\nArray index %d:\n", i);
    printBitValues(ids[i]);
  }

  return 0;
}

