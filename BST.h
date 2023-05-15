
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
    BST *right,*left;
public:
    //constructor
    BST();
    //insert from file
    void AddStudentFromFile(vector<BST> students);
    //insertion
    void AddStudent(int id,string name,double gpa,string dept);

    //Search For Student
    void SearchStudent(int id);
    //deletion
    void DeleteStudent(int item);
    void DeleteFromTree(BST* &stud);
    //inorder traversal
    void inorder(BST* node);
//get root of tree
    BST* getRoot();

};
#endif //MAIN_CPP_BST_H
