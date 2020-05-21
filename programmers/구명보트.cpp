#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int size = people.size()-1;
    int start = 0;
    for(int i = size; i >= start; i--){
        if(people[i] + people[start] <= limit) {
            start++;
        }
        answer++;
    }
    
    return answer;
}