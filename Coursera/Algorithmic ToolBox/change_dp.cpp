#include <iostream>

int get_recursive_change(int m,int temp[]) {
if(temp[m]==-1)
{ int a[3]={0,0,0},t=0;
  if(m>=4)
   { a[0]=1;
      a[0]=a[0]+get_recursive_change(m-4,temp);
   }
   if(m>=3){
        a[1]=1;
     a[1]=a[1]+get_recursive_change(m-3,temp);
   }
   if(m>=1)
    {a[2]=1;
     a[2]=a[2]+get_recursive_change(m-1,temp);
    }
   if(m==0){
    return 0;
   }
   for(int i=0;i<3;i++)
   {
       if(a[i]!=0)
       { if(t==0)
          {t=a[i]; }
          if(a[i]<t)
          {t=a[i];
          }
       }
   }

  temp[m]=t;
   return t;
}
else
  {return temp[m];}
}

int get_iterative_change(int m)
{   int temp[m+1],coin[3]={4,3,1},c;
  for(int i=0;i<m+1;i++)
  { temp[i]=0; }

  for(int i=0;i<m+1;i++)
  { for(int j=0;j<3;j++)
   { if(i>=coin[j])
        { if(temp[i]==0)
            {temp[i]=temp[i-coin[j]]+1;}
          if(temp[i]>temp[i-coin[j]]+1)
          { temp[i]=temp[i-coin[j]]+1;

          }
        }

    }

   }
return temp[m];
}


int main() {
  int m;
  std::cin >> m;
  int temp[m+1];
  for(int i=0;i<m+1;i++)
  { temp[i]=-1; }
  std::cout << get_iterative_change(m) << '\n';
}
//// geeks for geeks solution for coin change problem.
//    with 2d array for memory
//
//int count( int S[], int m, int n )
//{
//    int i, j, x, y;
//
//    // We need n+1 rows as the table
//    // is constructed in bottom up
//    // manner using the base case 0
//    // value case (n = 0)
//    int table[n + 1][m];
//
//    // Fill the enteries for 0
//    // value case (n = 0)
//    for (i = 0; i < m; i++)
//        table[0][i] = 1;
//
//    // Fill rest of the table entries
//    // in bottom up manner
//    for (i = 1; i < n + 1; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            // Count of solutions including S[j]
//            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
//
//            // Count of solutions excluding S[j]
//            y = (j >= 1) ? table[i][j - 1] : 0;
//
//            // total count
//            table[i][j] = x + y;
//        }
//    }
//    return table[n][m - 1];
//}
//
//// Driver Code
//int main()
//{
//    int arr[] = {1, 2, 3};
//    int m = sizeof(arr)/sizeof(arr[0]);
//    int n = 4;
//    cout << count(arr, m, n);
//    return 0;
//}
