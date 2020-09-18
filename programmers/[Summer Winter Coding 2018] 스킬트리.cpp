#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto s : skill_trees){

        int i = 0;//skill
        int j = 0;//skill_trees
        while(j <= s.find(skill[i]) && i < skill.length()){
            j = s.find(skill[i]);
            i++;
        }
        
        if(i == skill.length()) {
            answer++;
        }
    }
    
    return answer;
}
