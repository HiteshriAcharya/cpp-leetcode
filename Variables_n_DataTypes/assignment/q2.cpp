#include <iostream>
using namespace std;

int main()
{
    double pencil, pen, eraser;

    cout<< "Cost of pencil: ";
    cin>>pencil;
    cout<<endl;

    cout << "Cost of pen: ";
    cin >> pen;
    cout << endl;

    cout << "Cost of eraser: ";
    cin >> eraser;
    cout << endl;

    double total = (pencil + pen + eraser) * 1.18;

    cout<< "Total cost is: " << total << endl;
}