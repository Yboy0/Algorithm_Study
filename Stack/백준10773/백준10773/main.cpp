//
//  main.cpp
//  백준10773
//
//  Created by 유영우 on 2021/01/26.
//

#include <iostream>
#include <vector>
using namespace std;
int num;
int sum;
vector<int> v ;
int arr[100001];
int main(void) {
   // vector 풀이 
    int k;
    cin >> k;

    for(int i=0; i<k; i++){
        cin >> num;
        if(num!=0){
            sum+=num;
            v.push_back(num);
        }
        else{
            sum-=v.back();
            v.pop_back();
        }
    }
    cout << sum;
    /* 배열 풀이
    int K;
    cin >> K;
    int cnt = 0;
    while(K--){
        cin >> num;
        if(num != 0){
            arr[cnt] = num;
            cnt ++;
        }
        else{
            cnt --;
            arr[cnt] = num;
        }
    }

    for(int i = 0; i < cnt; i++){
        sum += arr[i];
    }
    cout << sum;
     */
    return 0;
}
