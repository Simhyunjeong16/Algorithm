#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int k = 0; k < arr1.size(); k++){
        
        vector<int> v;
        
        for(int i = 0; i < arr2[0].size(); i++){
            int sum = 0;
            
            for(int j = 0; j < arr1[0].size(); j++){
                sum += (arr1[k][j] * arr2[j][i]);
            }
            
            v.push_back(sum);
        }
        
        answer.push_back(v);
    }
    
    return answer;
}
