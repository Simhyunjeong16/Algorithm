#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int k = *max_element(citations.begin(), citations.end());
    int n = citations.size();
    
    for(int h = 0; h <= k; h++){
        int cnt = 0;
        for(auto c : citations){
            if(h <= c) cnt++;        
        }
        if(cnt >= h && n-cnt <= h) answer = h;
    }
    
    return answer;
}
