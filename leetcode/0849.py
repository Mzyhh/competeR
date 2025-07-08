from math import ceil


class Solution(object):
    def maxDistToClosest(self, seats):
        first, maxd, cur, start = 0, 0, 0, 0
        for i in range(len(seats)):
            if not seats[i]: first += 1
            else: 
                start = i
                break
        for i in range(start, len(seats)):
            if seats[i]:
                maxd = max(maxd, cur)
                cur = 0
            else:
                cur += 1
        return max(first, int(ceil(maxd / 2.0)), cur)
