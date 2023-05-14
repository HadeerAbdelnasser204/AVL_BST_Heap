#include <fstream>
#include <vector>
#include <string>
#include "BST.h"
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;
void displayMaxHeap() {
    MaxHeap Data;
    Student student;
    Student newStudent;
    fstream file("Data.txt");
    int choice;
    while (true) {
        cout << "Enter number of option: ";
        cin >> choice;
        if (choice == 1) {
            newStudent.StudentInfo();
            Data.addStudent(newStudent);

            cout << "\nThe student is added." << endl;
        } else if (choice == 2) {
            if (file.is_open()) {
                int noOfStud;
                file >> noOfStud;
                while (noOfStud--) {
                    file >> student.ID;
                    file.ignore();
                    getline(file, student.name);
                    file >> student.GPA;
                    file >> student.department;
                    Data.addStudent(student);
                }

                Data.sort();
                cout << "Print 11 Students." << endl;
                Data.printMaxHeap();
                file.close();
            } else {
                cout << "Unable to open file" << endl;
            }
        } else if (choice == 0) { //Enter 0 to exit

            break;
        }
    }
}


void displayMinHeap() {
    MinHeap Data;
    StudentData student;
    StudentData newStudent;
    fstream file("Data.txt");
    int choice;
    while (true) {
        cout << "Enter number of option: ";
        cin >> choice;
        if (choice == 1) {
            newStudent.StudentInfo();
            Data.add(newStudent);

            cout << "\nThe student is added." << endl;
        } else if (choice == 2) {
            if (file.is_open()) {
                int noOfStud;
                file >> noOfStud;
                while (noOfStud--) {
                    file >> student.ID;
                    file.ignore();
                    getline(file, student.name);
                    file >> student.GPA;
                    file >> student.department;
                    Data.add(student);
                }

                Data.minSort();
                cout << "Print 11 Students." << endl;
                Data.printMinHeap();
                file.close();
            } else {
                cout << "Unable to open file" << endl;
            }
        } else if (choice == 0) { //Enter 0 to exit
            break;
        }

    }
}
void displayBST()
{
    ifstream File;
    File.open("Data.txt",ios::out);
    string line="";
    int Num_Student;
    getline(File,line);
    Num_Student=stoi(line);
    vector<BST> Students;
    for(int i=0;i<Num_Student;i++)
    {
        BST stud;
        //get ID
        getline(File,line);
        stud.ID=stoi(line);
        //get Name
        getline(File,line);
        stud.NAME=line;
        //get GPA
        getline(File,line);
        stud.GPA=stod(line);
        //get Department
        getline(File,line);
        stud.DEPT=line;
        Students.push_back(stud);
    }
    BST *node=new BST;
    node->AddStudent(Students);
    node->inorderTraversal(node->getRoot());
    node->SearchStudent(20);
    node->RemoveStudent(1);
    node->SearchStudent(1);
}
int main() {
    int choice;
    cout << "Enter number of option: ";
    cin >> choice;
    if(choice == 1){
           disPlayBST();
    }
    else if (choice == 2){//AVL}
    
    
    else if(choice == 3){
         displayMinHeap();
    }

     else if (choice == 4)
     {
         displayMaxHeap();
     }
     else if (choice == 5){
          exit(0);
     }

}
