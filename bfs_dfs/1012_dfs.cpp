#include <iostream>
#include <string.h>

using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int a[51][51];
int t;
int m, n, k;
int x, y;
int answer;

void dfs(int x, int y){

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 1){
            a[nx][ny] = 0; 
            dfs(nx, ny);
        }
    }

    return;
}

int main(){

    cin >> t;
    
    while(t--){
        //초기화
        memset(a, -1, sizeof(a));
        answer = 0;

        cin >> m >> n >> k;

        while(k--){
            cin >> y >> x;//헷갈려서 내가 바꿔서 받음
            a[x][y] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1) {
                    a[i][j] = 0;
                    dfs(i, j);
                    answer++;
                }
            }
        }

        cout << answer << endl;
    }
        

    return 0;
}
