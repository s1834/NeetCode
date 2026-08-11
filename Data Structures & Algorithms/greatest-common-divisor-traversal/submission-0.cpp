class DSU {
public:
    vector<int> parent;
    vector<int> sizes;
    int numOfComponents;

    DSU(int n) {
        parent.resize(n);
        sizes.resize(n);
        numOfComponents = n;

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if(xParent == yParent) return;

        if(sizes[xParent] >= sizes[yParent]) {
            parent[yParent] = xParent;
            sizes[xParent] += sizes[yParent];
        } else {
            parent[xParent] = yParent;
            sizes[yParent] += sizes[xParent];
        }

        numOfComponents--;
    }

    int countComponents() {
        return numOfComponents;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
       int n = nums.size();

       DSU dsu(n);

       unordered_map<int, int> mp; // <factor, index> store only the first index where that factor is seen to make it parent

       for(int i = 0; i < n; i++) { // for each number find all its factors
            for(int factor = 2; factor * factor <= nums[i]; factor++) {
                if(nums[i] % factor != 0) continue; // if not a factor

                if(mp.find(factor) != mp.end()) { // if factor already exists, union current with parent index
                    int idx = mp[factor];
                    dsu.Union(idx, i);
                } else mp[factor] = i; // if factor doesnt already exists create it

                while(nums[i] % factor == 0) nums[i] /= factor; // divide current number by factor until it is no longer divisible
            }

            // if nums[i] is still greater than 1 / it is not prime factorized
            if(nums[i] > 1) {
                if(mp.find(nums[i]) != mp.end()) {
                    int idx = mp[nums[i]];
                    dsu.Union(idx, i);
                } else mp[nums[i]] = i;
            }
        }

        return dsu.countComponents() == 1; // if it is a single component we can traverse
    }
};