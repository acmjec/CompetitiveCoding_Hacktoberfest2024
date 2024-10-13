# Problem: Valid Parentheses

## Problem Description
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true


 Constraints
- 	1 <= s.length <= 104
-	s consists of parentheses only '()[]{}'.

SOLUTION

Language- C++


class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';

        for (char c : s) {
            if (map.count(c) == 0) {
                // It's an opening bracket
                stack.push(c);
            } else {
                // It's a closing bracket
                if (stack.empty() || stack.top() != map[c]) {
                    return false; // Mismatched or extra closing bracket
                }
                stack.pop(); // Valid match found
            }
        }

        return stack.empty(); // Return true if all opening brackets are matched
    }
};


