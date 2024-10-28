import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        // HashMap to store the array values and their indices
        HashMap<Integer, Integer> mp = new HashMap<>();
        
        int n = nums.length;
        
        // Iterating over the array
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i]; // Calculate the complement needed to reach the target
            
            // Check if the complement is already in the HashMap
            if (mp.containsKey(complement)) {
                // If found, return the indices of the complement and the current element
                return new int[]{mp.get(complement), i};
            }
            
            // If complement not found, add the current number and its index to the HashMap
            mp.put(nums[i], i);
        }
        
        // Return a default value if no solution is found 
        return new int[]{0, 0};
    }
}
