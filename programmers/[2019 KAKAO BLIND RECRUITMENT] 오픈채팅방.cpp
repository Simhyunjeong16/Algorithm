#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector <vector<string>> r(record.size(), vector<string>(3));
    // vector<vector<int>> temp(행 크기, vector<int>(열 크기));
    
    map<string,string> user;
    
    
    for(int i=0; i<record.size(); i++){
        
        istringstream iss(record[i]);//" "으로 잘라주기
        iss >> r[i][0] >> r[i][1] >> r[i][2];
        
        
        if(r[i][0] == "Enter" || r[i][0] == "Change"){
            user[r[i][1]] = r[i][2];
        }
    }
    
    
     for(int i=0; i<r.size(); i++){
         
        if(r[i][0] == "Enter"){
            string a = user[r[i][1]] + "님이 들어왔습니다.";
            answer.push_back(a);
        }
        else if(r[i][0] == "Leave"){
            string a = user[r[i][1]] + "님이 나갔습니다.";
            answer.push_back(a);
        }
    }
    
    
    return answer;
}