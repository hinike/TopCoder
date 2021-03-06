#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class BearPlays {
public:
	// 2^k % M
	long long powermod(int k, int M) {
		if (k == 0) {
			return 1;
		}

		long long a = powermod(k/2, M) % M;
		if (k % 2 == 0) {
			return (a * a) % M;
		} else {
			return (2 * a * a) % M;
		}
	}
    int pileSize(int A, int B, int K) {
		int a = (powermod(K, A+B) * A) % (A+B);
		int b = A + B - a;
		return min(a, b);
    }

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
	if( have.size() != need.size() ) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        BearPlays theObject;
        eq(0, theObject.pileSize(4, 7, 2),5);
    }
    {
        BearPlays theObject;
        eq(1, theObject.pileSize(5, 5, 3),0);
    }
    {
        BearPlays theObject;
        eq(2, theObject.pileSize(2, 6, 1),4);
    }
    {
        BearPlays theObject;
        eq(3, theObject.pileSize(2, 8, 2000000000),2);
    }
    {
        BearPlays theObject;
        eq(4, theObject.pileSize(900000000, 350000000, 3),300000000);
    }
	return 0;
}
// END CUT HERE
