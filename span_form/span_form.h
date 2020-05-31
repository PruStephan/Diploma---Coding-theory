//
// Created by Степан Прудников on 11/04/2020.
//

#include "../matrix/matrix.h"


matrix toSpanForm(matrix m);
vector<int> calculateComplexity(matrix m);
matrix random_shuffle(matrix A);
int compare_complexity(vector<int> c1, vector<int> c2);
matrix create_bch_matrix(const string& filepath, int code_size, int k);
std::pair<matrix, vector<int>> get_random_complexity(matrix A);
matrix load_matrix(string filepath);
pair<vector<int>, vector<int>> max_cmp_cols(vector<int> cmp);
