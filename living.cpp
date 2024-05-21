#include <iostream>
#include <string>
using namespace std;

class living {
  public:
    string name;
    bool is_zookeeper;

}


class living_Zookeeper:public living {
    public:
 double hourly_rate;
}
   


class living_animal:public living{
public:
int hunger_level;
int happiness_level;
bool is_dead;
int visitors_per_hour;
double height;
double weight;

void hunger_rate(double height,double weight){

float hungerrate=(height*weight)/100;
return float hungerrate;

}

void hunger_happines_relationship(int hunger_level){
if (hunger_level)<50; 
while(hunger_level<50){

    happiness_level-1

    cout << happiness_level;
    return ;
}


}
void cleanliness_happinesss_relationship(){

while(cleanliness<50){
happiness_level-1
cout << happiness_level ;
return;
}
}

void feed(food){
( hunger_level )=100;


}
}
class living_animal_mammal:public living_animal {
public:
bool need_shelter;

void mammal_cleanliness(height,weight){
    (height + weight)/100;
    return;

}


;}