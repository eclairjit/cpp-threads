/* Printing sum of even and odd numbers in first 100 natural numbers parallely */

#include <bits/stdc++.h>
#include <chrono> //library containing functions related to time
using namespace std;

void findOddSum(int start, int end, int &oddSum) {
  
  for(int i=start; i<=end; i++) {
    
    if(i%2==1) oddSum+=i;
    
  }
  
}

void findEvenSum(int start, int end, int &evenSum) {
  
  for(int i=start; i<=end; i++) {
    
    if(i%2==0) evenSum+=i;
    
  }
  
}

int32_t main() {
  
  int oddSum = 0, evenSum = 0;
  int start = 1, end = 100;
  
  auto startTime = chrono::high_resolution_clock::now();
  
  /*
  creating separate threads for the two functions to run parallely
  each thread taken reference of the function to run nad the parameters
  in case parameter is to be passed by reference, use the ref function
  */
  
  thread t1(findOddSum, start, end, ref(oddSum));
  thread t2(findEvenSum, start, end, ref(evenSum));
  
  /*
  the threads, after their works are done, need to be joined with the main thread
  otherwise, they'll continue running parallely and we'll get no output
  */
  
  if(t1.joinable()) t1.join();
  if(t2.joinable()) t2.join();
  
  auto stopTime = chrono::high_resolution_clock::now();
  
  auto duration = (stopTime-startTime);
  
  cout << "Odd sum: " << oddSum << endl;
  cout << "Even sum: " << evenSum << endl;
  cout << "Time taken: " << (double)duration.count()/1000000 << " seconds";
  
  //the count function gives the integral value of the duration in microseconds
  
  return 0;
}
