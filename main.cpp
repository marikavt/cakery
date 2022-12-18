#include <iostream>

using namespace std;

class AbstractCakery{
    protected:
        string CakeName;
        string Object;
        string DateOfManufacture;
        
    public:
        static int CakesAmount;
        
        string getCakeName(){
            return CakeName;
        };
        void setCakeName(string CakeName){
            this -> CakeName=CakeName;
        };
        
        string getObject(){
            return Object;
        };
        void setObject(string Object){
            this -> Object=Object;
        };
        
        string getDateOfManufacture(){
            return DateOfManufacture;
        };
        void setDateOfManufacture(string DateOfManufacture){
            this -> DateOfManufacture=DateOfManufacture;
        };
        
        AbstractCakery(string CakeName, string Object, string DateOfManufacture){
            this -> CakeName=CakeName;
            this -> Object=Object;
            this -> DateOfManufacture;
            CakesAmount++;
        }
        
        void getCostumer(){
            // Object can be added, CakeName can be added
            cout << "A costumer entered into the cakery." << endl;
        };
        
        void sellCake(){
            cout << "Cake was sold." << endl;
        };
        
        virtual void OrderOnline() = 0;
        
        void RefillCakes(){
            cout << "Cakes were refilled." << endl;
        };
};

int AbstractCakery::CakesAmount = 0;

class Pancakes: public AbstractCakery{
    public:
    
    Pancakes(string Object, string DateOfManufacture): AbstractCakery("Pancake", Object, DateOfManufacture){}
    void OrderOnline(){
        // complex logic to buy thigs online
        cout << "Pancakes were sold online." << endl;
    };
    
    // overloading
    void OrderOnline(string OrderMethod){
        cout << "Payement was done by" << OrderMethod << " method." << endl;
    };
};

class Donuts: public AbstractCakery{
    public:
    
    Donuts(string Object, string DateOfManufacture): AbstractCakery("Donuts", Object, DateOfManufacture){}
    
    // overriding
    void OrderOnline(){
        // complex logic to buy thigs online
        cout << "Donuts were sold online." << endl;
    };
    
    // overloading
    void OrderOnline(string OrderMethod){
        cout << "Payement was done by" << OrderMethod << " method." << endl;
    };
};

class PaymentMethod{
        bool PayedWithCash;
        
    public:
    static int NumberOfPayedWithCash;
    
    PaymentMethod(bool PayedWithCash){
        this -> PayedWithCash = PayedWithCash;
    };
    
    bool getPayedWithCash(){
        return PayedWithCash;
    };
    void setPayedWithCash(bool PayedWithCash){
        this -> PayedWithCash = PayedWithCash;
    };
    
    void payment(){
        cout << "A costumer payed with cash." << endl;
        NumberOfPayedWithCash++;
    };
    
    // overloading
    void payment(Pancakes cake){
        cout <<"Payment was done in " << cake.getObject() << endl;
        NumberOfPayedWithCash++;
    };
    
    void payment(Donuts cake){
        cout <<"Payment was done in " << cake.getObject() << endl;
        NumberOfPayedWithCash++;
    };
};

int PaymentMethod::NumberOfPayedWithCash = 0;

int main()
{
        Pancakes ChocolatePancakes("creperie", "monday");
        
        cout << ChocolatePancakes.CakesAmount << endl;
        cout << AbstractCakery::CakesAmount << endl;
};
