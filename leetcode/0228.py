class Solution(object):
    def summaryRanges(self, nums):
        res = []
        nums += [float('inf')]
        start = nums[0]
        for i in range(1, len(nums)):
            if nums[i] - 1 != nums[i - 1]:
                if nums[i - 1] == start:
                    res += [str(start)]
                else:
                    res += [str(start) + "->" + str(nums[i - 1])]
                start = nums[i]
        return res
