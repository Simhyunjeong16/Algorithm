#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> hash;
    
    for(int i = 0; i < clothes.size(); i++){
        hash[clothes[i][1]]++;
    }
    
    for(auto it = hash.begin(); it != hash.end(); it++){
        answer *= it->second + 1;//입을 수 있는 경우의 수 + 안입는다(1)
    }
    
    return answer -1;//모두 안입는 경우는 없어서 -1
}
