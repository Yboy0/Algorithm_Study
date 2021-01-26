//
//  main.cpp
//  백준10828
//
//  Created by 유영우 on 2021/01/26.
//

#include <iostream>
using namespace std;

int arr[10001];
int cnt;
int sz;
int main(void) {
    string order="";
    int n;
    cin >> n;
    
    while(n--){
        cin >> order;
        if(order == "push"){
            int num;
            cin >> num;
            arr[cnt]=num;
            cnt ++;
            sz ++;
        }
        else if (order == "pop"){
            if(sz == 0){
                cout << "-1" << endl;
            }
            else{
                cnt --;
                cout << arr[cnt] << endl;
                sz --;
            }
      
        }
        else if(order == "size"){
            if(sz ==  0){
                cout << "0" << endl;
            }
            else{
                cout << sz << endl;
            }
            
        }
        else if(order == "empty"){
            if(sz == 0){
                cout << "1" << endl;
            }
            else{
                cout << "0" << endl;
            }
            
        }
        //top
        else {
            if(sz == 0){
                cout << "-1" << endl;
            }
            else{
                cnt --;
                cout << arr[cnt] << endl;
                cnt ++;
            }
            
        }
                
    }
    
    return 0;
}
