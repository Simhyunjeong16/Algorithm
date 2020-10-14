#include <vector>

using namespace std;

bool chk(int n){
    for(int i = 2; i < (n / 2); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i + 1; j < nums.size() - 1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                
                if(chk(nums[i] + nums[j] + nums[k])) answer++;//소수면 ++
            }
        }
    }

    return answer;
}
