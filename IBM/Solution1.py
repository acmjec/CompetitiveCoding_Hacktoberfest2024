class Solution:
    def isValid(self, s: str) -> bool:
        # Map to identify diff parentheses and if its open or close
        mp={"(":1,")":-1,"{":2,"}":-2,"[":3,"]":-3}

        #stack to maintain validity of the string
        stack=[]

        #iterating over the string
        for ch in s:
                      
            if mp[ch]<0 and stack and mp[stack[-1]]+mp[ch]==0:  #checking if its valid

                stack.pop()

            else:
                stack.append(ch)        #if its a opening bracket

        return False if len(stack) else True
