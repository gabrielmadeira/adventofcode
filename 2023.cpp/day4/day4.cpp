#include <bits/stdc++.h>

using namespace std;

int main() {

    int sum = 0;

    string card;
    while(cin >> card) {
        // cout << "=============\n";
        string cardN;
        cin >> cardN;
        // cout << cardN;
        unordered_map<int, bool> winningNums;
        string winningN;
        while(cin >> winningN && isdigit(winningN[0])) {
            winningNums[stoi(winningN)] = true;
            // cout << winningN << "-";
        }
        // cout << winningN << "\n";
        // string div;
        // cin >> div;
        // cout << div;
        // cin.ignore();
        // cin.ignore();
        // vector<int> nums;
        int winningNumbersCount = 0;
        int num;
        while(cin >> num) {
            // nums.push_back(num);
            if(winningNums.count(num)) {
                winningNumbersCount++;
            }
            // cout << num << "-";
            if(cin.peek() == '\n') break;
        }

        if(winningNumbersCount > 0) sum += pow(2,(winningNumbersCount-1));
        cout << winningNumbersCount << "---" << sum << "\n";
        // cout << "\n";
    }
    // cout << sum << "\n";
}