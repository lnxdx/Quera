// ITNOA
// O(m.log(m)) Convex Hull Trick (Fully Dynamic) by lnxdx, Mashhad, 2019
// This code solves 'Quera C2436 - بهمن مرگبار (Deadly Avalanche)'.
// https://wcipeg.com/wiki/Convex_hull_trick
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
#define IT map<S, double>::iterator
ll INFLL = 9e18;
// There isn't any constraint for slopes or x's to be in any specific order.
struct S {
	ll m, b; // Slope and y-intercept
	S() :m(0), b(0) {}
	S(ll m, ll b) :m(m), b(b) {}
	bool operator<(S s) const { return make_pair(m, b) < make_pair(s.m, s.b); } // > for minimization
};
struct CHT {
	map<S, double>lef;
	map<double, S>s;
	IT beg, end, it1, it2, it3, it4, it5;
	CHT() {}
	// Return true if either line l1 or line l3 is always better than line l2.
	bool bad(S l1, S l2, S l3) {
		/*
		Intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1).
		Intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1).
		Set the former greater than the latter, and cross-multiply to ...
		... eliminate division.
		*/
		// Equality is needed when the lines are concurrent.
		return (l3.b - l1.b)*(l1.m - l2.m) <= (l2.b - l1.b)*(l1.m - l3.m);
	}
	// Returns x coordinates of intersections between the two lines.
	double intx(S l1, S l2) {
		return (double)(l2.b - l1.b) / (l1.m - l2.m);
	}
	void calcit(IT ins) {
		it1 = it2 = it3 = it4 = it5 = ins;
		end = lef.end(); end--; beg = lef.begin();
		if (it3 != beg)	it2--;
		if (it2 != beg) it1--, it1--;
		if (it3 != end) it4++;
		if (it4 != end) it5++, it5++;
	}
	void add(ll m, ll b) { // O(log(n))
						   // Cool iterator manipulations
						   // it3 is the new inserted line. If it is bad it will be removed.
						   // it1 and it2 are the two left to the it3. If it2 is bad it will be removed.
						   // it4 and it5 are the two right to the it3. If it4 is bad it will be removed.
		auto ins = lef.insert({ S(m,b),0 });
		if (ins.second == false) return;
		calcit(ins.first);
		if (it3 != beg && it3->first.m == it2->first.m) {
			s.erase(it2->second);
			lef.erase(it2);
			if (it3 != end) s.erase(it4->second);
		}
		else if (it3 != end && it3->first.m == it4->first.m) {
			lef.erase(it3);
			return;
		}
		calcit(it3);
		if (it3 != beg && it3 != end && bad(it2->first, it3->first, it4->first)) {
			lef.erase(it3);
			return;
		}
		while (it2 != beg && bad(it1->first, it2->first, it3->first)) {
			it1--; // out
			auto del = it2;
			it2--;
			s.erase(del->second);
			if (it3 != end) s.erase(it4->second);
			lef.erase(del);
		}
		while (it4 != end && bad(it3->first, it4->first, it5->first))
		{
			it5++; // lef.end()
			auto del = it4;
			it4++;
			s.erase(del->second);
			s.erase(it4->second);
			lef.erase(del);
		}
		// Setting new intersections; deleting some.
		//calcit(it3);
		if (it3 == beg) {
			it3->second = -INFLL;
			s[-INFLL] = it3->first;
		}
		else {
			it3->second = intx(it2->first, it3->first);
			s[intx(it2->first, it3->first)] = it3->first;
			if (it3 != end) s.erase(it4->second); // -_-
		}
		if (it3 != end) {
			it4->second = intx(it4->first, it3->first);
			s[intx(it4->first, it3->first)] = it4->first;
		}
	}
	/*
	Returns the minimum y-coordinate of any intersection between a given vertical ...
	... line and the lower envelope
	*/
	ll query(ll x) { // O(log(n)) and EZ!
		auto it = s.upper_bound(x);
		it--; // Greatest left value in the set that is less than or equal to the query value x.
		return it->second.m*x + it->second.b;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	CHT cht;
	for (int i = 0;i < m;i++)
	{
		ll s, v;
		cin >> s >> v;
		cht.add(v, s);
	}
	for (int i = 0;i < n;i++)
	{
		ll t;
		cin >> t;
		cout << cht.query(t) << ' ';
	}
}
