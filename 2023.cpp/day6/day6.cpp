#include <bits/stdc++.h>

using namespace std;

int main() {

    string input;
    cin >> input;
    vector<int> timeVec;
    while(cin >> input && isdigit(input[0])) {
        timeVec.push_back(stol(input));
        // cout << input << "-";
    }
    vector<int> distanceVec;
    while(cin >> input) {
        distanceVec.push_back(stol(input));
        // cout << input << "-";
    }
    int output = 1;
    for(int i=0; i<timeVec.size(); i++) {
        int wt = 0;
        int rt = timeVec[i]-wt;
        int x = wt*rt;
        while(x<=distanceVec[i]) {
            wt++;
            rt = timeVec[i]-wt;
            x = wt*rt;
            // cout << x << "-";
        }
        // cout << endl;

        int minWt = wt;
        wt = timeVec[i];
        rt = timeVec[i]-wt;
        x = wt*rt;
        while(x<=distanceVec[i]) {
            wt--;
            rt = timeVec[i]-wt;
            x = wt*rt;
            // cout << x << "-";
        }
        // cout << endl;
        int maxWt = wt;
        // cout << maxWt << "--" << minWt << endl;
        output *= maxWt-minWt+1;
    }
    cout << output << "\n";
}