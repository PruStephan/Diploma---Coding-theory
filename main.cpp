#include "permutations/permutations.h"
#include <chrono>
#include <fstream>


using namespace std;


int main() {

    srand(static_cast<unsigned int>(time(nullptr)));


    string out_filepath = "matrix_result";

    vector<binary_array> test_array = {binary_array(387, 9, 0),
                                       binary_array(781, 9, 1),
                                       binary_array(246, 9, 2),
                                       binary_array(136, 9, 3),
                                       binary_array(70, 9, 4)};



//    matrix A = load_matrix("/home/prustephan/Diploma-half/Diploma---Coding-theory/matrix.txt");
//    matrix B = load_matrix("/home/prustephan/Diploma-half/Diploma---Coding-theory/matrix2.txt");
//    matrix C = load_matrix("/home/prustephan/Diploma-half/Diploma---Coding-theory/matrix3.txt");
//    matrix D = load_matrix("/home/prustephan/Diploma-half/Diploma---Coding-theory/matrix4.txt");


    matrix A = create_bch_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/bch.txt");
    //matrix A = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix4.txt");
//    matrix B = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix2.txt");
//    matrix C = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix3.txt");
//    matrix D = load_matrix("/Users/stephan/CLionProjects/DiplomaLongLong/matrix4.txt");
    vector<matrix> test;
    test.push_back(A);
    //smart_col_swap(A);
    swap_in_halves(A);


    //matrix A(test_array);
    //A = random_shuffle(A);
    //A = toSpanForm(A);

    cout << A.print() << endl;

    matrix E = toSpanForm(A);


    double border = rand() % 6  +  10;


//    for(int i = 0; i < test.size(); i++)
//    {
//        ofstream out(out_filepath + to_string(i) + ".txt");
//        try {
//
//
//            cout << test[i].print() << endl;
//            auto res = permut_with_recursion(test[i]);
//
//            matrix cur = res.second;
//            swap_in_halves(cur);
//            smart_col_swap(cur);
//
//            out << cur.print() << endl;
//
//            vector<int> complexity = calculateComplexity(res.second);
//            out << "(";
//            for (size_t i = 0; i < complexity.size() - 1; i++) {
//                out << complexity[i] << ", ";
//            }
//
//            out << complexity.back() << ")" << endl;
//        } catch (...)
//        {
//            out << "Error";
//        }
//    }

    vector<int> complexity = calculateComplexity(E);
    cout << "(";
    for (size_t i = 0; i < complexity.size() - 1; i++) {
        cout << complexity[i] << ", ";
    }

    cout << complexity.back() << ")" << endl;


/*
    auto start = std::chrono::high_resolution_clock::now();
    matrix B = toSpanForm(A);
    auto finish = std::chrono::high_resolution_clock::now();
*/
    return 0;
}

