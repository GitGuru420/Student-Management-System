#include <bits/stdc++.h>
using namespace std;

// Student Class
class Student {
    // Attributes
    private:
        int id;
        string name;
        int age;
    public:
        // Constructor
        Student(int id, string name, int age) {
            this->id = id;
            this->name = name;
            this->age = age;
        }

        // Setter & Getter
        void setID(int id) {
            this->id = id;
        }
        int getID() {
            return id;
        }
        void setName(string name) {
            this->name = name;
        }
        string getName() {
            return name;
        }
        void setAge(int age) {
            this->age = age;
        }
        int getAge() {
            return age;
        }
};

// add new student
void addNewStudent(vector<Student> &students) {
    int id, age;
    string name;
    cout << "Enter ID: "; cin >> id;

    // check if student already exist or not
    for(int i=0; i<students.size(); i++) {
        if(students[i].getID() == id) {
            cout << "Student Already Exist, Please Enter Another ID No" << endl;
            return;
        }
    }
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Age: "; cin >> age;
    
    students.push_back(Student(id, name, age));
    cout << "Student Add Successfully" << endl;
}


int main()
{
    vector<Student> students;

    cout << "\"Student Management System\"" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Update Student" << endl;
    cout << "5. Delete Student" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter Your Option: ";
    int option; cin >> option;

    switch(option) {
        case 1: addNewStudent(students); break;
    }
    return 0;
}