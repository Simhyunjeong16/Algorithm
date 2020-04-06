#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, float> x, pair<int, float> y) {
    if(x.second == y.second)//두번째 수가 같다면
        return x.first < y.first;//첫번째수중 작은수로 내보내기 (오름차순)
    return x.second > y.second;//내림차순
}

vector<int> solution(int N, vector<int> stages) {//N은 스테이지 숫자
    vector<int> answer;
    vector<pair<int, float>> a;
    
    for(int s=1; s<=N; s++){
        float person = 0.0;
        float challen = 0.0; 
        for(int i=0; i<stages.size(); i++){
            
            if(s <= stages[i]){
                if(s == stages[i]) person++; //s번째 스테이지 실패한사람
                
                challen++;
            }
            
        }
        if(challen != 0)
            a.push_back(make_pair(s, float(person / challen)));
        else
            a.push_back(make_pair(s, 0));//이 예외처리 꼭 잊지말고 해주기!
    }
    
    sort(a.begin(), a.end(), comp);
    
    for(int i=0; i<N; i++){
        answer.push_back(a[i].first);
    }
    
    return answer;
}