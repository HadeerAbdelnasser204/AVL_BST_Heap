//DS_Assignment_Heap
// Created by Hadeer Abdelnasser on 5/13/2023.

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
#ifndef DS_MAXHEAP_H
#define DS_MAXHEAP_H

struct Student {

    int ID;
    double GPA;
    string name;
    string department;

    Student() = default;

    Student(int id, double g, string name, string p) {
        ID = id;
        this->name = std::move(name);
        GPA = g;
        department = std::move(p);
    }

    void setID(int id) {
        ID = id;
    }


    void setName(string name) {
        this->name = name;
    }

    void setGPA(double GPA) {
        this->GPA = GPA;
    }

    void setDepartment(string department) {
        this->department = std::move(department);
    }

    double getGPA() {
        return GPA;
    }

    string getName() {
        return name;
    }

    int getID() {
        return ID;
    }

    string getDep() {
        return department;
    }

    void StudentInfo() {
        int id;
        double gpa;
        string studentName;
        string dep;
        cout << "id: ";
        cin >> id;
        setID(id);
        cout << "Name: ";
        cin.ignore();
        getline(cin, studentName);
        setName(studentName);
        cout << "GPA: ";
        cin >> gpa;
        setGPA(gpa);
        cout << "Department: ";
        cin >> dep;
        setDepartment(dep);

    }
};


class MaxHeap {
private:
    vector<Student> maxHeap;
public:
    MaxHeap() = default;

    void maxHeapify(int pos, int sz);

    void add(const Student &student);

    void sort();

    void printMaxHeap();


};


#endif //DS_MAXHEAP_H
