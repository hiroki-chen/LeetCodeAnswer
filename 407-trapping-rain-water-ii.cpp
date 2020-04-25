/*
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
*/

class Solution {
public:
    struct Cell {
        int x, y, h;

        Cell() {}; 
        Cell(int xx, int yy, int hh) : x(xx), y(yy), h(hh) {};

        bool operator < (const Cell& c) const {
            return h > c.h;
        }
    };

    int compare(Cell x, Cell y) {
        if (x.h > y.h) return 1;
        else if (x.h == y.h) return 0;
        else return -1;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;

        priority_queue<Cell> minHeap;
        int rows = heightMap.size();
        int cols = heightMap[0].size();

        vector<vector<bool> > visited(rows, vector<bool>(cols,false));
        for (int i = 0; i < cols; i++) {
            minHeap.push({0, i, heightMap[0][i]});
            minHeap.push({rows - 1, i, heightMap[rows - 1][i]});
            visited[0][i] = true;
            visited[rows - 1][i] = true;
        }

        for (int j = 1; j < rows - 1; j++) {
            minHeap.push({j, 0, heightMap[j][0]});
            minHeap.push({j, cols - 1, heightMap[j][cols - 1]});
            visited[j][0] = true;
            visited[j][cols - 1] = true;
        } //把四周的元素都push进队列中即可。

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int ans = 0;
        while(!minHeap.empty()) {
            Cell curCell = minHeap.top();
            minHeap.pop();

            for (int i = 0; i < 4; i++) {
                int nx = curCell.x + dx[i];
                int ny = curCell.y + dy[i];

                if (nx >= 0 && nx < rows &&
                    ny >= 0 && nsy < cols &&
                    visited[nx][ny] == false) /*该位置合法*/{
                        visited[nx][ny] = true;
                        minHeap.push({nx, ny, max(heightMap[nx][ny], curCell.h)}); // 之所以取得最大值是因为已经灌水到更大的值了。
                        if (heightMap[nx][ny] < curCell.h) {
                            ans += curCell.h - heightMap[nx][ny];
                        }
                    }
            }
        }
        return ans;
    }
};