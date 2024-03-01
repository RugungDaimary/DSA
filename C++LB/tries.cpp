#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    // vector<TrieNode *> children{26,NULL};
    bool isTerminal;
    TrieNode(char d){
        this->data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
           
        }
        this->isTerminal=false;
    }

};
void insertWord(TrieNode* root,string word){ //TC -> O(word.length())
    // cout<<"Inserting : "<<word<<endl;
    //base case
    if(word.length()==0){//the current root will be terminal
        root->isTerminal=true;//the last character of string
        return;

    }
    char ch=word[0];
    int index=ch-'a';//dealing with LowerCase letter,will give index of children
    TrieNode* child;
    if(root->children[index]!=NULL){//present
        child=root->children[index];

    }else{//absent
        child=new TrieNode(ch);
        root->children[index]=child;

    }
    //recursion sambaal lega
    insertWord(child,word.substr(1));

}
bool searchWord(TrieNode*root,string word){
    //base case
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a'; // dealing with LowerCase letter,will give index of children
    TrieNode *child;
    if (root->children[index] != NULL)
    { // present
        child = root->children[index];
    }else{
        return false;
    }
    return searchWord(child,word.substr(1));
    
}
void deletion(TrieNode*root,string word){
    //base case
    if(word.length()==0){
        if(root->isTerminal){
            root->isTerminal=false;
        }
        return;
    }
    char ch = word[0];
    int index = ch - 'a'; // dealing with LowerCase letter,will give index of children
    TrieNode *child;
    if(root->children[index]!=NULL){//is present
        child=root->children[index];

    }else{
        return;
    }
    deletion(child,word.substr(1));
}

void storeSuggestions(TrieNode *curr, vector<string> &temp, string &prefix)
{
    if (curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    // a to z tak choices dedo
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';

        TrieNode *next = curr->children[index];

        if (next != NULL)
        {
            // if child exists
            prefix.push_back(ch);
            storeSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode *root, string input)//O(n*m^2);
{

    // TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < input.length(); i++)
    {
        char lastChar = input[i];

        int index = lastChar - 'a';
        TrieNode *curr = root->children[index];

        if (curr == NULL)
            break;
        else
        {
            // iske andar main saare suggestion store krke launga
            vector<string> temp;
            prefix.push_back(lastChar);
            storeSuggestions(curr, temp, prefix);
            output.push_back(temp);
            root = curr;
        }
    }
    return output;
}

int main(){
    /*
    TrieNode* root=new TrieNode('-');
    string word="leetcode";
    insertWord(root,"afdddv");
    insertWord(root,"rugung");
    insertWord(root,"adwfrevcd");
    insertWord(root,"coding");
    insertWord(root,"leetcoce");
    insertWord(root,"leetcode");
    if(searchWord(root,word)){
        cout<<"Present\n";
    }else{
        cout<<"Absent\n";
    }
    deletion(root, "afdddvew");
    if(searchWord(root,"afdddv")){
        cout<<"Present\n";
    }else{
        cout<<"Absent\n";
    }
    */
    vector<string> v;
	v.push_back("love");
	v.push_back("lover");
	v.push_back("loving");
	v.push_back("last");
	v.push_back("lost");
	v.push_back("lane");
	v.push_back("lord");

	string input = "lovx";

	TrieNode* root = new TrieNode('-');
	for(int i=0; i<v.size(); i++) {
		insertWord(root, v[i]);
	}

	vector<vector<string> > ans  = getSuggestions(root, input);

	cout << "Printing the answer: " << endl;

	for(int i=0; i<ans.size(); i++) {

		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j]<<", ";
		}
		cout << endl;
	}

    return 0;
}