#include <iostream>
#include <vector>

using namespace std;

bool bad[201][201];
vector<int> res;
bool chk[201] = {false};
int N, M;
int result = 0;

void icecream(){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == j) continue;//같은 수 일테니까 넘어가기

            if(bad[res[i]][res[j]] == true) return;//안좋은 아이스크림 조합
        }
    }

    result++;
}



void dfs(int x, int cnt){
    
    if(cnt == 3){
        icecream();
        return;
    }

    for(int i = x; i<=N; i++){
        if(chk[i] == true) continue;
        chk[i] = true;
        res.push_back(i);

        dfs(i, cnt+1);
        chk[i] = false;
        res.pop_back();
    }

}


int main(){
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;//아이스크림 종류, 섞어먹으면 안 되는 조합의 개수

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        bad[a][b] = true;
    }

    dfs(1, 0);

    cout << result;
    
    return 0;
}