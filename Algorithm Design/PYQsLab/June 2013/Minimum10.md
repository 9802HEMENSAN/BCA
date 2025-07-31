Q.2. Write a program to find minimum of 10 numbers and calculate time complexity of 
each statement and total complexity of a program. 

Here's a complete **C program** to find the **minimum of 10 numbers** entered by the user. After that, you'll find a detailed **time complexity analysis of each statement** and the **total program complexity**.

---

## ✅ C Program to Find Minimum of 10 Numbers

```c
#include <stdio.h>

int main() {
    int arr[10];                     // O(1) (fixed size array)
    int min;                         // O(1)

    // Input: Read 10 numbers from user
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {   // O(10) → O(1)
        scanf("%d", &arr[i]);        // O(1) per iteration → O(10) total → O(1)
    }

    // Initialize minimum with first element
    min = arr[0];                    // O(1)

    // Compare with the rest of the array
    for (int i = 1; i < 10; i++) {   // O(9) → O(1)
        if (arr[i] < min) {          // O(1)
            min = arr[i];            // O(1)
        }
    }

    // Output the result
    printf("Minimum number is: %d\n", min); // O(1)

    return 0;                        // O(1)
}
```

---

## 📊 Time Complexity Analysis (Line by Line)

| Line / Statement                              | Time Complexity    |
| --------------------------------------------- | ------------------ |
| `int arr[10];`                                | O(1)               |
| `int min;`                                    | O(1)               |
| `for (int i = 0; i < 10; i++) scanf(...)`     | O(10) = O(1)       |
| `min = arr[0];`                               | O(1)               |
| `for (int i = 1; i < 10; i++)`                | O(9) = O(1)        |
| `if (arr[i] < min)`                           | O(1) per iteration |
| `min = arr[i];` (only when condition is true) | O(1) worst case    |
| `printf(...)`                                 | O(1)               |

---

## 🧠 Total Time Complexity

* All operations are over **fixed-size (10) input**, so every loop has **constant time** bounds.
* No operation scales with variable input size.

> ✅ **Total Time Complexity: O(1)**
> (*Because input size is fixed at 10; complexity is constant regardless of algorithmic structure.*)

---

### 📌 If Input Size Were Variable (n instead of 10)

If the input size were `n` instead of 10 (i.e., dynamically sized), then:

* Reading input: O(n)
* Finding min: O(n)

> **Total Complexity in that case:** O(n)

---

Let me know if you'd like a version using dynamic memory allocation or for variable-size input.
