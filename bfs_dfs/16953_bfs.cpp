#include <iostream>
#include <queue>

using namespace std;

int main(){
    int a, b;
    bool chk = false;
    queue<pair<int, int>> q;

    cin >> a >> b;
    q.push({a, 1});
    
    while(!q.empty()){//BFS

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if(x == b){
            chk = true;
            cout << y;
            break;
        }

        if(x*2 <= b) q.push({x*2, y+1});
        if(x < 100000000 && x*10+1 <= b) q.push({x*10+1, y+1});//x < 100000000 -> int의 범위를 벗어날 수 있어서
    }
    
    if(!chk) cout << -1;

    return 0;
}
