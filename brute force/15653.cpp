#include <iostream>
#include <queue>

using namespace std;

char a[10][10];
bool chk[10][10][10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n,m;
int r1,r2,b1,b2;

queue <pair <pair<int, int>, pair<int, int>>> q;//빨 파

int bfs(){

    q.push(make_pair(make_pair(r1,r2), make_pair(b1,b2)));
    chk[r1][r2][b1][b2] = true;

    int cnt=0;
    while(!q.empty()){
        int qSize = q.size();

        while(qSize--){
            
            int rx = q.front().first.first; 
            int ry = q.front().first.second;
            int bx = q.front().second.first;
            int by = q.front().second.second;

            q.pop();

            if(a[rx][ry] == 'O' && a[rx][ry] != a[bx][by]) return cnt;//탈출
            
            for(int i=0; i<4; i++){
                
                int nrx = rx, nry = ry, nbx = bx, nby = by;
                int red_move = 0, blue_move = 0;

                while(a[nrx + dx[i]][nry + dy[i]] != '#' && a[nrx][nry] != 'O'){//빨간구슬 움직이기
                    nrx += dx[i]; nry += dy[i];
                    red_move++;
                }

                while(a[nbx + dx[i]][nby + dy[i]] != '#' && a[nbx][nby] != 'O'){//파란구슬 움직이기
                    nbx += dx[i]; nby += dy[i];
                    blue_move++;
                }

                if(nrx == nbx && nry == nby){//빨,파 같은 위치에 있다면?
                    if(a[nrx][nry] == 'O') continue;

                    if(red_move > blue_move){ nrx -= dx[i]; nry -= dy[i];}//파란구슬이 먼저 도착
                    else{ nbx -= dx[i]; nby -= dy[i]; }//빨간구슬이 먼저 도착
                    
                }

                if(chk[nrx][nry][nbx][nby] == true) continue;//이미 방문한적 있으면 무시

                q.push(make_pair(make_pair(nrx,nry), make_pair(nbx,nby)));
                chk[nrx][nry][nbx][nby] = true;//방문
            }

        }

        cnt++;
    }

    return -1;//문제조건(빨간 구슬을 구멍을 통해 빼낼 X)
}

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];

            if(a[i][j] == 'R'){r1 = i, r2 = j;}
            else if (a[i][j] == 'B') {b1 = i, b2 = j;}
        }
    }
            

    cout << bfs();
    return 0;
}