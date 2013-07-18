#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

using namespace std;

// split, auto generated by FileEdit
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
	if ( delim.find( s[i] ) != string::npos ) {
	    if ( !t.empty() ) {
		res.push_back( t );
		t = "";
	    }
	} else {
	    t += s[i];
	}
    }
    if ( !t.empty() ) {
	res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
	res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// split, auto generated by FileEdit

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
	if ( i != 0 ) cerr << ", ";
	print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
	cerr << "Case " << n << " passed." << endl;
    } else {
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
	print( have );
	print( need );
	return;
    }
    for( int i= 0; i < have.size(); i++ ) {
	if( have[i] != need[i] ) {
	    cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
	    print( have );
	    print( need );
	    return;
	}
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
	cerr << "Case " << n << " passed." << endl;
    } else {
	cerr << "Case " << n << " failed: expected ";
	print( need );
	cerr << " received ";
	print( have );
	cerr << "." << endl;
    }
}
// END CUT HERE

/************** Program  Begin *********************/

class PipeCuts {
public:
    double probability(vector <int> weldLocations, int L) {
	double res;
	int all = 0;
	int good = 0;
	int front, below;
	for (int i = 0; i < weldLocations.size() - 1; i++) {
		for (int j = i + 1; j < weldLocations.size(); j++) {
			++all;
			front = max(weldLocations[i], weldLocations[j]);
			below = min(weldLocations[i], weldLocations[j]);

			if (	front - below > L ||
				below > L ||
				100 - front > L) {
				++good;
			}
		}
	}

	res = (double) good / all;

	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int weldLocationsARRAY[] = {25, 50, 75};
	vector <int> weldLocations( weldLocationsARRAY, weldLocationsARRAY+ARRSIZE(weldLocationsARRAY) );
	PipeCuts theObject;
	eq(0, theObject.probability(weldLocations, 25),1.0);
    }
    {
	int weldLocationsARRAY[] = {25, 50, 75};
	vector <int> weldLocations( weldLocationsARRAY, weldLocationsARRAY+ARRSIZE(weldLocationsARRAY) );
	PipeCuts theObject;
	eq(1, theObject.probability(weldLocations, 50),0.0);
    }
    {
	int weldLocationsARRAY[] = {25, 50, 75};
	vector <int> weldLocations( weldLocationsARRAY, weldLocationsARRAY+ARRSIZE(weldLocationsARRAY) );
	PipeCuts theObject;
	eq(2, theObject.probability(weldLocations, 24),1.0);
    }
    {
	int weldLocationsARRAY[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
	vector <int> weldLocations( weldLocationsARRAY, weldLocationsARRAY+ARRSIZE(weldLocationsARRAY) );
	PipeCuts theObject;
	eq(3, theObject.probability(weldLocations, 50),0.7222222222222222);
    }
}
// END CUT HERE
