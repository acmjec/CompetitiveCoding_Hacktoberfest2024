#include <iostream>
#include <vector>
#include <string>
#include <functional>  // Add this to use std::function

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        // Numbers below 20, the tens multiples, and the thousand units
        vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                   "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                   "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        // Lambda helper function for converting numbers below 1000
        function<string(int)> helper = [&](int num) -> string {
            if (num == 0) return "";
            else if (num < 20) return below_20[num] + " ";
            else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
            else return below_20[num / 100] + " Hundred " + helper(num % 100);
        };

        string result;
        int index = 0;

        // Breaking the number into groups of thousands
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + thousands[index] + " " + result;
            }
            num /= 1000;
            index++;
        }

        // Trim the trailing space
        while (!result.empty() && result.back() == ' ') result.pop_back();

        return result;
    }
};

int main() {
    Solution solution;
    int num;

    cout << "Enter a number: ";
    cin >> num;
    
    string words = solution.numberToWords(num);
    cout << "Number in words: " << words << endl;

    return 0;
}
