class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
		int l = 0, r = 0, n = s.size(), ans = 0;
		while(r<n)
		{
			if(set.find(s[r]) == set.end()) //If the character does not in the set
			{
				set.insert(s[r++]); //Insert the character in set and update the j counter
				ans = max(ans, int(set.size())); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[l++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
		return ans;
    }
};