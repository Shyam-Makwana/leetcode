class Solution {
public:
    vector < int > asteroidCollision(vector < int > & asteroids) {
  vector<int>ans;
    for(auto i:asteroids){
        abc:
        if(!ans.empty() && (ans.back()>0) && (i<0) && (ans.back()*i<0)){
            int top=ans.back();
            if(top==(-1*i)){
                ans.pop_back();
            }
            else if(top<(-1*i)){
                ans.pop_back();
                goto abc;
            }
        }
        else    ans.push_back(i);
    }
    return ans;
    }
};