from collections import defaultdict


class Solution(object):
    def groupAnagrams1(self, strs):
        ans = defaultdict(list)
        for s in strs:
            k = "".join(sorted(s))
            ans[k].append(s)
        return list(ans.values()) 

    def groupAnagrams2(self, strs):
        ans = defaultdict(list)
        for s in strs:
            hash_arr = [0] * 26
            for c in s:
                hash_arr[ord(c) - ord('a')] += 1
            ans[tuple(hash_arr)].append(s)
        return ans.values()
