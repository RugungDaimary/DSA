/*
#include<iostream>
using namespace std;
class vehicle{
    private:
    int maxSpeed;
    protected:
    int numTyres;
    public:
    string colour;
    vehicle(){
        cout<<"Default Constructor Call\n";
    }
    vehicle(int n){
        cout<<"Vehicle's Parameterized Constructor Call\n";
    }
    ~vehicle(){
        cout<<"Default Destructor call\n";
    }
};
class car:public vehicle{
    public:
    int numGears;
    car(int x,int y):vehicle(x){
        cout<<"Car's Constructor Call\n";
        numGears=y;

    }
    ~car(){
        cout<<"Car's default  Destructor Call\n";
    }
    // void print(){
    //     cout<<"NumTyres : "<<numTyres<<endl;
    //     cout<<"Colour : "<<colour<<endl;
    //     cout<<"numGrears : "<<numGears<<endl;
    // }

};
class HondaCity:public car{
    public:
    HondaCity(int x,int y):car(x,y){
        cout<<"HondaCity's Constructor call\n";
    }
    ~HondaCity(){
        cout<<"HondaCity's Destructor Call\n";
    }


};
int main(){
    // vehicle v;
    // v.colour="Red";
    // car c;
    // c.colour="Black";
    // c.numGears=4;
    // //c.numTyres=6;//not accessible from outside class
    // c.print();
    //car c;
    HondaCity h(3,4);


    
    return 0;
}
*/




// #include <iostream>
// using namespace std;
// class vehicle
// {
// private:
//     int maxSpeed;

// protected:
//     int numTyres;

// public:
//     string colour;

//     vehicle()
//     {
//         cout << "Default Constructor Call\n";
//     }
//     void print(){
//         cout<<"Vehicle\n";
//     }
    
// };
// class Car : public vehicle
// {   public:
//     int numGears;
//     Car(){
//         cout << "Car's Constructor Call\n";
//     }
//     void print(){
//         cout<<"Print Car\n"; 
//     }
// };
// class Truck:public vehicle{
//     public:
//     Truck(){
//         cout<<"Truck's Constructor Call\n";
//     }

// };
// class Bus:public Car,public Truck{
//     public:
//     Bus(){
//         cout<<"Bus's Constructor Call\n";
//     }
//     // void print(){
//     //     cout<<"Print\n";
//     // }

// };
// int main()
// {
//     Bus b;//order of constructor call
//     // vehicle(),car(),vehicle(),Truck(),Bus();
//     b.Car::print();
//     return 0;
// }





//USE of VIRTUAL KEYWORD

// #include <iostream>
// using namespace std;
// class vehicle
// {
// private:
//     int maxSpeed;

// protected:
//     int numTyres;

// public:
//     string colour;

//     vehicle()
//     {
//         cout << "Vehicle Constructor Call\n";
//     }
//     void print(){
//         cout<<"Vehicle\n";
//     }
    
// };
// class Car : virtual public vehicle
// {   public:
//     int numGears;
//     Car(){
//         cout << "Car's Constructor Call\n";
//     }
//     void print(){
//         cout<<"Print Car\n"; 
//     }
// };
// class Truck:virtual public vehicle{
//     public:
//     Truck(){
//         cout<<"Truck's Constructor Call\n";
//     }

// };
// class Bus:public Car,public Truck{
//     public:
//     Bus(){
//         cout<<"Bus's Constructor Call\n";
//     }
//     // void print(){
//     //     cout<<"Print\n";
//     // }

// };
// int main()
// {
//     /*
//     Bus b;//order of constructor call
//     // vehicle(),car(),vehicle(),Truck(),Bus();
//     b.Car::print();
//     cout<<endl;
//     */
//    vehicle v;
//    Car c;
//    v.print();
//    c.print();
//    vehicle *v1=new vehicle;
//    vehicle *v2;
//    v2=&c;
//    v1->print();
//    v2->print();

//     return 0;
// }

/*

#include<iostream>
using namespace std;
class vehicle{
    public:
    virtual void print(){
        cout<<"Vehicle\n";
    }

};
class car:public vehicle{
    public:
    void print(){
        cout<<"Car\n";
    }

};
int main(){
    // vehicle v;
    // car c;
    // vehicle * v1=new vehicle;
    // vehicle *v2;
    // v2=&c;
    // v1->print();
    // v2->print();
    car c;
    vehicle *v1=new vehicle;
    vehicle *v2;
    v2=&c;
    v2->print();
    v1->print();
    c.print();

    return 0;
}

*/

//Singleton class

#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    // Private constructor so no one can create objects directly
    Singleton()
    {
        cout << "Singleton instance created" << endl;
    }

    // This holds the one and only instance
    static Singleton *instance;

public:
    // Static method to get the single instance
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton(); // Create it if it doesn't exist yet
        }
        return instance; // Always return the same instance
    }
};

// Initialize the static instance pointer to nullptr (no object created yet)
Singleton *Singleton::instance = nullptr;

int main()
{
    // Get the Singleton instance
    Singleton *obj1 = Singleton::getInstance();

    // Trying to get another instance will give the same one
    Singleton *obj2 = Singleton::getInstance();

    return 0;
}