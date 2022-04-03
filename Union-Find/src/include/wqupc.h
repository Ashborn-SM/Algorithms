#pragma once
#include <vector>

class WeightedQuickUnionPC{
    private:
        std::vector<int> parent, size;

    public:
        WeightedQuickUnionPC(int n);

        int root(int p);
        bool connected(int p, int q);
        void join(int p, int q);
};
