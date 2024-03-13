class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        parentheses = {'(': ')', '{': '}', '[': ']'}
        for c in s:
            if c in ['(', '{', '[']:
                stack.append(parentheses[c])
            else:
                if not stack:
                    return False
                paren = stack.pop()
                if paren != c:
                    return False
                
        return not stack
        