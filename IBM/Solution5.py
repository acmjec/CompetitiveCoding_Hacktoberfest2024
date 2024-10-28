class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        x,y=m-1,n-1         #pointers for nums1 and nums2
        i=m+n-1             #pointer to update value in nums1

        while x>-1 and y>-1:

            if nums1[x]<nums2[y]:       #if nums2[y] is greater we place it at ith index
                nums1[i]=nums2[y]
                y-=1
            else:
                nums1[i]=nums1[x]       #else we place nums1[x]
                x-=1 
            i-=1                        
        while y>-1:                     #if nums2 has more elements left
            nums1[i]=nums2[y]
            y-=1
            i-=1