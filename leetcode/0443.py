class Solution(object):
    def compress(self, chars):
        length = 0
        prev = chars[0]
        group_cnt = 1
        for c in chars[1:] + ['\0']:
            if c == prev:
                group_cnt += 1
            else:
                chars[length] = prev
                delta = 1
                if group_cnt != 1:
                    delta += len(str(group_cnt))
                    chars[length + 1 : length + delta] = list(str(group_cnt))
                length += delta
                group_cnt = 1
            prev = c
        return length
