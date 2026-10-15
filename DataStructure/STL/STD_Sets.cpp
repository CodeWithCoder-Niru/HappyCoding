//syntax : std::set<T> objName;

//1. set is an associative container that contains a sorted set of unique obj of type key]
//2. It is usuallly impl using Red black tree
//3. Insertion, Removal search have logirathmic complexity
//4. If we want to store user defined data type in set then
//   we will have to provide compare function so that set can store them in order

#include<bits/stdc++.h>
#include<set>

class person {
    public:
        int age;
        std::string name;
    bool operator < (const person &rhs) const { return name > rhs.name;}
};

int main() {
    std::set<person> my_Set = {{20, "Niranjan"}, {25, "Shetty"}, {30, "Elluru"}};
    for(const auto &i:my_Set) {
        std::cout<< i.age <<i.name <<std::endl;
    }
    auto it = my_Set.begin();
    auto itr = next(my_Set.begin(), 4);
    std::cout<<it->name << std::endl;
    std::cout<<itr->age << std::endl;

    int i = 2;
    auto itr1 = next(my_Set.begin(), i);
    std::cout << itr1->name <<std::endl;
    auto itr2 = my_Set.find({20, "Niranjan"});
    if(itr2 != my_Set.end()) {
        std::cout<< itr2->age;
    }

    return 0;

}