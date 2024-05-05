//#include<iostream>
//using namespace std;
//class Hero{
//    //properties/data members
////    char name[100];
//   // int health;
////    char level;
//
//};
//int main(){
//    //creation of object
//    Hero h1;
//    cout<<"size : "<<sizeof(h1)<<endl;
//    //in case of empty class also,object is allocated 1 byte of memory for identifiaction
//
//
//    return 0;
//}
//


// #include<iostream>
// //#include "hero.cpp"
// using namespace std;
// class hero{
//     private:
//     int health=75;
//     char level='B';
//     public://isse niche wala public ho jayenge
   
//     string name;


   
    
// //    void print(){
// //        cout<<level<<endl;
// //    }
//     int getHealth(){//getter
//         return health;
//     }
//     char getLevel(){//getter
//         return level;
//     }
    
//     void setHealth(int h/*,char pswd*/){//setter,koi b condition use kar sakta hai
// //        if (pswd=='A') {//agar password A k equal ho jaye tabhi set kar paoge
// //            health=h;
// //        }
//         health=h;
        
//     }
//     void setLevel(char ch){
//         level=ch;
//     }
// };

// int main(){
//     hero ramesh;
//     ramesh.name="Ramesh";
//     //ramesh.health=80;
//     //ramesh.level='D';
    
//     cout<<"Name is "<<ramesh.name<<endl;
//     //cout<<"Health is "<<ramesh.health<<endl;
//     //cout<<"Level is "<<ramesh.level<<endl;
    
//     cout<<"Size "<<sizeof(ramesh)<<endl;
//     cout<<"Ramesh's Health is : "<<ramesh.getHealth()<<endl;
//     ramesh.setHealth(80/*,'B'*/);//setter function is used
//     cout<<"Ramesh's Health after set is now : "<<ramesh.getHealth()<<endl;
//     cout<<"Ramesh's Level is : "<<ramesh.getLevel()<<endl;
//     ramesh.setLevel('Z');
//     cout<<"Ramesh's Level after set is now : "<<ramesh.getLevel()<<endl;
    
//     return 0;
// }



#include<iostream>
using namespace std;
class Fraction{
    int n;
    int d;
    public:
    Fraction(int n,int d){
        this->n=n;
        this->d=d;

    }
    
    Fraction add(Fraction const &f2){
        int LCM=this->d*(f2.d);
        int numer=this->n*(LCM/this->d)+f2.n*(LCM/f2.d);
        Fraction fNew(numer,LCM);
        return fNew;
    }
    void print(){
        cout<<n<<"/"<<d<<endl;
    }
    Fraction operator+ (Fraction const &f2){
        int LCM = this->d * (f2.d);
        int numer = this->n * (LCM / this->d) + f2.n * (LCM / f2.d);
        Fraction fNew(numer, LCM);
        return fNew;
    }
    Fraction operator* (Fraction const &f2){
        int numer=this->n*f2.n;
        int deno=this->d* f2.d;
        Fraction fNew(numer,deno);
        return fNew;
    }
    bool operator== (Fraction const &f2){
        return (n==f2.n && d==f2.d);
    }
    Fraction& operator++(){
        this->n=this->n +this->d;
        return *this;
    }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(3,2);
    Fraction f3=f1.add(f2);
    f3.print();
    cout<<endl;
    Fraction f4=f1+f2;
    cout<<"After Operator Overloading\n";
    f4.print();
    cout<<endl;
    Fraction f5=f1*f2;
    f5.print();
    cout<<endl;
    if (f1==f2)
    {
        cout<<"Equal\n";
    }else{
        cout<<"Not Equal\n";
    }
    
    Fraction f6=++(++f1);
    f6.print();
    
    
    return 0;
}