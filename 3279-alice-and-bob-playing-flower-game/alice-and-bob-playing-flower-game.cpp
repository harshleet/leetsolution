class Solution {
public:
    long long flowerGame(int n, int m) {
        long long a=(n+1)/2;
        long long b=n/2;
        long long c=(m+1)/2;
        long long d=m/2;
        return (a*d+b*c);
    }
};