//
//  main.cpp
//  백준9663(N-Queen)
//
//  Created by 유영우 on 2021/04/15.
//

#include <iostream>
using namespace std;

int n;
bool check1[16];
int check2[16][2];
int result;

void queen(int cnt){
    if(cnt==n){
        result++;
        return;
    }
    else{
        for(int i=0; i<n; i++){
                if(check1[i]==false){
                    bool ch =false;
                    for(int j=0; j<cnt; j++){
                        if(i==check2[j][0] || i==check2[j][1]){
                            ch=true;
                            break;
                        }

                    }
                    if(ch==false){
                        
                        check1[i]=true;
                        
                        for(int j=0; j<cnt; j++){
                            check2[j][0]--;
                            check2[j][1]++;
                        }
                        
                        check2[cnt][0]=i-1;
                        check2[cnt][1]=i+1;

                        queen(cnt+1);
                        
                        for(int j=0; j<cnt; j++){
                            check2[j][0]++;
                            check2[j][1]--;
                        }
                        
                        check1[i]=false;
                }
            }
            
        }
    }
}

int main(void) {
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        check1[i]=true;
        check2[0][0]=i-1;
        check2[0][1]=i+1;
        queen(1);
        check1[i]=false;
    }
    
    cout << result;
    return 0;
}
