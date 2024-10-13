# Problem: Happy Number

## Problem Description

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.


Example 1:
Input: n = 19
Output: true

Example 2:
Input: n = 2
Output: false

Constraints:

1 <= n <= 231 - 1


SOLUTION

Language- C++

class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
        return true;
        int s = 0;
        while (n > 1) {
            while (n > 0) {
                int m = n % 10;
                s += m * m;
                n /= 10;
            }
            if (s == 1) {
                return true;
            }
            n = s;
            s = 0;
            if (n == 4) {  
                return false;
            }
        }
        return false;
    }
};