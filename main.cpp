#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <exception>

int main() {

    std::stack <int> Num;
    std::string exmp;
    std::getline (std::cin, exmp);
    std::cout << exmp << std::endl;
    int left, right;
    std::string a = "";
    for (const char &b : exmp){

        if (isdigit(b)){
            a += b;
        }
        else {
            if (a!= ""){
                Num.push(std::stod(a));
                a= "";

            if (Num.size() > 1){
                    right = Num.top();
                    Num.pop();
                    left = Num.top();
                    Num.pop();
                }
            }

            switch(b) {
                case '+': Num.push(left + right); break;
                case '-': Num.push(left - right); break;
                case '*': Num.push(left * right); break;
                case '/': 
                            try{
                                if(right==0) throw std::exception();
                                left / right;
                                Num.push(right);
                            }
                                catch (const std::exception &error){
                                    std::cout << error.what() << std::endl;
                                    std::cout << "div zero" << std::endl;
                                } continue;
                case ' ': break;
                }
        }
        
    }

    if (Num.size() > 1){
        std::cout << "error" << std::endl;
    }
    else{
        std::cout << "solution: " << Num.top() << std::endl;
    }
    return 0;
}
