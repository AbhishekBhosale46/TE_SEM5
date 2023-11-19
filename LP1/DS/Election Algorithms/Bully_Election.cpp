#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int id;
    bool isActive;

    Node(int id){
        this->id = id;
        this->isActive = true;
    }
};

class BullyElection{

    public:
    int currCoordinator;
    vector<Node> nodes;

    BullyElection(){
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

        for(int i=initiateFrom; i<nodes.size(); i++){
            if(nodes[i].isActive==true){
                for(int j=i+1; j<nodes.size(); j++){
                    cout<<"Node "<<nodes[i].id<<" sends ELECTION message to node "<<nodes[j].id<<endl;
                }
                for(int j=i+1; j<nodes.size(); j++){
                    if(nodes[j].isActive==true){
                        cout<<"Node "<<nodes[i].id<<" receives OK message from node "<<nodes[j].id<<endl;
                    }
                }
                cout<<endl;
            }
        }

        int newId = -1;
        for(int i=0; i<nodes.size(); i++){
            if(nodes[i].isActive==true && nodes[i].id>newId){
                newId = nodes[i].id;
            }
        }
        this->currCoordinator = newId;
        cout<<currCoordinator<<" WON the election !"<<endl<<endl;
        
    }

};

int main(){
    BullyElection be;
    be.conductElection(3);
    be.conductElection(2);
    return 0;
}