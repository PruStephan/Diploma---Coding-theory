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
    while(!flag && iter < 1000000) {
        flag = true;
        for(size_t i = 0; i < a.size(); i++) {
            int last = a[i].findLast1();
            if(last == - 1)
                continue;
            int from_swap = -1;
            int to_swap = -1;
            int first = a[i].findFirst1();
            for(int j = last; j > first; --j) {
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
                            flag = false;
                        }
                    }
                }
            }
            if(to_swap != -1 && from_swap != -1)
                a.swap_bytes(to_swap, from_swap);
            cout << i << endl;
            //cout << a.print() << endl;

        }
        a = toSpanForm(a);
        iter++;
        cout << iter << endl;
    }
}




matrix diviser3(matrix a) {
    a.swap_bytes(16, 15);
    cout << a.print() << endl;
    a.swap_bytes(12, 13);
    cout << a.print() << endl;
    a.swap_bytes(13, 14);
    cout << a.print() << endl;
    a.swap_bytes(14, 15);
    cout << a.print() << endl;
    a.swap_bytes(16, 17);
    cout << a.print() << endl;
    a.swap_bytes(17, 18);
    cout << a.print() << endl;
    a.swap_bytes(21, 22);
    cout << a.print() << endl;
    return a;
}


