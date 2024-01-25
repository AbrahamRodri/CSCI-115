#include <iostream>
using namespace std;

// Function (iterative) + for
int Factorial1(int n)
{
	// n*(n-1)* .... * 1
	// 1*n*(n-1)*...
	int s = n;
	// for (statement 1;statement 2;statement 3)
	for (int i = n-1; i > 1; i--)
	{
		// s=s*i;
		s *= i;
	}
	return s;
}

int Factorial2(int n)
{
	int s = 1.0;
	// for (statement 1;statement 2;statement 3)
	for (int i = 1; i <= n; i++)
	{
		// s=s*i;
		s *= i;
	}
	return s;
}

// Function (iterative) + while
int Factorial3(int n)
{
	double s = 1.0;
	int i = 1; // initialization (statement 1)
	while (i <= n) // test (statement 2)
	{
		s *= i;
		i++; // (statement 3)
	}
	return s;
}

int Factorial4(int n)
{
	int s = n;
	int i = n-1; // initialization (statement 1)
	while (i > 1) // test (statement 2)
	{
		s *= i;
		i--; // (statement 3)
	}
	return s;
}

// Base case: when we start or when we end?
// It depends. That s the difficult part: glass half full vs half empty

// Function (recursive) 
// Remark: we go from n to 1, not from 1 to n
int Factorial5(int n)
{
	if (n == 1)
		return 1.0; // Base case
	else
		return (Factorial5(n - 1) * n);
}

int Factorial6(int n)
{
	return  (n == 1) ? 1 : (Factorial6(n - 1) * n);
}


// Function (recursive) 
// Remark: we go from 1 to n, but need to keep track of n and have a counter i
int Factorial7a(int i, int n)
{
	if (i > n)
		return 1.0; // base case
	else // i<=n
		return (i * Factorial7a(i + 1, n));
}

//   1*f3a(2,n)
//   1*2*f3a(3,n)
//   1*2*3*f3a(4,n)
//   1*2*3* ..... * n
// 1 * 2 * 3* ..... * n * 1


// Main call of the function, without the variable i
int Factorial7(int n)
{
	return Factorial7a(1, n);
}


// Void (iterative) + for + pointer
void Factorial8(int n, int* s)
{
	(*s) = 1.0;
	// for (statement 1;statement 3;statement 3)
	for (int i = 1; i <= n; i++)
	{
		(*s) *= i;
	}
	// (f(n)== (*s))
}

// Void (iterative) + for + reference
void Factorial9(int n, int& s)
{
	s = 1.0;
	// for (statement 1;statement 3;statement 3)
	for (int i = 1; i <= n; i++)
	{
		s *= i;
	}
	// (f(n)== s)
}

// Void (recursive) + pointer
// from n to 1
void Factorial10(int n, int* s)
{
	if (n == 1) // condition: when we stop
		(*s) = 1.0; // base case
	else
	{
		int s1; // it corresponds to the output of (n-1)!
		Factorial10(n - 1, &s1); // dig, dig, dig, reach the base case
		(*s) = s1*n; // then do the action, climb, climb, ... reach the first call
	}
}

// Void (recursive) + pointer
// from i=1 to n
void Factorial11a(int n, int i, int* s)
{
	if (i <= n) // condition: when we stop
	{
		(*s) *= i; // do the action
		Factorial11a(n, i + 1, s); // then go to the next element
	}
}

void Factorial11(int n, int* s)
{
	(*s) = 1;
	Factorial11a(n, 1, s);
}

