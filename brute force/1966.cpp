#include <iostream>
#include <queue>

using namespace std;

int main(){

    int testcase;
    cin >> testcase;

    for(int i = 0; i < testcase; i++){
        int n, m, k;
        priority_queue<int> pq;
        queue<pair<int, int>> q;

        cin >> n >> m;//문서의 수, 몇번째로 인쇄되엇는지 궁금한 문서의 현재 위치
        
        for(int j = 0; j < n; j++){
            cin >> k;
            pq.push(k);
            q.push(make_pair(k, j));//중요도, 자리
        }

        int cnt = 1;
        while(!pq.empty()){

            if(pq.top() > q.front().first){
                int p1 = q.front().first;
                int p2 = q.front().second;
                q.pop();
                q.push(make_pair(p1, p2));
            }

            else if(pq.top() == q.front().first){
                if(q.front().second == m) break;

                pq.pop();
                q.pop();
                cnt++;
            }
        }
        

        cout << cnt << "\n";
    }

    return 0;
}