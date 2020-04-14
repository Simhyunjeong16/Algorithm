#include <iostream>
#include <string.h>

using namespace std;

int n, m;
int a[500][500];
bool chk[500][500];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int result = 0;
int cnt = 0;
int picture_cnt = 0;

void dfs(int x, int y){

    chk[x][y] = true;
    cnt++;

    for(int i=0; i<4; i++){
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(chk[nx][ny] == false && a[nx][ny] == 1){
                dfs(nx, ny);
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

    memset(chk, false, sizeof(chk));//false로 초기화하기

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 1 && chk[i][j] == false){
                dfs(i, j);
                picture_cnt++;
                result = max(result, cnt);
                cnt = 0;
            }
        }
    }

    cout << picture_cnt << "\n" << result;

    return 0;
}