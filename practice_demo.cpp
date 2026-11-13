class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        current = self.head
        while current.next:
            current = current.next

        current.next = new_node

    def search(self, key):
        current = self.head
        position = 1

        while current is not None:
            if current.data == key:
                print("Element found at position", position)
                return

            current = current.next
            position += 1

        print("Element not found")


ll = LinkedList()

n = int(input("Enter number of nodes: "))

for i in range(n):
    value = int(input("Enter element: "))
    ll.insert(value)

key = int(input("Enter element to search: "))
ll.search(key)