#include <algorithm>
#include <cstddef>
#include<string>
#include <vector>
#include <iostream>

using str = std::string;

class Worker{
    str FIO;
    str tabelNumber;
    str doljnosty;
    str startRoadToHell;
    int kopeiky;
    public:
    Worker(str FIO,str tabelNumber,str doljnosty,str startRoadToHell,int kopeiky):
    FIO{FIO},tabelNumber{tabelNumber},doljnosty{doljnosty},startRoadToHell{startRoadToHell},kopeiky{kopeiky}{}
    str getName(){
        return FIO;
    }
    int getAge(){
        return std::stoi(startRoadToHell.substr(0,startRoadToHell.find_first_of(".")));
    }
    int getZP(){
        return kopeiky;
    }
    str getDolj(){
        return doljnosty;
    }
};

std::vector<std::string> returnUpSotrSpisok(std::vector<Worker>&vec,int age){
    std::vector<std::string> data;
    for(auto i:vec){
        if(2022-i.getAge()>age){
            data.push_back(i.getName());
        }
    }
    std::sort(data.begin(),data.end());
    return data;
}

std::vector<std::string> zpVDiap(std::vector<Worker>&vec,int a,int b){
    std::vector<std::string> data;
    for(auto i:vec){
        if(i.getZP()-a>=0 && b-i.getZP()>=0){
            data.push_back(i.getName());
        }
    }
    return data;
}

std::vector<std::string> retDolj(std::vector<Worker>&vec,std::string dolj){
    std::vector<std::string> data;
    for(auto i:vec){
        if(i.getDolj()==dolj){
            data.push_back(i.getName());
        }
    }
    return data;
}

int main(){
    std::vector<Worker> vector{{"DimaAA","123","LOLKA","2004.20.12",200},{"DimaBA","123","LOLKA","2004.13.11",200}};
    for(auto i:returnUpSotrSpisok(vector, 3)){
        std::cout<<i<<" ";
    }
    return 0;
}