#include <iostream>
using namespace std;
#define PI 3.14

int main()
{

    double r;

    cout << "Enter r: ";
    cin >> r;

    double area = r * r * PI;

    cout << "Area of circle of radius " << r << " is " << area;
}