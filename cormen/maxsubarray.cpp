#include <iostream>
#include <tuple>
#include <limits.h>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;
using lli = long long int;

#ifndef P
#define P 1
#endif


/**
 * Find contiguous subarray consisting array[`mid`] with maximum sum.
 *
 * @param array Data.
 * @param low Index of first element of target array.
 * @param mid Index of middle element that should be in resulting subarray.
 * @param high Index of last element of target array.
 * @return tuple: (i, j, sum) where array[i..j] (inclusive) is the resulting
 * subarray.
 *
 * Time complexity: O(n).
 * Space complexity: O(1).
 */
tuple<size_t, size_t, lli> find_max_cross_subarray(const vector<int>& array,
                        const size_t low, const size_t mid, const size_t high){
    lli left_sum = LONG_LONG_MIN, right_sum = LONG_LONG_MIN;
    size_t max_left, max_right;
    for (lli i = mid, sum = 0; i >= (lli)low; --i) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    for (lli i = mid + 1, sum = 0; i <= (lli)high; ++i) {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    return {max_left, max_right, left_sum + right_sum};
}


/**
 * Find contiguous subarray with the largest sum, using divide and conquer
 * algorithm.
 *
 * @param array Data.
 * @param low Index of first element of target array.
 * @param high Index of last element of target array.
 * @return tuple: (i, j, sum) where array[i..j] (inclusive) is the resulting
 * subarray.
 *
 * Time complexity: O(n*log(n)).
 * Space complexity: O(log(n)).
 */
tuple<size_t, size_t, lli> find_max_subarray(const vector<int>& array,
                                const size_t low, const size_t high){
    if (low == high) return {low, high, array[low]};
    size_t mid = int((low + high) / 2);
    auto [l1, r1, s1] = find_max_subarray(array, low, mid);
    auto [l2, r2, s2] = find_max_subarray(array, mid + 1, high);
    auto [l3, r3, s3] = find_max_cross_subarray(array, low, mid, high);
    if (s1 >= s2 && s1 >= s3) return {l1, r1, s1};
    if (s2 >= s3 && s2 >= s1) return {l2, r2, s2};
    return {l3, r3, s3};
}


/**
 * Find contiguous subarray with the largest sum, using brutforce algorithm.
 *
 * @param array Data.
 * @param low Index of first element of target array.
 * @param high Index of last element of target array.
 * @return tuple: (i, j, sum) where array[i..j] (inclusive) is the resulting
 * subarray.
 *
 * Time complexity: O(n^2).
 * Space complexity: O(1).
 */
tuple<size_t, size_t, lli> brutforce_max_subarray(const vector<int>& array,
                                const size_t low, const size_t high) {
    size_t max_left, max_right;
    lli max_sum = LONG_LONG_MIN;
    for (int size = 1; size <= high - low + 1; ++size) {
        lli sum = accumulate(array.begin() + low, array.begin() + low + size, 0);
        for (int i = low + 1; 1; ++i) {
            if (sum > max_sum) {
                max_sum = sum;
                max_left = i - 1;
                max_right = i + size - 2;
            }
            if (i + size > high + 1) break;
            sum += array[i + size - 1] - array[i - 1];
        } 
    }
    return {max_left, max_right, max_sum};
}

#ifdef N
/**
 * Find contiguous subarray with the largest sum, using combination
 * of divide&conquer and brutforce algorithms.
 *
 * N (macro-defined) is the maximum length of array that is given
 * to brutforce algorithm. Depends on machine and architecture.
 *
 * @param array Data.
 * @param low Index of first element of target array.
 * @param high Index of last element of target array.
 * @return tuple: (i, j, sum) where array[i..j] (inclusive) is the resulting
 * subarray.
 *
 * Time complexity: O(n*log(n)).
 * Space complexity: O(log(n)).
 */
tuple<size_t, size_t, lli> find_max_subarray_imp(const vector<int>& array,
                                const size_t low, const size_t high){
    if (high - low + 1 <= N) 
        return brutforce_max_subarray(array, low, high);
    size_t mid = int((low + high) / 2);
    auto [l1, r1, s1] = find_max_subarray(array, low, mid);
    auto [l2, r2, s2] = find_max_subarray(array, mid + 1, high);
    auto [l3, r3, s3] = find_max_cross_subarray(array, low, mid, high);
    if (s1 >= s2 && s1 >= s3) return {l1, r1, s1};
    if (s2 >= s3 && s2 >= s1) return {l2, r2, s2};
    return {l3, r3, s3};
}
#endif


/**
 * Find contiguous subarray with the largest sum, using Kadane algorithm.
 *
 * @param array Data.
 * @param low Index of first element of target array.
 * @param high Index of last element of target array.
 * @return tuple: (i, j, sum) where array[i..j] (inclusive) is the resulting
 * subarray.
 *
 * Time complexity: O(n).
 * Space complexity: O(1).
 */
tuple<size_t, size_t, lli> find_max_subarray_kadane(const vector<int>& array,
                                const size_t low, const size_t high) {
    lli cur_sum = 0, best_sum = 0;
    size_t cur_first = 0, cur_last = 0,
           first = 0, last = 0;
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] >= cur_sum + array[i]) {
            cur_first = i;
            cur_sum = array[i];
        } else {
            cur_sum += array[i];
        }
        cur_last = i;
        if (cur_sum > best_sum) {
            best_sum = cur_sum;
            first = cur_first, last = cur_last;
        }
    }
    return {first, last, best_sum};
}


int main(int argc, char* argv[]) {
    size_t n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    lli t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    for (int _ = 0; _ < P; ++_) {
        auto begin_t = chrono::steady_clock::now();
        auto [l, r, s] = brutforce_max_subarray(a, 0, a.size() - 1);
        auto end_t = chrono::steady_clock::now();
        t1 += chrono::duration_cast<chrono::nanoseconds>(end_t - begin_t).count();

        begin_t = chrono::steady_clock::now();
        auto [l2, r2, s2] = find_max_subarray(a, 0, a.size() - 1);
        end_t = chrono::steady_clock::now();
        t2 += chrono::duration_cast<chrono::nanoseconds>(end_t - begin_t).count();

        #ifdef N
        begin_t = chrono::steady_clock::now();
        auto [l3, r3, s3] = find_max_subarray_imp(a, 0, a.size() - 1);
        end_t = chrono::steady_clock::now();
        t3 += chrono::duration_cast<chrono::nanoseconds>(end_t - begin_t).count();

        if (l != l3 || r != r3 || s != s3) {
            cout << "Hmm.. Something went wrong.\n";
            return -1;
        }
        #endif

        begin_t = chrono::steady_clock::now();
        auto [l4, r4, s4] = find_max_subarray_kadane(a, 0, a.size() - 1);
        end_t = chrono::steady_clock::now();
        t4 += chrono::duration_cast<chrono::nanoseconds>(end_t - begin_t).count();

        if (l != l2 || r != r2 || s != s2 || l != l4 || r != r4 || s != s4) {
            cout << "Hm.. Something went wrong.\n";
            return -1;
        }
    }


    cout << "n = " << n << endl;
    cout << "Precision param = " << P << endl;
#ifdef N
    cout << "BDC cross number = " << N << endl;
    cout << "Improved time: " << t3 / P << endl;
#endif
    
    cout << "Brutforce time: " << t1 / P << endl;
    cout << "D&C time: " << t2 / P << endl;
    cout << "Kadane time: " << t4 / P << endl;
    return 0;
}
