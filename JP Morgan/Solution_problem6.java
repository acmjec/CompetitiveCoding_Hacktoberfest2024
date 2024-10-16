

class Solution_problem6 {

    // Method to determine if a number is a happy number
    public static boolean isHappy(int n) {

        // Initialize two variables: slow (s) and fast (f), both starting with n
        int s = n;
        int f = n;

        // Loop to move slow (s) by one step and fast (f) by two steps
        // Continues until they meet (indicating a cycle) or we find the number equals 1.
        do {
            s = sqr(s);         
            f = sqr(sqr(f));    
        } while (s != f);       

        // If slow equals 1, the number is happy, return true
        return s == 1;
    }

    // Helper method to calculate the sum of squares of digits of a number
    public static int sqr(int num) {
        int ans = 0;
        while (num > 0) {
            int remainder = num % 10;  // Get the last digit
            ans += remainder * remainder; // Square the digit and add it to the answer
            num /= 10;  // Remove the last digit from the number
        }

        return ans; 
    }

    // Main method to test the isHappy method
    public static void main(String[] args) {

        // Test with input 19, which is a happy number
        int test1 = 19;
        System.out.println("Is " + test1 + " a happy number? " + isHappy(test1));

        // Test with input 2, which is not a happy number
        int test2 = 2;
        System.out.println("Is " + test2 + " a happy number? " + isHappy(test2));
    }
}
