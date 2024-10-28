class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)     #len of the array
        nums.sort()     #sorting the array for using two pointer      
        ans=[]

        for i in range(n-2):
            if i>0 and nums[i-1]==nums[i]:continue      #skiping duplicates
            
            #first element would be nums[i]

            left=i+1            #pointer for second element
            right=n-1           #pointer for third element

            while left<right:

                triplet=nums[left]+ nums[right]+ nums[i]

                if triplet ==0:           #if a triplet is found

                    ans.append([nums[i],nums[left],nums[right]])

                    #Skiping the duplicates
                    while left<right and nums[left]==nums[left+1]:left+=1     
                    while left<right and nums[right]==nums[right-1]:right-=1

                    #checking for other
                    left+=1
                    right-=1

                elif triplet < 0:     #if current sum is less moving to bigger num
                    left+=1
                else:
                    right-=1        #if current sum is greater moving to lesser num
        
        return ans
