#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string x, string y){ 
    return x + y > y + x;//내림차순
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> n;
    
    for(int i : numbers) n.push_back(to_string(i));
        
    sort(n.begin(), n.end(), comp);
    
    for(string s : n) answer += s;
    
    if(answer[0] == '0') answer = "0";
    
    return answer;
}