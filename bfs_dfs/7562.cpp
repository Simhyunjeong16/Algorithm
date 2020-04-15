#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int testcase, l;
queue<pair<int, int>> q;
pair<int, int> p;
vector<int> cnt;
int chk[300][300];

int main(){
    cin >> testcase;

    for(int t=0; t<testcase; t++){
        cin >> l;

        int x, y;//나이트의 현위치
        int a, b;//도착해야하는 나이트 위치
        cin >> x >> y >> a >> b;
        if(x != a || y != b)
            q.push(make_pair(x, y));

        //chk 초기화
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++){
                chk[i][j] = 0;
            }
        }

        while(!q.empty()){
            
            p = q.front();
            q.pop();

            int nx, ny;
            for(int k=0; k<8; k++){
                
                nx = p.first + dx[k];
                ny = p.second + dy[k];

                if(nx >= 0 && nx < l && ny >= 0 && ny < l && chk[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    chk[nx][ny] = chk[p.first][p.second] + 1;//1칸이동
                    // if(nx == a && ny == b) break;//위치도착
                }
            }

        }

        cnt.push_back(chk[a][b]);
    }


    for(int i=0; i<cnt.size(); i++) cout << cnt[i] << endl;

    return 0;
}