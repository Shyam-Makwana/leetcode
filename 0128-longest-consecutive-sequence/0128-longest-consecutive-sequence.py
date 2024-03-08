class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hash_map = {}
        for n in nums:
            hash_map[n] = 1
        
        ans = 0
        for n in nums:
            if n-1 not in hash_map:
                length = 1
                while n + length in hash_map:
                    length += 1
                
                ans = max(ans, length)
        
        return ans
        