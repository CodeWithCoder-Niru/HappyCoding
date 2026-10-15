#include <bits/stdc++.h>
constexpr int BUFFER = 5;

std::binary_semaphore signal_to_producer{1}, signal_to_consumer{0};

std::vector<int> buffer;

void producer(){
    
    while(1){
        signal_to_producer.acquire();
        
        for(int i=1; i<=BUFFER; i++){
            std::cout<< "Push to Buffer: "<< i <<" " <<std::flush;
            buffer.push_back(i);
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        signal_to_consumer.release();
    }
    
}

void consumer(){
    
    while(1){
        signal_to_consumer.acquire();
        
        for(int i=BUFFER; i > 0; i--){
            std::cout<< "Pop from Buffer: "<< i <<" "<<std::flush;
            buffer.pop_back();
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        signal_to_producer.release();
    }
}

int main()
{
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);
    
    producer_thread.join();
    consumer_thread.join();
    
    return 0;
    
}