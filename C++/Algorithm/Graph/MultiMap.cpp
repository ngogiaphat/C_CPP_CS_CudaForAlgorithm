#include<bits/stdc++.h>
using namespace std;
// function to print multimap elements
void print(multimap<pair<int, int>, bool>& myContainer){
    cout << "Key" << " " << "Value(boolean)\n\n";
    for(auto pr: myContainer){
        pair<int, int> myPair = pr.first;
        // pr points to current pair of my Container
        cout << '[' << myPair.first << ", " << myPair.second << ']' << " " << pr.second << '\n';
    };
};
int main(){
    // declaring a multimap, key is of pair<int, int> type and value is of bool type
    multimap<pair<int, int>, bool> myContainer;
    // creating some pairs to be used as keys
    pair<int, int> pair1;
    pair1 = make_pair(100, 200);
    pair<int, int> pair2;
    pair2 = make_pair(200, 300);
    pair<int, int> pair3;
    pair3 = make_pair(300, 400);
    pair<int, int> pair4;
    pair4 = make_pair(100, 200);
    // Since each element is a pair on its own in a multimap. So, we are inserting a pair. Note that [] operator doesn't working in case of a multimap
    myContainer.insert(pair<pair<int, int>, bool>(pair1, true));
    myContainer.insert(pair<pair<int, int>, bool>(pair2, false));
    myContainer.insert(pair<pair<int, int>, bool>(pair3, true));
    myContainer.insert(pair<pair<int, int>, bool>(pair4, false));
    print(myContainer);
    return 0;
};