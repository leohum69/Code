// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;

// int main(){

//     // int nums[] = {2,7,11,15};
//     // int n;

//     // vector<int> ret;

//     // for (int i = 0; i < 4; i++)
//     // {
//     //     for (int j = i+1; j < 4; j++)
//     //     {
//     //         if (nums[i] + nums[j] == 9)
//     //         {
//     //             ret.push_back(i);
//     //             ret.push_back(j);
//     //         }
            
//     //     }
//     // }

//     // for (int i = 0; i < ret.size(); i++)
//     // {
//     //     cout<<ret[i]<<" ";
//     // }
    

//     int x = 120;
    
//     int rev = 0;

//     while (x != 0)
//     {
//         int pop = x % 10;
//         x /= 10;
//         if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
//         if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
//         rev = rev * 10 + pop;
//     }
//     cout <<rev;

//     return 0;
// }

/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.*/
// Path: Testing/file1.cpp
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){

//     vector<int> nums = {1,0,-1,0,-2,2};
//     int target = 0;

//     vector<vector<int>> ret;

    // sort(nums.begin(), nums.end());

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i+1; j < nums.size(); j++)
    //     {
    //         int left = j+1;
    //         int right = nums.size()-1;

    //         while (left < right)
    //         {
    //             int sum = nums[i] + nums[j] + nums[left] + nums[right];
    //             if (sum == target)
    //             {
    //                 ret.push_back({nums[i], nums[j], nums[left], nums[right]});
    //                 while (left < right && nums[left] == nums[left+1])
    //                 {
    //                     left++;
    //                 }
    //                 while (left < right && nums[right] == nums[right-1])
    //                 {
    //                     right--;
    //                 }
    //                 left++;
    //                 right--;
    //             }
    //             else if (sum < target)
    //             {
    //                 left++;
    //             }
    //             else
    //             {
    //                 right--;
    //             }

    //         }

    //         while (j+1 < nums.size() && nums[j] == nums[j+1])
    //         {
    //             j++;
    //         }

    //     }

    //     while (i+1 < nums.size() && nums[i] == nums[i+1])
    //     {
    //         i++;
    //     }

    // }

