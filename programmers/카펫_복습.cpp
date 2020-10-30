#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x = brown + yellow;
    
    for(int h = 3; h < x; h++){//높이는 최소 3에서 시작
        int w = x / h;//너비
        
        if(yellow == (w-2)*(h-2) && w >= h){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    
    
    return answer;
}
