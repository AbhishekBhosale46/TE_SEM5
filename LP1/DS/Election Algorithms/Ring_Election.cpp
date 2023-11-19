#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int id;
    bool isActive;
    
    Node(int id){
        this->id = id;
        isActive = true;
    }
}; 

class RingElection{

    public:
    int currCoordinator;
    vector<Node> nodes;
    
    RingElection(){
        int n;
        cout<<"Enter number of nodes : ";
        cin>>n;
        for(int i=0; i<n; i++){
            Node newN(i);
            nodes.push_back(newN);
        }
        int currId;
        cout<<"Enter current coordinator id : ";
        cin>>currId;
        this->currCoordinator = currId;
    }

    void conductElection(int initiateFrom){

        nodes[(this->currCoordinator)].isActive = false;
        cout<<endl<<"Current coordinator with id "<<this->currCoordinator<<" failed"<<endl<<endl;

        vector<int> messages;

        int end = initiateFrom-1;
        int i = initiateFrom;
        while(i%nodes.size()!=end){
            if(nodes[i].isActive==true){
                messages.push_back(nodes[i].id);
            }
            i++;
        }

        sort(messages.begin(), messages.end());

        this->currCoordinator = messages[messages.size()-1];
        cout<<messages[messages.size()-1]<<" WON the election "<<endl<<endl;

    }


};

int main(){
    RingElection re;
    re.conductElection(3);
    return 0;
}