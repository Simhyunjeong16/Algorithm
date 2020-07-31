#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
        }
    }
    
    for(int i = 0; i < n; i++){
        answer = max(answer, triangle[n-1][i]); 
    }
    
    
    return answer;
}