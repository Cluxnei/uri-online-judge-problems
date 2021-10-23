#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        string eq;
        cin >> eq;
        int result;
        if ((eq[0] - '0') == (eq[2] - '0')) {
            result = (eq[0] - '0') * (eq[2] - '0');
        } else if (islower(eq[1])) {
            result = (eq[0] - '0') + (eq[2] - '0');
        } else {
            result = (eq[2] - '0') - (eq[0] - '0');
        }
        cout << result << endl;
    }
    return 0;
}