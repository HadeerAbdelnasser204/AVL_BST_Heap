#ifndef AVL_TREE
#define AVL_TREE

#include <bits/stdc++.h>

using namespace std;

class IDStudent {
public:
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


    IDStudent() = default;

    IDStudent(int id, double g, string name, string p) {
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

    bool operator<(const IDStudent &other) const {
        return ID < other.ID;
    }

    bool operator>(const IDStudent &other) const {
        return ID > other.ID;
    }

    friend ostream &operator<<(ostream &out, const IDStudent &student) {
        cout << "ID: " << student.ID << endl;
        cout << "Name: " << student.name << endl;
        cout << "GPA: " << student.GPA << endl;
        cout << "Department: " << student.department << endl;
        return out;
    }
};

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

template<typename T>
AVLnode<T> *AVL<T>::rotateToLeft(AVLnode<T> *ptr) {
    AVLnode<T> *newRoot = ptr->right;
    ptr->right = newRoot->left;
    newRoot->left = ptr;

    updateHeight(ptr);
    updateHeight(newRoot);

    return newRoot;
}

template<typename T>

AVLnode<T> *AVL<T>::rotateToRight(AVLnode<T> *ptr) {
    AVLnode<T> *newRoot = ptr->left;
    ptr->left = newRoot->right;
    newRoot->right = ptr;

    updateHeight(ptr);
    updateHeight(newRoot);

    return newRoot;
}

template<typename T>

int AVL<T>::updateHeight(AVLnode<T> *ptr) {
    if (ptr == nullptr) {
        return 0;
    }
    return ptr->height = 1 + std::max(getHeight(ptr->left), getHeight(ptr->right));
}

template<typename T>
int AVL<T>::getHeight(AVLnode<T> *ptr) {
    if (ptr == nullptr) {
        return 0;
    }
    return ptr->height;
}

template<typename T>
AVLnode<T> *AVL<T>::insert(T val, AVLnode<T> *ptr) {
    if (head == nullptr) {
        head = new AVLnode<T>(val);
        return head;
    }
    if (ptr == nullptr) {
        return head = insert(val, head);
    }
    if (val < ptr->value) {
        if (ptr->left == nullptr) {
            ptr->left = new AVLnode<T>(val);
            sz++;
        } else {
            ptr->left = insert(val, ptr->left);
        }
    } else if (val > ptr->value) {
        if (ptr->right == nullptr) {
            ptr->right = new AVLnode<T>(val);
            sz++;
        } else {
            ptr->right = insert(val, ptr->right);
        }
    }
    updateHeight(ptr);
    if (getHeight(ptr->left) - getHeight(ptr->right) <= -2) {
        if (ptr->right->right == nullptr) {
            ptr->right = rotateToRight(ptr);
        }
        return rotateToLeft(ptr);
    } else if (getHeight(ptr->left) - getHeight(ptr->right) >= 2) {
        if (ptr->left->left == nullptr) {
            ptr->left = rotateToLeft(ptr->left);
        }
        return rotateToRight(ptr);
    }
    return ptr;
}

template<typename T>
bool AVL<T>::find(T val, AVLnode<T> *ptr) {
    if (ptr == nullptr) {
        return find(val, head);
    }
    if (val < ptr->value) {
        if (ptr->left == nullptr) {
            return 0;
        } else {
            return find(val, ptr->left);
        }
    } else if (val > ptr->value) {
        if (ptr->right == nullptr) {
            return 0;
        } else {
            return find(val, ptr->right);
        }
    } else {
        return 1;
    }
}

template<typename T>
void AVL<T>::print() {
    dfs(head);
}

template<typename T>
void AVL<T>::dfs(AVLnode<T> *ptr) {
    if (ptr == nullptr) {
        return;
    }
    dfs(ptr->left);
    std::cout << ptr->value << ' ';
    dfs(ptr->right);
}

template<typename T>
void AVL<T>::erase(T val) {
    if (head == nullptr) {
        return;
    }
    head = AVLerase(val, head);
}

template<typename T>
AVLnode<T> *AVL<T>::AVLerase(T val, AVLnode<T> *ptr) {
    if (ptr->value < val) {
        ptr->right = AVLerase(val, ptr->right);
    } else if (ptr->value > val) {
        ptr->left = AVLerase(val, ptr->left);
    } else {
        if (ptr->left == nullptr && ptr->right == nullptr) {
            delete ptr;
            return nullptr;
        } else if (ptr->left == nullptr) {
            AVLnode<T> *temp = ptr->left;
            *ptr = *(ptr->left);
            delete temp;
        } else if (ptr->right == nullptr) {
            AVLnode<T> *temp = ptr->right;
            *ptr = *(ptr->right);
            delete temp;
        } else {
            AVLnode<T> *temp = minValueNode(ptr->right);
            ptr->value = temp->value;
            ptr->right = AVLerase(ptr->value, ptr->right);
        }
        sz--;
    }
    if (ptr == nullptr) {
        return nullptr;
    }
    updateHeight(ptr);
    if (getHeight(ptr->left) - getHeight(ptr->right) <= -2) {
        if (ptr->right->right == nullptr) {
            ptr->right = rotateToRight(ptr);
        }
        return rotateToLeft(ptr);
    } else if (getHeight(ptr->left) - getHeight(ptr->right) >= 2) {
        if (ptr->left->left == nullptr) {
            ptr->left = rotateToLeft(ptr->left);
        }
        return rotateToRight(ptr);
    }
    return ptr;
}

template<typename T>
AVLnode<T> *AVL<T>::minValueNode(AVLnode<T> *node) {
    AVLnode<T> *current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}


#endif