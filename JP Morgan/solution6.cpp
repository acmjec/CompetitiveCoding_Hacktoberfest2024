#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumOfSquares(n);
        }
        return n == 1;
    }

private:
    int sumOfSquares(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    int test1 = 19;
    std::cout << "Is " << test1 << " a happy number? " << (solution.isHappy(test1) ? "true" : "false") << std::endl;

    int test2 = 2;
    std::cout << "Is " << test2 << " a happy number? " << (solution.isHappy(test2) ? "true" : "false") << std::endl;

    return 0;
}
