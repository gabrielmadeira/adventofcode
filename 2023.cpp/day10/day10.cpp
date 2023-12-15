#include <bits/stdc++.h>

using namespace std;

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
        stepCount++;
    }

    cout << ceil(stepCount/2) << endl;
}