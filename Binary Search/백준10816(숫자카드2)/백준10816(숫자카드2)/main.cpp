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

struct Data{
    int num;
    int count;
};

int n,m;
vector<Data> answer;
int problem[500001];
int cnt;
int num;

bool compare(Data a, Data b){
    return a.num<b.num;
}

void card(int begin, int end, int number){
    
    int mid = (begin+end)/2;
    
    if(begin>end){
       // cout << 0 << " ";
        printf("0 ");
    }
    else{
        if(answer[mid].num==number){
            //cout << answer[mid].count << " ";
            printf("%d ",answer[mid].count);
        }else if(answer[mid].num>number){
            card(begin,mid-1,number);
        }else{
            card(mid+1,end,number);
        }
    }
}

int main(void) {
    
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        cin >> num;
        
        if(cnt==0){
            Data d = {num,1};
            answer.push_back(d);
            cnt++;
        }else{
            bool ch =false;
            for(int j=0; j<cnt; j++){
                if(answer[j].num==num){
                    answer[j].count++;
                    ch=true;
                    break;
                }
            }
            if(!ch){
                Data d = {num,1};
                answer.push_back(d);
                cnt++;
            }
            
        }
    }
    
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        cin >> problem[i];
    }
        
    sort(answer.begin(),answer.end(),compare);

        for(int i=0; i<m; i++){
            card(0,cnt-1,problem[i]);
        }
    
    return 0;
}

