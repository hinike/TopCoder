#include <cassert>
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

typedef pair<int, int> pii;
#define mkp make_pair

const int MOD = 1000000007;

long long PowerMod(long long a, long long b, long long c)
{
	long long ans = 1;
	a = a % c;
	while (b > 0) {
		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans % c;
}

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("jam.in", "r", stdin)) {
		printf("Can't open jam.in!\n");
		exit(-1);
	}
	FILE * f = NULL;
	f = freopen("jam.out", "w", stdout);
#endif

	int T;
	scanf("%d\n", &T);
	for (int casei = 0; casei < T; ++casei) {
		
		scanf("");
		int res = 0;
		printf("Case #%d: %d\n", casei + 1, res);
	}
	
	return 0;
}