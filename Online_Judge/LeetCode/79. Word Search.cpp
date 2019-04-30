/*
Author: Tony Hsiao
Date: 2019/04/30
Topic: 79. Word Search
Note: 一個2維文字表，確認字串是否可用連連看(垂直或水平)連起來
這題容易TLE，如果沒有call by reference 就會TLE
*/
class Solution {
private:
    bool is_find = false;
public:
    bool SearchWord(vector<vector<char>>& board, int x, int y, string word, int index){
        if(is_find)
            return true;
        if(word.size() == index){
            is_find = true;
            return true;
        }
        if(x==-1 || y==-1 || x == board[0].size() || y == board.size() || board[y][x] != word[index])
            return false;

        char tmp = board[y][x];
        board[y][x] = '0';
        bool find= (SearchWord(board, x+1, y, word, index+1) ||
            SearchWord(board, x-1, y, word, index+1) ||
            SearchWord(board, x, y+1, word, index+1) ||
            SearchWord(board, x, y-1, word, index+1) );
        board[y][x] = tmp;
        return find;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty()) return false;

        bool find;
        for(int y = 0; y < board.size() ; y++){
            for(int x = 0; x < board[0].size() ; x++){
                if(SearchWord(board, x, y, word, 0))
                    return true;
            }
        }
        return false;
    }
};