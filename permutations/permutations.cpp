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
        cout << iter << endl;
        iter++;
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


