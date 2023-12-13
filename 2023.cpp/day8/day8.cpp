#include <bits/stdc++.h>

using namespace std;

int main() {
    string dirs;
    cin >> dirs;

    unordered_map<string, string> lDir;
    unordered_map<string, string> rDir;
    string line;
    while(getline(cin, line)) {
        if(line == "") continue;
        string source = line.substr(0,3);
        string l = line.substr(7,3);
        string r = line.substr(12,3);
        lDir[source] = l;
        rDir[source] = r;
    }

    long stepCount = 0;

    string current = "AAA";
    while(current != "ZZZ") {
        if(dirs[stepCount%dirs.size()] == 'L') 
            current = lDir[current];
        else
            current = rDir[current];
        stepCount++;
    }

    cout << stepCount << endl;
}
