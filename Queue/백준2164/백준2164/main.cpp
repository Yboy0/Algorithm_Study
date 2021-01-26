//
//  main.cpp
//  백준2164
//
//  Created by 유영우 on 2021/01/26.
//

#include <iostream>
#include <queue>
using namespace std;
//int sz;
//int cnt;
//int arr[500001];

queue<int> q;
int m;
int main(void) {
    int n;
    cin >> n;
    
    for(int i=1;i<n+1;i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop();
        m=q.front();
        q.pop();
        q.push(m);
    }
    cout << q.front();
    
//    for(int i=1;i<n+1;i++){
//        arr[sz]=i;
//        sz++;
//    }
//    while(true){
//        cnt++;
//        arr[sz]=arr[cnt];
//        cnt++;
//        if(cnt == sz)
//            break;
//        sz++;
//    }
//    cout << arr[sz];
   return 0;
    
}
