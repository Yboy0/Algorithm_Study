//
//  main.cpp
//  백준1477(휴게소 세우기)
//
//  Created by 유영우 on 2021/05/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M,L,n;
int ans;

vector<int> v;

int main(void) {
    
    cin >> N >> M >> L;
    
    for(int i=0; i<N; i++){
        cin >> n;
        v.push_back(n);
    }
    
    v.push_back(0);
    v.push_back(L);
    
    sort(v.begin(), v.end());
    
    int low = 1;
    int high = v.back();
    
    while(low <= high){
        
        int cnt = 0;
        
        int mid = (low+high)/2;
        //cout << mid << endl;
        for(int i=1; i<v.size(); i++){
            int distance = v[i] - v[i-1];
            
            int ccnt = distance/mid;
            
            if(distance%mid ==0){
                ccnt--;
            }
            
            cnt += ccnt;
        }
        
        if(cnt<=M){ //줄여준다
            high = mid-1;
            if(cnt==M){
                ans = mid;
            }
        }
        else{ //늘려준다
            low = mid+1;
        }
    }
    
    
    cout << ans;
    return 0;
}
