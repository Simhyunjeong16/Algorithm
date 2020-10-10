#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums){
    int answer = 0;
    map<int, int> m;
    
    for(int i = 0; i < nums.size(); i++){
        m[nums[i]]++;
    }
    
    answer = min(nums.size() / 2, m.size());
    
    // if((n / 2) <= m.size()) answer = n / 2;//실제 폰켓몬의 종류와 최대 폰켓몬 종류가 같다면
    // else answer = m.size();//실제 폰켓몬 종류가 적다면
    
    return answer;
}
