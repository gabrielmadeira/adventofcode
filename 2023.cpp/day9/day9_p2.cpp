#include <bits/stdc++.h>

using namespace std;

int main() {

    int sumOutput = 0;

    string line;
    while(getline(cin, line)) {
        stringstream lineStream(line);
        vector<int> numbers(istream_iterator<int>(lineStream), {});
        vector<vector<int>> diffVecVec = { numbers };
        while(true) {
            vector<int> compVec = diffVecVec[diffVecVec.size()-1];
            if(compVec.size() == 1) break;

            int allZero = 1;
            vector<int> diffVec;
            for(int i=1; i<compVec.size(); i++) {
                int diff = compVec[i]-compVec[i-1];
                if (allZero && diff != 0) allZero = 0;

                diffVec.push_back(diff);
            }
            diffVecVec.push_back(diffVec);
            if(allZero) break;
        }

        int pred = 0;
        for(int i=diffVecVec.size()-2; i>=0; i--) {
            pred = diffVecVec[i][0]-pred;
        }
        sumOutput += pred;
    }

    cout << sumOutput << endl;
}