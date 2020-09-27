#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int n;
int d[MAX], time[MAX], res[MAX];
vector<int> v[MAX];

void topologySort(){
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(d[i] == 0) {
            res[i] = time[i];//각 결과에 걸리는 시간 더하기
            q.push(i);
        }
    }
    
    for(int i = 1; i <= n; i++){
        int x = q.front();
        q.pop();
        
    
        for(int j = 0; j < v[x].size(); j++){
            int y = v[x][j];

            res[y] = max(res[y], res[x] + time[y]);//조건

            if(--d[y] == 0) q.push(y);
        }
    }


    for(int i = 1; i <= n; i++){
        cout << res[i] << endl;
    }
}


int main(){
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> time[i];
        
        while(1){
            int num;
            cin >> num;
            if(num == -1) break;

            v[num].push_back(i);
            d[i]++;
        }

    }

    topologySort();
    
    return 0;
}