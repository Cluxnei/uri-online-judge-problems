#include<bits/stdc++.h> 
#include <vector>

using namespace std; 

int main() { 
    vector<string> names;
    string name;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> name;
        names.push_back(name);
    }
    sort(names.begin(), names.end());
    cout << names.at(k - 1) << endl;

    return 0; 
} 