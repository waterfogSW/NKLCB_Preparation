#include <bits/stdc++.h>
using namespace std;

#define INF 100000

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char miro[100][100];
bool v[100][100];

int dfs(int x, int y, int count) {
    if (x == n-1 && y == m-1) {
        return count;
    }
    int temp = INF;
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (!v[cy][cx] && 0 <= cx && cx <= n-1 && 0 <= cy && cy <= m-1) {
            v[cy][cx] = true;
            if (miro[cy][cx] == '1')
                temp = min(temp, dfs(cx, cy, count + 1));
            else if (miro[cy][cx] == '0') {
                temp = min(temp, dfs(cx, cy, count));
            }
            v[cy][cx] = false;
        }
    }
    return temp;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> miro[i][j];
        }
    }

    v[0][0] = true;

    cout << dfs(0, 0, 0);
}