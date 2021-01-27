//
//  main.cpp
//  백준10866
//
//  Created by 유영우 on 2021/01/27.
//

#include <iostream>
#include <deque>
using namespace std;

deque<int> dp;
int cntf;
int cntb;
int sz;
int arr[10001];
int main(void) {
    int n;
    cin >> n;
    
    
    while(n--){
        string order;
        cin >> order;
        if(order == "push_front"){
            int m;
            cin >> m;
            dp.push_front(m);
            
        }
        else if(order == "push_back"){
            int m;
            cin >> m;
            dp.push_back(m);
            
        }
        else if(order == "pop_front"){
            if(dp.size() == 0){
                cout << "-1" << endl;
            }
            else{
                int fr = dp.front();
                dp.pop_front();
                cout << fr << endl;
            }
        }
        else if(order == "pop_back"){
            if(dp.size() == 0){
                cout << "-1" << endl;
            }
            else{
                int bc = dp.back();
                dp.pop_back();
                cout << bc << endl;
            }
            
        }
        else if(order == "size"){
            cout << dp.size() << endl;
            
        }
        else if(order == "empty"){
            if(dp.size() == 0){
                cout << "1" << endl;
            }
            else{
                cout << "0" << endl;
            }
            
        }
        else if(order == "front"){
            if(dp.size() == 0){
                cout << "-1" << endl;
            }
            else{
                cout << dp.front() << endl;
            }
        }
        //back
        else{
            if(dp.size() == 0){
                cout << "-1" << endl;
            }
            else{
                cout << dp.back() << endl;
            }
        }
    }
    return 0;
}
