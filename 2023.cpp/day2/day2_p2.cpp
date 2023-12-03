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

        int minG = 0;
        int minR = 0;
        int minB = 0;

        while(i<line.size()) {
            int qtd = getDigit(line, i);
            // cout << qtd << "\n";
            i++;
            if(qtd == 0) break;
            if(line.substr(i,5) == "green" && qtd > minG) minG = qtd;
            if(line.substr(i,3) == "red" && qtd > minR) minR = qtd;
            if(line.substr(i,4) == "blue" && qtd > minB) minB = qtd;
            while(i<line.size() && line[i] != ',' && line[i] != ';') i++;
            i += 2;
        }
        sum += minG*minR*minB;
    }
    cout << sum << "\n";
}