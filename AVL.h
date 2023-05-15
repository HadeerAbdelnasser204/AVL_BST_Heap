#ifndef AVL_TREE
#define AVL_TREE

#include <bits/stdc++.h>

using namespace std;

template<typename T>
class AVLnode {
public:
    T value;
    int height = 1;
    AVLnode *left = nullptr;
    AVLnode *right = nullptr;

    explicit AVLnode(T val) {
        value = val;
    }
};

template<typename T>

class AVL {
private:
    int sz = 0;
    AVLnode<T> *head = nullptr;

    AVLnode<T> *rotateToRight(AVLnode<T> *);

    AVLnode<T> *rotateToLeft(AVLnode<T> *);

    AVLnode<T> *AVLerase(T val, AVLnode<T> *);

    AVLnode<T> *minValueNode(AVLnode<T> *node);

    int updateHeight(AVLnode<T> *ptr);

    int getHeight(AVLnode<T> *);

    void dfs(AVLnode<T> *);

public:
    int size() { return sz; }

    bool find(T val, AVLnode<T> *ptr = nullptr);

    AVLnode<T> *insert(T val, AVLnode<T> *ptr = nullptr);

    void erase(T val);

    void print();
};

class AVLStudent {
private:
    int ID{};
    double GPA{};
    string name;
    string department;

    void setID(int id) {
        ID = id;
    }


    void setName(string val) {
        this->name = val;
    }

    void setGPA(double G) {
        this->GPA = G;
    }

    void setDepartment(string dep) {
        this->department = std::move(dep);
    }

public:
    AVLStudent() = default;

    AVLStudent(int id, double g, string name, string p) {
        ID = id;
        this->name = std::move(name);
        GPA = g;
        department = std::move(p);
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
        cout << "Enter id: ";
        cin >> id;
        setID(id);
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, studentName);
        setName(studentName);
        cout << "Enter GPA: ";
        cin >> gpa;
        setGPA(gpa);
        cout << "Enter department: ";
        cin >> dep;
        setDepartment(dep);

    }

    bool operator<(const AVLStudent &other) const {
        return ID < other.ID;
    }

    bool operator>(const AVLStudent &other) const {
        return ID > other.ID;
    }
};

#endif