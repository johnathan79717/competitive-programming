#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[50], b[50], c[50];

int main( void ) {
  int t;
  scanf( "%d", &t );
  for( ; t; --t ) {
    memset( a, 0, sizeof( a ) );
    memset( b, 0, sizeof( b ) );
    memset( c, 0, sizeof( c ) );

    int n, m;
    scanf( "%d", &n );
    for( int i = 0; i <= n; ++i )
      scanf( "%d", a+i );
    scanf( "%d", &m );
    for( int i = 0; i <= m; ++i )
      scanf( "%d", b+i );
    
    int ok = 1;
    for( int i = n; i >= 0; --i ) {
      if( i < m && a[i] ) { ok = 0; break; }
      if( a[i]%b[m] ) { ok = 0; break; }
      
      int k = a[i]/b[m], d = i-m;
      for( int j = 0; j <= m; ++j )
	a[j+d] -= k*b[j];
      c[d] += k;
    }

    if( !ok ) puts( "no solution" ); else {
      for( int i = 0; i <= n-m; ++i ) {
	if( i ) putchar( ' ' );
	printf( "%d", c[i] );
      }
      putchar( '\n' );
    }
  }
  return 0;
}
