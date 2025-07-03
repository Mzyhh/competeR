class Solution(object):
    def numUniqueEmails(self, emails):
        unique = set()
        for e in emails:
            local_name, domain = e.split('@')
            local_name = local_name.split('+')[0].replace('.', '')
            unique.add(local_name + '@' + domain)
        return len(unique)
