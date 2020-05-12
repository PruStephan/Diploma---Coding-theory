#include "permutations/permuatations.h"
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
    int res = permut_compl2(A);
    cout << "result: " << res << endl;

//    complexity = calculateComplexity(A);
//    cout <<  "(";
//    for(size_t i = 0; i < complexity.size() - 1; i++)
//    {
//        cout <<complexity[i] << ", ";
//    }
//    cout << complexity.back() << ")" << endl;
//

/*
    auto start = std::chrono::high_resolution_clock::now();
    matrix B = toSpanForm(A);
    auto finish = std::chrono::high_resolution_clock::now();
*/
    return 0;
}

