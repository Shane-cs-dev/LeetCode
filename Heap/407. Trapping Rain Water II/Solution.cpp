#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
private:
    class Cell {
        public:
            int height;
            int row;
            int col;

            // Constructor
            Cell(int h, int r, int c) : height(h), row(r), col(c) {}

            // Destructor
            ~Cell() {}
    };

public:
    // Define the exploration direction
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        // Define the size of the matrix heightMap
        int r = (int)heightMap.size();
        int c = (int)heightMap[0].size();

        // Create a empty min-heap and add all edge locations into it
        auto cmp = [](auto &a, auto &b) {
            return a.height > b.height;
        };
        priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);

        // Create a matrix to track the visited location
        vector<vector<bool>> used(r, vector<bool>(c, false));

        // Initialize the pq
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    // Add into the heap and maark as visited
                    pq.push(Cell(heightMap[i][j], i, j));
                    used[i][j] = true;
                }
            }
        }

        // BFS operation
        int totalWaterVol = 0;
        while (!pq.empty()) {
            // Get current Cell
            auto currCell = pq.top(); pq.pop();

            // Define current height, row and col
            int currH = currCell.height;
            int currR = currCell.row;
            int currC = currCell.col;

            // Loop through its neighbor, add into heap, and update the totalWaterVol is possible
            for (auto& [dr, dc] : dir) {
                int nextR = currR + dr;
                int nextC = currC + dc;

                // Check if the location is valid
                if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c) {
                    if (!used[nextR][nextC]) {
                        // Define height for neighbor
                        int neiHeight = heightMap[nextR][nextC];

                        // Update totalWaterVol if the neighbor is shorter
                        if (currH > neiHeight) {
                            totalWaterVol += currH - neiHeight;
                        }
                        pq.push(Cell(max(currH, neiHeight), nextR, nextC));
                        used[nextR][nextC] = true;
                    }
                }
            }
        }

        return totalWaterVol;
    }
};
