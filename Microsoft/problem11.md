# Problem: Integer to English Words

## Problem Description


Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

- 0 <= num <= 231 - 1

<!-- ---------------------------solution in C++ ------------------------------ -->

class Solution {
public:
     string numberToWords(int num) {
        if (num == 0) return "Zero";  
        
         vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                   "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                   "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        
         function<string(int)> helper = [&](int num) -> string {
            if (num == 0) return "";
            else if (num < 20) return below_20[num] + " ";
            else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
            else return below_20[num / 100] + " Hundred " + helper(num % 100);
        };
        
        string result;
        int index = 0;
        
         while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + thousands[index] + " " + result;
            }
            num /= 1000;
            index++;
        }
        
         while (!result.empty() && result.back() == ' ') result.pop_back();
        
        return result;
    }
};