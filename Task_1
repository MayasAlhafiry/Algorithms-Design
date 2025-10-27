#include <iostream>

using namespace std;

// Implement the Fibonacci series using divide and conquer (matrix multiplication)

void multiply_fib_matrix(int arr[2][2], int arr2[2][2], int res[2][2]) {

    res[0][0] = arr[0][0]*arr2[0][0] + arr[0][1]*arr2[1][0];
    res[0][1] = arr[0][0]*arr2[0][1] + arr[0][1]*arr2[1][1];
    res[1][0] = arr[1][0]*arr2[0][0] + arr[1][1]*arr2[1][0];
    res[1][1] = arr[1][0]*arr2[0][1] + arr[1][1]*arr2[1][1];
}

void powerMatrix(int mat[2][2], int n, int powerRes[2][2]) {
    if (n==1) {
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

    powerMatrix(mat, n/2, halfRes);

    multiply_fib_matrix(halfRes, halfRes, multRes);

    if (n%2==0) {
        powerRes[0][0] = multRes[0][0];
        powerRes[0][1] = multRes[0][1];
        powerRes[1][0] = multRes[1][0];
        powerRes[1][1] = multRes[1][1];
    }
    else {
        multiply_fib_matrix(mat, multRes, powerRes);
    }
}

int fibonacci_DC (int n) {
    int fibArray [2][2] = { {1, 1}, {1,0}};
    int resuilt [2][2];
    powerMatrix(fibArray, n, resuilt);
    return resuilt[0][1];
}

// 



int main() {
    int n = fibonacci_DC(10);
    cout << n;

    return 0;
}

