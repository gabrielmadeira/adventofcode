#include <bits/stdc++.h>

using namespace std;

int main() {

    string input;
    cin >> input;
    vector<long> timeVec;
    string timeStr = "";
    while(cin >> input && isdigit(input[0])) {
        timeStr += input;
    }
    timeVec.push_back(stol(timeStr));

    vector<long> distanceVec;
    string distanceStr = "";
    while(cin >> input) {
        distanceStr += input;
    }
    distanceVec.push_back(stol(distanceStr));
    cout << timeStr << "-" << distanceStr << endl;
    
    long output = 1;
    for(int i=0; i<timeVec.size(); i++) {
        long wt = 0;
        long rt = timeVec[i]-wt;
        long x = wt*rt;
        while(x<=distanceVec[i]) {
            wt++;
            rt = timeVec[i]-wt;
            x = wt*rt;
            // cout << x << "-";
        }
        // cout << endl;

        long minWt = wt;
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
        long maxWt = wt;
        // cout << maxWt << "--" << minWt << endl;
        output *= maxWt-minWt+1;
    }
    cout << output << "\n";
}