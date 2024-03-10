class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        l, r = 0, n - 1
        max_amount = -1
        
        while l<r:
            area = (r-l) * min(height[l], height[r])
            max_amount = max(max_amount, area)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        
        return max_amount