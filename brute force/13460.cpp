#include <iostream>
#include <queue>

using namespace std;

int n, m;
char a[10][10];
bool chk[10][10][10][10] = {false, };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair <pair<int, int>, pair<int, int>> > q;//빨간구슬, 파란구슬
int r1=0, r2=0;//빨간구슬
int b1=0, b2=0;//파란구슬

int bfs(){

    q.push(make_pair( make_pair(r1, r2), make_pair(b1, b2)));
    chk[r1][r2][b1][b2] = true;//방문

    int cnt = 0;//답(최단탈출거리)

    while(!q.empty()){
        int qSize = q.size();
        
        while (qSize--){ //bfs시 depth 계산 용이

            int rx = q.front().first.first;//빨x
            int ry = q.front().first.second;//빨y
            
            int bx = q.front().second.first;//파x
            int by = q.front().second.second;//파y

            q.pop();

            if(a[rx][ry] == 'O' && a[rx][ry] != a[bx][by])// 문제 조건(빨간 구슬 위치 != 파란 구슬 위치)
                return cnt;

            for(int i=0; i<4; i++){

                int n_rx = rx, n_ry = ry;
                int n_bx = bx, n_by = by;
                int red_move = 0, blue_move = 0;

                while(a[n_rx + dx[i]][n_ry + dy[i]] != '#' && a[n_rx][n_ry] != 'O'){//빨간구슬 기울인 방향으로 쭉
                    n_rx += dx[i];
                    n_ry += dy[i];

                    red_move++;
                }

                while(a[n_bx + dx[i]][n_by + dy[i]] != '#' && a[n_bx][n_by] != 'O'){//파란구슬 기울인 방향으로 쭉
                    n_bx += dx[i];
                    n_by += dy[i];

                    blue_move++;
                }


                //둘다 위치가 똑같다면 먼저 도착한 구슬이 그 위치 차지
                if(n_rx == n_bx && n_ry == n_by){
                    
                    if(a[n_rx][n_ry] == 'O') continue;//빨간구슬 탈출

                    if(red_move > blue_move){//파란구슬이 먼저도착
                        n_rx -= dx[i]; n_ry -= dy[i];//빨간구슬 한칸뒤로
                    }
                    else{
                        n_bx -= dx[i]; n_by -= dy[i];//파란구슬 한칸뒤로
                    }
                }

                if(chk[n_rx][n_ry][n_bx][n_by] == true) continue;//이미 방문한 적 있다면 넘어가기

                q.push(make_pair( make_pair(n_rx, n_ry), make_pair(n_bx, n_by)));
                chk[n_rx][n_ry][n_bx][n_by] = true;//방문

            }


        }
        
        cnt++;
        if(cnt > 10) return -1;//문제 조건
        
    }

    return -1;//큐가 비어있다면 문제가 발생했다(탈출실패)
}



int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'B'){ b1=i; b2=j; }
            else if(a[i][j] == 'R'){ r1=i; r2=j; }
        }
    }

    cout << bfs();

    return 0;
}