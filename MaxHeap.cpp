#include "MaxHeap.h"
using namespace std;

void MaxHeap::maxHeapify(int pos, int sz) {
    Student stud;

    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int maxIndex = pos;

    if (left < sz && maxHeap[left].GPA < maxHeap[maxIndex].GPA) {
        maxIndex = left;
    }

    if (right < sz && maxHeap[right].GPA < maxHeap[maxIndex].GPA) {
        maxIndex = right;
    }

    if (maxIndex != pos) {
        swap(maxHeap[pos], maxHeap[maxIndex]);

        maxHeapify(maxIndex, sz);
    }


}
void MaxHeap::addStudent(const Student &student) {
    maxHeap.push_back(student);

    int index = int(maxHeap.size()) - 1;

    while (index > 0 && maxHeap[(index - 1) / 2].GPA > maxHeap[index].GPA) {
        swap(maxHeap[index], maxHeap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void MaxHeap::sort() {
    for (int i = maxHeap.size() - 1; i > 0; i--) {
        swap(maxHeap[0], maxHeap[i]);
        maxHeapify(0, i);
    }

}


void MaxHeap::printMaxHeap() {
    for (auto &i: maxHeap) {
        cout << "[" << i.ID << ", " << i.name << ", " << i.GPA << ", " << i.department << "]" << endl;
    }


}

