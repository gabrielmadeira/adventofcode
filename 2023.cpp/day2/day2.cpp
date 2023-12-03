#include <bits/stdc++.h>

using namespace std;

int getDigit(string line, int &i) {
    string digitStr = "0";
    while(isdigit(line[i])) {
        digitStr += line[i];
        i++;
    }
    return stoi(digitStr);
}

int main() {
    string line;
    int sum = 0;
    while (getline(cin, line))
    {
        int fail = 0;
        int i = 5;
        int gameN = getDigit(line, i);
        // cout << gameN << "--------------\n";
        i += 2;

        while(i<line.size()) {
            int qtd = getDigit(line, i);
            // cout << qtd << "\n";
            if(qtd == 0) fail = 1;
            i++;
            if((line.substr(i,5) == "green" && qtd <= 13) ||
                (line.substr(i,3) == "red" && qtd <= 12) ||
                (line.substr(i,4) == "blue" && qtd <= 14)) {
                while(i<line.size() && line[i] != ',' && line[i] != ';') i++;
                i += 2;
                continue;
            }
            fail = 1;
            break;
        }
        if(!fail) sum += gameN;
    }
    cout << sum << "\n";
}