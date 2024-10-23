#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// Directions based on the move rule
vector<tuple<int, int>> getDirections(const pair<int, int>& moveRule) {
    return {
        {moveRule.first, moveRule.second},   // Forward
        {moveRule.second, -moveRule.first},  // Right (90 degrees clockwise)
        {-moveRule.second, moveRule.first},   // Left (90 degrees counterclockwise)
        {-moveRule.first, -moveRule.second}   // Backward (180 degrees)
    };
}

int minMovesToDestination(const vector<vector<int>>& grid, const pair<int, int>& src,
                          const pair<int, int>& dest, const pair<int, int>& moveRule) {
    int M = grid.size();
    int N = grid[0].size();
    queue<tuple<int, int, int>> q; // (x, y, moves)
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    // Directions based on the move rule
    auto directions = getDirections(moveRule);
    
    q.push({src.first, src.second, 0}); // Starting point with 0 moves
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        auto [x, y, moves] = q.front();
        q.pop();

        // Check if we have reached the destination
        if (x == dest.first && y == dest.second) {
            return moves;
        }

        // Explore the four possible moves
        for (const auto& [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            // Check if the new position is within bounds and is traversable (0)
            if (newX >= 0 && newX < M && newY >= 0 && newY < N && 
                grid[newX][newY] == 0 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY, moves + 1});
            }
        }
    }

    return -1; // If the destination cannot be reached
}

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int srcX, srcY;
    cin >> srcX >> srcY;
    
    int destX, destY;
    cin >> destX >> destY;
    
    int moveX, moveY;
    cin >> moveX >> moveY;
    
    pair<int, int> src = {srcX, srcY};
    pair<int, int> dest = {destX, destY};
    pair<int, int> moveRule = {moveX, moveY};
    
    int result = minMovesToDestination(grid, src, dest, moveRule);
    cout << result;

    return 0;
}
