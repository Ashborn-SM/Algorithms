#include "include/percolation_stats.h"
#include <iostream>
#include <iomanip>

int main(){
    int n = 200;
    int t = 100;
    PercolationStats p(n, t);
    std::cout << "Mean: " << std::setprecision(5) << p.mean() << std::endl;
    std::cout << "Stddev: " << std::setprecision(5) << p.stddev() << std::endl;
    std::cout << "Confidence: " << std::setprecision(5) << "[ " << p.confidenceLow()
              << ", " << p.confidenceHigh()<< " ]"<< std::endl;
}
