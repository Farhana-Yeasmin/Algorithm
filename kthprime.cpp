// #include <bits/stdc++.h>

// #define mx 10000000

// using namespace std;

// vector<bool> isprime(mx + 1);
// vector<int> p;

// void Sieve()
// {

//     // for (int i = 1; i <= mx; i++)
//     // {
//     //     isprime[i] = false;
//     // }

//     for (int i = 3; i <= mx; i += 2)
//         isprime[i] = true;

//     isprime[2] = true;

//     for (int i = 2; i * i <= mx; i++)
//     {
//         if (isprime[i])
//         {
//             for (int j = i * i; j <= mx; j += i)
//                 isprime[j] = false;
//         }
//     }

//     for (int i = 2; i <= mx; i++)
//         if (isprime[i])
//             p.push_back(i);
// }

// int main()
// {
//     int test;
//     cin >> test;
//     Sieve();
//     while (test--)
//     {
//         int kth;
//         cin >> kth;
//         cout << p[kth - 1] << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>

//const int N = 1e8;
#define N 100000000
using namespace std;

vector<bool> isprime(N + 1);
vector<int> p;
void Sieve()
{
    for (int i = 0; i <= N; i++)
        isprime[i] = false;

    for (int i = 3; i <= N; i += 2)
        isprime[i] = true;

    isprime[2] = true;

    for (int i = 2; i * i <= N; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= N; j += i)
                isprime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
        if (isprime[i])
            p.push_back(i);
}

int main()
{
    int test;
    cin >> test;
    Sieve();
    while (test--)
    {
        int kth;
        cin >> kth;
        cout << p[kth - 1] << endl;
    }
    return 0;
}