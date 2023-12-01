#include <bits/stdc++.h>

using namespace std;

vector<string> numbersStr = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

char checkSequence(string line, int index) {
    if(isdigit(line[index])) {
        return line[index];
    }

    for(int i=0; i<numbersStr.size(); i++) {
        // cout << line.substr(index,numbersStr[i].size()) << "---" << numbersStr[i] << "\n";
        if(line.substr(index,numbersStr[i].size()) == numbersStr[i]) {
            return (i+1) + '0';
        }
    }

    return 0;
}

int main() {
    string line;
    int sum = 0;
    while (getline(cin, line))
    {
        string numberStr = "0";
        for(int i=0; i<line.size(); i++) {
            char res = checkSequence(line, i);
            if(res != 0) {
                numberStr += res;
                break;
            }
        }
        for(int i=line.size()-1; i>=0; i--) {
            char res = checkSequence(line, i);
            if(res != 0) {
                numberStr += res;
                break;
            }
        }
        // cout << numberStr << "\n";
        int number = stoi(numberStr);
        sum += number;
    }
    cout << sum << "\n";
}