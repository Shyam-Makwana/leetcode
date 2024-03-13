class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        parentheses = {'(': ')', '{': '}', '[': ']'}
        for c in s:
            if c in parentheses:
                stack.append(parentheses[c])
            elif not stack or stack.pop() != c:
                return False
                
        return not stack
        