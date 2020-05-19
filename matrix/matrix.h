//
// Created by Степан Прудников on 11/04/2020.
//
#pragma once
#include "../binary_array/binary_array.h"
#include <algorithm>
#include <set>



using namespace std;

class matrix {
private:
    vector<binary_array> rows;
public:
    vector<int> cols;
    binary_array& operator[](const int& i);
    size_t size();
    vector<binary_array>::iterator begin();
    vector<binary_array>::iterator end();

    explicit matrix(vector<binary_array> a) {
        rows = a;
        cols = vector<int>(a[0].size(), 0);
        for(size_t i = 0; i < cols.size(); i++) {
            cols[i] = i + 1;
        }
    }

    string print();
    void swap_bytes(int i, int j);
    void reverse(int x, int y);
    void move(int to, int from);
    void reset_rows();
    int count_ones(int i);
    set<int> count_good_rows();
};