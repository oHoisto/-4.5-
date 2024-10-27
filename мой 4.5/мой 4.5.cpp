#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int numRows, numCols;
vector<vector<int>> vv;

int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isValid(int x, int y) {
    return (x >= 0 && x < numRows && y >= 0 && y < numCols && vv[x][y] == 1);
}

int Find(int startRow, int startCol) {
    queue<pair<int, int>> q;
    q.push({ startRow, startCol });
    vv[startRow][startCol] = 0;

    int area = 0;

    while (!q.empty()) {
        auto front = q.front();
        int x = front.first;
        int y = front.second;
        q.pop();
        area++;

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (isValid(newX, newY)) {
                q.push({ newX, newY });
                vv[newX][newY] = 0;
            }
        }
    }

    return area;
}

void countIslands() {
    int islandsCount = 0;
    int maxArea = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (vv[i][j] == 1) {
                int area = Find(i, j);
                islandsCount++;
                maxArea = max(maxArea, area);
            }
        }
    }
    cout << "Количество островов: " << islandsCount << endl;
    cout << "Площадь самого большого острова: " << maxArea << endl;
}

int main() {
    setlocale(0, "");
    vv = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1}
    };

    numRows = vv.size();
    numCols = vv[0].size();

    countIslands();
    return 0;
}
