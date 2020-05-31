//
// Created by Степан Прудников on 08/05/2020.
//

#include "diviser.h"


void sort_by_cols(matrix &a, int l, int r) {
    int v = (l + r) / 2;
    if(r <= l)
        return;
    int i = l, j = r - 1, p = l -1, q = r;
    while(i <= j) {
        while (a.count_ones(i) < a.count_ones(v)) i++;
        while (a.count_ones(j) > a.count_ones(v)) j--;
        if (i >= j)
            break;
        a.swap_bytes(i, j);
        if (a.count_ones(i) == a.count_ones(v)) {
            p++;
            a.swap_bytes(p, i);
        }
        i++;
        if (a.count_ones(j) == a.count_ones(v)) {
            q--;
            a.swap_bytes(q, j);
        }
        j--;
    }
    a.swap_bytes(i, r);
    j = i - 1;
    i++;
    for(int k = l; k <= p; k++, j--)
        a.swap_bytes(k, j);
    for(int k = r - 1; k >= q; k--, i++)
        a.swap_bytes(k, i);
    sort_by_cols(a, l, j);
    sort_by_cols(a, i, r);
}

bool smart_plus(matrix a, int x, int y){
    int counter = 0;
    int next_counter = 0;
    for(int i = 0; i < a[0].size(); i++)
    {
        if(a[x][i] && a[y][i])
            next_counter++;
        if(a[x][i] && !a[y][i])
            next_counter--;
        if(a[y][i])
            counter++;
    }

    return counter > next_counter;
}

void smart_col_swap(matrix &a) {
    bool flag = false;
    int iter = 0;
    vector<int> cmp = calculateComplexity(a);
    while(!flag && iter < 10000) {
        flag = true;
        vector<int> old_cmp = cmp;
        for(size_t i = 0; i < a.size(); i++) {
            int last = a[i].findLast1();
            if(last == - 1)
                continue;
            int from_swap = -1;
            int to_swap = -1;
            int first = a[i].findFirst1();
            for(int j = last; j > first; --j) {
                if(a[i][j] != 1)
                    continue;
                int min = 0;
                for (size_t k = a.size() - 1; k > i; k--) {
                    int cur_first = a[k].findFirst1();
                    if(cur_first == -1)
                        continue;
                    if(cur_first > j)
                        continue;
                    if (a[k][last] != 0 && cur_first > min)
                        min = a[k].findFirst1();
                }

                for (int k = j - 1; k >= first && k >= min; --k) {
                    if( k == -1)
                        break;
                    bool found = true;
                    if (a[i][k] == 0) {
                        for(int l = i - 1; l >= 0; --l){
                            if(a[l][k] == 1) {
                                found = false;
                                break;
                            }
                        }
                        if(found) {
                            from_swap = j;
                            to_swap = k;
                            //flag = false;
                        }
                    }
                }
            }
            if(to_swap != -1 && from_swap != -1)
                a.swap_bytes(to_swap, from_swap);
            //cout << i << endl;
            //cout << a.print() << endl;

        }
        a = toSpanForm(a);
        cmp = calculateComplexity(a);
        for(size_t i = 0; i < cmp.size(); i++) {
            if(cmp[i] != old_cmp[i])
            {
                flag = false;
                break;
            }
        }
        iter++;
        cout << iter << endl;
    }
}

void swap_to_halves(matrix &a) {
    set<int> good_rows = a.count_good_rows();
    bool flag = false;
    int iter = 0;
    while(!flag && iter < 2000) {
        iter++;
        cout << iter << endl;
        flag = true;
        matrix b = a;
        for(int i = 0; i < a[0].size() - 1; ++i)
        {
            for(int j = i + 1; j < a[0].size(); ++j) {
                b.swap_bytes(i, j);
                b = toSpanForm(b);
                if (b.count_good_rows().size() > good_rows.size()) {
                    a = b;
                    good_rows = b.count_good_rows();
                    flag = false;
                }
            }
        }
    }
}

void swap_in_halves(matrix &a) {
    vector<int> cmp = calculateComplexity(a);
    int border = a[0].size() / 2 - 1;
    bool flag = false;
    int iter = 0;
    while(!flag && iter < 20000) {
        iter++;
        cout << iter << endl;
        flag = true;
        matrix b = a;
        auto old_cmp = cmp;
        for (int i = 0; i < border - 1; i++) {
            for (int j = i + 1; j < border; j++) {
                b.swap_bytes(i, j);
                b = toSpanForm(b);
                auto b_cmp = calculateComplexity(b);
                if(compare_complexity(b_cmp, cmp) == -1)
                {
                    a = b;
                    flag = false;
                    cmp = b_cmp;
                    break;
                }
            }
        }
        for(size_t i = 0; i < cmp.size(); i++) {
            if(cmp[i] != old_cmp[i])
            {
                flag = false;
                break;
            }
        }
    }
    flag = false;
    iter = 0;
    cout << "started second half" << endl;
    while(!flag && iter < 20000) {
        iter++;
        cout << iter << endl;
        flag = true;
        matrix b = a;
        auto old_cmp = cmp;
        for (int i = border; i < a[0].size() - 1; i++) {
            for (int j = i + 1; j < a[0].size(); j++) {
                b.swap_bytes(i, j);
                b = toSpanForm(b);
                auto b_cmp = calculateComplexity(b);
                if(compare_complexity(b_cmp, cmp) == -1)
                {
                    a = b;
                    flag = false;
                    cmp = b_cmp;
                    break;
                }
            }
            for(size_t i = 0; i < cmp.size(); i++) {
                if(cmp[i] != old_cmp[i])
                {
                    flag = false;
                    break;
                }
            }
        }
    }
}

