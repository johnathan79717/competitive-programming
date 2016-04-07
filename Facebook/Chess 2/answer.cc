#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#pragma comment(linker,"/STACK:256000000")

using namespace std;

int bx[]={1,1,-1,-1};
int by[]={1,-1,1,-1};

int nx[]={2,2,-2,-2,1,1,-1,-1};
int ny[]={1,-1,1,-1,2,-2,2,-2};

int qx[]={1,1,-1,-1,1,-1,0,0};
int qy[]={1,-1,1,-1,0,0,1,-1};

int rx[]={0,0,1,-1};
int ry[]={1,-1,0,0};

char a[17][17];

int ok(int x,int y){
	return x>=1&&x<=16&&y>=1&&y<=16;
}

int n;
int used[17][17];

int main(){
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	for (int tt=1; tt<=t; tt++){
		memset(a,0,sizeof(a));
		memset(used,0,sizeof(used));
		int n;
		cin>>n;
		for (int i=0; i<n; i++){
			string c;
			cin>>c;
			int x,y;
			cin>>x>>y;
			a[x][y]=c[0];
		}

		for (int i=1; i<=16; i++)
			for (int j=1; j<=16; j++){
				if (a[i][j]=='K'){
					for (int k=0; k<8; k++){
						int x,y;
						x=i+qx[k], y=j+qy[k];
						if (ok(x,y)){
							if (a[x][y]!=0){
								used[x][y]=1;
							}
						}
					}
				} else
				if (a[i][j]=='Q'){
					for (int k=0; k<8; k++){
						for (int l=1; l<20; l++){
							int x,y;
							x=i+l*qx[k], y=j+l*qy[k];
							if (ok(x,y)){
								if (a[x][y]!=0){
									used[x][y]=1;
									break;
								}
							}
						}
					}
				} else
				if (a[i][j]=='R'){
					for (int k=0; k<4; k++){
						for (int l=1; l<20; l++){
							int x,y;
							x=i+l*rx[k], y=j+l*ry[k];
							if (ok(x,y)){
								if (a[x][y]!=0){
									used[x][y]=1;
									break;
								}
							}
						}
					}
				} else
				if (a[i][j]=='B'){
					for (int k=0; k<4; k++){
						for (int l=1; l<20; l++){
							int x,y;
							x=i+l*bx[k], y=j+l*by[k];
							if (ok(x,y)){
								if (a[x][y]!=0){
									used[x][y]=1;
									break;
								}
							}
						}
					}
				} else
				if (a[i][j]=='N'){
					for (int k=0; k<8; k++){
						int x,y;
						x=i+nx[k], y=j+ny[k];
						if (ok(x,y)){
							if (a[x][y]!=0)
								used[x][y]=1;
						}
					}
				} else
				if (a[i][j]=='S'){
					for (int k=0; k<8; k++){
						for (int l=1; l<20; l++){
							int x,y;
							x=i+l*nx[k], y=j+l*ny[k];
							if (ok(x,y)){
								if (a[x][y]!=0){
									used[x][y]=1;
									break;
								}
							}
						}
					}
				} else
				if (a[i][j]=='A'){
					for (int k=0; k<8; k++){
						int x,y;
						x=i+nx[k], y=j+ny[k];
						if (ok(x,y)){
							if (a[x][y]!=0)
								used[x][y]=1;
						}
					}
					for (int k=0; k<4; k++){
						for (int l=1; l<20; l++){
							int x,y;
							x=i+l*bx[k], y=j+l*by[k];
							if (ok(x,y)){
								if (a[x][y]!=0){
									used[x][y]=1;
									break;
								}
							}
						}
					}
				} else
				if (a[i][j]=='E'){
					for (int k=1; k<17; k++)
						for (int l=1; l<17; l++)
							if (!(k==i&&l==j))
								used[k][l]=1;
				}
			}
		int ans=0;
		for (int i=1; i<17; i++)
			for (int j=1; j<17; j++)
				if (used[i][j]&&a[i][j]!=0) ans++;
		cout<<ans<<endl;
	}




	return 0;
}