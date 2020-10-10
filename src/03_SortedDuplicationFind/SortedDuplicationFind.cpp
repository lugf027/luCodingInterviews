/********************************************
* SortedDuplicationFind.cpp                              *
* Created by lugf027 on 2020/10/10.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include "SortedDuplicationFind.h"
#include <iostream>

bool SortedDuplicationFind::find(int *matrix, int rows, int columns, int number) {
    bool found = false;

    if (matrix != nullptr && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;
        while (row < rows && columns >= 0) {
            if (matrix[row * columns + column] == number) {
                found = true;
                break;
            } else if (matrix[row * columns + column] > number) {
                --column;
            } else {
                ++row;
            }
        }
    }

    return found;
}

void SortedDuplicationFind::Test() {
    int aArr[16] = {1, 2, 8, 9,
                    2, 4, 9, 12,
                    4, 7, 10, 13,
                    6, 8, 11, 15,};
    bool aF0 = find(aArr, 4, 4, 5);
    bool aF1 = find(aArr, 4, 4, 7);
    std::cout << "aF0 expected: 0; return: " << aF0 << std::endl;
    std::cout << "aF1 expected: 1; return: " << aF1 << std::endl;

}
