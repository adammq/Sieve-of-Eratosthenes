#include <iostream>
using namespace std;

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
void SieveOfEratosthenes(long long int limit)
{
	long long int i;
	long long int k;
	long long int primeCount;
	bool * isPrime = new bool[limit + 1];

	memset(isPrime, true, limit + 1);
	isPrime[0] = false;
	isPrime[1] = false;

	for (i = 2; i <= limit; i++)
	{
		if (isPrime[i])
		{
			for (k = i*i; k <= limit; k += i)
			{
				isPrime[k] = false;
			}
		}
	}
	primeCount = 0;
	for (i = 2; i <= limit; i++)
	{
		if (isPrime[i])
		{
			primeCount ++;
		}
	}
	cout << "\nThere are " << primeCount << " prime numbers below "
		 << limit << ".\n\n";
	delete[] isPrime;
}

int main()
{
	long long int upperBound;

	cout << "Enter upper bound (inclusive): ";
	cin  >> upperBound;

	cout << "Thinking ...\n";

	SieveOfEratosthenes(upperBound);


	return 0;
}
