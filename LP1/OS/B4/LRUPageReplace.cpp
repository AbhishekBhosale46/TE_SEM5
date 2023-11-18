#include<bits/stdc++.h>
using namespace std;

class LRUPageReplace{

    public:
    int frameSize;
    vector<int> frame;
    vector<int> pages;
    vector<vector<int>> states;
    int hit;
    int miss;

    LRUPageReplace(int frameSize){
        this->frameSize = frameSize;
        this->hit = 0;
        this->miss = 0;
    }

    void inputPages(){
        int num;
        cout<<"Enter number of pages : ";
        cin>>num;
        cout<<endl;
        for(int i=0; i<num; i++){
            int pageNo;
            cin>>pageNo;
            pages.push_back(pageNo);
        }
    }

    void replacePage(int pageNo, int indx){

        if(frame.size()<frameSize){
            if(find(frame.begin(), frame.end(), pageNo) == frame.end()){
                miss++;
                frame.push_back(pageNo);
            }else{
                hit++;
            }
        }else{

            if(find(frame.begin(), frame.end(), pageNo) == frame.end()){

                miss++;

                int start = indx - 1;
                int farthestPage = -1;
                int farthestDistance = -1;
                int farthestPageIndex = -1;

                for(int i=0; i<frame.size(); i++){
                    int currFrame = frame[i];
                    int currDistance;
                    for(int j=start; j>=0; j--){
                        if(currFrame == pages[j]){
                            currDistance = abs(j-indx);
                            if(currDistance>farthestDistance){
                                farthestDistance = currDistance;
                                farthestPage = frame[i];
                                farthestPageIndex = i;
                            }
                            break;
                        }
                    }
                }

                frame[farthestPageIndex] = pageNo;

            }else{
                hit++;
            }

        }

        states.push_back(frame);
    }

    void process(){
        for(int i=0; i<pages.size(); i++){
            replacePage(pages[i], i);
        }
    }
    
    void printMemoryStates(){
        for(int i=0; i<states.size(); i++){
            for(auto i: states[i]){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    LRUPageReplace lrupr(3);
    lrupr.inputPages();
    lrupr.process();
    cout<<endl;
    lrupr.printMemoryStates();
    cout<<endl<<"Hit - "<<lrupr.hit<<" "<<"Miss - "<<lrupr.miss<<endl;
    return 0;
}