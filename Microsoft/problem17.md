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

### Solution for the Problem in Java:

```java
import java.util.*;

public class Solution {

    public static List<Integer> increment(int N, int[] arr) {
        
        for (int i = N - 1; i >= 0; i--) {
            if (arr[i] < 9) {
                arr[i]++;  
                return arrayToList(arr);  
            }
            arr[i] = 0;  
        }
        
        
        List<Integer> result = new ArrayList<>();
        result.add(1);  
        for (int num : arr) {
            result.add(num);  
        }
        return result;
    }

    
    private static List<Integer> arrayToList(int[] arr) {
        List<Integer> list = new ArrayList<>();
        for (int num : arr) {
            list.add(num);
        }
        return list;
    }

    public static void main(String[] args) {
        
        int[] arr1 = {1, 2, 4};
        System.out.println(increment(arr1.length, arr1));  

        
        int[] arr2 = {9, 9, 9};
        System.out.println(increment(arr2.length, arr2));  
    }
}
```
