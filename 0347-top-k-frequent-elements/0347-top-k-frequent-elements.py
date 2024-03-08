class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = [[] for i in range(len(nums) + 1)]
        freq = {}
        result = []
        
        for n in nums:
            freq[n] = 1 + freq.get(n, 0)
        
        for n, v in freq.items():
            count[v].append(n)
        
        for i in range(len(nums), 0, -1):
            for c in count[i]:
                result.append(c)
                
                if len(result) == k:
                    return result
        
        return result