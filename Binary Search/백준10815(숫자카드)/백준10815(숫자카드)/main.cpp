//
//  main.cpp
//  백준10815(숫자카드)
//
//  Created by 유영우 on 2021/04/17.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n; // 답
int m; // 문제
int answer[500001];
int problem[500001];


void search(int begin, int end, int num){

    if(begin>end){
        cout << 0 << " ";
        return;
    }
    
    int mid=(end+begin)/2;
    
    if(answer[mid]==num){
        cout << 1 << " ";
        return;
    }
    else if(answer[mid]>num){
        search(begin,mid-1,num);
    }else{
        search(mid+1,end,num);
    }
    
    
}

int main(void) {
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> answer[i];
    }
    sort(answer,answer+n);
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> problem[i];
    }
    
    for(int i=0; i<m; i++){
        search(0,n-1,problem[i]);
    }
    return 0;
}
