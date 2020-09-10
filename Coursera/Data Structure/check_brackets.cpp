#include <iostream>
#include <stack>
#include <string>

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

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket a(next,position);
           opening_brackets_stack.push(a);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.size()==0)
            {
                std::cout<<position+1;
                return 0;
            }
            if(opening_brackets_stack.top().Matchc(next)==1)
            {  opening_brackets_stack.pop();
            }
            else{
                std::cout<<position+1;
                return 0;
            }
        }
    }
    if(opening_brackets_stack.empty())
    {  std::cout<<"Success";  }
    else{
        std::cout<<opening_brackets_stack.top().position+1;
    }

    return 0;
}
