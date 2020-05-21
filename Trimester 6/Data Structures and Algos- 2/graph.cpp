/*
Assignment 2 -> Graph BFS and DFS
Vignesh Charan-> PE28
Batch ->E2
*/

# include<iostream>
# include<string>
#include<queue>
using namespace std;

class gnode{ //declaring the class node
    int id;
    string username;
    gnode *next;
    public:
    gnode(){
        id =0;
        username ="\0";
        next = NULL;
    }
    friend class graph; // declaring  friend class graph
};

class graph{
    int n;
    gnode *head[10];
    public:
        void graph_head();
        void create();
        void display();
        void dfc_rec();
        void dfc_rec(int, int *);
        // void dfs_nr(int);
        void bfs_nr();
    
};

class stack{
    int top;
    int stck[20];

    public:

    void push(int);
    int pop();
    isfull();
    isempty();
};

// class queuet{
//     int front,rear;
//     int que[20];

//     public:

//         queue();
//         void enqueue(int temp); // to add element in the queue
//         int isempty();
//         int dequeue();
//         friend class graph;

// };

void graph :: graph_head(){
        n =0;
        cout<<"Enter the number of friends : ";
        cin>>n;
        for(int i =0;i<n;i++){
            head[i] = new gnode();
            head[i]->id = i;
            cout<<"Enter the name of user id "<<i<<" :";
            cin>>head[i]->username;   
        }
}

void graph::create(){
    char choice;
    gnode *temp;
    gnode *current;
    int id;
    temp = new gnode();
    for(int i = 0;i<n; i++){
        temp = head[i];
        cout<<"Enter the friends of "<<head[i]->username<<" : "<<endl;
        do{
            cout<<"Enter ID :";
            cin>>id;
            if(id == head[i]->id){
                cout<<"Cannot loop yourself as a friend"<<endl;
            }
            else{
                current = new gnode();
                current->id = id;
                current->username = head[i]->username;
                temp->next = current;
                temp = temp->next;
            }
            cout<<"Wanna add more friends(Y/N) ?"<<endl;
            cin>>choice;
        }while(choice=='Y'|| choice=='y');
    }
}

void  graph ::  dfc_rec(){
    int uid;
    int user[10];
    for(int i =1;i<n;i++){
        user[i] = 0;
    }
        cout<<"Enter the starting vertex id :";
        cin>>uid;
        dfc_rec(uid, user);
        cout<<endl;
}

void graph :: dfc_rec(int v, int user[10]){
    cout<<head[v]->username<<"\t";
    user[v] = 1;
    gnode *temp = head[v]->next;

    while(temp!= NULL){
        if(!user[temp->id]){
            dfc_rec(temp->id, user);
        }
        temp = temp->next;
    }
}

void graph :: bfs_nr(){
    int user[10];
    int v;
    for(int i=0;i<n;i++){
        user[i] = 0;
    }
    cout<<"Enter the Starting vertex id :";
    cin>>v;
    queue <int> q;
    q.push(v);
    user[v] = 1;
    while(!q.empty()){
        v = q.front();
        q.pop();
        cout<<head[v]->username<<"\t";
        gnode *temp = head[v]->next;
        while(temp!=NULL){
            if(!user[temp->id]){
                q.push(temp->id);
                user[temp->id] = 1;
            }
            temp = temp->next;
        }
    }   
    cout<<endl;
}


int main(){

    // graph g1;
    // g1.graph_head();
    // g1.create();
    // g1.dfc_rec();
    // g1.bfs_nr();
    int option;
    char choice='y';
    graph g1;
    do
    {
        cout<<"\tMENU\n";
        cout<<"1. Create a Graph\n";
        cout<<"2. DFS Traversal\n";
        cout<<"3. BFS Traversal\n";
        cout<<"Enter your choice ";
        cin>>option;
        switch(option)
        {
            case 1: g1.graph_head();
                    g1.create();
                    break;
            case 2: g1.dfc_rec();
                    break;
            case 3: g1.bfs_nr();
                    break;
        }
        cout<<"Do you want to continue? (y/n): ";
        cin>>choice;
    }while(choice=='y');

    return 0;
}


/*
     MENU
1. Create a Graph
2. DFS Traversal
3. BFS Traversal
Enter your choice 1
Enter the number of friends : 3
Enter the name of user id 0 :charan
Enter the name of user id 1 :abc
Enter the name of user id 2 :def
Enter the friends of charan :
Enter ID :1
Wanna add more friends(Y/N) ?
y
Enter ID :2
Wanna add more friends(Y/N) ?
n
Enter the friends of abc :
Enter ID :0
Wanna add more friends(Y/N) ?
y
Enter ID :2
Wanna add more friends(Y/N) ?
n
Enter the friends of def :
Enter ID :1
Wanna add more friends(Y/N) ?
n
Do you want to continue? (y/n): y
        MENU
1. Create a Graph
2. DFS Traversal
3. BFS Traversal
Enter your choice 2
Enter the starting vertex id :2
def     abc
Do you want to continue? (y/n): y
        MENU
1. Create a Graph
2. DFS Traversal
3. BFS Traversal
Enter your choice 3
Enter the Starting vertex id :1
abc     charan  def
Do you want to continue? (y/n): n
*/