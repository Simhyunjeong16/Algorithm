#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
queue<int> q;
int chk[1000001] = {0, };

int main(){
    
    cin >> F >> S >> G >> U >> D;
    
    q.push(S);
    chk[S] = 1;//내가 헤맸던 이유

    while(!q.empty()){
        int k = q.front();
        q.pop();

        if(k == G) break;//스타트링크 층 도착

        int u = k + U;
        int d = k - D;

        if(u <= F && U != 0 && chk[u] == 0) {//윗층으로
            chk[u] = chk[k] + 1;
            q.push(u);
        }

        if(d >= 1 && D != 0 && chk[d] == 0) {//아래층으로
            chk[d] = chk[k] + 1;
            q.push(d);
        }
    }
    

    if(chk[G] != 0) cout << chk[G] - 1;
    else cout << "use the stairs";

    return 0;
}