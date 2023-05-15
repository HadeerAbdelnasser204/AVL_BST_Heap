#include "MinHeap.h"

using namespace std;

void MinHeap::minHeapify(int pos, int sz) {
    Student stud;
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
    int minIndex = pos;

    if (l < sz && minHeap[l].GPA < minHeap[minIndex].GPA) {
        minIndex = l;
    }

    if (r < sz && minHeap[r].GPA < minHeap[minIndex].GPA) {
        minIndex = r;
    }

    if (minIndex != pos) {
        swap(minHeap[pos], minHeap[minIndex]);

        minHeapify(minIndex, sz);
    }


}

void MinHeap::add(const Student &student) {
    minHeap.push_back(student);
    int index = int(minHeap.size()) - 1;

    while (index > 0 && minHeap[(index - 1) / 2].GPA > minHeap[index].GPA) {
        swap(minHeap[index], minHeap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void MinHeap::minSort() {
    for (int i = minHeap.size() - 1; i > 0; i--) {
        swap(minHeap[0], minHeap[i]);
        minHeapify(0, i);
    }
    reverse(minHeap.begin(), minHeap.end());
}


void MinHeap::printMinHeap() {
    for (auto &i: minHeap) {
        cout << "[" << i.ID << ", " << i.name << ", " << i.GPA << ", " << i.department << "]" << endl;
    }
}