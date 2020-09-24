#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words){
    vector<int> answer = {0, 0};
    vector<string> v;
    
    v.push_back(words[0]);
    char tmp = words[0][words[0].size()-1];
    
    for(int i = 1; i < words.size(); i++){
        
        if(find(v.begin(), v.end(), words[i]) == v.end() && tmp == words[i][0]){
            v.push_back(words[i]);
            tmp = words[i][words[i].size()-1];
        }
        else{
            if((i+1) % n != 0) {
                answer[0] = (i+1) % n;//번호
                answer[1] = (i+1) / n + 1;//차례
            }
            else {
                answer[0] = n;//번호
                answer[1] = (i+1) / n;//차례
            }
            break;
        }
    }

    return answer;
}
