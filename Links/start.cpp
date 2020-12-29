#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    string data;
    string name;
    node * next;
    node * below;
    int  count;
    node()
    {
        data="";
        name="";
        next =NULL;
        below = NULL;
        count=0;
    }
};
node * createRoot()
{
    node * root = new node();
    root->name = "c:";
    return root;
}

vector<string> splitPath(string location)
{
    vector <string> tokens; 
    stringstream check1(location); 
    string intermediate; 
    while(getline(check1, intermediate, '/' )) 
    { 
        tokens.push_back(intermediate); 
    } 
    return tokens;
}

void insertFile(node * root,string location,string content)
{
    node *temp = new node();
    node *prev = new node();
    node *pos = new node();
    temp = root;
    vector<string> token;
    token = splitPath(location);
    int i = 0;
    int flag=1;
    while(i<token.size())
    {

        while(temp!=NULL && flag==1)
        {
            if(temp->name==token[i])
            {
                pos = temp;
                flag=0;
            }
            prev = temp;
            temp = temp->next;
        }
        if(flag==1)
        {
            node * currNode = new node();
            currNode->name =  token[i];
            prev->next = currNode;
            pos = currNode;
        }
        i+=1;
        if(i<token.size())
        {
            if(pos->below==NULL)
            {
                node * currNode = new node();
                currNode->name =  token[i];
                pos->below = currNode;
                temp =currNode;
                prev= temp;
            }
            else
            {
                temp = pos->below;
                prev = temp;
            }
            
        }
        flag=1;
        if(i+1==token.size())
        {
            temp->data=content;
        }
    }
    

    
}

void display(node * root)
{
    cout<<root->name<<" ";
    if(root->next)
    {
        display(root->next);
    }
    cout<<endl;
    if(root->below)
    {
        display(root->below);
    }
}

void deleteFile(node *root, string location)
{
    node *temp = new node();
    node *prev = new node();
    temp = root;
    vector<string> token;
    token = splitPath(location);
    int i=0;
    while(i<token.size())
    {
        while(temp!=NULL)
        {
            if(temp->name==token[i] )
            {
                temp=temp->below;
                i+=1;
            }
            temp = temp->next;
        }
        if(temp==NULL)
        {
            cout<<"Element not found!!";
        }
    }

}
int main()
{   
    node * root = new node();
    root = createRoot();
    string location, data;
    int i=0;
    while(i<5)
    {
        cout<<"Enter file location ";
        getline(cin,location);
        cout<<"Enter data in file ";
        getline(cin,data);
        insertFile(root,location,data);
        i+=1;
        display(root);
    }
    return 0;   
}