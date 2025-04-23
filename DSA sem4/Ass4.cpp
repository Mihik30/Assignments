#include <iostream>
using namespace std;

const int MAX = 100;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int parent[MAX][MAX][2]; // To store parent cells for path tracing
int n, m;

// Directions: right, down, left, up
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// Simulating a queue
struct Point {
    int x, y;
};

Point queue[MAX * MAX];
int front = 0, rear = 0;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m &&
           maze[x][y] == 1 && !visited[x][y];
}

void bfs(int startX, int startY) {
    // Enqueue the starting point
    queue[rear++] = {startX, startY};
    visited[startX][startY] = true;
    parent[startX][startY][0] = -1; // no parent
    parent[startX][startY][1] = -1;

    while (front < rear) {
        Point curr = queue[front++];

        if (curr.x == n - 1 && curr.y == m - 1) {
            // Reached destination
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = curr.x + dx[d];
            int ny = curr.y + dy[d];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                queue[rear++] = {nx, ny};
                parent[nx][ny][0] = curr.x;
                parent[nx][ny][1] = curr.y;
            }
        }
    }
}

void printPath(int x, int y) {
    if (x == -1 || y == -1)
        return;

    printPath(parent[x][y][0], parent[x][y][1]);
    cout << "(" << x << ", " << y << ") ";
}

int main() {
    cout << "Enter maze dimensions (rows and columns): ";
    cin >> n >> m;

    cout << "Enter maze matrix (1 = open, 0 = blocked):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    bfs(0, 0);

    if (visited[n - 1][m - 1]) {
        cout << "Path found (from start to goal):\n";
        printPath(n - 1, m - 1);
        cout << "\n";
    } else {
        cout << "No path found.\n";
    }

    return 0;
}
