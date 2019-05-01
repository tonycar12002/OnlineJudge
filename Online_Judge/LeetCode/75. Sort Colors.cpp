/*
Author: Tony Hsiao
Date: 2019/05/01
Topic: 75. Sort Colors
Note: Try to solove the problem in constant space  
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int cursor_one = 0, cursor_zero = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){ //swap twice
                swap(nums[i], nums[cursor_zero]);
                if(cursor_one !=0)
                    swap(nums[i], nums[cursor_one + cursor_zero]);
                cursor_zero++;
            }
            else if(nums[i] == 1){ //swap once
                swap(nums[i], nums[cursor_one + cursor_zero]);
                cursor_one ++;
            }
        }
    }
};