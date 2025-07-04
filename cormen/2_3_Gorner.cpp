#include <iostream>
#include <vector>

#include "common.h"


using polynome = std::vector<double>;

/**
 * Calculate value of polynome in `x` using Gorner algorithm.
 *
 * Time complexity: O(n) (theta of n).
 * Memory complexity: O(1).
 * 
 * @param p Const reference to polynome (vector of doubles).
 * @param x Point in which polynome is calculated.
 * @return calculated value.
 */
double gorner(const polynome& p, const double x) {
    double y = 0;
    for (int i = p.size() - 1; i >= 0; --i)
        y = p[i] + x * y;
    return y;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Using: " << argv[0] << " a[0] a[1] ... a[n] x\n";
        return -1;
    } 
    int n = argc - 2;
    polynome arr = cad(argv + 1, n);
    double value = atof(argv[argc - 1]);
    std::cout << "Result is " << gorner(arr, value) << ".\n";
    return 0;
}
