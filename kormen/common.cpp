#include <vector>
#include <cstdlib>

#include "common.h"

int* cai(char *argv[], int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = atoi(argv[i]);
    return arr;
}

std::vector<double> cad(char *argv[], int n) {
    std::vector<double> arr(n, 0);
    for (int i = 0; i < n; ++i)
        arr[i] = atof(argv[i]);
    return arr;
}

