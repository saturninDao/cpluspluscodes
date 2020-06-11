#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char **argv)
{
  bool supprimes[100];
 
  supprimes[0] = true;   // 0 n'est pas premier
  supprimes[1] = true;   // 1 n'est pas premier
  for (int i=2; i<100; i++)
    supprimes[i] = false;
 
  for (int i=2; i<100; i++)
    if (!supprimes[i]) {
        int multiple = 2 * i;
        while (multiple < 100) {
          supprimes[multiple] = true;
          multiple += i;
        }
    }
 
  for (int i=0; i<100; i++)
    if (!supprimes[i])
      cout << i << " ";
 
  cout << endl;
 
  return 0;
}