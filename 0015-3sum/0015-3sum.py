class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        ans = set()
        i = 0
        n = len(nums)
        while i < n - 2:
            j, k = i + 1, n - 1
            while j<k:
                total = nums[i] + nums[j] + nums[k]
                if total == 0:
                    ans.add((nums[i], nums[j], nums[k]))
                    j, k = j + 1, k - 1
                elif total > 0:
                    k -= 1
                else:
                    j += 1
            i += 1
        result = []
        for triplets in ans:
            result.append(triplets)
        return result