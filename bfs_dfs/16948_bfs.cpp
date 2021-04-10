#include <iostream>
#include <queue>

using namespace std;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int n, r1, r2, c1, c2;
int a[201][201] = {0};

void bfs(){

    queue<pair<int, int>> q;

    q.push({r1, c1});

    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == r2 && y == c2){
            cout << a[x][y];
            break;
        }

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0){
                q.push({nx, ny});
                a[nx][ny] = a[x][y] + 1;
            }
        }
    }

    if(q.empty()) cout << -1;
}

int main(){

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    bfs();

    return 0;
}
