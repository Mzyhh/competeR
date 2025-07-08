class Solution(object):
    def isValid(self, s):
        if len(s) % 2 == 1: return False
        map = {")": "(", "}" : "{", "]" : "["}
        stack = []
        for c in s:
            if c in "({[":
                stack.append(c)
            elif stack == [] or stack[-1] != map[c]:
                return False
            else:
                stack.pop()
        return len(stack) == 0
