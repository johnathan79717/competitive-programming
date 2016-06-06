#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
double pi=acos(-1);
struct ele{
	int num;
	double ang;
}a[100010];
bool cmp(ele p,ele q){
	return p.ang<q.ang;
}

int main(){
    int n,k,in;
    double d,x,y,min=100,t;
    scanf("%d",&n);
    for(k=1;k<=n;k++){
        scanf("%lf%lf",&x,&y);
        d=atan2(y,x);
        if(d<0) d+=2*pi;
        a[k].ang=d;
        a[k].num=k;
    }
    std::sort(a+1,a+n+1,cmp);
    a[n+1]=a[1];
    for(k=1;k<=n;k++){
        t=a[k+1].ang-a[k].ang;
        if(t<0) t+=2*pi;
        if(t<min){
            min=t;
            in=k;
        }
    }
    printf("%d %d",a[in].num,a[in+1].num);
}
