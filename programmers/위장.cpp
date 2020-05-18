#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for(int i=0; i<clothes.size(); i++){
            m[clothes[i][1]]++;
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
	    answer *= it->second +1;//입을 수 있는 경우의 수 + 안입는 경우(1)
	}
    
    return answer -1;//모두 안입는 경우가 없으므로 -1을 한다
}