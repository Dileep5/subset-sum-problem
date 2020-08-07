#include <bits/stdc++.h>
using namespace std;
bool dp[100][100];
void display(const vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}
void printSubsetsRec(int arr[], int i, int sum, vector<int> &p)
{

  if (i == 0 && sum != 0 && dp[0][sum])
   {
       p.push_back(arr[i]);
       display(p);
       return;
   }
    
     if (i == 0 && sum == 0) 
    {
        display(p);
        return;
    }
    if(i <= 0 || sum < 0) return;
    
    
    if (dp[i-1][sum])
    {
        
        vector<int> b = p;
        printSubsetsRec(arr, i - 1, sum, p);
    }
    
    if (sum >= arr[i - 1] && dp[i - 1][sum - arr[i - 1]])
    {
        p.push_back(arr[i - 1]);
        printSubsetsRec(arr, i - 1, sum - arr[i - 1], p);
        p.pop_back();
    }
}

void printAllSubsets(int arr[], int n, int sum)
{
    if (n == 0 || sum < 0)
        return; 
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    
    for (int i = 1; i <= sum; i++) dp[0][i] = false;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            printf("%4d", dp[i][j]);
        }
        if (dp[n][sum] == false)
        {
            printf("There are no subsets with sum %d\n", sum);
            return;
        }
        
        
        vector<int> p;
        printSubsetsRec(arr, n, sum, p);
    }
}
int main()
{
    int n,sum;
    printf("Enter the number of terms in the set:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element:");
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of sum:");
    scanf("%d", &sum);
    printAllSubsets(arr, n, sum);
    return 0;
}
