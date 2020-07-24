#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char a[1001][1001];
int dist[1001][1001][2];//wall 뚫을 수 있는 횟수
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

struct map {//구조체
    int x, y, w;
};

int bfs(){

    queue<map> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int w = q.front().w;

        q.pop();
        
        if(x == n-1 && y == m-1) return dist[x][y][w];//최소 거리

        for(int i = 0; i < 4; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >=0 && ny < m && dist[nx][ny][w] == 0){
                if(a[nx][ny] == '0'){
                    dist[nx][ny][w] = dist[x][y][w] + 1;
                    q.push({nx, ny, w});
  
                }
                else if(a[nx][ny] == '1' && w == 0){ //wall 1개 깼음. 이제 계속 w는 1임
                    dist[nx][ny][1] = dist[x][y][w] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }

    return -1;
}


int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    cout << bfs();

    return 0;
}