#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<iterator>
#include<functional>
#include<time.h>
#include<iomanip>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define INF 100000000000000000LL

#define eps 0.00001

ld diff(ld a,ld b)
{
    return a>b ? a-b : b-a;
}

bool eq(ld a,ld b)
{
    return diff(a,b) < eps;
}

/*#define COMB_NUM 10001L
ll comb[COMB_NUM][COMB_NUM];
//need init_comb();
void init_comb()
{
    comb[0][0]=1;
    ll i,j;
    for(i=1;i<COMB_NUM;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(j=1;j<i;j++)
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
}
*/

#define print(a)      for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
#define print2n(a,n)      for(int i=0;i<=n;i++) cout<<a[i]<<" "; cout<<endl;

void llFromString(const string &s,ll &a,ll &b)
{
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
               
    istringstream buffer(replacedString);
    buffer>>a;
    if(buffer.good())
    {
        buffer>>b;
    }
    else
    {
        b=0;
    }
}


template<class T>
vector<T> split(const std::string &s) {
    
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
    
    vector<T> ret;
    istringstream buffer(replacedString);
    copy(istream_iterator<T>(buffer),
         istream_iterator<T>(), back_inserter(ret));
    return ret;    
}// vector<ll> k = split<ll>(s);

ld ans, V,X, r[101],c[101];

bool func(ll a, ll b) {
    return diff(c[a],X) < diff(c[b],X);
}

int main()
{
	fstream in,out;
	//in.open("test.in.txt",ios::in); out.open("test.out.txt",ios::out);
	//in.open("B-small-attempt1.in",ios::in); out.open("B-small-0.out",ios::out);
	  in.open("B-large.in",ios::in); out.open("B-large-0.out",ios::out);

	istream& input = in;
	ostream& output = out;

    output<<fixed;
    output.precision(10);
	ll case_id,total_case,temp,N;

	input>>total_case; 
	ll I,H,K,L;
	for(case_id=1;case_id<=total_case;case_id++)
	{
        bool h=false,l=false,imp=false;
        ld er=0.0,lr=0.0,hr=0.0;
        input>>N>>V>>X;
        vector<ll> hv,lv;
        for(I=0;I<N;I++) {
            input>>r[I]>>c[I];
            if(eq(c[I],X)) {
                l=h=true;
                er+=r[I];
            }
            else if(c[I]>X)  {
                h=true;
                hv.push_back(I);
            }
            else {
                l=true;
                lv.push_back(I);
            }
        }
        ld lsum=0.0, hsum=0.0;
        if(!h || !l) {
            imp = true;
            goto ANS;
        }
        
        sort(hv.begin(),hv.end(),func);
        sort(lv.begin(),lv.end(),func);
        
        for(I=0;I<hv.size();I++) hsum+=diff(c[hv[I]],X) * r[hv[I]];
        for(I=0;I<lv.size();I++) lsum+=diff(c[lv[I]],X) * r[lv[I]];
        
        if(hsum<lsum) {
            hv.swap(lv);
            lsum = hsum;
        }
        
        for(I=0;I<lv.size();I++) lr+= r[lv[I]];
        
        for(I=0;I<hv.size();I++) {
            if(lsum > diff(c[hv[I]],X) * r[hv[I]]) {
                lsum -= diff(c[hv[I]],X) * r[hv[I]];
                hr += r[hv[I]];
            } else {
                hr += lsum / diff(c[hv[I]],X);
                break;
            } 
        }
        
        ans = V/(er+hr+lr);
ANS:
		output<<"Case #"<<case_id<<": ";
		imp? output<<"IMPOSSIBLE" : output<<ans;
		output<<endl;
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}











