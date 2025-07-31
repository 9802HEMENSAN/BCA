#include <stdio.h>

void fibonacci_iterative(int n) {
    int fib[n];                          // O(n) for array initialization (allocation is O(1) in C, but filling it is O(n) if you later traverse it)
    fib[0] = 0;                          // O(1)
    fib[1] = 1;                          // O(1)
    
    // Loop from 2 to n - 1: Each iteration does O(1) work.
    for (int i = 2; i < n; i++) {        // O(n)
        fib[i] = fib[i - 1] + fib[i - 2];  // O(1) per iteration
    }
    
    // Print the Fibonacci series
    printf("Iterative: ");
    for (int i = 0; i < n; i++) {        // O(n) for printing
        printf("%d ", fib[i]);           // O(1) per element
    }
    printf("\n");
}

int main() {
    int n = 10;                          // O(1)
    fibonacci_iterative(n);              // Overall complexity: O(n)
    return 0;
}


