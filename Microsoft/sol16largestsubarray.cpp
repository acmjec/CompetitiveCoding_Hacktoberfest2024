#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> prefixSumMap;
        int sum = 0, maxLength = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (sum == 0) {
                maxLength = i + 1;
            } 
            else if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[sum]);
            } 
            else {
                prefixSumMap[sum] = i;
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution solution;
    
    // Change the initialization of the vector
    vector<int> arr;
    arr.push_back(15);
    arr.push_back(-2);
    arr.push_back(2);
    arr.push_back(-8);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(23);
    
    int n = arr.size();
    int length = solution.maxLen(arr, n);
    
    cout << "Length of largest subarray with sum 0: " << length << endl;
    return 0;
}
