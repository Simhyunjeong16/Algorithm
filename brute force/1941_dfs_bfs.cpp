#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

char a[5][5];
bool chk[25];//dfs
bool isSelected[5][5];//bfs
bool isVisited[5][5];//bfs
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int answer = 0;

bool bfs(){//공주들이 연결되었는지 확인
    queue<pair<int, int>> q;
    int x, y;
    bool checking = false;

    memset(isSelected, false, sizeof(isSelected));
    memset(isVisited, false, sizeof(isVisited));

    for(int i = 0; i < 25; i++){
        if(chk[i]){
            x = i/5;
            y = i%5;
            isSelected[x][y] = true;
        }
    }
    
    q.push({x, y});
    isVisited[x][y] = true;
    int count = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isSelected[nx][ny] && !isVisited[nx][ny]){
                if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
                    count++;
                    q.push({nx, ny});
                    isVisited[nx][ny] = true;
                }
            }
        }
    }

    if(count == 7) return true;
    else return false;
}

void dfs(int idx, int cnt, int cnt_s){//조합, 7공주를 골라줌
    if(cnt == 7){
        if(cnt_s >= 4) {
            if(bfs()) answer++;
        }
        return;
    }

    for(int i = idx; i < 25; i++){//** 조합
        if(chk[i]) continue;

        chk[i] = true;
        dfs(i, cnt+1, cnt_s + (a[i/5][i%5] == 'S'));
        chk[i] = false;
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }

    memset(chk, false, sizeof(chk));
    dfs(0, 0, 0);
    
    cout<< answer;
    return 0;
}
