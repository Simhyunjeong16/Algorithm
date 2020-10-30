#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int i, int len, vector<int>& numbers, int target, int sum){
    if(i == len){
        if(sum == target) answer++;
        return;
    }
    
    dfs(i+1, len, numbers, target, sum + numbers[i]);
    dfs(i+1, len, numbers, target, sum - numbers[i]);
}

int solution(vector<int> numbers, int target) {
    
    dfs(0, numbers.size(), numbers, target, 0);
    
    return answer;
}
