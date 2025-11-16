// Finding Divisors
#include <bits/stdc++.h>
using namespace std;

vector<int> findAllPrimeDivisor(int N)
{
    vector<int> divs;
    
    for(int i = 2; i * i <= N; i++)
    {
        if(N%i == 0)
        {
            divs.push_back(i);
            while(N%i == 0) N /= i;
        }
    }

    if(N > 1) {
        divs.push_back(N);
    }

    return divs;
}
vector<int> findAllDivisors(int N)
{
    vector<int> divs;
    for(int i = 1; i*i <= N; i++)
    {
        if(N%i == 0)
        {
            divs.push_back(i);
            int j = N/i;
            if(i != j) divs.push_back(j);
        }
    }
    sort(divs.begin(),divs.end());
    return divs;
}
int main()
{
    int n;
    cin >> n;
    vector<int> divs;
    divs = findAllDivisors(n);
    for(auto i : divs)
    {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}