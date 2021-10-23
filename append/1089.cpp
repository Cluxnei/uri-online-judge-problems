#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> loop;
    int numberOfMagnitudes;
    while(true) {
        cin >> numberOfMagnitudes;
        if (numberOfMagnitudes == 0) {
            break;
        }
        int magnitude;
        for (int i = 0; i < numberOfMagnitudes; i++) {
            cin >> magnitude;
            loop.push_back(magnitude);
        }
        int numberOfPeaks = 0;
        for (int i = 0; i < numberOfMagnitudes - 1; i++) {
            if (i == 0 && (loop[0] < loop[numberOfPeaks - 1] || loop[0] > loop[numberOfPeaks - 1])) {
                numberOfPeaks++;
            } else if (loop[i] < loop[numberOfPeaks - 1] || loop[i] > loop[numberOfPeaks - 1]) {
                numberOfPeaks++;
            }
        }
        cout << numberOfPeaks << endl;
    }

    return 0;
}