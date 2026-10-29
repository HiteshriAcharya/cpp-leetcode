#include <iostream>
#include <unordered_set>
using namespace std;

vector<string> findItinerary(vector<vector<string>>& tickets) {

    unordered_map<string, string> map;
    unordered_set<string> to;

    for(int i = 0; i < tickets.size(); i++){
        map[tickets[i][0]] = tickets[i][1];
        to.insert(tickets[i][1]);
    }

    string startLocation = "";

    for(pair<string,string> location : map){
        if(to.find(location.first) == to.end()){
            startLocation = location.first;
        }
    }

    vector<string> itinerary;

    while(map.count(startLocation) == 1){
        itinerary.push_back(startLocation);
        startLocation = map[startLocation];
    }
}

int main(){

}