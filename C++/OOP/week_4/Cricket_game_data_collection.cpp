#include<iostream>
using namespace std;
class Cricketer{
protected:
    string name;
    int age, matches;
public:
    void cicketer_read_data(){
        cout<< "Name, Age, no of matches: "<< endl;
        cin>> name>>age>> matches;
    }
    void cicketer_display_data(){
        cout<<"Name: "<<name<<" , Age: "<<age<<" , Matches: "<<matches<<endl;
    }
};
class bowler:public Cricketer{
private:
    int wickets;
public:
    void bowler_read_data(){
        cicketer_read_data();
        cout<< "No of wickets: "<< endl;
        cin>> wickets;
    }
    void bowler_display_data(){
        cicketer_display_data();
        cout<<"Wickets: "<<wickets<<endl;
    }
};
class batsman: public Cricketer{
private:
    int runs, centuries;
public:
    void batsman_read_data(){
        cicketer_read_data();
        cout<< "No of runs, centuries "<< endl;
        cin>> runs>> centuries;
    }
    void batsman_display_data(){
        cicketer_display_data();
        cout<<"Runs: "<<runs<<" , Centuries:"<<centuries<<endl;
    }
};
int main(){
    bowler bowl1;
    batsman bat1;
    cout<<"enter bowler details: ";
    bowl1.bowler_read_data();
    cout<<"enter batsman details: ";
    bat1.batsman_read_data();

    bowl1.bowler_display_data();
    bat1.batsman_display_data();
    return 0;
}
