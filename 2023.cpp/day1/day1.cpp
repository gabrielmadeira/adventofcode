#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    int sum = 0;
    while (getline(cin, line))
    {
        string numberStr = "0";
        for(int i=0; i<line.size(); i++) {
            if(isdigit(line[i])) {
                numberStr += line[i];
                break;
            }
        }
        for(int i=line.size()-1; i>=0; i--) {
            if(isdigit(line[i])) {
                numberStr += line[i];
                break;
            }
        }
        int number = stoi(numberStr);
        sum += number;
    }
    cout << sum << "\n";
}