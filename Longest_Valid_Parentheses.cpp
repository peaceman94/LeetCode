class Solution {
public:
    bool isValidParen(string s, int start, int end)
    {
        int count_open = 0;
        int count_close = 0;
        
        for(int i =start; i<=end; i++ )
        {
            if(count_open<count_close) return false;
            if(s[i] == '(') count_open++;
            if(s[i] == ')') count_close++;
        }
        return count_open==count_close;
    }
    
    int longestValidParenthesesBrute(string s) {
        bool output = isValidParen(s, 0, s.size());
        int max_len = 0;
        for(int i=0; i<s.size(); i++)
        {
            for(int j = i+1; j<s.size(); j++)
            {
                if(isValidParen(s, i,j) && max_len < j-i+1)
                {
                    max_len = j-i+1;
                };
            }
        }
        return max_len;
    }
    
    //usign dp from the solution
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        if(s.size() == 1) return 0;
        
        int max = 0;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(') continue;
            //hcek what is i-1
            if( i-1>=0 && s[i-1] == '(' )
            {
                dp[i] = 2;
                if(i-2 >= 0) dp[i] += dp[i-2];
            }
            else if(i-1>=0 && s[i-1] == ')')
            {
                if( (i-1-dp[i-1] >= 0 ) && (s[i-1-dp[i-1]] == '(' ) )
                {
                    dp[i] = dp[i-1] + 2;
                    if(i-1-dp[i-1]-1 >= 0) dp[i] += dp[i-1-dp[i-1]-1];
                }
            }
            if(max < dp[i]) max = dp[i];
        }
        return max;
    }    
};
