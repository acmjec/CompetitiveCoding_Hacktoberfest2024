class Solution:
    def isHappy(self, n: int) -> bool:
        def func(n):
            curr_sum=0
            while n!=0:
                curr_sum=curr_sum+((n%10)**2)
                n=n//10
            return curr_sum
        s1=set()
        while n!=1 and n not in s1:
            s1.add(n)
            n=func(n)
        if n==1:
            return True
        else:
            return False
            