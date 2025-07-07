class Solution(object):
    def foo(self, opens, closes, n):
        if closes == n:
            return [""]
        l, r = [], []
        if opens < n:
            l = self.foo(opens + 1, closes, n)
            l = ["(" + c for c in l]
        if closes < opens:
            r = self.foo(opens, closes + 1, n)
            r = [")" + c for c in r]
        return l + r
    def generateParenthesis(self, n):
        return self.foo(0, 0, n)
