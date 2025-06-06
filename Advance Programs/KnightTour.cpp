#include <bits/stdc++.h>
using namespace std;

vector<int> dx{-2, -1, 1, 2, 2, 1, -1, -2};
vector<int> dy{1, 2, 2, 1, -1, -2, -2, -1};
int ans=0;
bool isSafe(vector<vector<int>>& grid, int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == -1;
}

void display(const vector<vector<int>>& grid, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << "\n....\n";
}

void solve(vector<vector<int>>& grid, int x, int y, int n, int moveCount) {
    grid[x][y] = moveCount;
    if (moveCount == n * n - 1) {
        display(grid, n);
        ans++;
        grid[x][y] = -1;
        return;
    }

    for (int k = 0; k < 8; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (isSafe(grid, nx, ny, n)) {
            solve(grid, nx, ny, n, moveCount + 1);
        }
    }

    grid[x][y] = -1;
    // cout<<moveCount;
}

void KnightsTour(int n, int startX, int startY) {
    vector<vector<int>> grid(n, vector<int>(n, -1));
    solve(grid, startX, startY, n, 0);
}

int main() {
    int n;
    cout<<"Enter Size Of Grid:";
    cin >> n;
    KnightsTour(n, 0, 0);
    cout<<"Total ways: "<<ans;
}
