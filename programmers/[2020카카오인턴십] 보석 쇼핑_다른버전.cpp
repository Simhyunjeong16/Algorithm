#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, (int)gems.size()};//최대 구간으로 설정
  
    map<string, int> m;
    for(auto i : gems){
        m.insert(make_pair(i, 1));
    }
    int kind = m.size();
    m.clear();
    
    int start = 0, end = 0, max = 100001;
    while(1){
        if(m.size() == kind){//모든 보석이 다 담긴 경우
            if(max > end - start){
                max = end - start;
                answer[0] = start+1;
                answer[1] = end;
            }
            
            //보석이 하나면 제거하고 시작 인덱스 증가
            if(m[gems[start]] == 1){
                m.erase(gems[start]);
                start++;
            }
            
            //같은 종류의 보석이 여러개면 1개 감소시키고 시작 인덱스 증가
            else if(m[gems[start]] > 1){
                m[gems[start]]--;
                start++;
            }
        }
        else if (end == gems.size()) break;//끝까지 탐색하면 종료
        else {//보석 종류를 다 포함하지 못하면 끝 인덱스 증가
            m[gems[end]]++;
            end++;
        }
    }
    
    
    return answer;
}
