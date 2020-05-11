#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};//북, 동, 남, 서
int dy[4] = {0, 1, 0, -1};

int n, m, r, c, d;//세로, 가로, 로봇 x좌표, 로봇 y좌표, 로봇 방향
int a[50][50];
bool chk[50][50];
int result = 0;

int main(){

    cin >> n >> m >> r >> c >> d;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    
    while(1){
        
        //현재 위치 청소(1)
        if(a[r][c] == 0 && !chk[r][c]) {
            chk[r][c] = true;
            result++;
        }

        //탐색 진행(2)
        bool flag = false;
        for(int i = 0; i < 4; i++){//(2-b)
            
            //현재 위치에서 왼쪽 방향으로 회전
            d = d - 1;
            if(d < 0) d = 3;

            int x = r + dx[d];
            int y = c + dy[d];

            if(a[x][y] == 0 && !chk[x][y]){
                r = x;
                c = y;
                flag = true;
                break;//(2-a)
            }

        }

        if(flag) continue;//(2-a)

        //4 방향 모두 청소가 이미 되어있거나 벽인 경우
        //바라보는 방향을 유지한 채로 한칸 후진(2-c)
        int direct;
        if(d == 3) direct = 1;
        else if(d == 2) direct = 0;
        else if(d == 1) direct = 3;
        else if(d == 0) direct = 2;

        r += dx[direct];
        c += dy[direct];

        //뒤쪽 방향이 벽이라 후진 못해서 작동 중지(2-d)
        if(a[r][c] == 1) break;
    }


    cout << result;
    return 0;
}