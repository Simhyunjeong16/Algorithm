#include <iostream>
#include <algorithm>
#include <climits>
#include <string.h>

using namespace std;

int n, m;
int a[8][8];
bool chk[8][8];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int result = INT_MIN, safe = 0;

void dfs(int x, int y){
    chk[x][y] = true;

    for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(a[nx][ny] == 0 && chk[nx][ny] == false){
                a[nx][ny] = 3;//바이러스 감염
                dfs(nx, ny);
            }
        }
    }
}

void Make_Wall(int wall){//DFS, 조합

    if(wall == 3){

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 2 && chk[i][j] == false){//바이러스 찾기
                    dfs(i,j);
                }
            }
        }
        
        //모든경우의 수를 돌면서 3칸찾기(조합)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 0) safe++;//안전영역 크기 구하기
                else if(a[i][j] == 3) a[i][j] = 0;//다른경로 찾아야하니 원상태 복구
            }
        }

        result = max(result, safe);
        safe = 0;//초기화

        memset(chk, false, sizeof(chk));//chk 초기화

        return;
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(a[i][j] == 0){
                a[i][j] = 1;
                Make_Wall(wall+1);//벽세웠으니까 wall+1
                a[i][j] = 0;
            }
        }
    }

}


int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    Make_Wall( 0);

    cout << result;
    return 0;
}