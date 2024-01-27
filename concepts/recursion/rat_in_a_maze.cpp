// Consider a rat placed at (0, 0) in a square matrix
// of order N * N. It has to reach the destination at
// (N - 1, N - 1). Find all possible paths that the rat
// can take to reach from source to destination. The
// directions in which the rat can move are 'U'(up),
// 'D'(down), 'L' (left), 'R' (right). Value 0 at a
// cell in the matrix represents that it is blocked
// and rat cannot move to it while value 1 at a cell
// in the matrix represents that rat can be travel through it.
// Note : In a path, no cell can be visited more than
// one time.If the source cell is 0, the rat cannot move to any other cell.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, int n, vector<vector<int>> &visited, vector<vector<int>> &m)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] == 0 && m[newx][newy] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &m, int n, int srcx, int srcy, vector<vector<int>> &visited, vector<string> &ans, string path)
{
    // base case
    if (srcx == n - 1 && srcy == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[srcx][srcy] = 1;

    // down
    int newx = srcx + 1;
    int newy = srcy;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }

    // left
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }

    // right
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }

    // up
    newx = srcx - 1;
    newy = srcy;
    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, newx, newy, visited, ans, path);
        path.pop_back();
    }

    visited[srcx][srcy] == 0;
}
int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 1, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans;
    vector<vector<int>> visited = m;

    int srcx, srcy = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            visited[i][j] = 0;
        }
    }
    if (m[0][0] == 0)
    {
        cout << "Not possible";
        return 0;
    }

    string path = "";
    solve(m, 4, srcx, srcy, visited, ans, path);
    cout << "All Possible Paths:\n"
         << path;
    return 0;
}