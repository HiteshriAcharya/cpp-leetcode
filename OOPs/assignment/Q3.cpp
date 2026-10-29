#include <iostream>
#include <string>
using namespace std;

class Person{
private:

    string name;
    int age;

public:

    Person(string name, int age){

        this->name = name;
        this->age = age;
    }

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }
};

class Student : public Person{

    string studentNumber;

    /**
     * Use a method like this for constructor as this
     * will keep the name and age not edittable by anyone 
     * except for the Person class. This is good practice
     */

public:
    Student(string name, int age, string studentNumber) : Person(name,age)
    {
        this->studentNumber = studentNumber;
    }

    void displayStudentInfo(){

        cout << "name: " << getName() << endl;
        cout << "age: " << getAge() << endl;
        cout << "student number: " << studentNumber << endl;
    }
};

int main(){

    Student s1("Alice", 20, "S12345");
    s1.displayStudentInfo();
}