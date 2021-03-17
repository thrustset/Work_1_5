#include <iostream>
#include "point.hpp"
#include "curve.hpp"

int main() {
    int n1 = 3;
    auto *array1 = new Point[n1];
    for(int i = 0; i < n1; i++)
        array1[i] = Point('A' + i, i, i);

    int n2 = 3;
    auto *array2 = new Point[n2];
    for(int i = 0; i < n2; i++)
        array2[i] = Point('A' + i, n1 + i, n1 + i);

    auto curve1 = Curve('1', n1, array1);
    auto curve2 = Curve('2', n2, array2);

    delete [] array1;
    delete [] array2;

    auto curve3 = curve1 + curve2 + Point('0', n1 + n2, n1 + n2);
    curve3.setName('3');

    std::cout << curve1 << curve2 << curve3;

    return 0;
}
