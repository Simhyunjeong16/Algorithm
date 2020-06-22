#include <string>
#include <vector>
#include <unordered_map>//hash_map

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> hmap;
    
    for(auto p: participant){

        auto search = hmap.find(p);//이름이 같은 참가자 있는 지 확인
        
        if(search != hmap.end()) search->second += 1;//이름이 같은 참가자가 있음
        
        else hmap.insert(make_pair(p, 1));//이름이 같은 참가자가 없음
    }
    
    
    for(auto c: completion){
        auto search = hmap.find(c);
        if(search != hmap.end()) search->second -= 1;//완주자 명단에 있다면 -1
    }
    
    
    for(auto it= hmap.begin(); it != hmap.end(); it++){
        if(it->second != 0) answer = it->first;
    }
    
    
    return answer;
}