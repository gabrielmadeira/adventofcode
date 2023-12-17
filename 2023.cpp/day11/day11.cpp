#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> colCheck;
    vector<string> map;
    string line;
    while(getline(cin, line)) {
        if(colCheck.empty()) colCheck = vector<int>(line.size(), 0);
        int empty = 1;
        for(int i=0; i<line.size(); i++) {
            if(line[i] == '#') { 
                if(!colCheck[i]) colCheck[i] = 1;
                if(empty) empty = 0; 
            }
        }
        map.push_back(line);
        if(empty) { 
            string emptyLine(line.size(), '.');
            map.push_back(emptyLine);
        }
    }
    int size = map[0].size();
    int inc = 0;
    for(int i=0; i<size; i++) {
        if(!colCheck[i]) {
            for(int j=0; j<map.size(); j++) {
                map[j].insert(i+inc, ".");
            }
            inc++;
        }
    }
    vector<int> galaxyI;
    vector<int> galaxyJ;
    for(int i=0; i<map.size(); i++) {
        for(int j=0; j<map[0].size(); j++) {
            if(map[i][j] == '#') {
                galaxyI.push_back(i); galaxyJ.push_back(j);
            }
        }
    }
    int sum = 0;
    for(int a=0; a<galaxyI.size(); a++) {
        for(int b=a+1; b<galaxyI.size(); b++) {
            sum += abs(galaxyI[a]-galaxyI[b]) + abs(galaxyJ[a]-galaxyJ[b]);
        }
    }
    cout << sum << endl;
}