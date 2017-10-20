#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
using namespace std;

const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

void compute_primes(vector<bool>& v)
{
	v[0] = v[1] = false;
	for (int p = 2; p*p < v.size(); p++)
	{
		if (v[p])
		{
			for (int i = p*2; i < v.size(); i += p)
			{
				v[i] = false;
			}
		}
	}
}

void make_prime_spiral(vector< vector< int > >& v, int n, int start)
{
	int t, b, l, r, value;
	t = l = 0;
	b = r = n - 1;
	value = start + n*n - 1;
	v.resize( n, vector<int>( n, 1 ) );
	while (l <= r && t <= b && value >= start)
	{
		for (int j = r; j >= l; j--)
		{
			v[b][j] = value--;
		}
		b--;
		for (int i = b; i >= t; i--)
		{
			v[i][l] = value--;
		}
		l++;
		for (int j = l; j <= r; j++)
		{
			v[t][j] = value--;
		}
		t++;
		for (int i = t; i <= b; i++)
		{
			v[i][r] = value--;
		}
		r--;
	}
	return;
}

void print_prime_spiral(vector< vector < int > > v, int n, int start)
{
	int value = start + n*n - 1;
	vector<bool> primes(value + 1, true);
	compute_primes(primes);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if(primes[v[i][j]]) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void do_prime_spiral(const int n, const int start)
{
	cout << "Prime spiral of size " << n
		<< " starting at " << start << endl;
	if (n % 2 == 0)
	{
		cout << "***** Error: Size " << n << " must be odd."<< endl << endl;
		return;
	}
	else if ((start > MAX_START) || (start < 1))
	{
		cout << "***** Error: Starting value " << start << " < 1 or > 50" << endl << endl;
		return;
	}
	else if (n == 1)
	{
		cout << endl;
		cout << right << setw(4) << "." << endl << endl;
		return;
	}
	else
	{
		cout << endl;
		vector< vector < int > > v;
		make_prime_spiral(v, n, start);
		print_prime_spiral(v, n, start);
		return;
	}

}

/**
 * The main: Generate and print prime spirals of various sizes.
 */

int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
    return 0;
}