/**
 * @file 12097 - Pie.cpp
 * @author wk00100
 * @date 2023-03-10
 * @discription:
 * See discription on UVa-online-judge:
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=242&page=show_problem&problem=3249
 * @method: Binary Search
 */

#include <iostream>
#include <cstdio>
#include <cmath>

#define PI 3.1415926
#define PIE 500

using namespace std;

bool isPossible(const double mid, const double *area, int n, int f)
{
    int people = 0;
    for (int i = 0; i < n; i++)
    {
        people += floor(area[i] / mid);
    }
    return people >= f ? true : false;
}

int main()
{
    int testCase;
    int n, f; // n: number of pie, f: number of friend
    int r, i; // r: radius of pie
    double area[PIE];
    cin >> testCase;
    while (testCase > 0)
    {
        testCase--;
        cin >> n >> f;

        double maxArea = -1; // max area of pie
        for (i = 0; i < n; i++)
        {
            cin >> r;
            area[i] = r * r * PI;
            maxArea = area[i] > maxArea ? area[i] : maxArea;
        }
        double L = 0, U = maxArea;
        double mid;
        while (U - L > 1e-4) // binary search
        {
            mid = (L + U) / 2;
            if (isPossible(mid, area, n, f + 1))
                L = mid;
            else
                U = mid;
        }
        printf("%.4f\n", L);
    }
    return 0;
}
