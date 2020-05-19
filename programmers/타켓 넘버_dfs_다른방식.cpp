#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int sum, int idx, vector<int> numbers, int target){
    if(idx == numbers.size()){//다 돌았을 때
        if(sum == target) answer++;
        return;
    }
    
    
    dfs(sum + numbers[idx], idx+1, numbers, target);
    dfs(sum - numbers[idx], idx+1, numbers, target);
    
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers[0], 1, numbers, target);
    dfs(-numbers[0], 1, numbers, target);
    
    return answer;
}