// Void (recursive) +  reference
void Factorial12(int n, int& s)
{
	if (n == 1) // condition: when we stop
		s = 1.0; // base case
	else
	{
		int s1; // s1 corresponds to the output of (n-1)!
		Factorial12(n - 1, s1); // dig, dig, dig, reach the base case
		s = s1*n; // then do the action, climb, climb, ... reach the first call
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int FibonacciREC1(int n)
{
	return (n == 0) ? 0 : (n == 1) ? 1 : FibonacciREC1(n - 1) + FibonacciREC1(n - 2);
}

int FibonacciREC2(int n)
{
	switch (n)
	{
	case 0: return 0; // base case
	case 1:return 1; // base case
	default: return FibonacciREC2(n - 1) + FibonacciREC2(n - 2); // any other case
	}
}

int FibonacciREC(int n)
{
	if (n == 0)
		return 0; // base case
	else if (n == 1)
		return 1; // base case
	else
		return FibonacciREC(n - 1) + FibonacciREC(n - 2); // recursive call
}

void FibonacciREC(int n, int& output)
{
	if (n == 0)
		output = 0; // base case
	else if (n == 1)
		output = 1; // base case
	else
	{
		int output1;
		int output2;
		FibonacciREC(n - 1, output1);
		FibonacciREC(n - 2, output2);
		output = output1 + output2;
	}
}


int FibonacciITE(int n)
{
	if (n == 0)
		return 0; // base case
	else if (n == 1)
		return 1; // base case
	else
	{
		int a, b, f = 0;
		a = 0; b = 1;
		for (int i = 2; i <= n; i++)
		{
			f = b + a; // f(n)=f(n-1)+f(n-2)
			// Update the values for the next iteration
			a = b;
			b = f;
			// next iteration will be:
			// f(i) = f + b
		}
		return f;
	}
}


void FibonacciITE(int n, int& output)
{
	if (n == 0)
		output = 0; // base case
	else if (n == 1)
		output = 1; // base case
	else
	{
		int a, b, f = 0;
		a = 0; b = 1;
		for (int i = 2; i <= n; i++)
		{
			f = b + a; // f(n)=f(n-1)+f(n-2)
			// Update the values for the next iteration
			a = b;   // Warning the order of these instructions is important! otherwise you erase the value in B
			b = f;
			// next iteration will be:
			// f(i) = f + b
		}
		output = f;
	}
}

int main()
{
	int n;
	cout << "CSci 115" << endl;

	cout << "*******************************" << endl;
	cout << "**** Factorial functions  *****" << endl;

	n = 6;
	cout << "Factorial1 of " << n << "=" << Factorial1(n) << endl;
	cout << "Factorial2 of " << n << "=" << Factorial2(n) << endl;
	cout << "Factorial3 of " << n << "=" << Factorial3(n) << endl;
	cout << "Factorial4 of " << n << "=" << Factorial4(n) << endl;
	cout << "Factorial5 of " << n << "=" << Factorial5(n) << endl;
	cout << "Factorial6 of " << n << "=" << Factorial6(n) << endl;
	cout << "Factorial7 of " << n << "=" << Factorial7(n) << endl;

	int f;
	Factorial8(n, &f);
	cout << "Factorial8 of " << n << "=" << f << endl;
	Factorial9(n, f);
	cout << "Factorial9 of " << n << "=" << f << endl;
	Factorial10(n, &f);
	cout << "Factorial10 of " << n << "=" << f << endl;
	Factorial11(n, &f);
	cout << "Factorial11 of " << n << "=" << f << endl;
	Factorial12(n, f);
	cout << "Factorial12 of " << n << "=" << f << endl;

	cout << "*******************************" << endl;
	cout << "**** Fibonacci functions  *****" << endl;

	n = 8;

	cout << "Fibonacci (REC1) of " << n << "=" << FibonacciREC1(n) << endl;
	cout << "Fibonacci (REC2) of " << n << "=" << FibonacciREC2(n) << endl;
	cout << "Fibonacci (REC) of " << n << "=" << FibonacciREC(n) << endl;
	cout << "Fibonacci (ITE) of " << n << "=" << FibonacciITE(n) << endl;

	int output;
	FibonacciREC(n, output);
	cout << "Fibonacci (REC) of " << n << "=" << output << endl;
	FibonacciITE(n, output);
	cout << "Fibonacci (ITE) of " << n << "=" << output << endl;

	return 1;
}