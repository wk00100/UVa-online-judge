/**
 * @file 11462 - Age Sort.cpp
 * @author wk00100
 * @date 2023-03-17
 * @discription:
 * See discription on UVa-online-judge:
 * https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2457
 * @method: Radix Sort
 */

#include <stdio.h>  // use iostream will cause TLE
#define MAX_AGE 100 + 10

int main() {
  int n;  // 0 < n < 20,000,000

  int i, j;

  while (scanf("%d", &n)) {
    if (n == 0) break;
    int ageData[MAX_AGE] = {0};
    int age;

    for (i = 0; i < n; i++) {
      scanf("%d ", &age);
      ageData[age]++;
    }

    // unstable counting sort
    int count = 0;
    for (i = 1; i < 100; i++) {
      for (j = 0; j < ageData[i]; j++) {
        if (count == n - 1 || ageData[i] == 0) break;
        printf("%d ", i);
        count++;
      }
      if (count == n - 1 && j < ageData[i]) break;
    }
    printf("%d\n", i);  // the last number with breakline
  }
  return 0;
}
