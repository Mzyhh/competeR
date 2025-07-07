class RandomizedSet(object):

    def __init__(self):
        import random
        self.rand = random.choice
        self.map = {}
        self.arr = []


    def insert(self, val):
        if val in self.map:
            return False
        self.arr.append(val)
        self.map[val] = len(self.arr) - 1
        return True

        

    def remove(self, val):
        if val not in self.map:
            return False
        i = self.map[val] 
        self.arr[-1], self.arr[i] = self.arr[i], self.arr[-1]
        self.map[self.arr[i]] = i
        self.arr.pop()
        del self.map[val]
        return True
        

    def getRandom(self):
        return self.rand(self.arr)
