#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

double* create(int n, const double Low, const double High)
{
    double* a = new double[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = Low + static_cast<double>(rand()) / RAND_MAX * (High - Low);
    }
    return a;
}

void print(double* a, int n)
{
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << a[i];
    }
    cout << endl;
}

double MaxRecursive(double* a, int n, int currentIndex)
{
    if (currentIndex == n - 1)
        return a[currentIndex];

    double nextMax = MaxRecursive(a, n, currentIndex + 1);
    return (a[currentIndex] > nextMax) ? a[currentIndex] : nextMax;
}

double SumRecursive(double* a, int n, int currentIndex)
{
    if (currentIndex == 0)
        return 0;

    if (a[currentIndex] > 0)
        return a[currentIndex] + SumRecursive(a, n, currentIndex - 1);
    else
        return SumRecursive(a, n, currentIndex - 1);
}

void CompressArrayRecursive(double* a, int n, double a_val, double b_val, int currentIndex)
{
    if (currentIndex >= n)
        return;  // Ѕазовий випадок: завершити рекурс≥ю, коли дос€гнуто к≥нц€ масиву.

    if (abs(a[currentIndex]) < a_val || abs(a[currentIndex]) > b_val)
        a[currentIndex] = 0;  // «ам≥нити елемент на 0, €кщо не задовольн€Ї умову.

    CompressArrayRecursive(a, n, a_val, b_val, currentIndex + 1);  // –екурсивно викликати дл€ наступного елемента.
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    double Low = 1.0;
    double High = 20.0;

    double n;
    cout << "Enter the size: ";
    cin >> n;

    double* a = create(n, Low, High);
    print(a, n);

    double a_val, b_val;
    cout << "Enter a: ";
    cin >> a_val;

    cout << "Enter b: ";
    cin >> b_val;

    CompressArrayRecursive(a, n, a_val, b_val, 0);
    cout << "Max = " << MaxRecursive(a, n, 0) << endl;
    cout << "Sum = " << SumRecursive(a, n, n - 1) << endl;

    delete[] a;

    return 0;
}
