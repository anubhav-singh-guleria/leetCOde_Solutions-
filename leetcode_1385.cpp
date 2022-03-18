// Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

// The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

 

// Example 1:

// Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
// Output: 2
// Explanation: 
// For arr1[0]=4 we have: 
// |4-10|=6 > d=2 
// |4-9|=5 > d=2 
// |4-1|=3 > d=2 
// |4-8|=4 > d=2 
// For arr1[1]=5 we have: 
// |5-10|=5 > d=2 
// |5-9|=4 > d=2 
// |5-1|=4 > d=2 
// |5-8|=3 > d=2
// For arr1[2]=8 we have:
// |8-10|=2 <= d=2
// |8-9|=1 <= d=2
// |8-1|=7 > d=2
// |8-8|=0 <= d=2

class Solution {
public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {    
    sort(begin(arr2), end(arr2));
    int ans = 0;
    for (int a : arr1) {// finding range between [a-d,a+b];
      auto it1 = lower_bound(begin(arr2), end(arr2), a - d);
      auto it2 = upper_bound(begin(arr2), end(arr2), a + d);
      if (it1 == it2) ++ans;//if it1==it2 that means no elements = in the range hance 1 added.
    }
      // lower bound first elemnt >= target
      // upper bound first elemrnt > target;
      // hence used upper both time for the case when there is only one value in the range 
      // in that case upper case will give the next value making it1-it2 == 1 thats why else if
      // used lower bound both times then it1==it2 even if 1 value exists
      // amazing sollution
    return ans;
  }
};
