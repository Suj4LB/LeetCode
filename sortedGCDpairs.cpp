//Q. - You are given an integer array nums of length n and an integer array queries.

// Let gcdPairs denote an array obtained by calculating the GCD of all possible pairs (nums[i], nums[j]), where 0 <= i < j < n, and then sorting these values in ascending order.
// For each query queries[i], you need to find the element at index queries[i] in gcdPairs.
// Return an integer array answer, where answer[i] is the value at gcdPairs[queries[i]] for each query.
// The term gcd(a, b) denotes the greatest common divisor of a and b.

//Solution - 

class Solution{
public:
    vector<int> gcdValues(vector<int>& v, vector<long long>& q){
        int n = v.size();
        int maxx = *max_element(v.begin(), v.end());
        vector<int> cntDivisors(maxx + 1, 0);
        for(auto x : v){
            for(int i = 1; i * i <= x; i++){
                if(x % i == 0){
                    cntDivisors[i]++;
                    if(i != x / i){
                        cntDivisors[x / i]++;
                    }
                }
            }
        }
        vector<long long int> gcdCount(maxx + 1, 0);
        for(int g = maxx; g >= 1; g--){
            long long int count = cntDivisors[g];
            gcdCount[g] = 1ll * count *(count - 1) / 2;
            for(int mult = 2 * g; mult <= maxx; mult += g){
                gcdCount[g] -= gcdCount[mult];
            }
        }
        vector<long long int> pref(maxx + 1, 0);
        for(int g = 1; g <= maxx; g++){
            pref[g] = pref[g - 1] + gcdCount[g];
        }
        vector<int> ans;
        for(auto q : q){
            long long int left = 1, right = maxx, answer = -1;
            while(left <= right){
                long long int mid =(left + right) / 2;
                if(pref[mid] > q){
                    answer = mid;
                    right = mid - 1;
                } else{
                    left = mid + 1;
                }
            }
            ans.push_back(answer);
        }

        return ans;
    }
};
