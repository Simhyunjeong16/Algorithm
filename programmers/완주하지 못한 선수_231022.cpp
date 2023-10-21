#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
   
    unordered_map <string, int> m;
    
    for(string p : participant){
        m[p]++;
    }
    
    for(string c : completion){
        m[c]--;
    }
    
    for(auto i : m){
        if(i.second > 0){
            return i.first;
        }
    }
}