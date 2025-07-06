class Solution(object):
    def moveZeroes(self, nums):
        top = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[top], nums[i] = nums[i], nums[top]
                top += 1
