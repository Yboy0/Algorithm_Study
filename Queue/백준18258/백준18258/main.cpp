//
//  main.cpp
//  백준18258
//
//  Created by 유영우 on 2021/01/30.
//

#include <iostream>
#include <queue>

using namespace std;

int n;
int pn;
char od[10];
queue<int>q;

int main(void) {
    scanf("%d", &n);

    while(n--){
        scanf("%s",od);

        if(od[0] == 'p'){
            if(od[1] == 'u'){
                scanf("%d", &pn);
                q.push(pn);
            }
            else{
                if(q.empty())
                    printf("-1\n");
                else{
                    printf("%d\n",q.front());
                    q.pop();
                }
            }
            
        }
    
        else if(od[0] == 'f'){
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n",q.front());
        }

        else if(od[0] == 'b'){
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n",q.back());
        }
        else if(od[0] == 's'){
            printf("%lu\n",q.size());
        }
        else if(od[0] == 'e'){
            if(q.empty())
                printf("1\n");
            else
                printf("0\n");
        }
    }
    

    return 0;
}
