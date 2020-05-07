#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Bfs
vector<int> v[100001];
vector<int> r;
queue<int> q;
int d[100001];
bool chk[100001];
int n, k;

int main(){    
    scanf("%d %d", &n, &k);

    q.push(n);
    chk[n] = true;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(int nx : {f-1, f+1, f*2}){

            if(nx >=0 && nx <=100000 && chk[nx] == false){

                chk[nx] = true;
                d[nx] = d[f] + 1;
                v[nx].push_back(f);
                q.push(nx);
                    
            }

        }
    }
    
    cout << d[k] << "\n"; 

    r.push_back(k);
    int a = k;
    while (a != n){

        r.push_back(v[a][0]);
        a = v[a][0];
    }

    for(int i=r.size()-1; i>=0; i--){
        cout << r[i] << ' ';
    }

    return 0;
}