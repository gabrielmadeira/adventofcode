#include <bits/stdc++.h>

using namespace std;

int main() {
    string dirs;
    cin >> dirs;

    unordered_map<string, string> lDir;
    unordered_map<string, string> rDir;
    vector<string> current;
    string line;
    while(getline(cin, line)) {
        if(line == "") continue;
        string source = line.substr(0,3);
        if(source[2] == 'A') current.push_back(source);
        string l = line.substr(7,3);
        string r = line.substr(12,3);
        lDir[source] = l;
        rDir[source] = r;
    }

    vector<long> stepCount(current.size(), 0);
    
    while(true) {
        // if(stepCount == 6) break;
        int allZEnding = 1;
        for(int i=0; i<current.size(); i++) {
            // cout << current[i] << "-";
            if(current[i][2] == 'Z') continue;
            if(dirs[stepCount[i]%dirs.size()] == 'L') 
                current[i] = lDir[current[i]];
            else
                current[i] = rDir[current[i]];
            if(allZEnding && current[i][2] != 'Z') allZEnding = 0;
            stepCount[i]++;
        }
        // cout << endl;
        if(allZEnding) break;
    }
    long long lcmCalc = stepCount[0];
    for(int i=1; i<stepCount.size(); i++) {
        lcmCalc = lcm(lcmCalc, stepCount[i]);
    }
    cout << lcmCalc << endl;
}
