#pragma once
#include "percolation.h"
#include <vector>

class PercolationStats{
    private:
        // size of the sides
        int N;
        // total number of trials
        int T;
        
        double mean_val = 0;
        double stddev_val = 0;
        double confidenceLow_val = 0, confidenceHigh_val = 0;

        std::vector<double> thresholds;

        void computeStats();


        double computeThreshold(Percolation percolation);
    public:
        PercolationStats(int n, int trials);
        double mean();
        double stddev();
        double confidenceLow();
        double confidenceHigh();
};
