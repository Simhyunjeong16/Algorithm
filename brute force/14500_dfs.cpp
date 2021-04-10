#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int a[501][501];
bool chk[501][501] = { false };
int n, m, answer = 0;

void DFS(int x, int y, int cnt, int sum){

    if(cnt == 4) {
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !chk[nx][ny]){
            chk[nx][ny] = true;
            DFS(nx, ny, cnt+1, sum + a[nx][ny]);
            chk[nx][ny] = false;//Back-tracking
        }
    }

    /* 예외처리 */
    if(x-1 >= 0 && x+1 < n && y-1 >= 0){//ㅓ
        int r = a[x-1][y] + a[x][y-1] + a[x][y] + a[x+1][y];
        answer = max(answer, r);
    }

    if(x-1 >= 0 && x+1 < n && y+1 < m){//ㅏ
        int r = a[x - 1][y] + a[x][y] + a[x][y + 1] + a[x + 1][y];
        answer = max(answer, r);
    }

    if(x-1 >= 0 && y-1 >= 0 && y+1 < m){//ㅗ
        int r = a[x][y - 1] + a[x][y] + a[x - 1][y] + a[x][y + 1];
        answer = max(answer, r);
    }

    if(x+1 < n && y-1 >= 0 && y+1 < m){//ㅜ
        int r = a[x][y - 1] + a[x][y] + a[x + 1][y] + a[x][y + 1];
        answer = max(answer, r);
    }
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            chk[i][j] = true;
            DFS(i, j, 1, a[i][j]);
            chk[i][j] = false;
        }
    }
    
    cout << answer;
    return 0;
}
