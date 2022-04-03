#include "include/percolation_stats.h"

#include <random>
#include <numeric>
#include <math.h>
#include <iostream>

PercolationStats::PercolationStats(int n, int trails): N(n), T(trails){
    computeStats();
}

void PercolationStats::computeStats(){
    double threshold;
    for(int i=0; i<T; i++){
        Percolation percolation(N);
        threshold = computeThreshold(percolation);
        thresholds.push_back(threshold);
    }

    mean_val = std::accumulate(thresholds.begin(), thresholds.end(), (double)0)/T; 

    // stddev
    for(int i=0; i<thresholds.size(); i++){
        stddev_val += pow(thresholds[i] - mean_val, 2);
    }
    stddev_val = stddev_val/(T-1);

    // confidence
    confidenceLow_val = mean_val - 1.96*stddev_val/pow(T, 1/2);
    confidenceHigh_val = mean_val + 1.96*stddev_val/pow(T, 1/2);
}

double PercolationStats::computeThreshold(Percolation percolation){
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distributions(1, N); 

    int open_sites;

    while(!percolation.percolates()){
        int p = distributions(eng);
        int q = distributions(eng);
        percolation.open(p, q);
        open_sites = percolation.number_of_open_sites();
    }
    return (double)open_sites/(N*N);
}

double PercolationStats::mean(){
    return mean_val;
}

double PercolationStats::stddev(){
    return stddev_val;
}
double PercolationStats::confidenceLow(){
    return confidenceLow_val;
}
double PercolationStats::confidenceHigh(){
    return confidenceHigh_val;
}
