#include<bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2) {
    unsigned long long R1 = r1;
    unsigned long long R2 = r2;
    long long answer = 0;
    
    for (unsigned long long x = 1; x <= R2; x++) {
        unsigned long long max_y = floor(sqrt(pow(R2, 2) - pow(x, 2)));
        unsigned long long min_y;
        if(x>R1)
            min_y = 0;
        else
            min_y = ceil(sqrt(pow(R1, 2) - pow(x, 2)));
        
        answer += (max_y - min_y + 1);
    }
    
    return answer * 4;
}
