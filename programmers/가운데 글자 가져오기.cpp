#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    // string answer(1, s[s.size()/2]);
    
    // if(s.size() % 2 == 0) {
    //     answer = s[s.size()/2-1] + answer;
    // }
    
    string answer = s.substr((s.size()-1)/2, 2-(s.size()%2));
    
    return answer;
}
