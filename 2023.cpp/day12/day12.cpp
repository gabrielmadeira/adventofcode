#include <bits/stdc++.h>

using namespace std;

void rec(string& row, int rowI, vector<int>& seq, int seqI, int& count, string out) {
    // cout << rowI << "-" << seqI << "-" << count << "-" << out << endl;
    
    if(seqI==seq.size() && rowI>=row.size()) { 
        count++; 
        // cout << "----->>>>" << out << endl; 
        return; 
    }
    if(rowI>=row.size()) { 
        // cout << "-a-\n"; 
        return; 
    }
    while(row[rowI] == '.') { rowI++; out += "."; }
    if(rowI>=row.size()) { rec(row, rowI, seq, seqI, count, out); return; }
    // cout << "aaa\n";
    if(row[rowI] == '?') {
        rec(row, rowI+1, seq, seqI, count, out+".");
    }
    int currSeq = seq[seqI];
    while(currSeq > 0) {
        if(row[rowI] != '?' && row[rowI] != '#') { 
            // cout << "-aa-\n"; 
            return; 
        }
        out += to_string(seq[seqI]);
        rowI++;
        currSeq--;
    }
    if(row[rowI] != '.' && row[rowI] != '?' && rowI<row.size()) { 
        // cout << rowI << "-aaaa-\n"; 
        return; 
    }
    rowI++;
    out += ".";
    seqI++;
    rec(row, rowI, seq, seqI, count, out);
}
// .1.333.1
// ?#?#?#?#?#?#?#? 1,3,1,6

// ???.### 1,1,3

// .??..??...?##. 1,1,3



int main() {
    int sum = 0;
    string line;
    while(getline(cin, line)) {
        int div = 0;
        while(line[div] != ' ') div++;
        string row = line.substr(0,div);
        // cout << row << endl;
        line = line.substr(div+1, line.size()-div-1);
        vector<int> seq;
        size_t pos = 0;
        string token;
        while((pos=line.find(",")) != string::npos) {
            token = line.substr(0, pos);
            seq.push_back(stoi(token));
            // cout << token << "-";
            line.erase(0, pos+1);
        }
        seq.push_back(stoi(line));
    //    cout << line << endl;
        int count = 0;
        rec(row, 0, seq, 0, count, "");
        // cout << count << endl;
        sum += count;
    }
    cout << sum << endl;
}