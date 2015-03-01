#include "PrimeChecker.h"

namespace PrimeChecker
{
	//This method was adapted from http://en.wikipedia.org/wiki/Primality_test
	bool IsPrime(int number)
	{
		if (number <= 3) {
			return number > 1;
		}
		else if (number % 2 == 0 || number % 3 == 0) {
			return false;
		}
		else {
			for (unsigned short i = 5; i * i <= number; i += 6) {
				if (number % i == 0 || number % (i + 2) == 0) {
					return false;
				}
			}
			return true;
		}
	}
}