#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = citations[0]; i >= 0; i--){
        
        int cnt = 0;
        for(int j : citations){
            if(i <= j) cnt++;
        }
        
        if(cnt >= i && citations.size() -cnt <= i)
            return i;
    }
    
    
}