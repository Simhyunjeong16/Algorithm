#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 1004

using namespace std;

int t;//테스트케이스의 개수
int n, k;//건물의 개수, 건설 순서 규칙의 개수
int x, y;//건설 순서
int w;//승리하기 위해 건설해야 할 건물 번호

vector<int> a[MAX];
int inDegree[MAX];
int time[MAX];//각 건물당 건설에 걸리는 시간
int result[MAX];

void topologySort(){

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) {
            q.push(i);
            result[i] = time[i];
        }
    }
    
    for(int i = 1; i <= n; i++){

        int cur = q.front();
        q.pop();

        if(cur == w) {
            cout << result[w] << endl;
            return;
        }
                
        for(int i = 0; i < a[cur].size(); i++){
            int next = a[cur][i];
            
            result[next] = max(result[next], result[cur] + time[next]);//점화식
            
            if(--inDegree[next] == 0) q.push(next);
        }
    }
}

int main(){//DP, 위상정렬

    cin >> t;

    for(int i = 0; i < t; i++){
        
        cin >> n >> k;

        //초기화
        memset(time, 0, sizeof(time));
        memset(result, 0, sizeof(result));
        memset(inDegree, 0, sizeof(inDegree));
        for(int j = 0; j < MAX; j++) a[j].clear();

        for(int j = 1; j <= n; j++){
            cin >> time[j];
        }

        for(int j = 0; j < k; j++){
            cin >> x >> y;
            a[x].push_back(y);
            inDegree[y]++;
        }

        cin >> w;

        topologySort();
    }

    

    return 0;
}