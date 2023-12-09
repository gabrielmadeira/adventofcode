#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;

    vector<long> seeds;
    while(cin >> input && isdigit(input[0])) {
        seeds.push_back(stol(input));
        // cout << input << "-";
    }
    // cout << "\n";

    for(int mapCount=0; mapCount<7; mapCount++) {
        cin >> input;
        vector<vector<long>> map;
        while(cin >> input && isdigit(input[0])) {
            vector<long> range = { stol(input), 0, 0 };
            cin >> range[1] >> range[2];
            // cout << range[0] << "-" << range[1] << "-" << range[2] <<"\n";
            map.push_back(range);
        }
        // cout << "============================\n";
        // continue;
        for(int seedI = 0; seedI < seeds.size(); seedI++) {
            for(int i=0; i<map.size(); i++) {
                if(seeds[seedI] >= map[i][1] && seeds[seedI] < map[i][1]+map[i][2]) {
                    // cout << "(" << map[i][1] << ")";
                    seeds[seedI] = seeds[seedI] + (map[i][0]-map[i][1]);
                    break;
                }
            }
            // cout << seeds[seedI] << "-";
        }
        // cout << "\n";
    }

    long minLocation = LONG_MAX;
    for(long seed : seeds) {
        if(seed < minLocation) minLocation = seed;
    }
    cout << minLocation << "\n";
}
