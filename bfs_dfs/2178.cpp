#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <cstdio>

using namespace std;

int n, m;
int v[101][101];
int chk[101][101] = {0, };
// check배열의 역할 및 0 : 방문 안한 것
// 1이상 : 방문한 것이면서 0,0로부터의 거리

//오른쪽: {0, 1}, 아래: {1, 0}, 왼쪽: {0, -1}, 위:{-1, 0}
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};


void bfs(int x, int y){

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    pair<int, int> f;

    chk[x][y] = 1;//방문했습니다.


    while(!q.empty()){
        
        f = q.front();

        q.pop();

        for(int i=0; i<4; i++){

            int nx = f.first + dx[i];
            int ny = f.second + dy[i];


            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (v[nx][ny] == 1 && chk[nx][ny] == 0){

                    q.push(make_pair(nx,ny));
                    chk[nx][ny] = chk[f.first][f.second] + 1;//움직인 칸수
                }
            }
            

        }


    }
    
    cout << chk[n-1][m-1] << endl;



}



int main(){

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%1d", &v[i][j]); 
        }
    }

    bfs(0, 0);

    return 0;
}