#include <bits/stdc++.h>

using namespace std;

void bfs(vector<string> &map, int pI, int pJ, int &count) {
    queue<int> posI;
    queue<int> posJ;
    posI.push(pI);
    posJ.push(pJ);
    int inner = 1;
    while(!posI.empty()) {
        int i = posI.front(); posI.pop();
        int j = posJ.front(); posJ.pop();
        map[i][j] = 'T';
        if(inner && (i == 0 || i == map.size()-1 || j == 0 || j == map[0].size()-1)) inner = 0;

        if(i>0 && map[i-1][j] != 'P' && map[i-1][j] != 'I' && map[i-1][j] != 'T' && map[i-1][j] != 'O') {
            posI.push(i-1); posJ.push(j);
        } 
        if(i<map.size()-1 && map[i+1][j] != 'P' && map[i+1][j] != 'I' && map[i+1][j] != 'T' && map[i+1][j] != 'O') {
            posI.push(i+1); posJ.push(j);
        }
        if(j>0 && map[i][j-1] != 'P' && map[i][j-1] != 'I' && map[i][j-1] != 'T' && map[i][j-1] != 'O') {
            posI.push(i); posJ.push(j-1);
        }
        if(j<map[0].size()-1 && map[i][j+1] != 'P' && map[i][j+1] != 'I' && map[i][j+1] != 'T' && map[i][j+1] != 'O') {
            posI.push(i); posJ.push(j+1);
        }
    }

    for(int i=0; i<map.size(); i++) {
        for(int j=0; j<map[0].size(); j++) {
            cout << map[i][j];
            if(map[i][j] == 'T') {
                if(inner) {
                    map[i][j] = 'I';
                    count++;
                } else map[i][j] = 'O';
            }
        }
        cout << endl;
    }
    cout << "===============================================\n";
}

int main() {
    vector<string> map;
    string line;
    int lineCount = 0;
    int sPosX = -1;
    int sPosY = -1;
    while(getline(cin, line)) {
        map.push_back(line);
        if(sPosX == -1) for(int i=0; i<line.size(); i++) if(line[i] == 'S') {
            sPosX = i;
            sPosY = lineCount;
            break;
        }
        lineCount++;
    }

    int lPosX = sPosX;
    int lPosY = sPosY;
    int cPosX = sPosX;
    int cPosY = sPosY;

    float stepCount = 0;
    
    while(cPosX != sPosX || cPosY != sPosY || (lPosX == sPosX && lPosY == sPosY)) {
        // cout << "posX:" << cPosX << "  posY:" << cPosY << endl;
        int nextLPosX = cPosX;
        int nextLPosY = cPosY; 
        if(cPosY>0 && cPosY-1 != lPosY && map[cPosY][cPosX] != '7' && map[cPosY][cPosX] != 'F' && map[cPosY][cPosX] != '-' && (
            (map[cPosY-1][cPosX] == '|') || 
            (map[cPosY-1][cPosX] == '7') || 
            (map[cPosY-1][cPosX] == 'F') || 
            map[cPosY-1][cPosX] == 'S'))  cPosY--;

        else if(cPosY<map.size()-1 && cPosY+1 != lPosY && map[cPosY][cPosX] != 'L' && map[cPosY][cPosX] != 'J' && map[cPosY][cPosX] != '-' && (
            (map[cPosY+1][cPosX] == '|') || 
            (map[cPosY+1][cPosX] == 'L') || 
            (map[cPosY+1][cPosX] == 'J') || 
            map[cPosY+1][cPosX] == 'S')) cPosY++;

        else if(cPosX>0 && cPosX-1 != lPosX && map[cPosY][cPosX] != '|' && map[cPosY][cPosX] != 'L' && map[cPosY][cPosX] != 'F' && (
            (map[cPosY][cPosX-1] == '-') || 
            (map[cPosY][cPosX-1] == 'L') || 
            (map[cPosY][cPosX-1] == 'F') || 
            map[cPosY][cPosX-1] == 'S')) cPosX--;

        else if(cPosX<map[0].size()-1 && cPosX+1 != lPosX && map[cPosY][cPosX] != '|' && map[cPosY][cPosX] != 'J' && map[cPosY][cPosX] != '7' && (
            (map[cPosY][cPosX+1] == '-') || 
            (map[cPosY][cPosX+1] == '7') || 
            (map[cPosY][cPosX+1] == 'J') || 
            map[cPosY][cPosX+1] == 'S')) cPosX++;

        else { cout << "ERROR\n"; break;}
        lPosX = nextLPosX;
        lPosY = nextLPosY;

        map[cPosY][cPosX] = 'P';

        stepCount++;
    }

    int tilesCount = 0;

    for(int i=0; i<map.size(); i++) {
        for(int j=0; j<map[0].size(); j++) {
            if(map[i][j] != 'P' && map[i][j] != 'O' && map[i][j] != 'I') bfs(map, i, j, tilesCount);
        }
    }

    cout << tilesCount << endl;
}