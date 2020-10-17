#include <iostream>
#include <cstring>

#define MAX 103
using namespace std;

int n;
int a[MAX][MAX];
bool chk[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int k){
    
    chk[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(!chk[nx][ny] && a[nx][ny] > k){
                dfs(nx, ny, k);
            }
        }
    }

}

int main(){

    cin >> n;

    int min_num = 101, max_num = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];

            min_num = min(min_num, a[i][j]);
            max_num = max(max_num, a[i][j]);
        }
    }

    int answer = 1;//최소 값
    for(int k = min_num; k < max_num; k++){

        int cnt = 0;
        memset(chk, false, sizeof(chk));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!chk[i][j] && a[i][j] > k){
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }
        // cout << k << " " << cnt << endl;
        answer = max(answer, cnt);
    }

    
    cout << answer;

    return 0;
}