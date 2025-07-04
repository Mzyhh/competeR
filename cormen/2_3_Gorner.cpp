#include <iostream>
#include <vector>
#include <chrono>

#include "common.h"

/**
 * Polynome has a following view:
 *  v[0] + x*v[1] + x**2 * v[2] + ... + x**n * v[n], where n = v.size() - 1
 */
using polynome = std::vector<double>;

/**
 * Calculate value of polynome in `x` using inductive approach.
 *
 * Time complexity: O(n) (theta of n).
 * Memory complexity: O(1).
 * 
 * @param p Const reference to polynome (vector of doubles).
 * @param x Point in which polynome is calculated.
 * @return calculated value.
 */
long double calculate(const polynome& p, const double x) {
    long double pow_x  = 1,
           result = 0;
    for (int i = 0; i < p.size(); ++i) {
        result += pow_x * p[i];
        pow_x *= x;
    }

    return result;
}

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
long double gorner(const polynome& p, const double x) {
    long double y = 0;
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
    std::chrono::steady_clock::time_point begin, end;
    
    begin = std::chrono::steady_clock::now();
    long double result1 = gorner(arr, value);
    end = std::chrono::steady_clock::now();
    std::cout << "Gorner time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;

    begin = std::chrono::steady_clock::now();
    long double result2 = calculate(arr, value);
    end = std::chrono::steady_clock::now();
    std::cout << "Inductive time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << std::endl;

    if (result1 != result2)
        std::cout << "Hmmm... Results are different.\n" << result1 << " vs " << result2 << "\n";
    else
        std::cout << "Result is " << result1 << ".\n";
    return 0;
}
