/**	This program checks if a string is a palindrome
 * 	by using the STL container classes for stack and
 * 	queue, adding the string char by char to each,
 * 	and removing from both until they are empty.
 *
 * 	As a queue is First In First Out and a stack
 *  is Last In First Out it effectively compares
 *  the forward string with the reverse.
 * 
 *  This program is mainly for practice with STL container
 * 	classes.
 * */

#include <iostream>
#include <stack>
#include <queue>

/** This method removes non alphabetic characters
 *  and spaces from a string, and makes it uppercase.
 * */
std::string cleanString(const std::string &str) {
    
    std::string newStr {};
    
    //We do not want to mutate the original
    //string, hence the const.
    //Would not be necessary in Java.
    for(const char &c : str) {
            
        if(std::isalpha(c) && c != ' ') {
            
            newStr += std::toupper(c);
        }
    }    
       
    return newStr;
}

/** This method checks a string and returns
 *  a boolean value of whether it's a palindrome
 *  (reversible string) or not.
 * */
bool stackQPalindromeTest(const std::string &test) {
    
    std::string temp {cleanString(test)};
    
    std::cout << "cleaned string: " << temp << std::endl;
    
    //We use the inbuilt stack & queue classes
    std::stack<char> palStack {};
    std::queue<char> palQ {};
    
    for(char c : temp) {
        palStack.push(c);
        palQ.push(c);
    }
    
    bool palindrome {true};
    
    while(!palStack.empty()) {
        
        char stackTop {palStack.top()};
        char qFront {palQ.front()};
        
        std::cout << "stack top: " << stackTop;
        std::cout << " queue front: " << qFront;
        std::cout << std::endl;
        
        if(stackTop != qFront) {
            palindrome = false;
            break;	//could also check the palindrome
										//value in the while loop condition
										//instead of using break
        } else {
            palStack.pop();
            palQ.pop();
        }
        
    }
    
    return palindrome;
    
}



int main() {
    
    std::string test {"This is a test, ok?!!"};
    
    std::string cleaned = cleanString(test);
    
    std::cout << cleaned << std::endl;
    
    std::cout   << std::boolalpha
                << stackQPalindromeTest(test)
                << std::endl;
    
    std::vector<std::string> testStrings {"a", "aa", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma","A Toyota's a toyota", "A Santa at NASA", "C++",
     "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal - Panama!", "This is a palindrome", "palindrome"};
    
    for(auto str : testStrings) {
        std::cout << str << ": " 
                    << stackQPalindromeTest(str) << "\n" << std::endl; 
    }
    
	return 0;
}
