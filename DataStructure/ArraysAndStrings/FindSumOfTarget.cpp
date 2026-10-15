/**
 * 
 * in give array find the elements which sum will become target
 * eg : array = {2,7,11,15}
 *         target = 9;
 *      output = 2,7
 */

#include <bits/stdc++.h>
// o(n^2)
// void findTargetSumElements(std::vector<int> &array, int const target) {
//     for(int i = 0 ; i < array.size(); i++) {
//         for(int j= 1; j< array.size(); j++) {
//             if(array[i] + array[j] == target) {
//                 std::cout << array[i] << array[j];
//                 array[i] = 0;
//             }
//         }
//     }
// }


//return indices of array which satisfyies the target
void findTargetSumElements(std::vector<int> &array, int const target) {

    std::unordered_map<int, int> mMap; int cnt=0;

    for(auto i = 0; i <array.size(); i++) {
        int need = target - array[i];

        auto it = mMap.find(need);

        if(it != mMap.end()) {
            std::cout << it->second << i;
        } else {
            mMap[array[i]] = i;
        }
    }

}




int main() {
    int target = 2;
    std::vector<int> array{1,0,1,0,1};
    findTargetSumElements(array, target);

    return 0;
}