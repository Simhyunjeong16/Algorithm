#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i];//각 장르별로 얼마나 들었는지
    }
    
    vector<pair<string, int>> gen(m.begin(), m.end());
    sort(gen.begin(), gen.end(), cmp);//value 값으로 내림차순
    
    for(auto it : gen){
        
        string g = it.first;
        vector<pair<int, int>> p;
        
        for(int i = 0; i < genres.size(); i++){
            if(genres[i] == g) p.push_back(make_pair(i, plays[i]));
        }
        
        if(p.size() == 1) answer.push_back(p[0].first);
        else{
            sort(p.begin(), p.end(), cmp2);//내림차순으로 정렬
            answer.push_back(p[0].first);
            answer.push_back(p[1].first);
        }
    }
    
    return answer;
}
