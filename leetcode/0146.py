class Node(object):

    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

class List(object):

    def __init__(self, head=None):
        self.head = head
        self.tail = head
        self.len = 0 if head is None else 1
    
    def pop_back(self):
        self.tail = self.tail.prev
        if self.tail is None:
            self.head = None
        else:
            self.tail.next = None
        self.len -= 1

    def pop(self, node):
        if self.head == node:
            self.head = node.next
        if self.tail == node:
            self.tail = node.prev
        if node.prev is not None:
            node.prev.next = node.next
        if node.next is not None:
            node.next.prev = node.prev
        self.len -= 1

    
    def push_front(self, val):
        new_node = Node(val, prev=None, next=self.head)
        if self.head is not None:
            self.head.prev = new_node
        else:
            self.tail = new_node
        self.head = new_node
        self.len += 1

class LRUCache(object):

    def __init__(self, capacity):
        self.cache = List()
        self.cap = capacity
        self.pos = {}
        

    def get(self, key):
        if key not in self.pos:
            return -1
        node = self.pos[key]
        _, val = node.val
        self.cache.pop(node)
        self.cache.push_front((key, val))
        self.pos[key] = self.cache.head
        return val
        

    def put(self, key, value):
        if key in self.pos:
            self.get(key)
            self.cache.head.val = (key, value)
            return
        if self.cache.len == self.cap:
            del_key, _ = self.cache.tail.val
            self.cache.pop_back()
            del self.pos[del_key]
        self.cache.push_front((key, value))
        self.pos[key] = self.cache.head
