#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#define MAXN 1000500
#define MAXL 40050

using namespace std;

const int mod=1000000007;

class Coor {
   public:
      int r,c;
      Coor() {}
      Coor(int _r,int _c):r(_r),c(_c) {}
};

class Event {
   public:
      int c,r1,r2,a;
      Event(int _c,int _r1,int _r2,int _a):c(_c),r1(_r1),r2(_r2),a(_a) {}
      const bool operator<(const Event &b) const {
         return c<b.c;
      }
};

class Node {
   public:
      int vl,vr,val,zero;
      Node *_l,*_r;
      Node(int _vl,int _vr):vl(_vl),vr(_vr) {
         _l=_r=NULL;
         val=0;
         zero=vr-vl+1;
      }
      ~Node() {
         delete _l;
         delete _r;
      }
      Node* left() {
         int m=(vl+vr)>>1;
         if(!_l) _l=new Node(vl,m);
         return _l;
      }
      Node* right() {
         int m=(vl+vr)>>1;
         if(!_r) _r=new Node(m+1,vr);
         return _r;
      }
      void up() {
         if(val) zero=0;
         else {
            if(vl==vr) zero=1;
            else zero=left()->zero+right()->zero;
         }
      }
      int add(int l,int r,int x) {
         if(vl==l&&vr==r) {
            val+=x;
            up();
         } else {
            int m=(vl+vr)>>1;
            if(r<=m) left()->add(l,r,x);
            else if(l>m) right()->add(l,r,x);
            else {
               left()->add(l,m,x);
               right()->add(m+1,r,x);
            }
            up();
         }
      }
};

int rn,cn,rl,cl,n;
int r0,c0,ccc,ccr,crc,crr;
Coor p[MAXN];

int solve() {
   int sol=0;
   vector<Event> e;
   int maxr=rn-rl;
   int maxc=cn-cl;
   for(int i=0;i<n;i++) {
      int r1,r2;
      r1=min(max(0,p[i].r-rl+1),maxr);
      r2=min(p[i].r,maxr);
      e.push_back(Event(p[i].c-cl+1,r1,r2,+1));
      e.push_back(Event(p[i].c+1,r1,r2,-1));
   }
   sort(e.begin(),e.end());
   Node seg(0,maxr);
   for(int c=0,ei=0;c<=maxc;c++) {
      while(ei<e.size()&&e[ei].c<=c) {
         seg.add(e[ei].r1,e[ei].r2,e[ei].a);
         //printf("(%d) <%d %d %d>\n",e[ei].c,e[ei].r1,e[ei].r2,e[ei].a);
         ei++;
      }
      //printf("c=%d, zero=%d\n",c,seg.zero);
      sol+=seg.zero;
   }
   return sol;
}

int main(void) {
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d",&cn,&rn);
      scanf("%d %d %d",&cl,&rl,&n);
      scanf("%d %d %d %d %d %d",&c0,&r0,&ccc,&ccr,&crc,&crr);
      p[0]=Coor(r0,c0);
      for(int i=1;i<n;i++)
         p[i]=Coor(
               (crr*(long long)p[i-1].r+crc*(long long)p[i-1].c+1)%rn,
               (ccr*(long long)p[i-1].r+ccc*(long long)p[i-1].c+1)%cn
               );
      printf("Case #%d: %d\n",cas++,solve());
   }
   return 0;
}
