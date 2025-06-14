#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//version 1
int rangeBitwiseAnd(int left, int right) {
        while(left < right) {
            right = right & (right-1);
        }
        return right;
}
//version 2
 int rangeBitwiseAnd(int left, int right) {
        int shift{0};
        while (left != right)
        {
            left >>= 1;
            right >>=1;
            shift += 1;
        }
        return left << shift;
    }
//version 3
  int rangeBitwiseAnd(int left, int right) {
        int s = 0;
        for (int i = 31; i >= 0; i--) {
            int bitLeft = (left >> i) & 1;
            int bitRight = (right >> i) & 1;

            if (bitLeft == bitRight) {
                if (bitLeft == 1) {
                    s |= (1 << i);
                }
            } else break;
        }
        return s;
    }
int main() {
    int L,R;
    cin >> L>>R;
  cout<< rangeBitwiseAnd(L,R)<<"\n";
    return 0;
}
