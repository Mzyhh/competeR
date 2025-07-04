class Solution(object):
    def findMaxAverage(self, nums, k):
        maximum = curr = sum(nums[:k])
        for i in range(1, len(nums) - k + 1):
            curr += nums[i + k - 1] - nums[i - 1]
            maximum = max(curr, maximum)
        return maximum / float(k)
