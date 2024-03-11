class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        index = {}
        l = 0
        max_len = 0
        for r in range(len(s)):
            if s[r] not in index:
                max_len = max(max_len, r - l + 1)
                index[s[r]] = r
            else:
                l = max(l, 1 + index[s[r]])
                max_len = max(max_len, r - l + 1)
                index[s[r]] = r
        return max_len