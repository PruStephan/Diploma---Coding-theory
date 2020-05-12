//
// Created by Степан Прудников on 11/04/2020.
//
#pragma once
#include "../binary_array/binary_array.h"

using namespace std;

class matrix {
private:
    vector<binary_array> rows;
public:
    binary_array& operator[](const int& i);
    size_t size();
    vector<binary_array>::iterator begin();
    vector<binary_array>::iterator end();

    explicit matrix(vector<binary_array> a) : rows(a) {}

    string print();
    void swap_bytes(int i, int j);
    void reverse(int x, int y);
    int count_ones(int i);
};