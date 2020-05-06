#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> x, pair<int, string> y) {
    return x.first > y.first;//내림차순
}

vector<string> split(string input, char d){
    vector<string> ans;
    stringstream ss(input);
    string tmp;
    
    while(getline(ss, tmp, d)){
        ans.push_back(tmp);
    }
    return ans;
}

string change(string str){//C#, D#, F#, G# 처리 -> c, d, f, g
    for(int i=0; i<str.size(); i++){
        if(str[i] == '#') {
            str[i-1] = tolower(str[i-1]);//소문자로 변경
            str.erase(i,1);//i위치에 있는 # 지우기
        }
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int time, start_hour, start_min, end_hour, end_min;
    vector<pair<int, string>> v;
    
    m = change(m);//기억한 멜로디 변경
    
    for(int i=0; i<musicinfos.size(); i++){
        
        vector<string> music = split(musicinfos[i], ',');

        //음악 재생 시간 구하기
        start_hour = ((music[0][0]-'0') * 10) + (music[0][1]-'0');
        start_min = ((music[0][3]-'0') * 10) + (music[0][4]-'0');
        end_hour = ((music[1][0]-'0') * 10) + (music[1][1]-'0');
        end_min = ((music[1][3]-'0') * 10) + (music[1][4]-'0');
        time = (end_hour - start_hour) * 60 + (end_min - start_min);

        music[3] = change(music[3]);//악보정보 변경
        
        string info = "";
        if(time < music[3].size()){//곡이 음악 길이보다 짧게 재생된 경우
            info = music[3].substr(0, time);
        }
        else if(time == music[3].size()){//곡이 음악 길이만큼 재생된 경우
            info = music[3];
        }
        else{//곡이 음악 길이보다 길게 재생된 경우
            int x = time / music[3].size();
            int y = time % music[3].size();
            
            for(int i=0; i<x; i++) info += music[3];
            info += music[3].substr(0, y);
        }
        
        
        if(info.find(m) != string::npos) {//해당 문자열을 찾았다!
            v.push_back(make_pair(time, music[2]));
        }
    }

    if(!v.empty()){
        stable_sort(v.begin(), v.end(), comp);//정렬후 동일값의 원소 순서를 보장
        answer = v[0].second;   
    }
    else answer = "(None)";
    
    return answer;
}