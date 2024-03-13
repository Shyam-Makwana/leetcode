class Solution:
    def findMaxChar(self, freq: dict) -> int:
        maxx = 0
        for k, v in freq.items():
            maxx = max(maxx, v)
        return maxx
    
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        result = 0
        l, r = 0, 0
        while r < len(s):
            freq[s[r]] = 1 + freq.get(s[r], 0)
            maxx = self.findMaxChar(freq)
            if ((r-l+1) - maxx) <= k:
                result = max(result, r-l+1)
                r += 1
            else:
                freq[s[l]]-=1
                l+=1
                r+=1
        return result
        