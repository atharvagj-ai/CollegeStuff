/*
Assignment 2 -> Binary Search Tree
Atharva Jibhakate -> PE08
Batch ->E1
*/

#include <iostream>
#include <string>
#include<queue>
using namespace std;

class Node{
    private:
    Node *left;
    Node *right;
    string key;
    string value;
    friend class Bst;
};

class Bst{
    Node *root;
    public:
        Bst(){
            root =NULL;
    }
    void createBst();
    void deleteBst();
    void  mirror(Node*root);
    int height(Node *root);
    Node* copy(Node *root);

    void preOrder(Node *root);
    void displayPre();

    void displayCopy();
    void displayHeight();
    void displayMirror();
    void levelWise(Node *root);
    void dispLevelWise();

};

void Bst :: createBst(){

    root = new Node;
    cout<<"Enter the Key for Root Node : ";
    cin>>root->key;
    cout<<"Enter the corresponding Value for the Root Node :  ";
    cin>>root->value;
    root->right=root->left=NULL;

    Node *temp;
    char check;
    Node *curr;

    do{

        temp = new Node;
        temp = root;

        curr = new Node;
        cout<<"Please enter the the key for new Node : ";
        cin>>curr->key;
        cout<<"Please enter the corresponding value for the new Node : ";
        cin>>curr->value;

        curr->left=curr->right=NULL;

        int flag =0;

        while(flag==0){
            if(curr->key < temp->key){
                if(temp->left == NULL){
                    temp->left = curr;
                    flag = 1;

                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right == NULL){
                    temp->right = curr;
                    flag = 1;
                }else{
                    temp = temp->right;
                }
            }
        }

        cout<<"Do you want to continue ?? (Y/N):";
        cin>>check;

    }while(check =='y'|| check =='Y');
}


void Bst :: deleteBst(){
    string del_key;
    cout<<"Please enter the word which you want to delete :";
    cin>>del_key;

    Node *temp;
    Node *curr;
    Node *parent;
    Node *s;
    Node *t1;
    Node *t2;

    temp = root;

    while(temp!=NULL){
        // cout<<temp->key<<endl;

        if(del_key == temp->key){

            curr = temp;
            break;

        }else if(del_key < temp->key){

            parent =temp;
            temp = temp->left;

        }else{

            parent = temp;
            temp = temp->right;
            // cout<<temp<<endl;
        }
    }


    if(curr==root){             // if the delete value is a root node
        if(curr->left == NULL){

            curr = curr->right;

        }else if(curr->right == NULL){

            curr = curr->left;

        }else if(curr->left != NULL && curr->right != NULL){
            root = curr->right;
            temp = curr->left;
            s = curr->right;

            while(s->left!=NULL){

                s = s->left;

            }
            s->left = temp;
        }

    }else if(curr!=root){               // if the delete value is not root node

        if(curr->left!=NULL && curr->right!=NULL){// if my left child and right child is not null
            s = temp->left;
            t1= temp-> right;

            while(t1->left!= NULL){

                t1=t1->left;
            }

            t1->left = s;
            t2= temp->right;

            if(temp == parent->left){

                parent->left = t2;

            }else{

                parent->right = t2;

            }

        }else if(curr->left== NULL && curr->right !=NULL){      // When left child is NULL and Right child is not Null

            if(curr == parent->right){

                parent->right = curr->right;
            }else{
                parent->left = curr->right;

            }
        }else if (curr->left!=NULL && curr->right == NULL){     // when left child is not NULL and right child is null

            if(curr== parent->right){

                parent->right = curr->left;

            }else{

                parent->left = curr->left;
            }

        }else{                  // when both are NULL
            if( curr == parent->left){

                parent->left =NULL;

            }else{

                parent->right =NULL;

            }
        }
    }
}


Node* Bst :: copy(Node *root){

    Node * curr =NULL;
    if(root !=NULL){

        curr = new Node();
        curr->key = root->key;
        curr->value= root->value;
        curr->left = copy(root->left) ;
        curr->right = copy(root->right);

    }

    return(curr);
    // cout<<"PRE ORDER Of copied tree: "<<endl;
    // preOrder(curr);
	// cout<<endl;

}
void Bst:: displayCopy(){
    Node * var = copy(root);
     cout<<"PRE ORDER Of copied tree: "<<endl;
     preOrder(var);
	 cout<<endl;
}


int Bst :: height(Node *root){

    if(root == NULL){
    return(0);
    }else{
        return(max(height(root->left),height(root->right))+1);
    }

}

void Bst :: displayHeight(){

    int h = height(root);
    cout<<"\nHeight of the tree is : "<<h<<endl;

}

void Bst :: mirror(Node *root){
    Node *temp;

    if(root!=NULL){
        temp = root->left;
        root->left = root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }

}

