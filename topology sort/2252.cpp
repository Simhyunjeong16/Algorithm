#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m;

    int d[100001];
    vector<int> v[100001];
    queue<int> q;
    vector<int> res;

    for(int i = 0; i < m; i++){
        cin >> a >> b;//학생 A가 학생 B의 앞에 서야 한다는 의미
        v[a].push_back(b);
        d[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(d[i] == 0) q.push(i);
    }

    for(int i = 1; i <= n; i++){
        int x = q.front();
        q.pop();

        res.push_back(x);

        for(int j = 0; j < v[x].size(); j++){
            int y = v[x][j];
            if(--d[y] == 0) q.push(y);//집입차수가 0이 된 정점을 큐에 삽입
        }
    }

    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }

    return 0;
}