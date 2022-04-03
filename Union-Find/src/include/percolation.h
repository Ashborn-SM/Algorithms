#pragma once
#include <vector>
#include "wqupc.h"


class Percolation{
    private:
        std::vector<bool> open_sites;
        WeightedQuickUnionPC wqupc;
        
        // number of open sites
        int n_open_sites = 0;
        // number of sites present
        int n_sites;
        // size of the sides
        int n;

        void validate(int row, int col);
        int row_col_to_site(int row, int col);
        void link_adjacent_sites(int row, int col);

    public:
        Percolation(int n);
        void open(int row, int col);
        bool is_open(int row, int col);
        bool is_open(int site);
        bool is_full(int row, int col);
        int number_of_open_sites();
        bool percolates();

};
