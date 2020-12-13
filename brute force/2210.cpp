#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int a[5][5];
vector<string> v;

void dfs(int x, int y, int cnt, string str){

    if(cnt == 6){
        if(find(v.begin(), v.end(), str) == v.end()){
            v.push_back(str);
        }
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            dfs(nx, ny, cnt + 1, str + to_string(a[nx][ny]));
        }
    }
}

int main(){

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            dfs(i, j, 0, "");
        }
    }

    cout << v.size();
    return 0;
}