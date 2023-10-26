#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vector<string> bd;

ll ansW, ansB;
char now;
ll ct;
vvb visit;

const auto di = vi{ -1,1,0,0 };
const auto dj = vi{ 0,0,-1,1 };

void dfs(int i, int j) {
	auto st = stack<pii>{};
	st.push({ i, j });
	visit[i][j] = true;

	while (!st.empty()) {
		auto [y, x] = st.top();
		st.pop();

		++ct;

		for (auto d = 0; d < 4; ++d) {
			const auto ni = y + di[d];
			const auto nj = x + dj[d];

			if (ni < 0 || n <= ni ||
				nj < 0 || m <= nj) {
				continue;
			}

			if (visit[ni][nj]) {
				continue;
			}

			if (now != bd[ni][nj]) {
				continue;
			}

			st.push({ ni, nj });
			visit[ni][nj] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> m >> n;

	bd = vector<string>(n);
	for (auto&& s : bd) {
		cin >> s;
	}

	visit = vvb(n, vb(m, false));
	ansW = 0;
	ansB = 0;
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			if (visit[i][j]) {
				continue;
			}

			now = bd[i][j];
			ct = 0;

			dfs(i, j);

			if ('W' == now) {
				ansW += ct * ct;
			}
			else if ('B' == now) {
				ansB += ct * ct;
			}
		}
	}

	cout << ansW << ' ' << ansB;

	return 0;
}