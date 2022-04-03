#include "include/percolation.h"
#include <iostream>

Percolation::Percolation(int n): n(n), n_sites(n*n), wqupc(n*n+2){
    open_sites.assign(n_sites+1, false);
}

void Percolation::validate(int row, int col){
    if(row > n || col > n || row < 0 || col < 0){
       std::cerr << "\nInvalid element index. Values for rows and cols must be between " <<
			"1 and " << n << '\n' << std::endl;
       std::cout << row << " " << col << std::endl;
		exit(EXIT_FAILURE); 
    }
}

int Percolation::row_col_to_site(int row, int col){
    return n*(row - 1) + col;
}

bool Percolation::is_open(int row, int col){
    validate(row, col);
    return open_sites[row_col_to_site(row, col)];
}

bool Percolation::is_open(int site){
    return open_sites[site];
}

int Percolation::number_of_open_sites(){
    return n_open_sites;
}

bool Percolation::percolates(){
    return wqupc.connected(0, n_sites+1);
}

void Percolation::open(int row, int col){
    validate(row, col);
    if(!is_open(row, col)){
        link_adjacent_sites(row, col);
        open_sites[row_col_to_site(row, col)] = true;
        n_open_sites++;
    }
}

void Percolation::link_adjacent_sites(int row, int col){
    validate(row, col);

    int cur_site = row_col_to_site(row, col);

    if(row != 1 && row !=n && col != n && col != 1){

        int top_site = row_col_to_site(row-1, col);
        int bottom_site = row_col_to_site(row+1, col);
        int left_site = row_col_to_site(row, col-1);
        int right_site = row_col_to_site(row, col+1);

        if(is_open(top_site)){
            wqupc.join(top_site, cur_site); 
        }
        if(is_open(bottom_site)){
            wqupc.join(bottom_site, cur_site); 
        }
        if(is_open(left_site)){
            wqupc.join(left_site, cur_site); 
        }
        if(is_open(right_site)){
            wqupc.join(right_site, cur_site); 
        }

    }

    else if(row == 1){

        wqupc.join(cur_site, 0);

        int bottom_site = row_col_to_site(row+1, col);
        int right_site = row_col_to_site(row, col+1);
        int left_site = row_col_to_site(row, col-1);

        if(is_open(bottom_site)){
            wqupc.join(cur_site, bottom_site);
        }
        if(col != n){
            if(is_open(right_site)){
                wqupc.join(cur_site, right_site);
            }
        }
        if(col != 1){
            if(is_open(left_site)){
                wqupc.join(cur_site, left_site);
            }
        }
    }

    else if(row == n){

        wqupc.join(cur_site, n_sites + 1);

        int top_site = row_col_to_site(row-1, col);
        int right_site = row_col_to_site(row, col+1);
        int left_site = row_col_to_site(row, col-1);

        if(is_open(top_site)){
            wqupc.join(cur_site, top_site);
        }
        if(col != n){
            if(is_open(right_site)){
                wqupc.join(cur_site, right_site);
            }
        }
        if(col != 1){
            if(is_open(left_site)){
                wqupc.join(cur_site, left_site);
            }
        }
    }

    else{

        int top_site = row_col_to_site(row-1, col);
        int bottom_site = row_col_to_site(row+1, col);
        int right_site = row_col_to_site(row, col+1);
        int left_site = row_col_to_site(row, col-1);

        if(is_open(top_site)){
            wqupc.join(cur_site, top_site);
        }
        if(is_open(bottom_site)){
            wqupc.join(cur_site, bottom_site);
        }
        if(col == 1){
            if(is_open(right_site)){
                wqupc.join(cur_site, right_site);
            }
        }
        if(col == n){
            if(is_open(left_site)){
                wqupc.join(cur_site, left_site);
            }
        }
    }
}
