class Solution(object):
    def isPalindrome(self, x):
        s = str(x)
        return s == s[::-1]

    def isPalindrome2(self, x):
        if x < 0:
            return False
        new, old = 0, x
        while x:
            x, d = divmod(x, 10)
            new = 10*new + d
        return new == old
