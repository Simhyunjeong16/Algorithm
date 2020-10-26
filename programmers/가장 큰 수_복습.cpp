#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string x, string y){
    return x + y > y + x;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> n;

    for(int i = 0; i < numbers.size(); i++){
        n.push_back(to_string(numbers[i]));
    }
    
    sort(n.begin(), n.end(), cmp);//내림차순으로 정렬
    
    for(auto it : n) answer += it;
    
    if(answer[0] == '0') answer = "0";
    
    return answer;
}
