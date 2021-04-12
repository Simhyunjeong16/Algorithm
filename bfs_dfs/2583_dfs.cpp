#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int m, n, k;
int cnt;
bool a[101][101] = {false};
int lx, ly, rx, ry;
vector<int> v;

void dfs(int x, int y){

    a[x][y] = true;
    cnt++;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !a[nx][ny]){   
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        cin >> ly >> lx;//왼쪽 아래 꼭짓점의 x, y좌표값
        cin >> ry >> rx;//오른쪽 위 꼭짓점의 x, y좌표값

        //해당하는 정사각형 bool형 값 바꾸기
        for(int i = lx; i < rx; i++){
            for(int j = ly; j < ry; j++){
                a[i][j] = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == false){
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}
