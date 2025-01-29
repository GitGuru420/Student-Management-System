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

        void displayStudent() {
            cout << "ID No: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
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
    cin.ignore();
    cout << "Enter Full Name: "; getline(cin, name);
    cout << "Enter Age: "; cin >> age;
    
    students.push_back(Student(id, name, age));
    cout << "Student Add Successfully" << endl;
}

// display all students
void displayAllStudents(vector<Student> students) {
    if(students.empty()) {
        cout << "No Students Found" << endl;
        return;
    }
    for(int i=0; i<students.size(); i++) {
        students[i].displayStudent();
        cout << endl;
    }
}

// search student
void searchStudent(vector<Student> students) {
    int searchID;
    cout << "Enter Student ID: "; cin >> searchID;
    bool found = false;
    for(int i=0; i<students.size(); i++) {
        if(students[i].getID() == searchID) {
            students[i].displayStudent();
            found = true;
            return;
        }
    }
    if(found == false) {
        cout << "Students Not Found" << endl;
    }
}

// update student
void updateStudent(vector<Student> &students) {
    int id;
    cout << "Enter Student ID: "; cin >> id;
    bool found = false;
    int option;
    for(int i=0; i<students.size(); i++) {
        if(students[i].getID() == id) {
            found = true;
            char choice;
            do {
                cout << "1. Update ID" << endl;
                cout << "2. Update Name" << endl;
                cout << "3. Update Age" << endl;
                cout << "Enter Your Choice: "; cin >> option;

                switch(option) {
                    case 1: {
                        int newId;
                        cout << "Enter New ID: "; cin >> newId;
                        students[i].setID(newId); break;
                    }
                    case 2: {
                        string newName;
                        cin.ignore();
                        cout << "Enter New Name: "; getline(cin, newName);
                        students[i].setName(newName); break;
                    }   
                    case 3: {
                        int newAge;
                        cout << "Enter New Age: "; cin >> newAge;
                        students[i].setAge(newAge); break;
                    }
                    default: cout << "Invalid Number" << endl;
                }
                cout << "Do you want more update ? Yes / No [Y / N]: "; cin >> choice;
            } while(choice == 'Y' || choice == 'y');
        }
    }
    if(found == false) {
        cout << "Student Not Found" << endl;
    }
}


int main()
{
    vector<Student> students;

    char choice; 
    do {
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
            case 2: displayAllStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 6: exit(1);
        }
        cout << "Do you want to continue ? Yes / No [Y / N]: "; 
        cin >> choice;
    } while(choice == 'Y' || choice == 'y');
    return 0;
}