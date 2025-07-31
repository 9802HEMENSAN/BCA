Q.1.:   Write a program to generate 10 Fibonacci series and calculate complexity of each 
statement and total complexity of a program.    

Below are several C language implementations to generate the first 10 Fibonacci numbers using different methods. For each method, the code is presented along with comments on the time complexity of key statements and an overall complexity estimate.

---

## Method 1: Iterative Approach

This is the most common and efficient method for generating Fibonacci numbers. It uses a simple loop to build the series.

```c
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
```

### Complexity Analysis (Iterative Method)

* **Array Initialization:** Allocating and initializing the array is O(n).
* **Loop (calculating Fibonacci):** Runs from 2 to *n - 1*, each iteration is O(1) → O(n) total.
* **Printing Loop:** O(n)

> **Overall Time Complexity:** O(n)

---

## Method 2: Plain Recursive Approach

This method calculates the Fibonacci number using simple recursion. Notice that it recalculates subproblems and is therefore exponentially inefficient.

```c
#include <stdio.h>

// Recursive function to compute Fibonacci number (inefficient for large n)
int fibonacci_recursive(int n) {
    if (n == 0) return 0;                // O(1)
    if (n == 1) return 1;                // O(1)
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    // Each call results in two recursive calls (O(2^n) overall for fib(n))
}

void print_fibonacci_recursive(int n) {
    printf("Recursive: ");
    for (int i = 0; i < n; i++) {        // Loop O(n)
        printf("%d ", fibonacci_recursive(i));  // Each call is exponential: O(2^i) worst-case per number
    }
    printf("\n");
}

int main() {
    int n = 10;                          // O(1)
    print_fibonacci_recursive(n);
    return 0;
}
```

### Complexity Analysis (Plain Recursive Method)

* **Base Cases:** O(1)
* **Recursive Call:**

  * The function `fibonacci_recursive` calls itself twice, yielding a recurrence that is approximately O(2^n) for computing `fib(n)`.
* **Loop in `print_fibonacci_recursive`:** Calls the recursive function for each number from 0 to n−1.
  Thus, the overall computation for printing grows quickly.

> **Overall Time Complexity:** Approximately O(2^n) for the recursive calculations.

*Note:* Although this method is clear, its exponential complexity makes it impractical for larger values of *n*.

---

## Method 3: Recursive Approach with Memoization

Memoization stores previously computed Fibonacci numbers to avoid redundant calculations. This reduces the time complexity to O(n).

```c
#include <stdio.h>
#include <string.h>  // for memset

#define MAX 100

int memo[MAX];

// Recursive function with memoization
int fibonacci_memo(int n) {
    if (n == 0) return 0;                // O(1)
    if (n == 1) return 1;                // O(1)
    
    // If already computed, return it.
    if (memo[n] != -1) {                 // O(1)
        return memo[n];                // O(1)
    }
    
    // Otherwise, compute and store the result (each calculation is done once)
    memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);  // O(1) work plus recursive calls that are each computed once over all calls
    return memo[n];
}

void print_fibonacci_memo(int n) {
    // Initialize memo array with -1
    for (int i = 0; i < MAX; i++) {      // O(MAX) (constant if MAX is fixed)
        memo[i] = -1;                  // O(1) per iteration
    }
    
    printf("Recursive with Memoization: ");
    for (int i = 0; i < n; i++) {        // O(n)
        printf("%d ", fibonacci_memo(i));  // Each call now runs in O(1) amortized time due to memoization
    }
    printf("\n");
}

int main() {
    int n = 10;                          // O(1)
    print_fibonacci_memo(n);             // Overall complexity: O(n) + O(MAX) initialization (constant for fixed MAX)
    return 0;
}
```

### Complexity Analysis (Memoized Recursive Method)

* **Initialization of Memo Array:** O(MAX) (a constant factor if MAX is predetermined)
* **Recursive Function:**
  Each Fibonacci number from 0 to *n* is computed exactly once, so the overall time is O(n).
* **Loop for Printing:** O(n)

> **Overall Time Complexity:** O(n)

---

## Summary of Different Methods

1. **Iterative Method:**

   * **Pros:** Simple, efficient (O(n)), low memory overhead.
   * **Cons:** None for generating Fibonacci numbers up to moderate sizes.

2. **Plain Recursive Method:**

   * **Pros:** Direct and elegant code.
   * **Cons:** Exponential time complexity (O(2^n)); impractical for larger *n*.

3. **Recursive with Memoization:**

   * **Pros:** Retains the recursive clarity while reducing time complexity to O(n).
   * **Cons:** Requires extra space for memoization.

Each method has tradeoffs between clarity and performance. For most practical purposes when generating Fibonacci numbers, the iterative or memoized recursive approaches are recommended.

Feel free to ask if you have questions or need further explanations on any of these implementations!
