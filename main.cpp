#include <fstream>
#include <vector>
#include <string>
#include "BST.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "AVL.h"

using namespace std;

void displayMaxHeap() {
    MaxHeap Data;
    Student student;
    Student newStudent;
    fstream file("Data.txt");
    int choice;
    while (true) {
        cout << "1. Add student\n"
                "2. Print All (sorted by GPA)\n";

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
        cout << "1. Add student\n"
                "2. Print All (sorted by GPA)\n";

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

void BSTMenu()
{

    ifstream File;
    BST *node=new BST;
    int id;
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
    node->AddStudentFromFile(Students);
    while(true) {
        int opt;
        cout << "1. Add student\n"
                "2. Remove student\n"
                "3. Search student\n"
                "4. Print All (sorted by id)\n"
                "5. Return to main menu\n";
        cout << "enter your option >>\n";

        cin >> opt;
        if (opt == 1) {
            string name, dept;
            double gpa;
            cout << "enter your ID :-\n";
            cin >> id;
            cout << "enter your name :-\n";
            cin.ignore();
            getline(cin,name);
            cout << "enter your gpa :-\n";
            cin.ignore();
            cin >> gpa;
            cout << "enter your department :-\n";
            cin >> dept;
            node->AddStudent(id, name, gpa, dept);

        } else if (opt == 2) {
            cout << "enter id of student will removed\n ";
            cin >> id;
            node->DeleteStudent(id);
        } else if (opt == 3) {
            cout << "enter id of student \n ";
            cin >> id;
            node->SearchStudent(id);
        } else if (opt == 4) {
            node->inorder(node->getRoot());
        } else if (opt == 5) {
            return;
        }
    }

}
void displayAVL() {
    AVL<AVLStudent> Tree;
    AVLStudent newStudent;
    fstream file("Data.txt");
    int choice;
    while (true) {
        cout << "1. Add student\n"
                "2. Print All (sorted by GPA)\n";

        cout << "Enter number of option: ";
        cin >> choice;
        if (choice == 1) {
            newStudent.StudentInfo();
            Tree.insert(newStudent);
            cout << "\nThe student is added." << endl;
        } else if (choice == 2) {
            newStudent.StudentInfo();
            Tree.erase(newStudent);
        } else if (choice == 3) {
            newStudent.StudentInfo();
            if (Tree.find(newStudent)) {
                cout << "Student found!" << endl;
            } else {
                cout << "Student not found." << endl;
            }

        } else if (choice == 4) {
            Tree.print();
            cout << endl;
        } else if (choice == 5) {
            return;
        }

    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. BST\n"
             << "2. AVL\n"
             << "3. Min Heap\n"
             << "4. Max Heap\n"
             << "5. Exit Program\n";
        cout << "Enter number of option: ";
        cin >> choice;
        if (choice == 1) {
            displayBST();
        } else if (choice == 2) {

        } else if (choice == 3) {
            displayMinHeap();
        } else if (choice == 4) {
            displayMaxHeap();
        } else if (choice == 5) {
            exit(0);
        }
    }
}
