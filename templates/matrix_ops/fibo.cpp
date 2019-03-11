#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
#define N 2
const ll mod = 1e9 + 7;


ll add(ll x, ll y) { x %= mod; y %= mod; return (x + y)%mod; }
ll mul(ll x, ll y) { x %= mod; y %= mod; return (x * y)%mod; }


void matmul(ll mat1[][N] , ll mat2[][N] ) {

	ll tmp[N][N] ;
	memset(tmp, 0, sizeof tmp);

	for( int i = 0; i < N; ++i )
		for ( int j = 0; j < N; ++j )
			for ( int k = 0; k < N; ++k ) {
				ll z = mul( mat1[i][k] , mat2[k][j] ) ;
				tmp[i][j] = add ( z , tmp[i][j] );
			}

	memcpy(mat1, tmp, sizeof tmp);

	// multiplies the matrix inplace and copies the result to the first matrix

}


void matpow(ll mat[][N], ll x) {

	
	if ( x == 1 ) return ;
	ll tmp[N][N] = { { 1, 1 }, { 1, 0 } } ;

	// assert( sizeof tmp == sizeof mat );
	// or replace by the original matrix
	if ( x & 1 ) {
		matpow( mat , x - 1 );
		// tmp[N][N] = { { 1, 1 } , { 1, 0 } };

	}
	else {
		memcpy(tmp, mat, sizeof tmp);
		matpow( mat , x / 2 );
	}

	matmul(mat, tmp);


}



ll fib(ll x) {

	// fib(0) = 0 , fib(1) = 1
	if ( x <= 1 ) return 0;

	--x;

	ll mat[][N] = { { 1, 1 } , { 1, 0 } };
	matpow(mat, x);

	// uncomment to debug
	// cout << mat[0][0] << " " << mat[0][1] << endl;
	// cout << mat[1][0] << " " << mat[1][1] << endl;

	return mat[0][0];



}




int main(int argc, char const *argv[])
{

	ll mat[][N] = { { 1, 1 } , { 1, 0 } };

	cout << fib(100000000000000) << endl;;



	return 0;

}