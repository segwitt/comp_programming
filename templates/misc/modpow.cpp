
/*
#include <iostream>
using namespace std;

*/

#define ll long long
const ll mod = 1e9 + 7;

ll add ( ll x , ll y ) {
	x %= mod;
	y %= mod;
	return ( x + y ) % mod;
}

ll mul(ll x, ll y) {
	x %= mod;
	y %= mod;
	return ( x * y ) % mod; 
}

ll modpow(ll x , ll y) {
	// x ^ y
	ll res = 1;
	while ( y ) {

		if ( y & 1 )
			res = mul( res , x );
		x = mul ( x , x );
		y >>= 1;

	}
	return res;
}

/*
int main(int argc, char const *argv[])
{
	cout << modpow( 3, 4 ) << endl;

	return 0;
}
*/