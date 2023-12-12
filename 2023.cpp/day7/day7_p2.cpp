#include <bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<char, string> cardMap;
    cardMap['A'] = "12";
    cardMap['K'] = "11";
    cardMap['Q'] = "10";
    cardMap['T'] = "09";
    cardMap['9'] = "08";
    cardMap['8'] = "07";
    cardMap['7'] = "06";
    cardMap['6'] = "05";
    cardMap['5'] = "04";
    cardMap['4'] = "03";
    cardMap['3'] = "02";
    cardMap['2'] = "01";
    cardMap['J'] = "00";

    map<long, int> handMap; // value, bid

    string input;
    while(cin >> input) {
        vector<int> cardTypeCount(13, 0);

        
        string handValueStr = "";
        for(int i=0; i<input.size(); i++) {
            handValueStr += cardMap[input[i]];
            cardTypeCount[stoi(cardMap[input[i]])] += 1;
        }

        int highQtdIndex = 1;
        int highQtd = 0;

        for(int i=1; i<cardTypeCount.size(); i++) {
            if(cardTypeCount[i] > highQtd) {
                highQtdIndex = i;
                highQtd = cardTypeCount[i];
            }
        }

        cardTypeCount[highQtdIndex] += cardTypeCount[0];

        string type = "1";
        for(int i=1; i<cardTypeCount.size(); i++) {
            if(cardTypeCount[i] == 0) continue;
            if(cardTypeCount[i] == 5) {
                type = "7"; break;
            }
            if(cardTypeCount[i] == 4) {
                type = "6"; break;
            }
            if(cardTypeCount[i] == 3) {
                if(type == "2") type = "5"; 
                else type = "4";
                continue;
            }
            if(cardTypeCount[i] == 2) {
                if(type == "4") type = "5"; 
                else if(type == "2") type = "3";
                else type = "2";
            }
        }

        handValueStr = type + handValueStr;

        int bid;
        cin >> bid;
        handMap[stol(handValueStr)] = bid;
    }
    int output = 0;
    int rank = 1;
    for (auto i = handMap.begin(); i != handMap.end(); i++) {
        output += i->second * rank;
        // cout << i->first << "-" << i->second << "-" << rank << endl;
        rank++;
    }
    cout << output << endl;
}