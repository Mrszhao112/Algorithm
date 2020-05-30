//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

//有效字符串需满足：

//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

//利用栈后进先出的特性匹配对应的字符串 
class Solution {
public:
    bool isValid(string s) {
     stack<char> s1;//辅助栈
     for (int i = 0; i < s.size(); i++){
         if (s1.empty()) {
             s1.push(s[i]);
         }else {
             if (s1.top() == '(' && s[i] == ')') {
                 s1.pop();
             }else if (s1.top() == '{' && s[i] == '}') {
                 s1.pop();
             }else if (s1.top() == '[' && s[i] == ']') {
                 s1.pop();
             }else {
                 s1.push(s[i]);
             }
         }
     }
     //栈空则全部匹配
     if (s1.empty()) {
         return true;
     }
     return false;
    }
};

//改进了匹配方法 从而提高了效率 
bool isValid(string s) {
    stack<char> stk;
    for(const auto& c : s){
        switch(c){
            case '{':  stk.push('}'); break;
            case '[':  stk.push(']'); break;
            case '(':  stk.push(')'); break;
            default:
                if(stk.size() == 0 || c != stk.top()) return false;
                else stk.pop();
        }
    }
    return stk.size() == 0;
}
