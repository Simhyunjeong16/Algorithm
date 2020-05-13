#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

//1697 숨바꼭질 문제 비슷한 유형
int main(){
    int n, k;
    cin >> n >> k;

    int a[n+1] = {0, };
    for(int i=1; i<=n; i++) cin >> a[i];

    int d[k+1] = {0, };

    q.push(0);

    while(!q.empty()){
        int f = q.front();
        q.pop();

        if(f == k) break; 

        for(int i=1; i<=n; i++){

            int nx = f + a[i];

            if(nx <= k && d[nx] == 0){//어차피 처음 들어온 값이 젤 적을테니까(최솟값)
                d[nx] = d[f] + 1;//동전 개수 추가
                q.push(nx);
            }
        }
    }


    if(d[k] == 0) d[k] = -1;

    cout << d[k];

    return 0;
}