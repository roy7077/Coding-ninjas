Code : Search in Tries
______________________
Send Feedback
Implement the function SearchWord for the Trie class.
For a Trie, write the function for searching a word. Return true if the word is found successfully, otherwise return false.
Note : main function is given for your reference which we are using internally to test the code.



class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }

    bool search_helper(TrieNode *root, string word) {
        // Base case
        if(root==NULL)
            return false;
        
        if (word.size() == 0) 
        {
            if(root->isTerminal)
                return true;
            else
                return false;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
            return false;
        
        bool is_present=search_helper(root->children[index],word.substr(1));
        return is_present;
            
    }
    bool search(string word) {
        
        return search_helper(root,word);
    }
};




--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Pattern Matching
________________
Send Feedback
Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.



#include <string>
#include <vector>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
        
    }

    void insertWord(string word) 
  {
        for(int i=0;i<word.length();i++)
        {
            //return insertWord(child,)
            if (insertWord(root, word.substr(i))) 
         {
            this->count++;
         }
       }
  }
    /////////////////////
        
    
    bool search_pattern(TrieNode *root, string word) {
        // Base case
        if(root==NULL)
            return false;
        
        if (word.size() == 0) 
        {
            return true;
            //if(root->isTerminal)
              //  return true;
            //else
              //  return false;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
            return false;
        
        bool is_present=search_pattern(root->children[index],word.substr(1));
        return is_present;
            
    }
//     bool search(string word) {
        
//         return search_pattern(root,word);
//     }
    
    
    ///////////////////

    bool patternMatching(vector<string> vect, string pattern) 
    {
        for(int i=0;i<vect.size();i++)
          insertWord(vect[i]);
        
        return search_pattern(root,pattern);
        
    }
};






------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Palindrome Pair
________________
Send Feedback
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.




#include<string>
#include<vector>
#include<algorithm>
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childcount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childcount=0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;
    Trie() { 
        this->count=0;
        root = new TrieNode('\0'); 
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) 
        {
            if(!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else 
                return false;
            
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childcount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) { 
        if(add(root,word))
            this->count++;
    }

    bool search_helper(TrieNode *root, string word) {
        // Base case
        if(root==NULL)
            return false;
        
        if (word.size() == 0) 
        {
            if(root->isTerminal)
                return true;
            else
                return false;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
            return false;
        
        bool is_present=search_helper(root->children[index],word.substr(1));
        return is_present;
            
    }
    bool search(string word) {
        
        return search_helper(root,word);
    }
    
    
    /*------------palindrome----------*/
    string reverseword(string word)
    {
        string reverse="";
        for(int i=word.size()-1;i>=0;i--)
            reverse=reverse+word[i];
        
        return reverse;
    }
    
    bool isPalindromePair(vector<string> words)
    {
        if(words.size()==0)
            return false;
        
        for(int i=0;i<words.size();i++){
            this->add(reverseword(words[i]));
        }
        return isPalindromePair(this->root,words);
    }
    bool isPalindromePair(TrieNode* root,vector<string> words)
    {
        if(words.size()==0||root==NULL)
            return false;
        
        for(int i=0;i<words.size();i++)
        {
            if(doespairexistfor(root,words[i],0))
                return true;
        }
        return false;
    }
    bool doespairexistfor(TrieNode*root,string word,int startIndex)
    {
        if(word.length()==0)
            return true;
        if(startIndex==word.length())
        {
            if(root->isTerminal)
                return true;
            
            return checkRemainingBranchesInTrie(root,"");
        }
        int charIndex=word[startIndex]-'a';
        TrieNode* child=root->children[charIndex];
        if(child==NULL)
        {
            if(root->isTerminal)
                return checkwordforpalindrome(word.substr(startIndex));
            
            return false;
        }
        return doespairexistfor(child,word,startIndex+1); 
    }
    
    bool checkRemainingBranchesInTrie(TrieNode* root,string word)
    {
        if(root->isTerminal)
        {
            if(checkwordforpalindrome(word))
                return true;
        }
        for(int i=0;i<26;i++)
        {
            TrieNode* child=root->children[i];
            if(child==NULL)
                continue;
            
            string fwd=word+child->data;
            if(checkRemainingBranchesInTrie(child,fwd))
                return true;
        }
        return false;
    }
    
    bool checkwordforpalindrome(string word)
    {
        int startIndex=0;
        int endIndex=word.length()-1;
        while(startIndex<endIndex)
        {
            if(word[startIndex]!=word[endIndex])
                return false;
            
            startIndex+=1;
            endIndex-=1;
        }
        return true;
    }
    
};















-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




Auto complete
______________
Send Feedback
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.





#include<string>
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    
    /*-----------------auto complete---------------*/
    void helper(TrieNode *root,string word)
    {
        if(root==NULL)
            return ;
        
        if(root->isTerminal)
        {
            cout<<word<<endl;
        }
        //output=root->data+output;
        for(int i=0;i<26;i++)
        {
            if(root->children[i]!=NULL)
            helper(root->children[i],word+root->children[i]->data);
        }
    }
     void search_pattern(TrieNode *root, string word,string firstword) 
     {
        // Base case
        if(root==NULL)
        {
            return ;
        }
        
        if (word.size() == 0) 
        {
            return helper(root,firstword);
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
        {
            return ;
        }
        
       search_pattern(root->children[index],word.substr(1),firstword);
        
            
    }
    
    
    /*----------------------------------------------*/
    void autoComplete(vector<string> input, string pattern) 
    {
        
        for(int i=0;i<input.size();i++)
        {
            insertWord(input[i]);
        }
        search_pattern(root,pattern,pattern);
    }
};







------------------------------------------------------------------------------------------END------------------------------------------------------------------------------------------------

