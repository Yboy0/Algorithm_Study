//
//  main.cpp
//  백준1021
//
//  Created by 유영우 on 2021/01/29.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;
deque<int> dq;
vector<int> lc;
vector<int> clc;
int fr;
int cnt;
int main(void) {
    
    int n,m;
    cin >> n >> m;;
    for(int i=1;i<n+1; i++){
        dq.push_back(i);
    }
    for(int i=m-1; i>=0; i++){
        int l;
        cin >> l;
        lc[i] = l;
        clc[i] = l-1;
    }
    while(!lc.empty()){
        if(lc.back() == dq.front()){//1번 수행
            lc.pop_back();
            clc.pop_back();
            dq.pop_front();
        }
        else{
            if(clc.front() <= dq.size()/2+1){ //2,3번 수행
                fr = dq.front();
                dq.pop_front();
                dq.push_back(fr);
                for(int i =0;i<clc.size();i++){
                    clc[i]--;
                    if(clc[i] < 0){
                        clc[i]=n+clc[i];
                    }
                }
            }
            else{
                fr = dq.back(); //
                dq.pop_back();
                dq.push_front(fr);
                for(int i =0;i<clc.size();i++){
                    clc[i]++;
                    if(clc[i] > n-1){
                        clc[i]=n-clc[i];
                    }
                }
            }
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
