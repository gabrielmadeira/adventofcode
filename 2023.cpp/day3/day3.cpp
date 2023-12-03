#include <bits/stdc++.h>

using namespace std;

string getDigit(string line, int i) {
    string digitStr = "";
    while(isdigit(line[i])) {
        digitStr += line[i];
        i++;
    }
    return digitStr;
}

int isSymbol(char s) {
    return !isdigit(s) && s != '.';
}

int main() {
    vector<string> scheme;
    string line;
    while (getline(cin, line)) scheme.push_back(line);
    int sum = 0;
    for(int l = 0; l<scheme.size(); l++) {
        int c = 0;
        while(c < scheme[l].size()) {
            if(!isdigit(scheme[l][c])) {
                c++;
                continue;
            }
            string digitStr = getDigit(scheme[l], c);
            int isPartNumber = 0;
            int i = c;
            while(i<c+digitStr.size()) {
                if(
                    (i-1>=0 && l-1>=0 && isSymbol(scheme[l-1][i-1])) ||
                    (l-1>=0 && isSymbol(scheme[l-1][i])) ||
                    (i+1<scheme[l].size() && l-1>=0 && isSymbol(scheme[l-1][i+1])) ||
                    (i+1<scheme[l].size() && isSymbol(scheme[l][i+1])) ||
                    (i+1<scheme[l].size() && l+1<scheme.size() && isSymbol(scheme[l+1][i+1])) ||
                    (l+1<scheme.size() && isSymbol(scheme[l+1][i])) ||
                    (i-1>=0 && l+1<scheme.size() && isSymbol(scheme[l+1][i-1])) ||
                    (i-1>=0 && isSymbol(scheme[l][i-1]))
                )
                {
                    isPartNumber = 1;
                    break;
                }
                i++;
            }
            if(isPartNumber) sum += stoi(digitStr);
            c += digitStr.size();
        }
    }
    cout << sum << "\n";
}