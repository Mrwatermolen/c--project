/*
8594 有重复元素的排列问题（优先做）
设集合R={r1,r2,...,rn}是要进行排列的n个元素，其中r1,r2,...,rn可能相同。
试着设计一个算法，列出R的所有不同排列。
即，给定n以及待排的n个可能重复的元素。计算输出n个元素的所有不同排列。
输入格式
第1行是元素个数n，1<=n<=15。接下来的1行是待排列的n个元素，元素中间不要加空格。
输出格式
程序运行结束时，将计算输出n个元素的所有不同排列。最后1行中的数是排列总数。
（说明：
此题，所有计算出的排列原本是无所谓顺序的。但为了容易评判，输出结果必须唯一！现做约定：所有排列的输出顺序如课本例2-4的程序段的输出顺序，区别仅是这道题是含重复元素。）
输入样例
4
aacc
输出样例
aacc
acac
acca
caac
caca
ccaa
6
提示
课本上有“递归”实现无重复元素全排列的源程序。
稍加修改即可满足此题要求。
在递归产生全排列的那段程序开始之前，
加一个判断：判断第i个元素是否在list[k,i-1]中出现过。
PermExcludeSame(char list[], int k, int m)
{
  ......
  for (int i=k; i<=m; i++)
  {
    if (Findsame(list,k,i))//判断第i个元素是否在list[k,i－1]中出现过
       continue;
    Swap (list[k], list[i]);
    PermExcludeSame(list, k+1, m);
    Swap (list[k], list[i]);
  }
}
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
  void PermExcludeSame(char list[], int k, int m);
  int n;
  scanf("%d", &n);
  char *s = (char *)malloc(sizeof(char) * n);
  scanf("%s", s);
  PermExcludeSame(s, 0, n - 1);
  free(s);
}

void PermExcludeSame(char list[], int k, int m)
{
  int Findsame(char list[], int k, int i);
  void Swap(char *a, char *b);
  if (k == m)
  {
    for (int i = 0; i <= m; ++i)
    {
      printf("%c", list[i]);
    }
    printf("\n");
  }
  else
  {
    for (int i = k; i <= m; ++i)
    {
      if (Findsame(list, k, i))
        continue;
      Swap((list + k), (list + i));
      PermExcludeSame(list, k + 1, m);
      Swap((list + k), (list + i));
    }
  }
}

int Findsame(char list[], int k, int i)
{
  for (int j = k; j < i; ++j)
  {
    if (list[j] == list[i])
      return 1;
  }
  return 0;
}

void Swap(char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}