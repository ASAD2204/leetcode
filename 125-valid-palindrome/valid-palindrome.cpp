class Solution {
bool isAlphanumeric(char ch){
    if((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
        return true;
    }
return false;
}
public:
    bool isPalindrome(string s) {
   int start=0;
   int end=s.size()-1;

   while(start<=end){
    if(!isAlphanumeric(s[start])){
        start++;
        continue;
    }
    if(!isAlphanumeric(s[end])){
        end--;
        continue;
    }
    if(tolower(s[start])!=tolower(s[end])){
        return false;
        break;
    }
    start++;
    end--;
   }
   return true;
   
    }

};