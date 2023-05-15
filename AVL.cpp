#include "AVL.h"

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
    ptr->height = 1 + std::max(getHeight(ptr->left), getHeight(ptr->right));
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

