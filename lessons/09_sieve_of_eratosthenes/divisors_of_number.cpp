#include <iostream>
#include <vector>
#include <set>
using namespace std;

void pretty_print(string S, vector<int>& elems) {
  cout << S << "\t";
  for (int i = 0; i < elems.size(); i++) {
    cout << elems[i] << "\t";
  }
  cout << endl;
}

vector<int> least_factors(int& N) {
  vector<int> sieve(N+1,0);
  int i = 2;
  while (i * i <= N) {
    if (sieve[i] == 0) {
      int k = i * i;
      while (k <= N) {
        if (sieve[k] == 0) sieve[k] = i;
        k += i;
      }
    }
    i++;
  }

  return sieve;
}

vector<int> find_primes(int N) {
  vector<int> prime_factors;
  vector<int> sieve = least_factors(N);

  while (sieve[N] > 0) {
    prime_factors.push_back(sieve[N]);
    N /= sieve[N];
  }
  prime_factors.push_back(N);

  return prime_factors;
}

set<int> factors2divisors(int& N, vector<int>& prime_factors) {
  set<int> divs;
  int tmp, factors_num = prime_factors.size();
 
  for (int fn = factors_num; fn > 0; fn--) {
    for (int pos = 0; pos <= factors_num - fn; pos++) {
      tmp = 1;
      for (int mtp = pos; mtp < pos+ fn; mtp++) {
        tmp *= prime_factors[mtp];
      }
      divs.insert(tmp);
      divs.insert(N/tmp);
    }
  }

  return divs;
}

int main() {
  cout << "Enter a positive integer: ";
  int N;
  cin >> N;

  cout << "You have entered " << N << endl;

  //find all prime factors
  vector<int> prime_factors = find_primes(N);
  pretty_print("PF",prime_factors);

  //compute all divisors
  // look for better container
  set<int> divisors = factors2divisors(N,prime_factors);
  
  cout << "DD:\t";
  for( set<int>::iterator it = divisors.begin();it!=divisors.end();it++ ) cout << *it << "  ";
  cout << endl;

  return 0;
}


//  // the iterator constructor can also be used to construct from arrays:
//  int myints[] = {16,2,77,29};
//  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
