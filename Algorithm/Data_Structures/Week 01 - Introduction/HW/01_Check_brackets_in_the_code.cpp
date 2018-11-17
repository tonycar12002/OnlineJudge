#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main(int argc, char* argv[]) {
    std::string text;
    getline(std::cin, text);
    int not_match = 0;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket new_br(next, position);
            opening_brackets_stack.push(new_br);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.size() == 0){
                Bracket new_br(next, position);
                opening_brackets_stack.push(new_br);                
                break;
            }
            Bracket now = opening_brackets_stack.top();
            bool match = now.Matchc(next);
            if(match)
                opening_brackets_stack.pop();
            else{
                Bracket new_br(next, position);
                opening_brackets_stack.push(new_br);                
                break;
            }
        }
    }

    if(opening_brackets_stack.size() == 0)
        cout << "Success" <<endl;
    else{
        Bracket now = opening_brackets_stack.top();
        cout << now.position+1 <<endl;
    }

    return 0;
}