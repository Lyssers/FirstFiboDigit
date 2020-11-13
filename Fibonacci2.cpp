#include <iostream>
#include <string> 
#include "BigIntegerLibrary.hh"
#include <chrono>
using namespace std::chrono;
using namespace std;

int fibDigit(int digits) {
	
	//1 is the first Term in the Fibonacci Sequence, (zero is the zeroeth) we start counting from 1
	int counter = 1;
	//Custom unlimited memory integer data type array with 2-elements, initialized with the zeroeth and first term of the fibonacci sequence
	BigInteger fiboNums[]{ 0,1 };
	//Temporasry number for calculation later
	BigInteger temp = fiboNums[0];
	//To find the first Fibonacci Term with 1000 digits, we need to calculate 10^999, there's no way that i know of of actually counting the digits in a number
	//that large
	BigInteger b = 10;
	BigInteger limit = 10;
	//Loop to calculate 
	for (int x = 1; x < digits; x++) {
		limit = limit * b;
	}
	
	//cout << limit << endl;
	//While Fibonacci Term is less than the limit number calculated above, count upwards
	while (fiboNums[1] <= limit) {
		counter++;
			//cout << "Current Index: " << counter << "\n";	
		temp = fiboNums[1];
		fiboNums[1] = fiboNums[0] + fiboNums[1];
		fiboNums[0] = temp;
	}
	//Display counter.
	cout << counter << endl;
	return 0;
}



int main() {
	int digits;
	cout << "Number of Digits?";
	cin >> digits;
	digits = digits - 1;
	auto start = high_resolution_clock::now();
	fibDigit(digits);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "MiliSeconds: " << duration.count() << endl;
	
	return 0;
}
