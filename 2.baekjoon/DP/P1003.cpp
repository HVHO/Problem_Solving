#include <stdio.h>
#include <utility>

#define mymax(a,b) ((a) > (b) ? (a) : (b))
#define updateBit(x,a) ((x) | (1<<(a)))
#define deleteBit(x,a) ((x) & ~(1<<a))
#define checkBit(x,a) ((x) & (1<<(a)))
#define toggleBit(x,a) ((x) ^ (1<<(a)))

const int INF = 987654321;
const int MOD = 1e7 + 9;
const int NMAX = (int)32000+1;
const int MMAX = (int)41;


using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

using namespace std;

int mem[NMAX][2] = {
    { 1, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 3 }, { 3, 5 }, { 5, 8 }, { 8, 13 }, { 13, 21 }, { 21, 34 }, { 34, 55 }, { 55, 89 }, { 89, 144 }, { 144, 233 }, { 233, 377 }, { 377, 610 }, { 610, 987 }, { 987, 1597 }, { 1597, 2584 }, { 2584, 4181 }, { 4181, 6765 }, { 6765, 10946 }, { 10946, 17711 }, { 17711, 28657 }, { 28657, 46368 }, { 46368, 75025 }, { 75025, 121393 }, { 121393, 196418 }, { 196418, 317811 }, { 317811, 514229 }, { 514229, 832040 }, { 832040, 1346269 }, { 1346269, 2178309 }, { 2178309, 3524578 }, { 3524578, 5702887 }, { 5702887, 9227465 }, { 9227465, 14930352 }, { 14930352, 24157817 }, { 24157817, 39088169 }, { 39088169, 63245986 }, { 63245986, 102334155 }
};

pair<int,int> dp(int n) {

    // printf("%d ",n);
    if(n == 0) return pair<int,int>(1,0);
    if(n == 1) return pair<int,int>(0,1);

    int &ret0 = mem[n][0];
    int &ret1 = mem[n][1];

    if(ret0) return pair<int,int>(ret0,ret1);

    ret0 = dp(n-1).first + dp(n-2).first;
    ret1 = dp(n-1).second + dp(n-2).second;

    return pair<int,int>(ret0,ret1);

}

int sol() {

    // init
    // for(int i = 0; i < 41; i++) {
    //     printf("{ %d, %d }, ",dp(i).first,dp(i).second);
    // }

    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        int tmp;
        scanf("%d",&tmp);
        printf("%d %d\n",mem[tmp][0],mem[tmp][1]);
    }
    
    return 0;
    
}


int main() {
    // printf("%d\n",sol());
    sol();
    return 0;
}