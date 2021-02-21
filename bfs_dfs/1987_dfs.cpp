#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
string str;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
bool chk[21][21] = {false, };
vector<char> alphabet;
char a[21][21];
int answer = 0;

void dfs(int x, int y, int cnt){

    if(answer < cnt) answer = cnt;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < r && ny >= 0 && ny < c && !chk[nx][ny]){
            if(find(alphabet.begin(), alphabet.end(), a[nx][ny]) == alphabet.end()){
                
                chk[nx][ny] = true;
                alphabet.push_back(a[nx][ny]);
                
                dfs(nx, ny, cnt+1);

                chk[nx][ny] = false;
                alphabet.pop_back();
            }
        }
    }
    
    return;
}

int main(){
    
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        cin >> str;
        for(int j = 0; j < c; j++){
            a[i][j] = str[j];
        }
    }

    //0,0부터 시작
    answer++;
    chk[0][0] = true;
    alphabet.push_back(a[0][0]);
    dfs(0, 0, 1);

    cout << answer;
    return 0;
}
