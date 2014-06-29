// Given a set of distinct integers, S, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        if(!S.size()) return res;
        sort(S.begin(), S.end());
        vector<int> oneSet;
        helper(S, 0, oneSet, res);
        return res;
    }
    
    void helper(vector<int> &S, int startIdx, vector<int> &oneSet, vector<vector<int> > &res) {
        if(startIdx == S.size()) {
            res.push_back(oneSet);
            return;
        }
        
        helper(S, startIdx+1, oneSet, res);
        
        oneSet.push_back(S[startIdx]);
        helper(S, startIdx+1, oneSet, res);
        oneSet.pop_back();
    }
    
};
