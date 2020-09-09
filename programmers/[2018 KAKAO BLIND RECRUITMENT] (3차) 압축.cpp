#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> a = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    for(int i = 0; i < msg.length(); i++){
        string w(1, msg[i]);
        int c;

        for(int k = 0; k < a.size(); k++){
            if(a[k] == w) c = k;
        }
        
        for(int j = i+1; j < msg.length(); j++){
            w += msg[j];
            
            if(find(a.begin(), a.end() ,w) == a.end()){//존재하지않으면, 사전추가
                a.push_back(w);
                break;
            }
            else{//존재하면
                for(int k = 0; k < a.size(); k++){
                    if(a[k] == w) c = k;
                }
                i++;
            }
        }
        
        answer.push_back(c+1);
    }
    
    return answer;
}
