//
//  main.cpp
//  백준6603(로또)
//
//  Created by 유영우 on 2021/04/08.
//

#include <iostream>
#include <queue>

using namespace std;

//k개의 수 중 6개로 이루어진 집합은 몇개인지 구하는 프로그램
int k;
int arr[14];
int answer[6];
bool check[14];


void lotto(int cnt,int idx){
    if(cnt==6){
        for(int i=0; i<6; i++){
            cout << answer[i] <<" ";
        }
        cout << endl;
    }else{
        for(int i=idx;i<k;i++){
            if(check[i]==false){
                answer[cnt]=arr[i];
                check[i]=true;
                lotto(cnt+1,i+1);
                check[i]=false;
            }
        }
    }
}


int main(void) {
    
    while(true){
        cin >> k;
        if(k==0){
            break;
        }

        for(int i=0; i<k; i++){
            cin >> arr[i];
        }
        
        lotto(0,0);
        cout<<endl;
        
        for(int i=0; i<k; i++){
            arr[i]=0;
            check[i]=false;
        }
    }
    return 0;
}
