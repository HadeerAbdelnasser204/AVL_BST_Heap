#include <fstream>
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

int main() {
   displayMinHeap();
   displayMaxHeap();
}