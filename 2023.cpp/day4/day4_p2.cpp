#include <bits/stdc++.h>

using namespace std;

int main() {
    string card;
    vector<int> cardCount(250, 1);
    int cardIndex = 0;
    while(cin >> card) {
        cardIndex++;
        string cardN;
        cin >> cardN;
        unordered_map<int, bool> winningNums;
        string winningN;
        while(cin >> winningN && isdigit(winningN[0])) {
            winningNums[stoi(winningN)] = true;
        }

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
        // cout << winningNumbersCount << "--";
        if(winningNumbersCount > 0) {
            for(int i=cardIndex; i<cardIndex+winningNumbersCount; i++) {
                cardCount[i] += 1*cardCount[cardIndex-1];
            }
        }
        // cout << winningNumbersCount << "---" << sum << "\n";
        // cout << "\n";
    }
    // cout << "\n";
    int sum = 0;
    for(int i=0; i<cardIndex; i++) {
        // cout << cardCount[i] << "\n";
        sum += cardCount[i];
    }
    cout << sum << "\n";
}