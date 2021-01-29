//
//  main.cpp
//  백준1874
//
//  Created by 유영우 on 2021/01/28.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int> stk({0}) ;
queue<string>result;
bool no = false;
int sz;
int pn;
int n;
int micnt;
int qsize;
int tp;

void check(int num){
    if( micnt>0 && micnt>=n ){
        no=true;
    }
    else{
        while(stk.top() != num ){
            if(pn < num){
                pn++;
                stk.push(pn);
                result.push("+");
                qsize++;
                
            }
            else{
                stk.pop();
                result.push("-");
                micnt++;
                qsize++;
            }

        }
        if(stk.top() == num){
            result.push("-");
            stk.pop();
            micnt++;
            qsize++;
        }
    }
}

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(no == true){
            break;
        }
        else{
            check(num);
        }
    }
    if(no == true){
        cout << "\n";
        cout << "NO" ;
    }
    else{
        for(int i=0; i<qsize;i++){
            cout << result.front() <<"\n";
            result.pop();
        }
    }
    return 0;
}
