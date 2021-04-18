class Solution {
public:
    void printVect(vector<int> inter)
    {
        cout << inter[0] << " " << inter[1] << endl;
        return;
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[0]<b[0];});
        vector<vector<int>> output;
        
        //[] [] or [ { ] } or [ [] ]
        vector<int> prev = intervals[0];
        vector<int> curr;
        
        for(int i = 1; i<intervals.size(); i++)
        {
            curr = intervals[i]; 
            if(curr[0]>prev[1])
            {
                output.push_back(prev);   
                prev = curr;
            }
            else
            {
                if(curr[1] >= prev[1])
                {
                    prev = {prev[0], curr[1]};
                }
            };
        };
        output.push_back(prev);
        return output;
    }
};
