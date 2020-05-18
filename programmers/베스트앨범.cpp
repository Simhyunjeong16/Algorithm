#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> x, pair<string, int> y){
    return x.second > y.second;
}

bool comp2(pair<int, int> x, pair<int, int> y){
    if(x.second == y.second) return x.first < y.first;//재생횟수가 같으면 고유번호 낮은 순
    return x.second > y.second;//재생번호가 많은 고유번호 정렬
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> h;
    
    for(int i=0; i<genres.size(); i++){
            h[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> v(h.begin(), h.end());
    sort(v.begin(), v.end(), comp);//value값 내림차순
    
    for(auto it = v.begin(); it != v.end(); it++){
        vector<pair<int, int>> m;
        for(int i = 0; i < genres.size(); i++){
            if(it->first == genres[i]){
                m.push_back(make_pair(i, plays[i]));
            }
        }
        sort(m.begin(), m.end(), comp2);
        
        answer.push_back(m[0].first);
        if(m.size() >= 2) answer.push_back(m[1].first);
    }
    
    return answer;
}