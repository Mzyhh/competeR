class Solution(object):
    def isPalindrome(self, s):
        c = ''.join(c.lower() for c in s if c.isalnum())
        return c == c[::-1]
