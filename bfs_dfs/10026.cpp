#include <iostream>
#include <string.h>

using namespace std;

char a[100][100];
char b[100][100];
bool chk[100][100];
bool chk2[100][100];

int n;
int cnt=0, cnt2 = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void dfs(int x, int y){

    char color = a[x][y];
    chk[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(a[nx][ny] == color && chk[nx][ny] == false){
                dfs(nx, ny);
            }
        }
    }
}

void dfs_RedIsGreen(int x, int y){

    char color = b[x][y];
    chk2[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(b[nx][ny] == color && chk2[nx][ny] == false){
                dfs_RedIsGreen(nx, ny);
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    memcpy(b, a, sizeof(a));//a배열을 b로 복사

    //빨간색 = 초록색
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(b[i][j] == 'G') b[i][j] = 'R';
        }
    }

    //일반인
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(chk[i][j] == false){
                dfs(i,j);
                cnt++;
            }
        }
    }
    
    //적록색약
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(chk2[i][j] == false){
                dfs_RedIsGreen(i,j);
                cnt2++;
            }
        }
    }
    
    
    cout << cnt << " " << cnt2;

    return 0;
}