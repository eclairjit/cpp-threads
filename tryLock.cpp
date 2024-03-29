/*
try_lock tries to lock and if not possible, returns
unlike lock, which waits till it can lock
*/

#include<bits/stdc++.h>
using namespace std;

mutex m;

void sum(int &val) {
    
    for(int i=0; i<10000000; i++) {
        
        if(m.try_lock()) {
            
            val++;
            m.unlock();
            
        }
        
    }
    
}

int main() {
    
    int val = 0;
    
    thread t1(sum, ref(val));
    thread t2(sum, ref(val));
    
    t1.join();
    t2.join();
    
    cout << val;
    
    return 0;
}
