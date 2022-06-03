class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
            int l = 0, r = nums.size() - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (nums[mid] == target) return mid;

               	//left sorted portion
                else if (nums[l] <= nums[mid])
                {
                    if (nums[mid] < target || nums[l] > target) l = mid + 1;
                    else r = mid - 1;
                }

               	//right sorted portion
                else
                {
                    if (nums[mid] > target || nums[r] < target) r = mid - 1;
                    else l = mid + 1;
                }
            }
            return -1;
        }
};