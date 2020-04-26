#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<int, string>> v;
    
    if(cacheSize == 0){
        answer = cities.size()*5;
        return answer;
    }
    
    for(int i=0; i<cities.size(); i++){
        bool flag = false;
        
        string city = "";
        for(char c=0; c<cities[i].size(); c++)
            city += tolower(cities[i][c]); //소문자로 변경
        
        if(i == 0){
            answer += 5;//cache miss
            v.push_back(make_pair(i, city));
            continue;
        }
        
        for(int j=0; j<v.size(); j++){
            if(city == v[j].second) {//같은 도시가 있다면
                v[j].first = i;//바꿔주기
                flag = true;
                answer += 1;//cache hit
            }
        }
        
        if(!flag){
            answer += 5;//cache miss
            
            if(v.size() < cacheSize){//캐시크기 만큼 안채워졌을 때
                v.push_back(make_pair(i, city));
            }
            
            else{//캐시크기 만큼 채워졌을 때 (젤 오래전에 들어왔던 도시 찾기)
                
                int mini = v[0].first;//젤 작은 값(오래된 값)
                int c = 0;//v의 위치
                for(int a=1; a<cacheSize; a++){
                    if(mini > v[a].first) {
                        mini = v[a].first;
                        c = a;
                    }
                }
                
                v[c].first = i;
                v[c].second = city;
            }
        }
            
    }
    
    return answer;
}