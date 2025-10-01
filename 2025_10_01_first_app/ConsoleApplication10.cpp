#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main() {
    int w, n;
    cin >> n >> w;
    vector<int> a(n + 1);
    vector<vector<bool>> dp(n + 1, vector<bool>(w + 1, false));
    for (int i = 1;i < n + 1;++i) {
        cin >> a[i];
    }
    dp[0][0] = true;
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 1;i < n + 1;++i) {
        for (int j = 0;j < w + 1;++j) {
            if (dp[i - 1][j] == true) {
                dp[i][j] = true;
            }
            if (a[i] <= j && dp[i - 1][j - a[i]] == true) {
                dp[i][j] = true;
            }
            if (dp[i][j] == true) {
                ans = max(ans, j);

            }
        }
    }
    cout << ans;


}