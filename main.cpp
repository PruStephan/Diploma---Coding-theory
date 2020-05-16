#include "permutations/permutations.h"
#include <chrono>


using namespace std;


int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    vector<binary_array> test_array = {binary_array(387, 9, 0),
                                       binary_array(781, 9, 1),
                                       binary_array(246, 9, 2),
                                       binary_array(136, 9, 3),
                                       binary_array(70, 9, 4)};

    //matrix A = create_bch_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/bch.txt");
    matrix A = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix.txt");
    //matrix A(test_array);

    cout << A.print() << endl;
    //cout << A.count_good_rows().size() << endl;

    auto res = permut_first_half(A);
    cout << res.first << endl;
    cout << res.second.print() << endl;
    //A.swap_bytes(10, 16);
    //swap_to_halves(A);
    //cout << A.count_good_rows().size() << endl;
    //smart_col_swap(A);
    vector<int> complexity = calculateComplexity(A);
    cout <<  "(";
    for(size_t i = 0; i < complexity.size() - 1; i++)
    {
        cout <<complexity[i] << ", ";
    }
    cout << complexity.back() << ")" << endl;

   // cout << A.print() <<endl;
//    pair<int, matrix> res = permut_first_half(A);
//    cout << A.print() <<endl;
//    cout << res.first << endl;
//    cout << res.second.print() << endl;
//    int res = permut_compl2(A);
//    cout << "result: " << res << endl;
/*
    auto start = std::chrono::high_resolution_clock::now();
    matrix B = toSpanForm(A);
    auto finish = std::chrono::high_resolution_clock::now();
*/
    return 0;
}

