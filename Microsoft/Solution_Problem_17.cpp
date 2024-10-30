#include <iostream>
#include <vector>
using namespace std;

vector<int> increment(vector<int>& arr) {
    int n = arr.size();  // Get the size of the array

    // Traverse the array from the last digit to the first
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] < 9) {       // If the current digit is less than 9
            arr[i] += 1;        // Increment the digit by 1
            return arr;         // Return the result as no further carry is needed
        }
        arr[i] = 0;             // If digit is 9, set it to 0 and carry over to the next digit
    }

    // If all digits were 9, we need to add an extra 1 at the beginning
    arr.insert(arr.begin(), 1);
    return arr;
}


int main() {
   
    vector<int> arr = {9, 9, 9};

    
    vector<int> result1 = increment(arr);
    for (int digit : result1) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}