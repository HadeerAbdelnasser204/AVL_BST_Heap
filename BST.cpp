#include "BST.h"
#include <iostream>
#include <vector>
#include <string>
BST::BST()
{
    root=NULL;
    right = NULL;
    left = NULL;
}
//insert from file
void BST :: AddStudentFromFile(vector<BST> students)
{
    for( auto stud : students) {

        BST *node = new BST, *current = root, *prev;
        node->right = NULL;
        node->left = NULL;
        node->ID = stud.ID;
        node->NAME = stud.NAME;
        node->GPA = stud.GPA;
        node->DEPT = stud.DEPT;
        //no student in the tree
        if (root == NULL) {
            root = node;
        } else {
            while (current != NULL) {
                prev = current;
                //current id greater than who will add
                if (current->ID > node->ID) {
                    current = current->left;
                }
                    //current id less than who will add
                else if (current->ID < node->ID) {
                    current = current->right;
                }
                    //this id added before
                else {
                    cout << "this student already exist\n";
                    exit(0);
                }

            }
            if (prev->ID > node->ID) {
                prev->left = node;
            } else {
                prev->right = node;
            }
        }

    }
}
void BST :: AddStudent(int id,string name,double gpa,string dept)
{
     BST *node = new BST, *current = root, *prev;
        node->right = NULL;
        node->left = NULL;
        node->ID = id;
        node->NAME = name;
        node->GPA = gpa;
        node->DEPT = dept;
        //no student in the tree
        if (root == NULL) {
            root = node;
        } else {
            while (current != NULL) {
                prev = current;
                //current id greater than who will add
                if (current->ID > node->ID) {
                    current = current->left;
                }
                    //current id less than who will add
                else if (current->ID < node->ID) {
                    current = current->right;
                }
                    //this id added before
                else {
                    cout << "this student already exist\n";
                    exit(0);
                }

            }
            if (prev->ID > node->ID) {
                prev->left = node;
            } else {
                prev->right = node;
            }
        }
        cout<<"Student added :)\n";
}
void BST ::DeleteStudent(int id)
{
    BST* current,*prev;
    if(root == NULL)
    {
        cout<<"No Student Exist\n";
    }
    if(root->ID == id)
    {
        DeleteFromTree(root);
        return;
    }
    prev=root;
    if(root->ID > id)
    {
        current=root->left;
    }
    else
        current=root->right;
    while (current !=NULL)
    {
        if (current->ID ==id)
            break;
        else if(current->ID > id)
        {
            prev=current;
            current = current->left;
        }
        else
        {
            prev=current;
            current = current->right;
        }

    }
    if(current == NULL)
    {
        cout<<"Student doesn't exist\n";
    }
    else if(prev->ID > id)
    {
        DeleteFromTree(prev->left);
    }
    else
        DeleteFromTree(prev->right);
}
void BST::DeleteFromTree(BST *&stud)
{
    BST* node,*trail,*temp;
    //don't have children
    if(stud->left == NULL && stud->right ==NULL)
    {
        cout<<"Student found \n";
        cout<<"["<<temp->ID<<", "<<temp->NAME<<", "<<temp->GPA<<", "<<temp->DEPT<<"]\n";
        delete stud;
        stud = NULL;
        cout<<"student deleted :)\n";
    }
    //have right child
    else if(stud->left == NULL && stud->right != NULL)
    {
        temp = stud;
        cout<<"Student found \n";
        cout<<"["<<temp->ID<<", "<<temp->NAME<<", "<<temp->GPA<<", "<<temp->DEPT<<"]\n";
        stud = stud->right;
        delete temp;
        cout<<"student deleted :)\n";
    }
    //have left child
    else if(stud->right == NULL && stud->left != NULL)
    {
        temp = stud;
        cout<<"Student found \n";
        cout<<"["<<temp->ID<<", "<<temp->NAME<<", "<<temp->GPA<<", "<<temp->DEPT<<"]\n";
        stud = stud->left;
        delete temp;
        cout<<"student deleted :)\n";
    }
    //have 2 child
    //predsure
    else
    {
        cout<<"Student found \n";
        cout<<"["<<stud->ID<<", "<<stud->NAME<<", "<<stud->GPA<<", "<<stud->DEPT<<"]\n";
        node=stud->left;
        trail=NULL;
        while (node->right !=NULL)
        {
            trail=node;
            node=node->right;
        }
        stud->ID=node->ID;
        if(trail == NULL)

            stud->left = node->left;
        else
            trail->right = node->left;

        delete node;
        cout<<"student deleted :)\n";
    }
}
//Search For Student
void BST:: SearchStudent(int id)
{
    BST* temp = root;
    if(root == NULL)
    {
        cout<<"no students found in list\n";
        return;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->ID > id)
            {
                temp=temp->left;
            }
            else if(temp->ID < id)
            {
                temp=temp->right;
            }
            else if(temp->ID == id)
            {
                cout<<"Student is found.\n";
                cout<<"["<<temp->ID<<", "<<temp->NAME<<", "<<temp->GPA<<", "<<temp->DEPT<<"]\n";
                return;
            }
        }
    }
    cout<<"this student not exist\n";
    return;
}
//inorder traversal
 void BST:: inorder(BST* node)
{
    if( node == NULL )
    {
        return;
    }

    inorder(node->left);
    cout<<"["<<node->ID<<", "<<node->NAME<<", "<<node->GPA<<", "<<node->DEPT<<"]\n";
    inorder(node->right);

}
//return root
BST* BST:: getRoot()
{
    return root;
}


