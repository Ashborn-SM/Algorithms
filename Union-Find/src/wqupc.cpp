#include "include/wqupc.h"

WeightedQuickUnionPC::WeightedQuickUnionPC(int n){
    parent.reserve(n);
    for(int i=0; i<n; i++){
        parent.push_back(i);
    }
    size.assign(n, 1);
};

int WeightedQuickUnionPC::root(int p){
    int i = p, current = p;

    // Finding the root
    while(i != parent[i]){
        i = parent[i];
    }
    
    // Path Compression
    while(parent[current] != i){
        int temp = parent[current];
        parent[current] = i;
        current = temp;
    }

    return i;
}

bool WeightedQuickUnionPC::connected(int p, int q){
    return root(p) == root(q);
}

void WeightedQuickUnionPC::join(int p, int q){
    int root_p = root(p); 
    int root_q = root(q); 
    if(root_p == root_q){
        return;
    }

    // q tree joins p tree
    else if(size[root_p] > size[root_q]){
        parent[root_q] = root_p;
        size[root_p] += root_q;
    }

    // p tree joins q tree
    else{
        parent[root_p] = root_q;
        size[root_q] += root_p;
    }
}
