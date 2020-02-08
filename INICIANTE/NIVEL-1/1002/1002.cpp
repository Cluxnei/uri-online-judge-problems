#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double radius;
    cin >> radius;
    cout << fixed << showpoint;
    cout << setprecision(4);
    cout << "A=" << (3.14159 * radius * radius) << endl;
    return 0;
}