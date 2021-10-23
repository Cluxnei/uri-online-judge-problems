#include <iostream>
#include <vector>

using namespace std;

int indexOf(const int x, const vector<int> haystack) {
    for (int i = 0, t = haystack.size(); i < t; i++) {
        if (haystack[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    while(cin >> n) {
        vector<int> start;
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            start.push_back(value);
        }
        vector<int> end;
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            end.push_back(value);
        }
        int bypasses = 0;
        for (int i = 0; i < n; i++) {
            int a = indexOf(start[i], end) - i;
            cout << start[i] << " || " << a << endl;
            bypasses += a > 0 ? a : 0;
        }
        cout << bypasses << endl;
    }
    return 0;
}