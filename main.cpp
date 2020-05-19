#include "permutations/permutations.h"
#include <chrono>
#include <fstream>


using namespace std;


int main() {

    srand(static_cast<unsigned int>(time(nullptr)));


    string out_filepath = "matrix";

    vector<binary_array> test_array = {binary_array(387, 9, 0),
                                       binary_array(781, 9, 1),
                                       binary_array(246, 9, 2),
                                       binary_array(136, 9, 3),
                                       binary_array(70, 9, 4)};

    //matrix A = create_bch_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/bch.txt");
    matrix A = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix.txt");
//    matrix B = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix2.txt");
//    matrix C = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix3.txt");
//    matrix D = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix4.txt");
    vector<matrix> test;
    test.push_back(A);


    //matrix A(test_array);
    //A = random_shuffle(A);
    //A = toSpanForm(A);

    for(int i = 0; i < test.size(); i++)
    {
        ofstream out(out_filepath + to_string(i) + ".txt");
        try {


            cout << test[i].print() << endl;
            auto res = permut_with_recursion(A);

            out << res.second.print() << endl;

            vector<int> complexity = calculateComplexity(res.second);
            out << "(";
            for (size_t i = 0; i < complexity.size() - 1; i++) {
                out << complexity[i] << ", ";
            }

            out << complexity.back() << ")" << endl;
        } catch (...)
        {
            out << "Error";
        }
    }


/*
    auto start = std::chrono::high_resolution_clock::now();
    matrix B = toSpanForm(A);
    auto finish = std::chrono::high_resolution_clock::now();
*/
    return 0;
}

