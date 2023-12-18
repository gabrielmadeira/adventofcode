#include <bits/stdc++.h>

using namespace std;

long rec(string& row, int rowI, vector<int>& seq, int seqI, string out, unordered_map<string, long>& hash) {
    string key = to_string(rowI) + "-" + to_string(seqI);
    if(hash.count(key)) return hash[key]; 
    
    if(seqI==seq.size() && rowI>=row.size()) { 
        hash[key] = 1;
        return 1; 
    }
    if(rowI>=row.size()) {  
        hash[key] = 0;
        return 0; 
    }
    while(row[rowI] == '.') { rowI++; out += "."; }
    if(rowI>=row.size()) { hash[key] = rec(row, rowI, seq, seqI, out, hash); return hash[key]; }
    long count = 0;
    if(row[rowI] == '?') {
        count += rec(row, rowI+1, seq, seqI, out+".", hash);
    }
    hash[key] = count;
    int currSeq = seq[seqI];
    while(currSeq > 0) {
        if(row[rowI] != '?' && row[rowI] != '#') { 
            return count; 
        }
        out += to_string(seq[seqI]);
        rowI++;
        currSeq--;
    }
    if(row[rowI] != '.' && row[rowI] != '?' && rowI<row.size()) { 
        return count; 
    }
    rowI++;
    out += ".";
    seqI++;
    hash[key] += rec(row, rowI, seq, seqI, out, hash);
    return hash[key];
}

int main() {
    long long sum = 0;
    string line;
    while(getline(cin, line)) {
        int div = 0;
        while(line[div] != ' ') div++;
        string row = line.substr(0,div);
        row = row + "?" + row + "?" + row + "?" + row + "?" + row;
        line = line.substr(div+1, line.size()-div-1);
        line = line + "," + line + "," + line + "," + line + "," + line;
        vector<int> seq;
        size_t pos = 0;
        string token;
        while((pos=line.find(",")) != string::npos) {
            token = line.substr(0, pos);
            seq.push_back(stoi(token));
            line.erase(0, pos+1);
        }
        seq.push_back(stoi(line));
        unordered_map<string, long> hash;
        long count = rec(row, 0, seq, 0, "", hash);
        sum += count;
    }
    cout << sum << endl;
}