//freopen("input.txt", "r", stdin);
//2060kb 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

int N, L;
int arr[101][101];
int ans = 0;

//정말 간결하고 잘짠 듯함
//https://rebas.kr/788

bool checkver(int hor)
{
   int visited[101] = {
       0,
   };
   int tmp[101];

   for (int i = 0; i < N; i++)
   {
      tmp[i] = arr[hor][i];
   }
   int before = tmp[0];

   for (int i = 1; i < N; i++)
   {
      int cur = tmp[i];
      int index = i;
      int count = L;
      if (before < cur)
      {
         if (cur - before != 1)
            return false;

         index--;
         while (count--)
         {
            if (visited[index])
               return false;

            if (index < 0)
               return false;

            if (tmp[index] != before)
               return false;

            index--;
         }
         index++;

         for (int j = index; j < index + L; j++)
         {
            visited[j] = 1;
         }
      }
      before = cur;
   }
   reverse(tmp, tmp + N);
   reverse(visited, visited + N);

   before = tmp[0];

   for (int i = 1; i < N; i++)
   {
      int cur = tmp[i];
      int index = i;
      int count = L;
      if (before < cur)
      {
         if (cur - before != 1)
            return false;

         index--;
         while (count--)
         {
            if (visited[index])
               return false;

            if (index < 0)
               return false;

            if (tmp[index] != before)
               return false;

            index--;
         }
         index++;

         for (int j = index; j < index + L; j++)
         {
            visited[j] = 1;
         }
      }
      before = cur;
   }
   return true;
}

bool checkhor(int ver)
{
   int visited[101] = {
       0,
   };
   int tmp[101];

   for (int i = 0; i < N; i++)
   {
      tmp[i] = arr[i][ver];
   }
   int before = tmp[0];

   for (int i = 1; i < N; i++)
   {
      int cur = tmp[i];
      int index = i;
      int count = L;
      if (before < cur)
      {
         if (cur - before != 1)
            return false;

         index--;
         while (count--)
         {
            if (visited[index])
               return false;

            if (index < 0)
               return false;

            if (tmp[index] != before)
               return false;

            index--;
         }
         index++;

         for (int j = index; j < index + L; j++)
         {
            visited[j] = 1;
         }
      }
      before = cur;
   }
   reverse(tmp, tmp + N);
   reverse(visited, visited + N);

   before = tmp[0];

   for (int i = 1; i < N; i++)
   {
      int cur = tmp[i];
      int index = i;
      int count = L;
      if (before < cur)
      {
         if (cur - before != 1)
            return false;

         index--;
         while (count--)
         {
            if (visited[index])
               return false;

            if (index < 0)
               return false;

            if (tmp[index] != before)
               return false;

            index--;
         }
         index++;

         for (int j = index; j < index + L; j++)
         {
            visited[j] = 1;
         }
      }
      before = cur;
   }
   return true;
}

int main()
{
   freopen("input.txt", "r", stdin);

   scanf("%d %d", &N, &L);

   rep(i, N)
   {
      rep(j, N)
      {
         scanf("%d", &arr[i][j]);
      }
   }

   rep(i, N)
   {
      if (checkver(i))
         ans++;
      if (checkhor(i))
         ans++;
   }

   printf("%d", ans);

   return 0;
}
