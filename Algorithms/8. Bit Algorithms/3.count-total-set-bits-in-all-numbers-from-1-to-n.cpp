// http://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/

#include <iostream>
#include <cmath>
using namespace std;

unsigned int countSetBitUtil(int n){
    if(n<=0)
        return 0;
    return (n%2 == 0 ? 0:1) + countSetBitUtil(n/2);
}

unsigned int countSetBits(int n){
    unsigned int count = 0;
    for(int i=1; i<=n; i++)
        count += countSetBitUtil(i);
    return count;
}

unsigned int countSetB(int n){
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    unsigned int count = 0;
    int tmp = n;
    int floor = 1;
    int b = 0;
    while(tmp){
        tmp  >>= 1;
        b++;
    }
    if(pow(2, b-1)-1 != n)
        b--;
    int res = b*pow(2, b-1)+1;
    int remain = n-pow(2, b);
    int c = remain;
    return res + remain + countSetB(remain);
}

int main() {
    int n = 4;
//    printf ("Total set bit count is %d", countSetBits(n));
    printf ("Total set bit count is %d", countSetB(17));
	return 0;
}


