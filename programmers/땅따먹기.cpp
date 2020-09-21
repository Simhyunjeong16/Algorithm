#include <vector>

using namespace std;

int solution(vector<vector<int>> land){
    
    int answer = 0;
    int n = land.size();
    int a[100001][4];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] = land[i][j];
        }
    }
    
    
    for(int k = 1; k < n; k++){
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i == j) continue;//같은 열을 연속해서 밟을 수 없는 특수 규칙
                
                if(a[k][i] < land[k][i] + a[k-1][j]){
                    a[k][i] = land[k][i] + a[k-1][j];
                }
            }
        }
    }
    

    for(int j = 0; j < 4; j++){
       if(answer < a[n-1][j]) answer = a[n-1][j];
    }
    
    return answer;
}
