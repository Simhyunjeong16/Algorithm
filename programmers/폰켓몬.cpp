#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int max = nums.size() / 2;//총 골라야하는 폰켓몬의 수
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()),nums.end()) ;
    answer = nums.size();//중복제거한 폰켓몬의 수
    
    if(answer > max){
        answer = max;
    }

    return answer;
}