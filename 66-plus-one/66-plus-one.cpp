class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int carry = 0;
        arr[arr.size()-1] = arr[arr.size()-1]+1;
        if(arr[arr.size()-1]>=10){
            carry = 1;
        }
        arr[arr.size()-1] = arr[arr.size()-1]%10;
        int i = arr.size()-2;
        while(i>=0 and carry!=0){
            arr[i] = arr[i]+carry;
            if(arr[i]>=10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            arr[i] = arr[i]%10;
            i--;
        }
        if(carry==1){
            arr.insert(arr.begin() , 1);
        }
        return arr;
    }
};