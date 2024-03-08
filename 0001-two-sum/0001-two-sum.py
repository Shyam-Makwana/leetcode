class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        freq = {}
        for i in range(len(nums)):
            exp = target - nums[i]
            if exp in freq:
                return [freq[exp], i]
            freq[nums[i]] = i
        