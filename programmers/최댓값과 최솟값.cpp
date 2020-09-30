#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string str = "";
    vector<int> v;
    
    for(auto i : s){
        if(i == ' ') {
            v.push_back(stoi(str));
            str = "";
        }
        else{
            str += i;
        }
    }
    v.push_back(stoi(str));
    
    answer = to_string(*min_element(v.begin(), v.end())) + " " + to_string(*max_element(v.begin(), v.end()));
    
    return answer;
}
