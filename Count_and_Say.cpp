class Solution {
public:
    string getString(char x)
    {
        // string class has a constructor
        // that allows us to specify size of
        // string as first parameter and character
        // to be filled in given size as second
        // parameter.
        string s(1, x);

        return s;  
    };
    
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = "1";
        
        string next;
        for(int i = 2; i<n+1; i++) 
        {
            next = "";
            for(int j=0; j<prev.size(); )
            {
                char curr = prev[j];
                int count = 1;
                j++;
                while(prev[j] == curr)
                {
                    j++;
                    count++;
                }
                
                next += to_string(count) + getString(curr);
            }
            prev = next;
        }
        return next;
    }
};
