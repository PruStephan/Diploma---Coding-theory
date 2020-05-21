//
// Created by Степан Прудников on 12/05/2020.
//

#include "permutations.h"

int permut_compl(matrix &a) {
    vector<int> cols(a[0].size());
    int res = 1000000;
    for(size_t i = 0 ; i < cols.size(); i++)
    {
        cols[i] = i;
    }
    long iter = 0;
    bool flag = false;
    while(!flag) {
        cout << iter << endl;
        iter++;
        flag = true;
        for(int i = cols.size() - 2; i >= 0; --i)
        {
            if(cols[i] < cols[i + 1]){
                int min = i + 1;
                for(size_t j = i + 1; j < cols.size(); j++) {
                    if(cols[j] < cols[min] && cols[j] > cols[i]){
                        min = j;
                    }
                }
                swap(cols[i], cols[min]);
                a.swap_bytes(i, min);
                reverse(cols.begin() + i + 1, cols.end());
                a.reverse(i + 1, cols.size() - 1);
                flag = false;
                auto b = toSpanForm(a);
                auto cmp = calculateComplexity(b);
                if(*max_element(cmp.begin(), cmp.end()) < res) {
                    cout << "found" << endl << endl;
                    cout << b.print() << endl;
                    res = *max_element(cmp.begin(), cmp.end());
                }
            }
        }
    }
    return res;
}

bool next_permut(matrix &a, vector<int> &cols)
{
    size_t n = cols.size();
    size_t j = n - 2;
    while(j != -1 && cols[j] >= cols[j + 1]) j--;
    if(j == -1)
        return false;
    int k = n - 1;
    while(cols[j] >= cols[k]) k--;
    swap(cols[j], cols[k]);
    a.swap_bytes(j, k);
    int l = j + 1, r = n - 1;
    while(l < r) {
        swap(cols[l], cols[r]);
        a.swap_bytes(l, r);
        l++;
        r--;
    }
    return true;
}


bool next_permut_with_n(int n, vector<int> &permut)
{
    size_t k = permut.size() - 1;
    int j = k;
    while(permut[j] == n + j - k)
    {
        j--;
        if(j == -1)
            break;
    }
    if(j == -1)
        return false;
    else {
        permut[j]++;
        for(int i = j; i < k; i++)
            permut[i + 1] = permut[i] + 1;
    }

    cout <<  "(";
    for(size_t i = 0; i < permut.size() - 1; i++)
    {
        cout <<permut[i] << ", ";
    }
    cout << permut.back() << ")" << endl;

    return true;
}


int permut_compl2(matrix &a) {
    vector<int> cols(a[0].size());
    auto cmp = calculateComplexity(a);
    int res = *std::max_element(cmp.begin(), cmp.end());

    for(size_t i = 0 ; i < cols.size(); i++)
    {
        cols[i] = i;
    }
    unsigned long long iter = 0;
    while(next_permut(a, cols)){
        //cout << iter << endl;
        //iter++;
        auto b = toSpanForm(a);
        cmp = calculateComplexity(b);
        if(*max_element(cmp.begin(), cmp.end()) < res) {
            cout << "found" << endl << endl;
            cout << b.print() << endl;
            res = *max_element(cmp.begin(), cmp.end());
        }
    }
    return res;
}


pair<int, matrix> permut_first_half(matrix &a)
{
    vector<int> cols(a[0].size() / 2);
    auto cmp = a.count_good_rows();
    int res_cmp = cmp.size();
    matrix res_matrix = a;

    for(size_t i = 0 ; i < cols.size(); i++)
    {
        cols[i] = i + 1;
    }
    unsigned long long iter = 0;

    while(next_permut_with_n(a[0].size(), cols))
    {
        iter++;
        cout << iter << endl;
        matrix b = a;
        for(size_t i = 0; i < cols.size(); i++)
        {
            for(size_t j = 0; j < a.cols.size(); j++)
            {
                if(b.cols[j] == cols[i])
                    b.move(i, j);
            }
        }
        b = toSpanForm(b);
        //cout << b.print() << endl;
        cmp = b.count_good_rows();
        if(cmp.size() > res_cmp) {
            cout << "found" << endl << endl;
            cout << b.print() << endl;
            res_cmp = cmp.size();
            res_matrix = b;
        }
    }
    return make_pair(res_cmp, res_matrix);
}

pair<int, matrix> permut_with_recursion(matrix &a, int border)
{
    vector<int> cols(border);
    auto good_rows = a.count_good_rows();
    auto cmp = calculateComplexity(a);
    int res_good = good_rows.size();
    matrix res_matrix = a;
    matrix b;
    matrix c;

    for(size_t i = 0 ; i < cols.size(); i++)
    {
        cols[i] = i + 1;
    }
    unsigned long long iter = 0;

    while(next_permut_with_n(a[0].size(), cols))
    {
        iter++;
        cout << iter << endl;
        b = a;
        for(size_t i = 0; i < cols.size(); i++)
        {
            for(size_t j = 0; j < a.cols.size(); j++)
            {
                if(b.cols[j] == cols[i])
                    b.move(i, j);
            }
        }
        c = b;
        b = toSpanForm(b);
        good_rows = b.count_good_rows();
        if(good_rows.size() < res_good) {
            continue;
        }
        auto cur_cmp = calculateComplexity(b);
        if(compare_complexity(cmp, cur_cmp) == 1) {
            cout << "found" << endl << endl;
            cout << b.print() << endl;
            res_good = good_rows.size();
            res_matrix = b;
            cmp = cur_cmp;
        }
    }
    a.reset_rows();
    cols.resize(0);
    for(int i = 0; i < (border / 2); i++) {
        cols.push_back(i + 1);
    }
    while(next_permut_with_n(border, cols))
    {
        iter++;
        cout << iter << endl;
        b = a;
        for(size_t i = 0; i < cols.size(); i++)
        {
            for(size_t j = 0; j < a.cols.size(); j++)
            {
                if(b.cols[j] == cols[i])
                    b.move(i, j);
            }
        }
        c = b;
        b = toSpanForm(b);
        good_rows = b.count_good_rows();
        if(good_rows.size() < res_good) {
            continue;
        }
        auto cur_cmp = calculateComplexity(b);
        if(compare_complexity(cmp, cur_cmp) == 1) {
            cout << "found" << endl << endl;
            cout << b.print() << endl;
            res_good = good_rows.size();
            res_matrix = b;
            cmp = cur_cmp;
        }
    }

    a.reset_rows();
    cols.resize(0);
    for(int i = 0; i < border / 2; i++) {
        cols.push_back(i + border + 1);
    }
    while(next_permut_with_n(a[0].size(), cols))
    {
        iter++;
        cout << iter << endl;
        b = a;
        for(size_t i = 0; i < cols.size(); i++)
        {
            for(size_t j = 0; j < a.cols.size(); j++)
            {
                if(b.cols[j] == cols[i])
                    b.move(i, j);
            }
        }
        c = b;
        b = toSpanForm(b);
        good_rows = b.count_good_rows();
        if(good_rows.size() < res_good) {
            continue;
        }
        auto cur_cmp = calculateComplexity(b);
        if(compare_complexity(cmp, cur_cmp) == 1) {
            cout << "found" << endl << endl;
            cout << b.print() << endl;
            res_good = good_rows.size();
            res_matrix = b;
            cmp = cur_cmp;
        }
    }

    cout << c.print() << endl;
    return make_pair(res_good, res_matrix);
}



