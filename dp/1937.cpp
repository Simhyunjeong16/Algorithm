#include <iostream>

using namespace std;

int d[501][501];
int a[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, answer = 0;

int dfs(int x, int y){

    if(d[x][y] != 0) return d[x][y];//이미 계산했으니까 return
    d[x][y] = 1;//처음 계산하는 거니까 계산 시작!

    for(int i = 0; i < 4; i++){

        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(a[nx][ny] > a[x][y])
                d[x][y] = max(d[x][y], dfs(nx, ny)+1);
        }
    }
    return d[x][y];
}


int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer = max(answer, dfs(i, j));
        }
    }
    
    cout << answer;

    return 0;
}
