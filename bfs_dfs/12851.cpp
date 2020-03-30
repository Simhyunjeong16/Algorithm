#include <iostream>
#include <queue>

using namespace std;

//Bfs

queue<int> q;
int d[100001];
int cnt[100001];
bool chk[100001];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    q.push(n);
    chk[n] = true;
    cnt[n] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(int nx : {f-1, f+1, f*2}){

            if(nx >=0 && nx <=100000){

                if(chk[nx] == false){
                    chk[nx] = true;
                    d[nx] = d[f] + 1;
                    q.push(nx);
                    cnt[nx] = cnt[f];
                }

                else if(d[nx] == d[f] + 1) {
                    cnt[nx] += cnt[f];
                }
            }

        }
    }
    
    cout << d[k] << "\n" << cnt[k];

    return 0;
}