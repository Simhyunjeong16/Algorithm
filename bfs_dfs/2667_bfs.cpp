#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int a[26][26];
bool chk[26][26];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int cnt = 0;
vector<int> v;
queue<pair<int, int>> q;
pair<int, int> f;
int nx, ny;

void bfs(){

    int x, y;
    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++){

            if(chk[x][y] == false && a[x][y] == 1){
                q.push(make_pair(x, y));
                chk[x][y] = true;
            }
            


            while(!q.empty()){

                f = q.front();
                q.pop();
                cnt++;

                for(int i=0; i<4; i++){
                
                    nx = f.first + dx[i];
                    ny = f.second + dy[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        if(chk[nx][ny] == false && a[nx][ny] == 1) {
                            q.push(make_pair(nx, ny));
                            chk[nx][ny] = true;
                        }
                    }

                }
            }

            if(q.empty() && cnt != 0){
                v.push_back(cnt);
                cnt = 0;
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

    bfs();

    cout << v.size() << "\n";

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\n";

}