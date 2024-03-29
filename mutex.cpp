#include<bits/stdc++.h>
using namespace std;

mutex m; //mutex: mutual exclusion

/*
the common variable needs to be locked when in use by one thread
once that thread has finished using that variable it can be unlocked
and can be used by any other thread waiting for the variable
*/

void increment(int &x) {
    
    m.lock();
    x++;
    m.unlock();
    
}

int main() {
    
    int x = 0;
    
    thread t1(increment, ref(x));
    thread t2(increment, ref(x));
    
    t1.join();
    t2.join();
    
    cout << x;
    
    return 0;
}
