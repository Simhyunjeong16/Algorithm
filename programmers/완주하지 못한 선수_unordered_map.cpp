#include <string>
#include <vector>
#include <unordered_map>//hash_map

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    unordered_map<string, int> hmap;
   
    for(string c : completion){
        if(hmap.end() == hmap.find(c))//map안에 해당값이 없으면 값 삽입
            hmap.insert(make_pair(c, 1));
        else
            hmap[c]++;//뒤에 값 더하기
    }
    
    for(string p : participant){
        if(hmap.end() == hmap.find(p)){//map안에 해당값이 없으니까!!
            answer = p;
            break;
        }
        else{
            hmap[p]--;//뒤에 값 빼기
            if(hmap[p] < 0){//하나 더 나왔으니까 답!!
                answer = p;
                break;
            }
        }
    
    }

    
    return answer;
}