#include <iostream>
#include <vector>
using namespace std;

// Implement the Fibonacci series using recursion
int fibonacci_recursion(int n) {
	if (n<0){
	  cout << "n is a position ,please enter a valid position" << endl;
        return -1;
	}
    if (n==0 || n==1)
        return n; // base cases: fib(0)=0, fib(1)=1
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2); // recursive case
}


// Implement the Fibonacci series using divide and conquer (matrix multiplication)

void multiply_fib_matrix(int arr[2][2], int arr2[2][2], int res[2][2]) {

    res[0][0] = arr[0][0] * arr2[0][0] + arr[0][1] * arr2[1][0];
    res[0][1] = arr[0][0] * arr2[0][1] + arr[0][1] * arr2[1][1];
    res[1][0] = arr[1][0] * arr2[0][0] + arr[1][1] * arr2[1][0];
    res[1][1] = arr[1][0] * arr2[0][1] + arr[1][1] * arr2[1][1];
}

void powerMatrix(int mat[2][2], int n, int powerRes[2][2]) {
	if (n<0){
	cout << "n is a position ,please enter a valid position" << endl;
	  return;
	}
    if (n == 1) {
        powerRes[0][0] = mat[0][0];
        powerRes[0][1] = mat[0][1];
        powerRes[1][0] = mat[1][0];
        powerRes[1][1] = mat[1][1];
        return;
    }

    if (n == 0) {
        powerRes[0][0] = 1;
        powerRes[0][1] = 0;
        powerRes[1][0] = 0;
        powerRes[1][1] = 1;
        return;
    }

    int halfRes[2][2];
    int multRes[2][2];

    powerMatrix(mat, n / 2, halfRes);

    multiply_fib_matrix(halfRes, halfRes, multRes);

    if (n % 2 == 0) {
        powerRes[0][0] = multRes[0][0];
        powerRes[0][1] = multRes[0][1];
        powerRes[1][0] = multRes[1][0];
        powerRes[1][1] = multRes[1][1];
    }
    else {
        multiply_fib_matrix(mat, multRes, powerRes);
    }
}

int fibonacci_DC(int n) {
    int fibArray[2][2] = { {1, 1}, {1,0} };
    int resuilt[2][2];
    powerMatrix(fibArray, n, resuilt);
    return resuilt[0][1];
}

// this is Fibonacci series using dynamic programming.
long fib(int n) {
    //  n position in Fibonacci sequence
    if (n < 0) { // Check that the input givin isnt negative
        cout << "n is a position ,please enter a valid position" << endl;
        return -1;
    }
    // if n is poisition 0 or 1 return n beacuse they are the same as their input in the sequence 
    if (n == 0 || n == 1) { 
        return n;
    }
    // an array/vector to store Fibonacci numbers from position 0 to n
    vector<long> fibArray(n + 1);
      fibArray[0] = 0;
      fibArray[1] = 1;
    for (int i = 2; i <= n; i++) { // for loop to get the answer as for every loop use the before answers to get it
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    } 
    return fibArray[n]; // return result 
}



int main() {
    cout<<"enter n to get Fibonacci for it using the three methods :"<<endl;
    int n ;
    cin>>n;
    cout << "Fibonacci of " << n << " using Recursion: " << fibonacci_recursion(n) << endl;
    cout << "Fibonacci of " << n << " using Divide and Conquer: " << fibonacci_DC(n) << endl;
    cout << "Fibonacci of " << n << " using Dynamic Programming: " << fib(n) << endl;


    return 0;
}