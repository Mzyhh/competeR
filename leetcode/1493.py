class Solution(object):
    def longestSubarray(self, nums):
        m = last = curr = 0
        shift = 1
        for i in range(len(nums)):
            if nums[i] == 1:
                curr += 1
            else:
                m = max(m, last + curr)
                last = curr
                curr = 0
                shift = 0
        return max(m, last + curr) - shift
