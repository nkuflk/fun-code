#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

const int maxn = 2010;

class Solution {
public:
	int wa[maxn], wb[maxn], wv[maxn], ws[maxn], sa[maxn];

	int cmp(int *r, int a, int b, int l) {
		return r[a]==r[b] and r[a+l]==r[b+l];
	}

	int Rank[maxn],height[maxn];
	void calheight(int *r, int *sa, int n) {
		int i, j, k=0;
		for (i=1; i<=n; ++i)
			Rank[sa[i]] = i;
		for (i=0; i<n; height[Rank[i++]]=k)
			for (k?k--:0, j=sa[Rank[i]-1]; r[i+k]==r[j+k]; ++k);
	}

	void da(int *r, int *sa, int n, int m) {
		int i, j, p, *x=wa, *y=wb;
		for (i=0; i<m; ++i) ws[i] = 0;
		for (i=0; i<n; ++i) ws[x[i]=r[i]]++;
		for (i=1; i<m; ++i) ws[i] += ws[i-1];
		for (i=n-1; i>=0; --i) sa[--ws[x[i]]] = i;
		for (j=1, p=1; p<n; j*=2, m=p) {
			for (p=0, i=n-j; i<n; ++i) y[p++] = i;
			for (i=0; i<n; ++i)	if(sa[i] >= j) y[p++] = sa[i] - j;
			for (i=0; i<n; ++i)  wv[i] = x[y[i]];
			for (i=0; i<m; ++i) ws[i] = 0;
			for (i=0; i<n; ++i) ws[wv[i]]++;
			for (i=1; i<m; ++i) ws[i] += ws[i-1];
			for (i=n-1; i>=0; --i) sa[--ws[wv[i]]] = y[i];
			std::swap(x,y);
			for (p=1, x[sa[0]]=0, i=1; i<n; ++i)
				x[sa[i]] = cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
		}
		return;
	}

    string longestPalindrome(string s) {
		int n = s.size();
		int r[maxn];
		s += '$';
		for (int i=n-1; i>=0; --i) s += s[i];
		for (int i=0; i<2*n+1; ++i) r[i] = s[i];
		r[2*n+1] = 0;
		da(r, sa, 2*n+2, 128);
		calheight(r, sa, 2*n+1);
		int len=0, start=0;
		for (int i=1; i<2*n+2; ++i) {
			if(height[i] > len and (sa[i-1] < n) ^ (sa[i] < n)){
				len = height[i];
				start = sa[i];
			}
		}
		string ans = "";
		for (int i=start; i<start+len; ++i) ans += s[i]; 
		return ans;
    }
};
