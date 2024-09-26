#include <iostream>
using namespace std;

int main() {
    int L, K;
    cin >> L >> K;

    if (K == L) {
        cout << 0; 
        return 0;
    }

    if (K == 0) {
        cout << L; 
        return 0;
    }

    int zeros = L - K;
    int segments = K + 1;
    int baseZeros = zeros / segments;
    int extraZeros = zeros % segments;

    int longestZeroBlock = baseZeros + (extraZeros > 0 ? 1 : 0);

    cout << longestZeroBlock;

    return 0;
}

