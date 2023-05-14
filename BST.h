
#ifndef MAIN_CPP_BST_H
#define MAIN_CPP_BST_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class BST
{
public:
    BST* root;
    int ID ;
    string DEPT,NAME;
    double GPA;
    BST* right,*left;
public:
    //constructor
    BST();
    //insert from file
    void AddStudentFromFile(vector<BST> students);
    //insertion
    void AddStudent(int id,string name,double gpa,string dept);
    //search
    bool searchFor(int id);
    //Search For Student
    void SearchStudent(int id);
    //deletion
    void RemoveStudent(int id);
    //inorder traversal
    void print(BST* node);
//get root of tree
    BST* getRoot();

};
#endif //MAIN_CPP_BST_H
