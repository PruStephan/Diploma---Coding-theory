//
// Created by Степан Прудников on 11/04/2020.
//


#include "binary_array.h"


binary_array::binary_array(unsigned long long a, int size, int row) : array(a), actual_size(size), row(row) {}

binary_array::binary_array(std::vector<int> a, int row) {
    this->row = row;
    this->actual_size = a.size();
    unsigned long long new_array = 0;
    for(int j = 0; j < 32; j++){

        new_array = new_array + (1u << j) * a[j];
    }
    this->array = new_array;
}


binary_array binary_array::operator+(const binary_array &other) {

    int size = std::max(this->actual_size, other.actual_size);
    return binary_array(this->array ^ other.array, size, this->row);
}

binary_array binary_array::operator+=(const binary_array &other) {
    return *this + other;
}

bool binary_array::operator[](const unsigned int &k) {
    unsigned int index = k % actual_size;
    return (this->array & (1u << index)) >> index;
}

std::string binary_array::print()
{
    std::string res;
    for(unsigned int i = 0; i < actual_size; i++)
    {
        res +=  std::to_string((this->array & (1u << i)) >> i);
        res += " ";
    }
    res+= "\n";
    return res;
}

int binary_array::size() {
    return actual_size;
}

bool binary_array::checkIfTwo() {
    int count = 0;
    for(unsigned int i = 0; i < actual_size; i++) {
        if((this->array & (1u << i)) != 0)
            count++;
        if(count > 2)
            return true;
    }
    return false;
}

int binary_array::findFirst1() {
    for(int i = 0; i < actual_size; i++) {
        if((this->array & (1u << i)) != 0)
        {
            return i;
        }
    }
    return -1;
}

int binary_array::findLast1() {
    for(int i = actual_size - 1; i >= 0; i--)
    {
        if((this->array & (1u << i)) != 0)
            return i;
    }
    return -1;
}

void binary_array::swap_bytes(unsigned int i, unsigned int j) {
    if(i >= actual_size || j >= actual_size)
        throw "i or j is greater than actual size";
    unsigned int tmp = (this->array & (1u << i)) >> i;
    unsigned int jth = (this->array & (1u << j)) >> j;
    this->array ^= (-jth ^ this->array) & (1UL << i);
    this->array ^= (-tmp ^ this->array) & (1u << j);
}