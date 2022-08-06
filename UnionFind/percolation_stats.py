from percolation import Percolation
from random import randint
from math import pow, sqrt


class Stats:
    def __init__(self, n, trials):
        self.n = n
        self.trials = trials

        self.mean = 0
        self.stddev = 0
        self.confidence_interval = []

    def run(self):
        threshold = []
        for i in range(self.trials):
            percolation = Percolation(self.n)
            while (not percolation.isPercolates()):
                row = randint(1, self.n)
                col = randint(1, self.n)
                percolation.open(row, col)
            threshold.append(percolation.n_open_sites / pow(self.n, 2))

        self.compute_mean(threshold)
        self.compute_stddev(threshold)
        self.compute_confidence_interval()

    def compute_mean(self, threshold):
        for i in range(self.trials):
            self.mean += threshold[i] / self.trials

    def compute_stddev(self, threshold):
        for i in range(self.trials):
            self.stddev += pow(threshold[i] - self.mean, 2) / (self.trials - 1)

    def compute_confidence_interval(self):
        a = self.mean - (1.95 * sqrt(self.stddev)) / sqrt(self.trials)
        b = self.mean + (1.95 * sqrt(self.stddev)) / sqrt(self.trials)
        self.confidence_interval.append(a)
        self.confidence_interval.append(b)

    def print_stats(self):
        print(f"Mean: {self.mean}")
        print(f"Stddev: {self.stddev}")
        print(
            f"Confidence Interval: [{self.confidence_interval[0]}, {self.confidence_interval[1]}]"
        )
