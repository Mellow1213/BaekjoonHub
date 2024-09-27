#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> W(N+1), V(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(W[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}