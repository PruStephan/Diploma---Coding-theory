//
// Created by Степан Прудников on 11/04/2020.
//

#include "../matrix/matrix.h"


matrix toSpanForm(matrix m);
vector<int> calculateComplexity(matrix m);
matrix random_shuffle(matrix A);
matrix create_bch_matrix(const string& filepath);
std::pair<matrix, vector<int>> get_random_complexity(matrix A);
matrix load_matrix(string filepath);