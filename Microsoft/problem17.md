## Problem Statement: Plus One

You are given a non-negative number represented as an array of digits, where the most significant digit is at the first position of the array. Your task is to add 1 to this number and return the resulting number as an array of digits.

### Examples:

#### Example 1:
**Input:**
- N = 3
- arr[] = {1, 2, 4}

**Output:**
- 1 2 5

**Explanation:**
The number represented by the array is 124. Adding 1 to it results in 125, which is represented as [1, 2, 5].

#### Example 2:
**Input:**
- N = 3
- arr[] = {9, 9, 9}

**Output:**
- 1 0 0 0

**Explanation:**
The number represented by the array is 999. Adding 1 to it results in 1000, which is represented as [1, 0, 0, 0].

---

## Task:

You need to implement the function `increment()` which takes two arguments:
1. `N`: An integer representing the number of digits in the array.
2. `arr[]`: An array of integers representing the digits of the number.

The function should return a list of integers that represents the new number after adding 1.

---

### Constraints:
- \( 1 \leq N \leq 10^5 \)
- \( 0 \leq arr[i] \leq 9 \)

---

### Expected Time Complexity:
- \( O(N) \), where \( N \) is the size of the input array.

### Expected Auxiliary Space:
- \( O(1) \), except for the space required to store the result.

---

