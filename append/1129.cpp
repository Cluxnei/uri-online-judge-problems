#include <iostream>
#include <vector>

using namespace std;

int main() {
    const char anwers_guide[6] = "ABCDE";
    while (true) {
        int numberOfCases;
        cin >> numberOfCases;
        if (numberOfCases == 0) {
            break;
        }
        for (int i = 0; i < numberOfCases; i++) {
            vector<int> anwers;
            for (int j = 0; j < 5; j++) {
                int value;
                cin >> value;
                anwers.push_back(value);
            }
            int numberOfBlacks = 0, indexOfLastBlack = -1;
            for (int j = 0; j < 5; j++) {
                if (anwers[j] <= 127) {
                    indexOfLastBlack = j;
                    numberOfBlacks++;
                }
            }
            cout << (numberOfBlacks != 1 ? '*' : anwers_guide[indexOfLastBlack]) << endl;
        }
    }
    return 0;
}