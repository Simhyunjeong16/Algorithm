#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[26][26];
bool chk[26][26];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int cnt = 0;
vector<int> v;
int nx, ny;

void dfs(int x, int y){

    if(chk[x][y] == false && a[x][y] == 1){
        chk[x][y] = true;
        cnt++;
    
        for(int i=0; i<4; i++){
        
            nx = x + dx[i];
            ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(chk[nx][ny] == false && a[nx][ny] == 1) {
                    dfs(nx, ny);
                }
            }
            
        }

    }
}



int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dfs(i, j);

            if(cnt != 0){
                v.push_back(cnt);
                cnt = 0;
            }

        }
    }

    
    cout << v.size() << "\n";

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\n";

}