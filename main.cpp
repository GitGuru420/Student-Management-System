#include <bits/stdc++.h>
using namespace std;

// Student Class
class Student {
private:
    int id;
    string name;
    int age;
public:
    // Constructor
    Student(int id = 0, string name = "", int age = 0) {
        this->id = id;
        this->name = name;
        this->age = age;
    }
    // Getter & Setter
    int getID() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    void setID(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    
    void displayStudent() {
        cout << "\nStudent ID: " << id << "\nName: " << name << "\nAge: " << age << "\n";
    }

    // Save Student to File
    void saveToFile(ofstream &outfile) {
        outfile << id << " " << name << " " << age << "\n";
    }
};

// Load Students from File
void loadFromFile(vector<Student> &students) {
    ifstream infile("students.txt");
    if (!infile) return;
    int id, age;
    string name;
    while (infile >> id >> ws) {
        getline(infile, name, ' ');
        infile >> age;
        students.push_back(Student(id, name, age));
    }
    infile.close();
}

// Save All Students to File
void saveAllToFile(vector<Student> &students) {
    ofstream outfile("students.txt", ios::trunc);
    for (Student &s : students) {
        s.saveToFile(outfile);
    }
    outfile.close();
}

// Add New Student
void addNewStudent(vector<Student> &students) {
    int id, age;
    string name;
    cout << "Enter ID: "; cin >> id;
    for (Student &s : students) {
        if (s.getID() == id) {
            cout << "Student Already Exists!\n";
            return;
        }
    }
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Age: "; cin >> age;
    students.push_back(Student(id, name, age));
    saveAllToFile(students);
    cout << "Student Added!\n";
}

// Display All Students
void displayAllStudents(vector<Student> &students) {
    if (students.empty()) { cout << "No Students Found\n"; return; }
    for (Student &s : students) s.displayStudent();
}

// Search Student
void searchStudent(vector<Student> &students) {
    int id;
    cout << "Enter Student ID: "; cin >> id;
    for (Student &s : students) {
        if (s.getID() == id) { s.displayStudent(); return; }
    }
    cout << "Student Not Found\n";
}

// Update Student
void updateStudent(vector<Student> &students) {
    int id;
    cout << "Enter Student ID: "; cin >> id;
    for (Student &s : students) {
        if (s.getID() == id) {
            cout << "1. Update ID\n2. Update Name\n3. Update Age\nChoose: ";
            int option; cin >> option;
            if (option == 1) { int newId; cout << "New ID: "; cin >> newId; s.setID(newId); }
            else if (option == 2) { string newName; cout << "New Name: "; cin.ignore(); getline(cin, newName); s.setName(newName); }
            else if (option == 3) { int newAge; cout << "New Age: "; cin >> newAge; s.setAge(newAge); }
            saveAllToFile(students);
            cout << "Student Updated!\n";
            return;
        }
    }
    cout << "Student Not Found\n";
}

// Delete Student
void deleteStudent(vector<Student> &students) {
    int id;
    cout << "Enter Student ID: "; cin >> id;
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->getID() == id) {
            students.erase(it);
            saveAllToFile(students);
            cout << "Student Deleted!\n";
            return;
        }
    }
    cout << "Student Not Found\n";
}

int main() {
    vector<Student> students;
    loadFromFile(students);

    char choice;
    do {
        cout << "\nStudent Management System\n1. Add Student\n2. Display All\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\nEnter: ";
        int option; cin >> option;
        switch (option) {
            case 1: addNewStudent(students); break;
            case 2: displayAllStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 5: deleteStudent(students); break;
            case 6: exit(0);
            default: cout << "Invalid Option!\n";
        }
        cout << "Continue? (Y/N): "; cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
