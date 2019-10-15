#include <stdio.h>
#include <string.h>

void SieveOfEratosthenes(int n)
{
  int prime[n+1];
  for (int i = 0; i < n+1; ++i)
  {
    prime[i] = 1;
  }

  for (int p=2; p*p<=n; p++)
  {
    if (prime[p] == 1)
    {
      for (int i=p*2; i<=n; i += p)
        prime[i] = 0;
    }
  }

  for (int p=2; p<=n; p++)
  {
    if (prime[p])
      printf("%d\n", p);
  }
}

int main()
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("prime numbers smaller than or equal to %d \n", n);
  SieveOfEratosthenes(n);
  return 0;
}
