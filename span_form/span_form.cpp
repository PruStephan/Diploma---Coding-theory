//
// Created by Степан Прудников on 11/04/2020.
//


#include "span_form.h"
#include <deque>
#include <fstream>

matrix toSpanForm(matrix m)
{
    int k = m.size();
    vector<int> start(k);

    vector<int> rows;
    for(int i = 0; i < m.size(); i++){
        m[i].setRow(i);
        rows.push_back(m[i].getRow());
    }

    for(int i = 0; i < k; i++)
    {
        start[i] = m[i].findFirst1();
        if(start[i] != -1)
        {
            for(int j = i + 1; j < k; j++)
            {
                if(m[j][start[i]]) {
                    int row = m[j].getRow();
                    m[j] = m[j] + m[i];
                    m[j].setRow(row);
                }
            }
        }
        //cout << m.print() << endl;
    }
    sort(m.begin(), m.end(), [=]( binary_array& a,  binary_array&b)->bool {
        return start[a.getRow()] < start[b.getRow()];
    });
    //cout << m.print() << endl;


    for(int i = k - 1; i >= 0; i--)
    {
        int last = m[i].findLast1();
        if(last != -1) {
            for (int j = i - 1; j >= 0; j--)
                if (m[j][last])
                    m[j] = m[j] + m[i];
        }
    }
    return m;
}

vector<int> calculateComplexity(matrix m) {
    vector<int> result(m[0].size());
    for(int i = 0; i < m.size(); i++)
    {
        int x = m[i].findFirst1(), y = m[i].findLast1() - 1;
        if(x == -1)
            continue;
        for(; x <= y; x++) {
            result[x]++;
        }
    }

    return result;
}

matrix random_shuffle(matrix A) {
    for(size_t k = 0; k < 1; k++)
    {
        int i = rand() % A[0].size();
        int j = rand() % A[0].size();
        for(auto & l : A)
        {
            l.swap_bytes(i, j);
        }
    }
    return A;
}


int compare_complexity(vector<int> c1, vector<int> c2)
{
    for (int i = 0; i < c1.size(); i++)
    {
        if(c2[i] > c1[i])
            return -1;
    }
    return 1;
}

std::pair<matrix, vector<int>> get_random_complexity(matrix A) {
    //matrix span = toSpanFrm(A);
    A = toSpanForm(A);
    vector<int> comp_compl = calculateComplexity(A);
    vector<int> res_compl = comp_compl;
    matrix res_matrix = A;
    for(int i = 0; i < 1000000; i++)
    {
        cout << i << endl;
        A = random_shuffle(A);
        A = toSpanForm(A);
        //cout << A.print() << endl;
        vector<int> cur_compl = calculateComplexity(A);
        if(*std::max_element(cur_compl.begin(), cur_compl.end()) < *std::max_element(res_compl.begin(), res_compl.end())) {
            res_compl = cur_compl;
            res_matrix = A;
        }
    }
    return make_pair(res_matrix, res_compl);

}



matrix create_bch_matrix(const string& filepath){
    ifstream in(filepath);
    vector<int> d;
    while(!in.eof())
    {
        int x;
        in >> x;
        d.push_back(x);
    }

    int prefix = 0;
    int suffix = 31 - d.size();
    vector<binary_array> m;
    while (prefix + d.size() <= 31)
    {
        vector<int> cur_pref(prefix, 0);
        vector<int> cur_suff(suffix, 0);

        vector<int> cur = cur_pref;
        cur.insert(cur.end(), d.begin(), d.end());
        cur.insert(cur.end(), cur_suff.begin(), cur_suff.end());
        m.push_back(binary_array(cur, prefix));
        prefix++;
        suffix--;
    }
    return matrix(m);
}

matrix load_matrix(string filepath)
{
    ifstream in(filepath);
    vector<int> d;
    string cur;
    vector<int> line;
    vector<binary_array> ba;
    int i = 0;
    while(getline(in, cur))
    {
        for(char c : cur) {
            if (c == 48)
                line.push_back(0);
            else if(c == 49)
                line.push_back(1);
        }
        ba.push_back(binary_array(line, i));
        line.resize(0);
        ++i;
    }
    return matrix(ba);
}