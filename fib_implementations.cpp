#include <iostream>
#include <ctime>

using namespace std;


int fib_recursive (int n) {
  if (n==0 || n==1) return n;
  else {
    return fib_recursive(n-1) + fib_recursive(n-2);
  }
}

int fib_iterative (int n) {
  if (n==0||n==1) return n;
  int prev = 0, last = 1, temp;
  for (int i=2; i <= n; ++i){
    temp = last;
    last = prev + last;
    prev = temp;
  }
  return last;
}

int fib_tailrecursive (int n, int last = 1, int prev = 0) {
  if (n == 0) return prev;
  if (n == 1) return last;
    return fib_tailrecursive(n-1, last+prev, last);
}


int main() {
  long long F;

  cout << "RECURSIVE" << endl;
  clock_t begin = clock();
   F = fib_recursive(45);
  clock_t end = clock();
  double elapsed_secs = double(end - begin);
  cout << F << " - Time elapsed: " << elapsed_secs << endl << endl;

  cout << "ITERATIVE" << endl;
  begin = clock();
   F = fib_iterative(45);
  end = clock();
  elapsed_secs = double(end - begin);
  cout << F << " - Time elapsed: " << elapsed_secs << endl << endl;

  cout << "TAIL RECURSIVE" << endl;
  begin = clock();
   F = fib_tailrecursive(45);
  end = clock();
  elapsed_secs = double(end - begin);
  cout << F << " - Time elapsed: " << elapsed_secs << endl << endl;



return 0;
}
