// Seive-of-erathonesis
/*find all the prime number from 3*/
#include <bits/stdc++.h>
using namespace std;
vector<int> closestPrimes(int left, int right)
{
    vector<int> p;
    vector<int> seive(1000001);
    p.push_back(2); // 2 is prime number
    if (p.size() == 1)
    {
        // every number after 2 digit is prime number
        for (int i = 3; i < 1000001; i += 2)
        {
            if (!seive[i])
            {
                p.push_back(i);
                for (int j = i * i; j < 1000001; j += i)
                {
                    // if the squareroot of the number is prime number then square of the number is also a primenumber
                    seive[i] = true;
                }
            }
        }
    }
            int n1 = -1, n2 = -1;

            for (int i = lower_bound(p.begin(), p.end(), left) - p.begin(); i + 1 < p.size() && p[i + 1] <= right; i++)
            {
                if (n1 == -1 || p[i + 1] - p[i] < n2 - n1)
                {
                    n1 = p[i];
                    n2 = p[i + 1];
//There are many primes with the gap of 2 
//exit early if we find a gap < 3,
                    if (n2 - n1 < 3)
                    {
                        break;
                    }
                }
            }

            return {n1, n2};
}