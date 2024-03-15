class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if nums[0] <= nums[-1]:  return nums[0]
        l, r = 0, n - 1
        while l<r:
            mid = l + (r - l) // 2
            if l == mid:
                return min(nums[l], nums[r])
            if nums[l] > nums[mid]:
                r = mid
            else:
                l = mid