#include <iostream>
#include <queue>

using namespace std;

int n, m;
// bool chk[1001][1001] = { false };
int a[1001][1001];
int dist[1001][1001];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

queue<pair<int, int>> q;
pair<int, int> f;


int main(){

    scanf("%d %d", &m, &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);

            if(a[i][j] == 1){
                q.push(make_pair(i, j));
                dist[i][j] = 0;
                // chk[i][j] = true;//방문
            }
            else dist[i][j] = -1;

        }
    }

    while(!q.empty()){

        f = q.front();
        q.pop();


        for(int i=0; i<4; i++){
            int nx = f.first + dx[i];
            int ny = f.second + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(a[nx][ny] == 0 && dist[nx][ny] == -1){
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[f.first][f.second] + 1;
                    // chk[nx][ny] = true;//방문
                }
            }

        }
        

    }
  
    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            result = max(result, dist[i][j]);
        }

    }

    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0 && dist[i][j] == -1)
                result = -1;
        }
    }
        
    cout << result;
    
    return 0;
}