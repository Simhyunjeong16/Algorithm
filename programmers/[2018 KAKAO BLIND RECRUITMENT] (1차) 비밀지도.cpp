#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> a1(n, vector<int>(n));
    vector<vector<int>> a2(n, vector<int>(n));
    vector<vector<int>> result(n, vector<int>(n));
    
    for(int i=0; i<n; i++){
        //arr1 10진수를 2진수로 변경    
        int num = arr1[i];  
        for(int j=0; num>0; j++){
            a1[i][j] = num%2;
            num = num/2;
        }
        reverse(a1[i].begin(), a1[i].end());
        
        //arr2 10진수를 2진수로 변경
        int num2 = arr2[i];
        for(int j=0; num2>0; j++){
            a2[i][j] = num2%2;
            num2 = num2/2;
        }
        reverse(a2[i].begin(), a2[i].end());
        
        //합쳐진 새로운 지도 만들기
        for(int k=0; k<n; k++){
            if(a1[i][k] == 1 || a2[i][k] == 1) result[i][k] = 1;
            else result[i][k] = 0;
        }
        
    }
    
     
    for(int i=0; i<n; i++){
        string r = "";
        for(int j=0; j<n; j++){
            if(result[i][j] == 0) r += " ";
            else r += "#";
        }
        answer.push_back(r);
    }
    
    
    return answer;
}