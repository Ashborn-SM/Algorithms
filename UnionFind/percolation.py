from wquf import WeightQuickUF


class Percolation:
    def __init__(self, n):
        self.size = n * n
        self.n = n
        self.n_open_sites = 0

        self.open_sites = [0 for i in range(self.size + 2)]
        self.open_sites[0] = 1
        self.open_sites[self.size + 1] = 1

        self.wquf = WeightQuickUF(self.size + 2)

    def rowColToSite(self, row, col):
        return 1 + (row - 1) * self.n + (col - 1)

    def isPercolates(self):
        return self.wquf.isConnected(0, self.size + 1)

    def isOpen(self, row, col):
        site = self.rowColToSite(row, col)
        return self.open_sites[site]

    def connectAdjacentSites(self, row, col):
        site = self.rowColToSite(row, col)

        if (row == self.n):

            self.wquf.connect(site, self.size + 1)

            if (col != 1):
                if (self.isOpen(row, col - 1)):
                    self.wquf.connect(site, self.rowColToSite(row, col - 1))

            if (col != self.n):
                if (self.isOpen(row, col + 1)):
                    self.wquf.connect(site, self.rowColToSite(row, col + 1))

            if (self.isOpen(row - 1, col)):
                self.wquf.connect(site, self.rowColToSite(row - 1, col))

        elif (row == 1):

            self.wquf.connect(site, 0)

            if (col != 1):
                if (self.isOpen(row, col - 1)):
                    self.wquf.connect(site, self.rowColToSite(row, col - 1))

            if (col != self.n):
                if (self.isOpen(row, col + 1)):
                    self.wquf.connect(site, self.rowColToSite(row, col + 1))

            if (self.isOpen(row + 1, col)):
                self.wquf.connect(site, self.rowColToSite(row + 1, col))

        elif (row != 1 and row != self.n and col != 1 and col != self.n):

            if (self.isOpen(row - 1, col)):
                self.wquf.connect(site, self.rowColToSite(row - 1, col))

            if (self.isOpen(row + 1, col)):
                self.wquf.connect(site, self.rowColToSite(row + 1, col))

            if (self.isOpen(row, col - 1)):
                self.wquf.connect(site, self.rowColToSite(row, col - 1))

            if (self.isOpen(row, col + 1)):
                self.wquf.connect(site, self.rowColToSite(row, col + 1))

        else:
            if (col == 1):

                if (self.isOpen(row - 1, col)):
                    self.wquf.connect(site, self.rowColToSite(row - 1, col))

                if (self.isOpen(row + 1, col)):
                    self.wquf.connect(site, self.rowColToSite(row + 1, col))

                if (self.isOpen(row, col + 1)):
                    self.wquf.connect(site, self.rowColToSite(row, col + 1))

            if (col == self.n):

                if (self.isOpen(row - 1, col)):
                    self.wquf.connect(site, self.rowColToSite(row - 1, col))

                if (self.isOpen(row + 1, col)):
                    self.wquf.connect(site, self.rowColToSite(row + 1, col))

                if (self.isOpen(row, col - 1)):
                    self.wquf.connect(site, self.rowColToSite(row, col - 1))

    def open(self, row, col):
        site = self.rowColToSite(row, col)
        if (not self.isOpen(row, col)):
            self.open_sites[site] = 1
            self.n_open_sites += 1
            self.connectAdjacentSites(row, col)

    def print_array(self):
        self.wquf.print_array()
        i = 1
        while (i != self.size + 1):
            print(self.open_sites[i], end=" ")
            if (i % (self.n) == 0):
                print()
            i += 1
        print()
