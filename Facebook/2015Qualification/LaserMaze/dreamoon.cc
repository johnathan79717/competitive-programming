#include <cstdio>
#include <queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 105;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
char cc[6]="v<^>";
const int rr=3;
const int uu=2;
const int ll=1;
const int dd=0;
char s[SIZE][SIZE];
int ban[4][SIZE][SIZE],tt;
int v[4][SIZE][SIZE];
int used[4][SIZE][SIZE];
int N,M;
bool Out(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
int main(){
    CASET{
        tt++;
        int sx,sy,ex,ey;
        RII(N,M);
        REP(i,N)RS(s[i]);
        REP(i,N)REP(j,M){
            if(s[i][j]=='S'){
                s[i][j]='.';
                sx=i;sy=j;
            }
            if(s[i][j]=='G'){
                s[i][j]='.';
                ex=i;
                ey=j;
            }
        }
        REP(i,4){
            REP(x,N){
                bool stop=0;
                REP(y,M){
                    if(s[x][y]!='.')stop=0;
                    if(s[x][y]==cc[(rr+4-i)%4])stop=1;
                    if(s[x][y]=='.'&&stop)ban[i][x][y]=tt;
                }
                stop=0;
                for(int y=M-1;y>=0;y--){
                    if(s[x][y]!='.')stop=0;
                    if(s[x][y]==cc[(ll+4-i)%4])stop=1;
                    if(s[x][y]=='.'&&stop)ban[i][x][y]=tt;
                }
            }
            REP(y,M){
                bool stop=0;
                REP(x,N){
                    if(s[x][y]!='.')stop=0;
                    if(s[x][y]==cc[(dd+4-i)%4])stop=1;
                    if(s[x][y]=='.'&&stop)ban[i][x][y]=tt;
                }
                stop=0;
                for(int x=N-1;x>=0;x--){
                    if(s[x][y]!='.')stop=0;
                    if(s[x][y]==cc[(uu+4-i)%4])stop=1;
                    if(s[x][y]=='.'&&stop)ban[i][x][y]=tt;
                }
            }
        }
        printf("Case #%d: ",case_n++);
        queue<int>bfs;
        bfs.PB(0);bfs.PB(sx);bfs.PB(sy);
        used[0][sx][sy]=tt;
        v[0][sx][sy]=0;
        bool suc=0;
        while(SZ(bfs)){
            int t=bfs.front();bfs.pop();
            int x=bfs.front();bfs.pop();
            int y=bfs.front();bfs.pop();
            if(x==ex&&y==ey){
                printf("%d\n",v[t][ex][ey]);
                suc=1;
                break;
            }
            REP(k,4){
                int nx=x+dx[k];
                int ny=y+dy[k];
                int nt=(t+1)&3;
                if(Out(nx,ny))continue;
                if(s[nx][ny]!='.')continue;
                if(ban[nt][nx][ny]==tt)continue;
                if(used[nt][nx][ny]==tt)continue;
                used[nt][nx][ny]=tt;
                v[nt][nx][ny]=v[t][x][y]+1;
                bfs.PB(nt);
                bfs.PB(nx);
                bfs.PB(ny);
            }
        }
        if(!suc)puts("impossible");
    }
    return 0;
}
