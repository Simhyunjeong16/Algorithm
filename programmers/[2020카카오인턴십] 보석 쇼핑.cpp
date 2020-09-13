#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> m;
    queue<string> q;
    
    for(auto i : gems){
        m[i] = 1;//m.insert(make_pair(i, 1));
    }
    
    int kind = m.size();
    m.clear();//map 비워주기


    int min = 0, max = 100001;
    int t = 0;
    for(int i = 0; i < gems.size(); i++){
        
        if(m[gems[i]] == 0) m[gems[i]] = 1;//같은 보석이 없으면 1 넣어주기
        else m[gems[i]] += 1;//같은 보석이 있으면 개수 1 더해주기
        
        q.push(gems[i]);
        
        while(1){
            if(m[q.front()] > 1){//모든 종류의 보석은 1개 이상 가지고 있어야 함
                m[q.front()] -= 1;
                q.pop();
                t++;
            }
            else break;
        }
        
        if(m.size() == kind && max > q.size()){
            min = t;
            max = q.size();
        }
    }
    
    answer.push_back(min+1);
    answer.push_back(min+max);
    return answer;
}
