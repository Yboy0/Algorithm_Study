//
//  main.cpp
//  프로그래머스_신규 아이디 추천(Level1)
//
//  Created by 유영우 on 2021/05/26.
//

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string answerT = "";
    
    //1, //2
    int cnt  = 0;
    for(int i=0; i<new_id.size();i++){
        new_id[i]=tolower(new_id[i]);
        
         if(new_id[i] == '~' || new_id[i] == '!' || new_id[i] == '@' || new_id[i] == '#' || new_id[i] == '$' || new_id[i] == '%' || new_id[i] == '^' || new_id[i] == '&' || new_id[i] == '*' || new_id[i] == '(' || new_id[i] == ')' || new_id[i] == '=' || new_id[i] == '+' || new_id[i] == '[' || new_id[i] == ']' || new_id[i] == '{' || new_id[i] == '}' || new_id[i] == ':' || new_id[i] == '?' || new_id[i] == ',' || new_id[i] == '<' || new_id[i] == '>' || new_id[i] == '/' ){
            continue;
        }else{
             if(new_id[i] == '.'){
                 cnt++;
                 if(cnt==1){
                   answerT+=new_id[i];
                 }
             }else{
                  cnt=0;
                  answerT+=new_id[i];
             }
        }
    }
    
    //4
    bool check = false;
    if(answerT[0]=='.'){
        check =true;
          for(int i=1; i<answerT.size(); i++){
            answer+=answerT[i];
        }
        answerT=answer;
    }
    if(answerT[answerT.size()-1]=='.'){
        if(check=true){
            answer = "";
        }
        for(int i=0; i<answerT.size()-1; i++){
            answer+=answerT[i];
        }
        answerT=answer;
    }

    answer="";
    
    //5
    if(answerT.size()==0){
        answerT+='a';
    }
    
    //6
    if(answerT.size()>=16){
        for(int i=0; i<15; i++){
            answer+=answerT[i];
        }
        answerT=answer;
         if(answerT[answerT.size()-1]=='.'){
            answer="";
            for(int i=0; i<answerT.size()-1; i++){
                answer+=answerT[i];
            }
        }
    }else{
        answer=answerT;
    }
   
    //7
    if(answer.size()<3){
        while(answer.size()<3){
            answer+=answer[answer.size()-1];
        }
    }
    
    return answer;
}
