// Daily 204 Hard CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<array>
using std::cout;
using std::endl;


template<int N, int max, int pos>
struct recurse
{
	static bool impl(std::array<int, N + 1> &tab)
	{
		for (int i1 = pos - 1; i1 >= 0; --i1) {
			int n1 = tab[i1];
			if (n1 << (N + 1 - pos) < max)
				break;
			for (int i2 = 0; i2 <= i1; ++i2) {
				int n2 = tab[i2];
				if ((n1 + n2) < tab[pos - 1])
					continue;
				tab[pos] = n1 + n2;
				bool result;
				result = recurse<N, max, pos + 1>::impl(tab);
				if (result)
					return true;
			}
		}
		return false;
	}
};

template<int N, int max>
struct recurse<N, max, N>
{
	static bool impl(std::array<int, N + 1> &tab)
	{
		for (int i1 = N - 1; i1 >= 0; --i1) {
			int n1 = tab[i1];
			if (n1 * 2 < max)
				break;
			for (int i2 = 0; i2 < N; ++i2) {
				int n2 = tab[i2];
				if (n1 + n2 == max) {
					tab[N] = n1 + n2;
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	const int N = 25;
	const int max = 1234567;

	std::array<int, N + 1> tab;
	tab[0] = 1;
	tab[1] = 2;

	bool success = recurse<N, max, 2>::impl(tab);

	if (success) {
		for (auto& i : tab)
			cout << i << " ";
		cout << endl;
	}
	else
		cout << "none\n";
}
