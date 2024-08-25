// https://leetcode.com/problems/knight-dialer/description/

    int mod = 1e9+7;
    int knightDialer(int n) {
        int i, j, ans = n == 1, A[4][4]{}, B[4][4]{};
        B[0][0] = 4, B[1][1] = B[2][2] = 2, B[3][3] = 1;
        A[0][1] = A[0][2] = A[2][3] = 2;
        A[1][0] = A[2][0] = A[3][2] = 1;
        for (n--; n; n >>= 1) {
            if (n & 1) mul(A, B, B);
            mul(A, A, A);
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                ans = (ans + B[i][j]) % mod;
            }
        }
        return ans;
    }

    void mul(int A[4][4], int B[4][4], int C[4][4]) {
        int64_t i, j, k, D[4][4]{};
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    D[i][j] += (int64_t)A[i][k] * B[k][j];
                }
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                C[i][j] = D[i][j] % mod;
            }
        }
    }
