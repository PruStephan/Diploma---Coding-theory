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

    for(int i = 0; i < rows[0].size(); i++) {

    }

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

void matrix::move(int to, int from) {
    if (to > rows[0].size() || to < 0) {
        cout << "to is out of bonds: " << to << endl;
        throw "0";
    }

    if (from > rows[0].size() || from < 0) {
        cout << "from is out of bonds: " << from << endl;
        throw "0";
    }

    if(to < from)
    {
        for(int i = from; i > to; --i)
        {
            this->swap_bytes(i, i - 1);
            swap(this->cols[i], this->cols[i - 1]);
        }
    } else {
        for(int i = from; i < to; ++i)
        {
            this->swap_bytes(i, i + 1);
            swap(this->cols[i], this->cols[i + 1]);
        }
    }
}

set<int> matrix::count_good_rows() {
    set<int> res;
    for(size_t i = 0; i < rows.size(); ++i){
        if(rows[i].findFirst1() > rows[0].size() / 2 - 1  || rows[i].findLast1() <= rows[0].size() / 2)
            res.insert(i);
    }
    return res;
}


void matrix::reset_rows() {
    cols = vector<int>(this->rows[0].size(), 0);
    for(size_t i = 0; i < cols.size(); i++) {
        cols[i] = i + 1;
    }
}