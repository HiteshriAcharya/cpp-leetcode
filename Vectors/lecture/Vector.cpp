#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <int> vec1 = {1,2,3,4,5};
    vector <int> vec;
    // vector <int> vec2(5,-1);
    // cout << vec1.size() << endl;
    // cout << vec2.size() << endl;

    // for(int i = 0; i < vec2.size(); i++){

    //     cout << vec2[i] << " ";
    // }

    // cout << endl;

    cout << "Size: " << vec1.size() << endl;
    cout << "Capacity: " << vec1.capacity() << endl;

    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec1.push_back(6); // Add 5 to the end of the vector
    vec.push_back(1);

    cout << "New Size: " << vec1.size() << endl;
    cout << "New Capacity: " << vec1.capacity() << endl;

    cout << "New Size: " << vec.size() << endl;
    cout << "New Capacity: " << vec.capacity() << endl;

    vec1.pop_back(); // Remove last element
    vec.pop_back();

    cout << "Reduced Size: " << vec1.size() << endl;
    cout << "Reduced Capacity: " << vec1.capacity() << endl;

    cout << "Reduced Size: " << vec.size() << endl;
    cout << "Reduced Capacity: " << vec.capacity() << endl;
}