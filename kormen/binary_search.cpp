#include <iostream>
#include <optional>

#include "common.h"


/**
 * Find index of value in array.
 *
 * Container should have sorted element between `left` and `right`.
 *
 * @param a Container in which we trying to find value. a[left:right] should be sorted.
 * @param left Index of first element in sequence.
 * @param right Length of sequence.
 * @param value Target value.
 * @return index of first entry of value in container `a` or std::nullopt if there is no such value.
 */
template <typename V>
std::optional<int> binary_search(const V* const a, const int left, const int right, const V value) {
    if (left > right) return std::nullopt;
    int mid = (left + right) / 2;
    if (a[mid] == value) return mid;
    if (value < a[mid]) return binary_search(a, left, mid - 1, value);
    return binary_search(a, mid + 1, right, value);
}


int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Using: " << argv[0] << " a[0] a[1] ... a[n-1] value\n";
        return -1;
    } 
    int n = argc - 2;
    int *arr = cai(argv + 1, argc - 1);
    int value = arr[argc - 2];
    auto index = binary_search(arr, 0, n, value);
    if (index.has_value())
        std::cout << "Value: " << value << " is found on " << index.value() << "th position\n";
    else
        std::cout << "Value: " << value << " not found.\n";
    return 0;
}
