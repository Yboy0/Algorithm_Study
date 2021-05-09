//
//  main.cpp
//  카카오인턴쉽 문제1
//
//  Created by 유영우 on 2021/05/08.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//네오와 프로도가 숫자놀이 하는중
//숫자를 영단어로 바꾼 카드를 원래 숫자로 바꾸는 게임

//영단어s를 숫자로 바꾸는 문제
vector<int>v; // 숫자 저장 배열
string tNum="";  //문자 chekck하기위한 문자열


void checkSubStr(){
    //tNum의 문자가 완성됐다면
    if(tNum=="zero" || tNum=="one" || tNum=="two" || tNum=="three" || tNum=="four" || tNum=="five" || tNum=="six" || tNum=="seven" || tNum=="eight" || tNum=="nine"){
        
        if(tNum == "zero"){
            v.push_back(0);
        }else if(tNum == "one"){
            v.push_back(1);
        }else if(tNum == "two"){
            v.push_back(2);
        }else if(tNum == "three"){
            v.push_back(3);
        }else if(tNum == "four"){
            v.push_back(4);
        }else if(tNum == "five"){
            v.push_back(5);
        }else if(tNum == "six"){
            v.push_back(6);
        }else if(tNum == "seven"){
            v.push_back(7);
        }else if(tNum == "eight"){
            v.push_back(8);
        }else if(tNum == "nine"){
            v.push_back(9);
        }
        
    //tNum초기화
        tNum = "";
    }
}

int solution(string s) {
    int answer = 0;
   
    for(int i=0; i<s.length();i++){
        
        checkSubStr();
        
        //문자가 숫자일 때
        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
            
            if(s[i] == '0'){
                v.push_back(0);
            }else if(s[i] == '1'){
                v.push_back(1);
            }else if(s[i] == '2'){
                v.push_back(2);
            }else if(s[i] == '3'){
                v.push_back(3);
            }else if(s[i] == '4'){
                v.push_back(4);
            }else if(s[i] == '5'){
                v.push_back(5);
            }else if(s[i] == '6'){
                v.push_back(6);
            }else if(s[i] == '7'){
                v.push_back(7);
            }else if(s[i] == '8'){
                v.push_back(8);
            }else if(s[i] == '9'){
                v.push_back(9);
            }
        } // 문자가 숫자 일때 끝
        
        else{ //문자가 문자일 떄
            tNum=tNum+s[i];
        }
    }
    
    if(tNum.length()>0){
        checkSubStr();
    }
    
    //배열에 있는 숫자를 int answer로 바꿔야 한다
    int a= v.size()-1;
    for(int i=0; i<v.size(); i++){
        answer+=v[i]*(pow(10,a));
        a--;
    }
    
    return answer;
}





int main(void) {
    
    string s = "23four5six7";
    
   cout <<  solution(s);

    return 0;
}
