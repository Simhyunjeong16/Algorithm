#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

queue<tuple<int, int, int>> q;
int a[100][100][100];
int dist[100][100][100];
int n, m, h;
    
int main(){
    cin >> m >> n >> h;
    
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
        
                cin >> a[i][j][k];

                if(a[i][j][k] == 1){
                    dist[i][j][k] = 0;
                    q.push(make_tuple(i, j, k));
                }
                else dist[i][j][k] = -1;
                
            }
        }
    }

    while (!q.empty()){

        int x, y, z;
        std::tie(x, y, z) = q.front();
        q.pop();

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h){
                if(a[nx][ny][nz] == 0 && dist[nx][ny][nz] == -1){
                    dist[nx][ny][nz] = dist[x][y][z] + 1;
                    q.push(make_tuple(nx, ny, nz));
                }
            }
        }

    }
    
    int result = 0;
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
        
                if(a[i][j][k] == 0 && dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                
                result = max(result, dist[i][j][k]);
            }
        }
    }

 
    
    cout << result;    
    return 0;
}