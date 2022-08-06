class WeightQuickUF:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def __root(self, i):
        while (i != self.parent[i]):
            i = self.parent[i]
        return i

    def isConnected(self, x, y):
        return self.__root(x) == self.__root(y)

    def connect(self, x, y):
        root_x = self.__root(x)
        root_y = self.__root(y)

        if (root_x == root_y):
            return

        if (self.size[root_x] > self.size[root_y]):
            self.parent[root_y] = root_x
            self.size[root_x] += self.size[root_y]
        else:
            self.parent[root_x] = root_y
            self.size[root_y] += self.size[root_x]

    def print_array(self):
        import math
        print(self.parent[0])
        i = 1
        size = len(self.parent) - 2
        n = math.sqrt(size)
        while (i != size + 1):
            print(self.parent[i], end=" ")
            if (i % (n) == 0):
                print()
            i += 1
        print(self.parent[size + 1])
        print()
