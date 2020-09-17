#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> s = {"4", "1", "2"};
    
    while(n > 0){
        answer = s[n % 3] + answer;
        
        if(n % 3 == 0) n = n / 3 - 1;
        else n /= 3;
    }
    
    return answer;
}
