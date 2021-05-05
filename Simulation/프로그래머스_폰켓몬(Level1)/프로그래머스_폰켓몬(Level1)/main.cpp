//
//  main.cpp
//  프로그래머스_폰켓몬(Level1)
//
//  Created by 유영우 on 2021/05/05.
//

#include <iostream>
#include <vector>
using namespace std;

int sz;
int check[1001];
vector<int> arr;
vector<int> numss;
int subA;

bool compare(int a, int b){
    return a<b;
}

int solution(vector<int> nums)
{
    
    int sz=nums.size();
    int answer = 0;
    sort(nums.begin(),nums.end(),compare);
    
    int ch=1;
    int a=0;
    for(a ; a<sz-1; a++){
        bool checkk=false;
        for(int j=a+1;j<sz;j++){
            if(nums[a]!=nums[j] && checkk==false){
                checkk=true;
                ch++;
            }else if(nums[a]==nums[j]){
                a++;
            }
        }
    }
    
    if(sz/2>=ch){
        answer=ch;
    }else{
        answer=sz/2;
    }
    return answer;
}

int main(void) {
    
    vector<int>numsr={3,2,3,2,2,2};
    
    cout << solution(numsr);
    
    
}
