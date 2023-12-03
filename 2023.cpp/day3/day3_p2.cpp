#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<int>> engines;
unordered_map<string, vector<int>> last;

string getDigit(string line, int i) {
    string digitStr = "";
    while(isdigit(line[i])) {
        digitStr += line[i];
        i++;
    }
    return digitStr;
}

void checkSymbol(char s, int l, int c, string digitStr, int digitL, int digitC) {
    if(s == '*') {
        string key = to_string(l)+"-"+to_string(c); 
        // cout << digit << "\n";
        int digit = stoi(digitStr);
        if(!engines.count(key)) { 
            engines[key] = { digit };
            last[key] = { digitL, digitC };
        }
        else if (last[key][0] != digitL && last[key][1] != digitC) { 
            engines[key].push_back(digit); 
            last[key] = { digitL, digitC };
        }
    }
}

int main() {
    vector<string> scheme;
    string line;
    while (getline(cin, line)) scheme.push_back(line);

    for(int l = 0; l<scheme.size(); l++) {
        int c = 0;
        while(c < scheme[l].size()) {
            if(!isdigit(scheme[l][c])) {
                c++;
                continue;
            }
            string digitStr = getDigit(scheme[l], c);
            int i = c;
            while(i<c+digitStr.size()) {
                if(i-1>=0 && l-1>=0) checkSymbol(scheme[l-1][i-1], l-1, i-1, digitStr, l, i);
                if(l-1>=0) checkSymbol(scheme[l-1][i], l-1, i, digitStr, l, i);
                if(i+1<scheme[l].size() && l-1>=0) checkSymbol(scheme[l-1][i+1], l-1, i+1, digitStr, l, i);
                if(i+1<scheme[l].size()) checkSymbol(scheme[l][i+1], l, i+1, digitStr, l, i);
                if(i+1<scheme[l].size() && l+1<scheme.size()) checkSymbol(scheme[l+1][i+1], l+1, i+1, digitStr, l, i);
                if(l+1<scheme.size()) checkSymbol(scheme[l+1][i], l+1, i, digitStr, l, i);
                if(i-1>=0 && l+1<scheme.size()) checkSymbol(scheme[l+1][i-1], l+1, i-1, digitStr, l, i);
                if(i-1>=0) checkSymbol(scheme[l][i-1], l, i-1, digitStr, l, i);
                i++;
            }
            c += digitStr.size();
        }
    }
    long int sum = 0;
    for (auto& it: engines) {
        if(it.second.size() == 2) {
            int mult = 1;
            cout << it.first << ":  ";
            for(int digit : it.second) { 
                cout << digit << "-";
                mult *= digit;
            }
            cout << ":::" << mult << "\n";
            sum += mult;
        }else{
            cout << it.first << "XXXXXXXXXXXXXXX\n";
        }
    }
    cout << sum << "\n";
} 