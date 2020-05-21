//
// Created by Степан Прудников on 11/04/2020.
//

#include <iostream>
#include <vector>
#include <string>

class binary_array {
private:
    unsigned long long array;
    int actual_size;
    int row;
public:
    bool operator[](const unsigned int& k);
    binary_array operator+(const binary_array& other);
    binary_array operator+=(const binary_array& other);


    explicit binary_array(unsigned long long a, int size, int row);
    explicit binary_array() : array(0), actual_size(0), row(0) {};
    binary_array(std::vector<int> a, int row);

    int getRow() {
        return row;
    }

    void setRow(int row) {
        this->row = row;
    }

    int size();
    bool checkIfTwo();
    int findFirst1();
    int findLast1();
    std::string print();
    void swap_bytes(unsigned int i, unsigned int j);
};