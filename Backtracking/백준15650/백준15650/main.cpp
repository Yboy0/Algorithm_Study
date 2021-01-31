//
//  main.cpp
//  백준15650
//
//  Created by 유영우 on 2021/01/31.
//

#include <iostream>

using namespace std;

int n,m;
int cnt;
int arr[10];
int check[10];
void sequence(int cnt){
    
    if(cnt == m){
        for(int i =0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else{
        for(int i=1; i<n+1; i++){
            if(!check[i]){
                if(cnt==0){
                    arr[cnt]=i;
                    check[i]=true;
                    sequence(cnt+1);
                    check[i]=false;
                }
                if(cnt>0 && i>arr[cnt-1]){
                    arr[cnt]=i;
                    check[i]=true;
                    sequence(cnt+1);
                    check[i]=false;
                }
                
            }
            
        }
    }
}

int main(void) {
    cin >> n >> m;
    sequence(cnt);
    return 0;
}
