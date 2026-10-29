#include <iostream>
#include <queue>
using namespace std;

class Student{ //"<" overload

public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator< (Student &other_student) const{
        return this->marks < other_student.marks;
    }
};

// Allow an object of this class to behave like a function !!

struct ComparePair{
    bool operator () (pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second;
    }
};

/**
 * Imagine if you wrote:
 * 
 * bool compare(pair<string,int> p1,
 *      pair<string,int> p2) {
 *      return p1.second < p2.second;
 * }
 * 
 * How would priority_queue store it?
 * It would need a pointer to the function
 * 
 * bool (*cmp)(pair<string,int>, pair<string,int>);
 * 
 * which gets messy.
 * 
 * Instead C++ STL says:
 * Give me a class that I can instantiate and call whenever I need comparisons.
 * 
 * So internally it does: ComparePair cmp;
 * and later: cmp(a,b);
 * 
 */

int main(){

    priority_queue<Student> pqStudent;
    priority_queue<pair<string,int>, vector<pair<string, int>>, ComparePair> pqPair;

    // pqStudent.push(Student("aman", 85));
    // pqStudent.push(Student("bhumi", 95));
    // pqStudent.push(Student("chatan", 65));

    pqPair.push(make_pair("aman", 85));
    pqPair.push(make_pair("bhumi", 95));
    pqPair.push(make_pair("chatan", 65));


    while(!pqPair.empty()){
        cout << pqPair.top().first << " " << pqPair.top().second << endl;
        pqPair.pop();
    }
}