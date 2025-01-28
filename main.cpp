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


int main()
{

    return 0;
}