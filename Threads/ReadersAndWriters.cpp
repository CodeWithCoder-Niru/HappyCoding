#include<bits/stdc++.h>


// int sharedData = 0;
// int readerCount = 0;

// bool isWriterActive = false;

// std::mutex mx;
// std::condition_variable cv;

// void reader(int id){
//     {
//         std::unique_lock<std::mutex> lock{mx};
//         cv.wait(lock, [](){
//             return !isWriterActive;
//         });

//            readerCount++;
//     }
//     std::cout<< "Reader id: "<< id << "Reading the Data :" << sharedData <<std::endl;

//     {
//         std::unique_lock<std::mutex> lock{mx};
//         readerCount--;
//         if(readerCount == 0){
//             cv.notify_all();
//         }
//     }
// }

// void writer(int id){
//     {
//         std::unique_lock<std::mutex> lock{mx};
//         cv.wait(lock, [](){
//             return ((readerCount == 0) && (!isWriterActive));
//         });
//         isWriterActive = true;
//     }

//     ++sharedData;
//     std::cout<< "Writer id: "<< id << "Updated the Data :" << sharedData<<std::endl;

//     {
//         std::unique_lock<std::mutex> lock{mx};
//         isWriterActive = false;
//     }
//     cv.notify_all();
// }


// int main(){
//     std::vector<std::thread> vec;

//     vec.emplace_back(reader, 1);
//     vec.emplace_back(reader, 2);
//     vec.emplace_back(writer, 1);
//     vec.emplace_back(reader, 3);
//     vec.emplace_back(writer, 2);

//     for(auto &itr:vec){
//         itr.join();
//     }
//     return 0;
// }

// You can do this in using the Shared::mutex

std::shared_mutex mx;
int sharedData = 0;

void reader(int id){
    std::shared_lock<std::shared_mutex> lock{mx};

    std::cout<< "Reader id: "<< id << " " << "Reading the Data :" << sharedData <<std::endl;
}

void writer(int id){
    std::unique_lock<std::shared_mutex> lock{mx};
    ++sharedData;
    std::cout<< "Writer id: "<< id << " " << "Updated the Data :" << sharedData<<std::endl;
}

int main(){
    std::vector<std::thread> vec;

    vec.emplace_back(reader, 1);
    vec.emplace_back(reader, 2);
    vec.emplace_back(writer, 1);
    vec.emplace_back(reader, 3);
    vec.emplace_back(writer, 2);

    for(auto &itr:vec){
        itr.join();
    }
    return 0;
}

