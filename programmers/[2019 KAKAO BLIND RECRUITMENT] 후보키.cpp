#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct fname{
    string head;
    int num;
    int index;
};

bool comp(fname x, fname y) {
    std::transform(x.head.begin(), x.head.end(), x.head.begin(), ::tolower);//string 소문자로 변경
    std::transform(y.head.begin(), y.head.end(), y.head.begin(), ::tolower);
    
    if(x.head == y.head)//헤더가 같다면
        return x.num < y.num;//오름차순
    return x.head < y.head;//오름차순
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fname> name;
    fname f;
    
    for(int i=0; i<files.size(); i++){
        
        for(int j=0; j<files[i].size(); j++){
            if(files[i][j] >= '0' && files[i][j] <= '9'){
                f.head = files[i].substr(0, j);//0번째부터 j의 길이만큼 자르기
                
                
                string str = "";
                vector<int> nums;
                for(int k=j; k<files[i].size(); k++){
                    if( files[i][k] >= '0' && files[i][k] <= '9') {
                        nums.push_back(files[i][k]-'0');
                    }
                    else break;
                    
                }
                
                int result = 0;
                for(int k=nums.size()-1; k >= 0; k--){
                    result += nums[k] * pow(10, nums.size()-1 -k);
                }
    
                f.num = result;
                f.index = i;
                // cout << f.head << "  " << result << endl;
                name.push_back(f);
                break;
            }
            
        }
        
    }
    
    stable_sort(name.begin(), name.end(), comp);//정렬후 동일값의 원소 순서를 보장
    
    
    for(int i=0; i<name.size(); i++){
        answer.push_back(files[name[i].index]);
    }

    return answer;
}