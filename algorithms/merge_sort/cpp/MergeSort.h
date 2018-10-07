//
// Created by ankurdubey on 11/8/18.
// Implements Merge Sort Algorithm
//
#include <vector>

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H

namespace alg {
      /*
       * Merge():
       * Merges two parts of an array of numbers such that the resultant is non-decreasing sequence.
       * The two parts are assumed to be individually non-decreasing.
       * Firstly two parts are copied into two different arrays, then the elements are written back into
       *  their correct place in the original array.
       * Time Complexity: O(n), Space Complexity: O(n).
       */
    template <typename T>
    void Merge(std::vector<T> &sequence, const int &start, const int &mid, const int &end) {
        std::vector<T> leftSeq, rightSeq;

        //Make individual arrays for both parts
        for (auto it = start; it <= mid; ++it) {
            leftSeq.push_back(sequence[it]);
        }
        for (auto it = mid + 1; it <= end; ++it) {
            rightSeq.push_back(sequence[it]);
        }

        //Merge back to original array
        auto it = start, leftCtr = 0, rightCtr = 0; //it tracks posn. in original array
        while (it <= end) { //The no. of writes into original array = no of elements to be merged
            //Compare initial elements of both arrays. Write the smaller one into original array(1).
            //Increment the pointer of array(1) and repeat.
            if (leftCtr < leftSeq.size() && rightCtr < rightSeq.size()) {
                if (leftSeq[leftCtr] <= rightSeq[rightCtr]) {
                    sequence[it] = leftSeq[leftCtr];
                    ++leftCtr;
                } else {
                    sequence[it] = rightSeq[rightCtr];
                    ++rightCtr;
                }
            }
            //If we run out of elements in any one of the arrays
            else if (leftCtr == leftSeq.size()) {
                sequence[it] = rightSeq[rightCtr];
                ++rightCtr;
            } else if (rightCtr == rightSeq.size()) {
                sequence[it] = leftSeq[leftCtr];
                ++leftCtr;
            }
            it++;
        }
    }

    /*
    * MergeSort():
    * Sorts an array recursively. It keeps breaking an array into two parts.
    * When a pair of arrays of length 1 is reached, it merges them back
    */
    template <typename T>
    void MergeSort(std::vector<T> &sequence, const int &start, const int &end) {
        int mid = (start + end) / 2; //For breaking array into two parts
        if (start < end) { // until length of array > 1
            MergeSort(sequence, start, mid);
            MergeSort(sequence, mid + 1, end);
            Merge(sequence, start, mid, end);
        }
    }
}
#endif //ALGORITHMS_MERGESORT_H
