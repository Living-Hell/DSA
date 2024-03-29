class Solution
{
public:
    // Function to find the largest prime factor of n using Algo Sieve of Eratosthenes.
    //ToC = O(sqrt(n))
    long long int largestPrimeFactor(int n)
    {
        for (long long int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                while (n > i and n % i == 0)
                    n /= i;
            }
        }
        return n;
    }
};