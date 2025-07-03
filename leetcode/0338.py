class Solution(object):
    # O(n*lg(n)) solution
    # def countBits(self, n):
    #     res = []
    #     for i in range(n + 1):
    #         count = 0
    #         while i:
    #             i, d = divmod(i, 2)
    #             if d:
    #                 count += 1
    #         res += [count]
    #     return res
    # def countBits(self, n):
    #     return [bin(i)[2:].count('1') for i in range(n + 1)]

    # O(n) solution using dynamic approach
    def countBits(self, n):
        res = [0]
        curpow = 1
        for i in range(1, n + 1):
            if i >= 2 * curpow:
                curpow *= 2
            res += [1 + res[i - curpow]]
        return res
