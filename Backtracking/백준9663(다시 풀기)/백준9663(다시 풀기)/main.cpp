//
//  main.cpp
//  백준9663(다시 풀기)
//
//  Created by 유영우 on 2021/02/09.
//

#include <iostream>
using namespace std;
int n;
int cnt;
int check[15][15];

void queen(int qsize){
    if(qsize == n){
        cnt++;
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check[i][j] == 0){
                    check[i][j] ++;
                    
                    for(int q=0;q<n;q++){
                        for(int w=0;w<n;w++){
                            //동서
                            if(q==i && w!=j){
                                check[q][w]++;
                            }
                            //북남
                            if(w==j && q!=i){
                                check[q][w]++;
                            }
                            //대각선 7시
                            if(i+q<n && j-w>=0){
                                check[i+q][j-w]++;
                            }
                            //대각선 11시
                            if(i-q>=0 && j-w>=0){
                                check[i-q][j-w]++;
                            }
                            //대각선 5시
                            if(i+q<n && j+w<n){
                                check[i+q][j+w]++;
                            }
                            //대각선 1시
                            if(i-q>=0 && j+w<n){
                                check[i-q][j+w]++;
                            }
                            
                        }
        
                    }
                    queen(qsize+1);
                    check[i][j] --;

                for(int q=0;q<n;q++){
                    for(int w=0;w<n;w++){
                        //동서
                        if(q==i && w!=j){
                            check[q][w]--;
                        }
                        //북남
                        if(w==j && q!=i){
                            check[q][w]--;
                        }
                        //대각선 7시
                        if(q!=i && w!=j && i+q<n && j-w>=0){
                            check[i+q][j-w]--;
                        }
                        //대각선 11시
                        if(q!=i && w!=j &&i-q>=0 && j-w>=0){
                            check[i-q][j-w]--;
                        }
                        //대각선 5시
                        if(q!=i && w!=j &&i+q<n && j+w<n){
                            check[i+q][j+w]--;
                        }
                        //대각선 1시
                        if(q!=i && w!=j &&i-q>=0 && j+w<n){
                            check[i-q][j+w]--;
                        }
                        
                    }
                }
            }
                
        }
        }
    }
}

int main(void) {
    
    cin >> n;
    queen(0);
    cout << cnt;
    return 0;
}