void Bst :: displayMirror(){
    mirror(root);
    cout<<"\nLevel Wise display Of Mirror tree: "<<endl;
    levelWise(root);
    cout<<endl;

}



void Bst :: preOrder(Node *root){
	if(root !=NULL){
	cout<<root->key<<" : "<<root->value<<endl;
	preOrder(root->left);
	preOrder(root->right);
	}
}
void Bst :: displayPre(){
	cout<<"PRE ORDER : "<<endl;
	preOrder(root);
	cout<<endl;
}

void Bst:: levelWise(Node *r){

    queue <Node *> q;
    Node *temp;
    temp=r;
    q.push(temp);
    cout<<"Word"<<"\tMeaning"<<"\n";
    while(q.empty()!=1)
    {
        temp=q.front();
        q.pop();
        cout<<temp->key<<" : \t"<<temp->value<<"\n";
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}

void Bst :: dispLevelWise(){
    cout<<"\nLevel wise display for the BST will be : "<<endl;
    levelWise(root);
}


int main()
{

    int option, created=0;
    char choice='y';
    char cont;
    Bst dictionary, copy_dictionary;
    do
    {
        cout<<"\tMENU\n";
        cout<<"1. Create a Dictionary\n";
        cout<<"2. Delete a keyword from the Dictionary\n";
        cout<<"3. Mirror the Dictionary's BST\n";
        cout<<"4. Copy the Dictionary\n";
        cout<<"Enter your choice ";
        cin>>option;
        switch(option)
        {
            case 1: dictionary.createBst();
                    dictionary.dispLevelWise();
                    created =1;
                    break;
            case 2: cont='y';
                    if(created==0)
                    {
                        cout<<"Cannot Delete!! as the dictionary has not been created yet.\n";
                    }
                    else
                    {
                        while(cont=='y')
                        {
                            dictionary.deleteBst();
                            std::cout<<"Do you want to continue? (y/n): ";
                            std::cin>>cont;
                        }
                        dictionary.dispLevelWise();
                    }
                    break;
            case 3: if(created==0)
                    {
                        std::cout<<"Cannot Mirror!! as the dictionary has not been created yet.\n";
                    }
                    else
                    {
                        dictionary.displayMirror();
                    }
                    break;
            case 4: if(created==0)
                    {
                        std::cout<<"Cannot Copy as the dictionary has not been created yet\n";
                    }
                    else
                    {
                        dictionary.displayCopy();
                    }
                    break;
            default: cout<<"Invalid selection!\n";
        }
        cout<<"Do you want to continue? (y/n): ";
        cin>>choice;
    }while(choice=='y');

    return 0;
}

/*

E:\MIT\SY\SY\Tri 6\DS 2\LAB>a
        MENU
1. Create a Dictionary
2. Delete a keyword from the Dictionary
3. Mirror the Dictionary's BST
4. Copy the Dictionary
Enter your choice 1
Enter the Key for Root Node : g
Enter the corresponding Value for the Root Node :  df
Please enter the the key for new Node : d
Please enter the corresponding value for the new Node : hgv
Do you want to continue ?? (Y/N):y
Please enter the the key for new Node : e
Please enter the corresponding value for the new Node : fv
Do you want to continue ?? (Y/N):y
Please enter the the key for new Node : j
Please enter the corresponding value for the new Node : fg
Do you want to continue ?? (Y/N):y
Please enter the the key for new Node : h
Please enter the corresponding value for the new Node : df
Do you want to continue ?? (Y/N):n

Level wise display for the BST will be :
Word    Meaning
g :     df
d :     hgv
j :     fg
e :     fv
h :     df
Do you want to continue? (y/n): y
        MENU
1. Create a Dictionary
2. Delete a keyword from the Dictionary
3. Mirror the Dictionary's BST
4. Copy the Dictionary
Enter your choice 3

Level Wise display Of Mirror tree:
Word    Meaning
g :     df
j :     fg
d :     hgv
h :     df
e :     fv

Do you want to continue? (y/n): y
        MENU
1. Create a Dictionary
2. Delete a keyword from the Dictionary
3. Mirror the Dictionary's BST
4. Copy the Dictionary
Enter your choice 4
PRE ORDER Of copied tree:
g : df
j : fg
h : df
d : hgv
e : fv

Do you want to continue? (y/n): y
        MENU
1. Create a Dictionary
2. Delete a keyword from the Dictionary
3. Mirror the Dictionary's BST
4. Copy the Dictionary
Enter your choice 2
Please enter the word which you want to delete :g
Do you want to continue? (y/n): n

Level wise display for the BST will be :
Word    Meaning
d :     hgv
e :     fv
j :     fg
h :     df
Do you want to continue? (y/n): n
*/
