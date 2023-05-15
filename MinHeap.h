//
// Created by A plus on 5/13/2023.
//


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
#ifndef DS_MINHEAP_H
#define DS_MINHEAP_H
#include "MaxHeap.h"


class MinHeap {
private:
    vector<Student> minHeap;
public:
    MinHeap() = default;

    void minHeapify(int pos, int sz);

    void add(const Student &student);

    void minSort();

    void printMinHeap();
};


#endif //DS_MINHEAP_H
