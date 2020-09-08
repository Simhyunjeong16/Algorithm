#include <algorithm>
#include <vector>

using namespace std;

//중간 값에 해당하는 인원이 징검다리를 건넜을 때, 연속되는 0의 개수가 k만큼 있는지 검사
bool binary_search(int mid, int k, vector<int> &stones){
    int cnt = 0;
    
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] <= mid) cnt++;
        else cnt = 0;
        
        if(cnt == k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int mid;
    int first = *min_element(stones.begin(), stones.end());
    int last = *max_element(stones.begin(), stones.end());
    
    while(first <= last){
        mid = (first + last) / 2;
        
        if(binary_search(mid, k, stones)) last = mid - 1;//k개보다 많다면
        else first = mid + 1;//k개보다 적다면
    }
    
    
    return first;
}
