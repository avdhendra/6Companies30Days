#include<bits/stdc++.h>
using namespace std;

//see it again
map<int, int> stock;
map<int, int> prices;
pair<int, int> currentStock = {-1, -1};

void update(int timestamp,int price){
    //update current stock price if we get a new greater timestamp
    if(timestamp>currentStock.first){
        currentStock = {timestamp, price};
    }
    if(stock.find(timestamp)!=stock.end()){
        int oldPrice=stock[timestamp]; //get old price for timestamp
        prices[oldPrice]--;
if(prices[oldPrice]==0){
    prices.erase(oldPrice); //remove if no timestamp has old price
}
    }
    prices[price]++;
   stock[timestamp] = price;
}
int current(){
   return currentStock.second;
}
int maximum(){
   return prices.rbegin()->first; //get last element

}
int minimum(){
   return prices.begin()->first; //get first element
}

int main(){

}