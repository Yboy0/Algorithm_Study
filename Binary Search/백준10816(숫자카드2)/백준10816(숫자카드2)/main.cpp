//
//  main.cpp
//  백준10816(숫자카드2)
//
//  Created by 유영우 on 2021/04/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> answer;
int num;

int main(void) {
    
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&num);
        answer.push_back(num);
    }
    
    sort(answer.begin(),answer.end());
    
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        scanf("%d",&num);
        printf("%ld ",upper_bound(answer.begin(), answer.end(), num)-lower_bound(answer.begin(), answer.end(), num));
    }

    return 0;
}

