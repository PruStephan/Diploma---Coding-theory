//
// Created by Степан Прудников on 11/04/2020.
//

#include "matrix.h"

binary_array& matrix::operator[](const int &i) {
    return rows[i];
}

size_t matrix::size() {
    return rows.size();
}

vector<binary_array>::iterator matrix::begin() {
    return rows.begin();
}

vector<binary_array>::iterator matrix::end(){
    return rows.end();
}

string matrix::print()
{
    //cout << "H = [";
    string res;
    for(int i = 0; i < rows.size(); i++)
    {
        res += rows[i].print();
    }
    //cout << "]";
    return res;
}

void matrix::swap_bytes(int i, int j) {
    for(auto &a : this->rows)
    {
        a.swap_bytes(i, j);
    }
}

int matrix::count_ones(int i) {
    int counter = 0;
    for(int j = 0; j < this->rows.size(); j ++ )
        if(this->rows[j][i])
            counter++;
    return counter;
}

void matrix::reverse(int x, int y) {
    for(int i = x, j = y; i <= j; ++i, --j)
    {
        this->swap_bytes(i, j);
    }
}

