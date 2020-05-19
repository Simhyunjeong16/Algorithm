#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int sum, int idx, vector<int> numbers, int target){
    if(idx == numbers.size()){//다 돌았을 때
        if(sum == target) answer++;
        return;
    }
    

    sum += numbers[idx];
    dfs(sum, idx+1, numbers, target);
    sum -= numbers[idx];
    
    sum -= numbers[idx];
    dfs(sum, idx+1, numbers, target);
    sum += numbers[idx];
    
}

int solution(vector<int> numbers, int target) {
    
    dfs(0, 0, numbers, target);
    
    return answer;
}