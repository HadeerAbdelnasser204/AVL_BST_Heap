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
//search
bool BST :: searchFor(int id)
{
    BST* temp = root;
    if(root == NULL)
        return false;
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
            else
            {
                return true;
            }
        }
        return false;
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
//deletion
void BST:: RemoveStudent(int id)
{
    if(root == NULL)
        cout<<"no students found in list\n";
    else if(!searchFor(id))
        cout<<"this student not exist";
    else if(searchFor(id))
    {
        BST* node=new BST,*temp=root,*prev=new BST,*parent=new BST;
        while(temp != NULL)
        {
            parent=temp;
            if(temp->ID > id)
            {
                temp=temp->left;
            }
            else if(temp->ID < id)
            {
                temp=temp->right;
            }
                //find id of student
            else if(temp->ID == id)
            {
                node=temp;
                cout<<"Student is found.\n";
                cout<<"["<<node->ID<<", "<<node->NAME<<", "<<node->GPA<<", "<<node->DEPT<<"]\n";
                //has no child
                if(temp->right == NULL && temp->left == NULL)
                {
                    if(temp==root)
                    {
                        root=NULL;
                    }
                    else if(parent->right==temp)
                    {
                        parent->right=NULL;
                    }
                    else if(parent->left==temp)
                    {
                        parent->left=NULL;
                    }
                    delete temp;
                }
                    //has one child at left
                else if(temp->right == NULL && temp->left != NULL)
                {
                    if(temp == root)
                    {
                        root=temp->left;
                    }
                    else if(parent->left == temp)
                    {
                        parent->left=temp->left;
                    }
                    else if(parent->right== temp)
                    {
                        parent->right=temp->left;
                    }
                }
                    //has one child at right
                else if(temp->right != NULL && temp->left == NULL)
                {
                    if(temp == root)
                    {
                        root=temp->right;
                    }
                    else if(parent->left ==temp)
                    {
                        parent->left=temp->right;
                    }
                    else if(parent->right == temp)
                    {
                        parent->right = temp->right;
                    }
                }
                    //has 2 child
                else
                {
                    prev=temp;
                    temp=temp->left;
                    while (temp->right!=NULL)
                    {
                        prev=temp;
                        temp=temp->right;
                    }
                    node->ID=temp->ID;
                    if(node == prev)
                    {
                        prev->left=temp->left;
                    }
                    else
                    {
                        prev->right=temp->left;
                    }
                    delete temp;

                }
                cout<<"Student is deleted.\n";
                break;
            }

        }
    }
}
//inorder traversal
 void BST:: print(BST* node)
{
    if( node == NULL )
    {
        return;
    }

    print(node->left);
    cout<<"["<<node->ID<<", "<<node->NAME<<", "<<node->GPA<<", "<<node->DEPT<<"]\n";
    print(node->right);

}
//return root
BST* BST:: getRoot()
{
    return root;
}


