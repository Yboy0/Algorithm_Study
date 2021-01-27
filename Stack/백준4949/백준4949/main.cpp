//
//  main.cpp
//  백준4949
//
//  Created by 유영우 on 2021/01/27.
//

#include <iostream>
#include <stack>

using namespace std;

stack<char> stk;
// r,l 순서 바뀜
char sl ='(';
char sr =')';
char bl ='[';
char br =']';

// String[i]은 type은 char형이다.
void balance(string str){
    bool no=false;
    for(int i=0;i<str.length();i++){
        if(str[i] == sl || str[i] == bl){
            stk.push(str[i]);
        }
        else if(str[i] == sr){
            if(!stk.empty() && stk.top() == sl){
                stk.pop();
            }
            else{
                no=true;
                break;
            }
        }
        else if(str[i] == br){
            if(!stk.empty() && stk.top() == bl){
                stk.pop();
            }
            else{
                no=true;
                break;
            }
        }
    }
    if(stk.empty() && no==false){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    
}


int main(void) {
    string str = "";
    while(1){
        getline(cin,str);
        if (str == ".")
            break;
        else
            balance(str);
        
    }
    return 0;
}
