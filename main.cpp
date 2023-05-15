#include <fstream>
#include <vector>
#include <string>
#include "BST.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "AVL.h"

using namespace std;

void displayMaxHeap(MaxHeap &Data)
{
//    Student student;
//    Student newStudent;
//    int choice;
//    while (true)
//    {
//        cout << "1. Add student\n"
//                "2. Print All (sorted by GPA)\n";
//
//        cout << "Enter number of option: ";
//        cin >> choice;
//        if (choice == 1)
//        {
//            newStudent.StudentInfo();
//            Data.add(newStudent);
//
//            cout << "\nThe student is added." << endl;
//        }
//        else if (choice == 2)
//        {
//            if (file.is_open())
//            {
//                int noOfStud;
//                file >> noOfStud;
//                while (noOfStud--)
//                {
//                    file >> student.ID;
//                    file.ignore();
//                    getline(file, student.name);
//                    file >> student.GPA;
//                    file >> student.department;
//                    Data.add(student);
//                }
//
//                Data.sort();
//                cout << "Print 11 Students." << endl;
//                Data.printMaxHeap();
//                file.close();
//            }
//            else
//            {
//                cout << "Unable to open file" << endl;
//            }
//        }
//        else if (choice == 0)
//        { // Enter 0 to exit
//
//            break;
//        }
//    }
}

void displayMinHeap(MinHeap &Data)
{
//    Student student;
//    Student newStudent;
//    int choice;
//    while (true)
//    {
//        cout << "1. Add student\n"
//                "2. Print All (sorted by GPA)\n";
//
//        cout << "Enter number of option: ";
//        cin >> choice;
//        if (choice == 1)
//        {
//            newStudent.StudentInfo();
//            Data.add(newStudent);
//
//            cout << "\nThe student is added." << endl;
//        }
//        else if (choice == 2)
//        {
//            if (file.is_open())
//            {
//                int noOfStud;
//                file >> noOfStud;
//                while (noOfStud--)
//                {
//                    file >> student.ID;
//                    file.ignore();
//                    getline(file, student.name);
//                    file >> student.GPA;
//                    file >> student.department;
//                    Data.add(student);
//                }
//
//                Data.minSort();
//                cout << "Print 11 Students." << endl;
//                Data.printMinHeap();
//                file.close();
//            }
//            else
//            {
//                cout << "Unable to open file" << endl;
//            }
//        }
//        else if (choice == 0)
//        { // Enter 0 to exit
//            break;
//        }
//    }
}

void displayBST()
{

    ifstream File;
    BST *node = new BST;
    int id;
    File.open("Data.txt", ios::out);
    string line = "";
    int Num_Student;
    getline(File, line);
    Num_Student = stoi(line);
    vector<BST> Students;
    for (int i = 0; i < Num_Student; i++)
    {
        BST stud;
        // get ID
        getline(File, line);
        stud.ID = stoi(line);
        // get Name
        getline(File, line);
        stud.NAME = line;
        // get GPA
        getline(File, line);
        stud.GPA = stod(line);
        // get Department
        getline(File, line);
        stud.DEPT = line;
        Students.push_back(stud);
    }
    node->AddStudentFromFile(Students);
    int opt;
    cout << "1. Add student\n"
            "2. Remove student\n"
            "3. Search student\n"
            "4. Print All (sorted by id)\n"
            "5. Return to main menu\n";
    cout << "enter your option >>\n";

    cin >> opt;
    if (opt == 1)
    {

        string name, dept;
        double gpa;
        cout << "enter your ID :-\n";
        cin >> id;
        cout << "enter your name :-\n";
        cin >> name;
        cout << "enter your gpa :-\n";
        cin >> gpa;
        cout << "enter your department :-\n";
        cin >> dept;
        node->AddStudent(id, name, gpa, dept);
    }
    else if (opt == 2)
    {
        cout << "enter id of student will removed\n ";
        cin >> id;
        node->RemoveStudent(id);
    }
    else if (opt == 3)
    {
        cout << "enter id of student \n ";
        cin >> id;
        node->SearchStudent(id);
    }
    else if (opt == 4)
    {
        node->print(node->getRoot());
    }
    else if (opt == 5)
    {
    }
}

void displayAVL(AVL<IDStudent> &Tree)
{

    IDStudent newStudent;
    int choice;
    while (true) {
        cout << "1. Add student\n"
                "2. Remove student\n"
                "3. Search student\n"
                "4. Print All (sorted by id)\n"
                "5. Return to main menu\n";

        cout << "Enter number of option: ";
        cout.flush();
        cin >> choice;
        if (choice == 1) {
            newStudent.StudentInfo();
            Tree.insert(newStudent);
            cout << "\nThe student is added." << endl;
        } else if (choice == 2) {
            int id;
            cout << "\nPlease, enter the id you want to erase: ";
            cout.flush();
            cin >> id;
            newStudent.ID = id;
            Tree.erase(newStudent);
        } else if (choice == 3) {
            int id;
            cout << "\nPlease, enter the id you want to find: ";
            cout.flush();
            cin >> id;
            newStudent.ID = id;
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

int main()
{
    AVL<IDStudent> AVLTree;
    MaxHeap maxHeap;
    MinHeap minHeap;
    int choice;
    ifstream File;
    File.open("Data.txt", ios::out);
    string line = "";
    int Num_Student;
    getline(File, line);
    Num_Student = stoi(line);
    for (int i = 0; i < Num_Student; i++)
    {
        IDStudent IDstudent;
        Student normalStudent;
        //--------------------------
        getline(File, line);
        IDstudent.ID = stoi(line);
        normalStudent.ID = stoi(line);
        //------------------------
        getline(File, line);
        IDstudent.name = line;
        normalStudent.name = line;
        //------------------------
        getline(File, line);
        IDstudent.GPA = stod(line);
        normalStudent.GPA = stod(line);
        //------------------------
        getline(File, line);
        IDstudent.department = line;
        normalStudent.department = line;
        //------------------------
        AVLTree.insert(IDstudent);
        maxHeap.add(normalStudent);
        minHeap.add(normalStudent);
    }
    while (true)
    {
        cout << "1. BST\n"
             << "2. AVL\n"
             << "3. Min Heap\n"
             << "4. Max Heap\n"
             << "5. Exit Program\n";
        cout << "Enter number of option: ";
        cin >> choice;
        if (choice == 1)
        {
            displayBST();
        }
        else if (choice == 2)
        {
            displayAVL(AVLTree);
        }
        else if (choice == 3)
        {
            displayMinHeap(minHeap);
        }
        else if (choice == 4)
        {
            displayMaxHeap(maxHeap);
        }
        else if (choice == 5)
        {
            exit(0);
        }
    }
}
