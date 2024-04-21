// Designed by Barun 4/21/2024.
// Basic inheritance example.
// Base specifier example
// Dimond problems.
/*
 concept refrence

    Single inheritance
    Multilevel inheritance
    Multiple inheritance
    Hierarchical inheritance
    Hybrid inheritance
    Constructor

https://www.geeksforgeeks.org/inheritance-in-c/


*/

#include <iostream>
using namespace std;
#include<stdint.h>

class vehicle
{
    private:
    uint16_t applyBreak;
    protected:
    uint16_t ManageFuelSup;
    public:
    uint16_t detectCapicityLoad;
    vehicle(){ cout<<"Inside node creation!"<<endl;}
    ~vehicle(){ cout<<"Inside node dletion!"<<endl;}
    void applyBreakTorcQ(void);
    /*{
        applyBreak=2;
        cout<<"Torcq rotation in Vehicle:"<<applyBreak<<endl;
        
    }*/
};

void vehicle ::applyBreakTorcQ(void)
{
        applyBreak=2;
        cout<<"Torcq rotation in Vehicle:"<<applyBreak<<endl;
        
}
class car :  virtual public vehicle // avoid using virtual or scope resulation operator
{
    public:
    void applyBreakTorcQinCar(void)
    {
        ManageFuelSup=5;
        
        cout<<"Torcq rotation in Car:"<<ManageFuelSup<<endl;
    }
};

class car2 : virtual public vehicle // This is case of dimond problem 
{
    public:
    void applyBreakTorcQinCar2(void)
    {
        ManageFuelSup=6;
        
        cout<<"Torcq rotation in Car2:"<<detectCapicityLoad<<endl;
    }
};


class carc :  public car, public car2
{
    public:
    void applyBreakTorcQinCarc(void)
    {
        //ManageFuelSup=6;
        
        cout<<"Torcq rotation in Carc:"<<endl;
    }
};


class carAlto :  public car
{
    public:
    void applyBreakTorcQinAltoCar(void)
    {
        
        
        cout<<"Torcq rotation in AltoCar:"<<endl;
    }
};

/*class carAltoRenz :  public carAlto, public vehicle
{
    public:
    void applyBreakTorcQinAltoCarRenz(void)
    {
        
        
        cout<<"Torcq rotation in AltoCarRenz:"<<endl;
    }
};
*/

int main()
{
    
    //car c1;
    carAlto c1;
    carc cc1;
    cc1.car::detectCapicityLoad=2;
    cc1.car2::detectCapicityLoad=2;
    cc1.car2::applyBreakTorcQinCar2();
    cc1.applyBreakTorcQinCar2();
   // carAltoRenz c1;
    c1.detectCapicityLoad =10000;
    //c1.ManageFuelSup=5;
    cout<<"Capload:"<<c1.detectCapicityLoad<<endl;
    c1.applyBreakTorcQinCar();
    c1.applyBreakTorcQ();
    c1.applyBreakTorcQinAltoCar();
   // c1.applyBreakTorcQinAltoCarRenz();

    return 0;
}
