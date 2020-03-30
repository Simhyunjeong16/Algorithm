#include <iostream>
#include <queue>

using namespace std;

int d[100001];
bool chk[100001];
queue<int> q;
int n, k;

int main(){

    cin >> n >> k;

    q.push(n);
    chk[n] = true;

    while(!q.empty()){

        int f = q.front();
        q.pop();

        int nx;
        for(int i=0; i<3; i++){
            if(i == 0) nx = f*2;//0초니까 얘가 앞에 와야함!
            if(i == 1) nx = f-1;
            if(i == 2) nx = f+1;

            if(nx >= 0 && nx <= 100000 && chk[nx] == false){
                if(i == 0) d[nx] = d[f];//0초 시간이 흐름
                else d[nx] = d[f] + 1;//1초 시간이 흐름

                q.push(nx);
                chk[nx] = true;
            }
        }

    }
   

    cout << d[k];

    return 0;
}