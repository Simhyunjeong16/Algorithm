#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    //플로이드 와샬 알고리즘
    int answer = 0;//승패가 확실한 선수의 수
    vector<vector<bool>> a(n+1, vector<bool>(n+1, false));
    
    for(auto r : results){//승리한 결과 true
        a[r[0]][r[1]] = true;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][k] && a[k][j]){//i가 k를 이겼고, k가 j를 이겼다면 -> i가 j를 이겼다
                    a[i][j] = true;
                }
            }
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for(int i = 1; i <= n; i++){
        int cnt = 1;//자기자신
        for(int j = 1; j <= n; j++){
            if(a[i][j] || a[j][i]) cnt++;//i가 j를 이겼거나, j가 i를 이긴 경우 cnt++
        }
        if(cnt == n) {
            answer++;
            // cout << i << "\n";
        }
    }
    

    return answer;
}