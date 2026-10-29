#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N;

    cout << "Enter N: ";
    cin >> N;

    int array[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Enter element: ";
        cin >> array[i];
    }

    // we do not minus one because this is the syntax. it will minus one on its own
    sort(array, array + N); // Ascending order

    sort(array, array+N, greater<int>()); //Descending order

    for (int i = 0; i < N; i++)
    {
        cout << " " << array[i];
    }

    cout << endl;
}