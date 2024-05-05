#include<iostream> 
using namespace std;
class Student{
    public:
    string name;
    int rollNo;

private:
    int age;
    

public: // this functions are to be public
    void display(){
        cout<<age<<" "<<rollNo<<endl;
    }
    int getAge(){
        return age;
    }
    void setRollNO(int rollNO){
        this->rollNo=rollNo;
    }

};
int main(){
    Student s1;//create object statically
    Student s3,s4;
    s1.rollNo=151;//setting or accessing in static
    cout<<s1.getAge()<<endl;// s1.age=60;
    s1.name="Rugung";
    Student *s2 = new Student; // dynamically
    (*s2).name="Daimary";
    (*s2).rollNo=1;
    cout<<(*s2).getAge()<<endl;
    // (*s2).age=10;
    //or
    s2->name="Daimary";
    s2->rollNo=20;

    cout<<s2->getAge()<<endl;
    s2->setRollNO(151);

    cout<<"Roll No of S2 "<<s2->rollNo<<endl;
    s2->display();
    s1.display();

    return 0;
}




// #include<iostream>
// using namespace std;
// class Student{
//     public:
//     string name;
//     int age;
//     private:
//     int RollNo;
//     public:
//     //default constructor
//     Student(){
//         cout<<"Default Constructor call\n";
//     }
//     //parameerized constructor
//     Student(int R)
//     {
//         cout<<"Parameterized Constructor Call\n";
//         cout<<"Address of s1 using 'this'-> "<<this<<endl;
//         this->RollNo=R;//here 'this' wrtiting is optional
//     }
//     void setRollNO(int n,string password){
//         if (password== "rugung@123")
//         {
//             RollNo = n;
//         }
//         if(n<0){
//             return;
//         }
        
       
//     }
//     int getRollNO(){
//         return RollNo;
//     }

// };
// int main(){
//     Student s1(10);//statically
//     /*
//     Student *s2=new Student();//dynamically,
//     s1.name="Rugung";
//     Student s3(5);
//     cout<<s1.getRollNO()<<endl;
//     s1.setRollNO(151,"rugung@123");
//     cout<<s1.getRollNO()<<endl;
//     */

//     // cout<<s2->getRollNO()<<endl;
//     // s2->setRollNO(20);
//     // cout << s2->getRollNO() << endl;
//     cout<<"Address of s1 "<<&s1<<endl;

    

//     return 0;
// }



//Copy Constructor
// #include<iostream>
// using namespace std;
// class Student{
//     public:
//     int age;
//     int rollNo;

//     Student(){

//     }
//     Student(int a,int r){
//         cout<<endl;
//         cout<<"Parameterized Constructor Call\n";
//         age=a;
//         rollNo=r;
//     }
//     ~Student(){
//         cout<<"Destructor Called !!"<<endl;
//     }

// };
// int main(){
//     /*
//     //Statically
//     Student s1(10,151);
//     cout<<"S1 : "<<s1.age<<" "<<s1.rollNo<<endl;
//     Student s2(s1);//copy constructor call
//     // s2.age=s1.age;
//     // s2.rollNo=s1.rollNo;
//     //or
//     cout<<"S2 : "<<s2.age<<" "<<s2.rollNo<<endl;

//     //Dynamically
//     Student *s3=new Student(20,180);
//     cout<<"S3 : "<<s3->age<<" "<<s3->rollNo<<endl;
//     Student s4(*s3);//here s3 is a pointer ,that's why * is used
//     cout << "S4 : " << s4.age << " " << s4.rollNo << endl;
//     Student *s5=new Student(*s3);
//     Student *s6=new Student(s1);
//     return 0;
//     */


//    //Using COPY Assignment Opearator
//    Student s1(10,1001);
//    Student s2(20, 2002);//statically
//    Student *s3 = new Student(30, 3003);//dynamically
//    cout<<"Before Copy :\n";
//    cout << "S1 : " << s1.age << " " << s1.rollNo << endl;
//    cout << "S2 : " << s2.age << " " << s2.rollNo << endl;
//    cout << "S3 : " << s3->age << " " << s3->rollNo << endl;
//    s2=s1;//statically
//    *s3=s1;//dynamically
//    cout<<"After Copy :\n";
//    cout<<"S1 : "<<s1.age<<" "<<s1.rollNo<<endl;
//    cout << "S2 : " << s2.age << " " << s2.rollNo << endl;
//    cout << "S3 : " << s3->age << " " << s3->rollNo << endl;

//    cout<<endl;

//    s2=*s3;
//    cout << "S2 : " << s2.age << " " << s2.rollNo << endl;
//    cout << "S3 : " << s3->age << " " << s3->rollNo << endl;
// }



//Destructor
// #include <iostream>
// using namespace std;
// class Student
// {
//    public:
//    int age;
//    int rollNo;
//    Student(int a, int r)
//    {

//         cout << "Parameterized Constructor Called!!\n";
//         age = a;
//         rollNo = r;
//    }
//    ~Student()
//    {
        
//         cout << "Destructor Called !!" << endl;
//    }
// };
// int main(){
//     Student s1(10,1001);
//     Student s2(20,2002);
//     Student *s3=new Student(30,3003);
//     delete s3;
// }

// #include <iostream>
// using namespace std;
// class Student
// {
//    public:
//    int age;
//    int rollNo;
//    Student(){
//     cout<<"Default Constructor called\n";
//    }
//    Student(int a, int r)
//    {

//         cout << "Parameterized Constructor Called!!\n";
//         age = a;
//         rollNo = r;
//    }
// };
// int main(){
//     Student s1;//Default Constructor Called
//     Student s2(10,151);//Parameterized Constructor Called
//     Student s3(s2);//Copy Constructor Called
//     s1=s2;//Copy Assignment Opeartor 
//     Student s4=s2;//Copy Constructor Called

// }


//FRACTION
// #include <iostream>
// using namespace std;
// class Fraction
// {
//     int numerator;
//     int denomerator;

// public:
//     Fraction(int numerator, int denomerator)
//     {
//         this->numerator = numerator;
//         this->denomerator = denomerator;
//     }
//     void print()
//     {
//         //cout << this->numerator << "/" << this->denomerator << endl;
//         cout << numerator << "/" << denomerator << endl;
//         //here writing of 'this' is optional,since no argument is passed
//     }
//     void simplify(){
//         //this=address of f1
//         int GCD=1;//highest common factor
//         int j=min(this->numerator,this->denomerator);
//         for (int i =1; i <= j; i++)//max common factor will be upto least of two.
//         {
//             if (this->numerator%i==0 && this->denomerator%i==0)
//             {
//                 GCD=i;
//             }
            
//         }
//         this->numerator = this->numerator/GCD;
//         this->denomerator = this->denomerator/GCD;
//         }
//     void add(Fraction &f2){
//         int LCM=this->denomerator*f2.denomerator; //here this= address of f1
//         int x=LCM/this->denomerator;//or denomerator only
//         int y=LCM/f2.denomerator;
//         int numer=x*numerator+(y*f2.numerator);
//         numerator=numer;
//         denomerator=LCM;
//         cout << numerator << "/" << denomerator << endl;
//         //To simplify the output
//         cout<<"After Simplified : ";
//         simplify(); // this->simplify(); this= address of f1
//     }
//     // ~Fraction()
//     // {
//     //     cout << "Destructor Called\n";
//     // }
// };
// int main()
// {
//     Fraction f1(10, 2);
//     f1.print();
//     Fraction f2(15,4);
//     f2.print();
//     f1.add(f2); 
//     f1.print();
    
//     return 0;
// }



// #include <iostream>
// using namespace std;
// class Fraction
// {
//     int numerator;
//     int denomerator;

// public:
//     Fraction(int numerator, int denomerator)
//     {
//         this->numerator = numerator;
//         this->denomerator = denomerator;
//     }
//     void print()
//     {
//         // cout << this->numerator << "/" << this->denomerator << endl;
//         cout << numerator << "/" << denomerator << endl;
//         // here writing of 'this' is optional,since no argument is passed
//     }
//     void simplify()
//     {
//         // this=address of f1
//         int GCD = 1; // highest common factor
//         int j = min(this->numerator, this->denomerator);
//         for (int i = 1; i <= j; i++) // max common factor will be upto least of two.
//         {
//             if (this->numerator % i == 0 && this->denomerator % i == 0)
//             {
//                 GCD = i;
//             }
//         }
//         this->numerator = this->numerator / GCD;
//         this->denomerator = this->denomerator / GCD;
//     }
//     void add(Fraction const &f2)// const is used to avoid changes in main()
//     {
//         int LCM = this->denomerator * f2.denomerator; // here this= address of f1
//         int x = LCM / this->denomerator;              // or denomerator only
//         int y = LCM / f2.denomerator;
//         int numer = x * numerator + (y * f2.numerator);
//         numerator = numer;
//         denomerator = LCM;
//         cout << numerator << "/" << denomerator << endl;
//         // To simplify the output
//         cout << "After Simplified : ";
//         simplify(); // this->simplify(); this= address of f1
//     }
//     // ~Fraction()
//     // {
//     //     cout << "Destructor Called\n";
//     // }
// };
// int main()
// {
//     Fraction f1(10, 2);
//     f1.print();
//     Fraction f2(15, 4);
//     f2.print();
//     f1.add(f2);
//     f1.print();

//     return 0;
// }



//MULTIFLY
// #include<iostream>
// using namespace std;
// class Fraction{
//     private:
//     int a;
//     public:
//     Fraction(int a){
//         this->a=a;     
//     }
//     void multifly(Fraction const &m2){
//         this->a=a*(m2.a);
//         cout<<"Multiplication : "<<a<<endl;    
//     }

// };
// int main(){
//     Fraction m1(2);
//     Fraction m2(3);
//     m1.multifly(m2);

    
    
//     return 0;
// }


//MULTIPLICATION of Fraction

// #include<iostream>
// using namespace std;
// class Fraction{
//     int numerator;
//     int denomerator;
//     public:
//     Fraction(int numerator,int denomerator){
//         this->numerator=numerator;
//         this->denomerator=denomerator;
//         cout<<numerator<<"/"<<denomerator<<endl;
//     }
//     void simplify(){
//         int GCD=1;
//         int j=min(numerator,denomerator);
//         for (int i = 1; i <=j; i++)
//         {
//             if (numerator%i==0 && denomerator%i==0)
//             {
//                 GCD=i;
//             }
            
//         }
//         numerator=numerator/GCD;
//         denomerator=denomerator/GCD;
        
        
        
//     }
//     void multifly(Fraction const &f2){
//         numerator=numerator*(f2.numerator);
//         denomerator=denomerator*(f2.denomerator);
//         cout<<"After Multiplication : ";
//         cout<<numerator<<"/"<<denomerator<<endl;
//         simplify();
//         cout << "After Simplified : ";
//         cout << numerator << "/" << denomerator << endl;
//     }

// };
// int main(){
//     Fraction f1(4,1);
//     Fraction f2(5,5);
//     f1.multifly(f2);
    
//     return 0;
// }


//COMPLEX NUMBER
// #include<iostream>
// using namespace std;
// class Complex{
//     int real;
//     int imaginary;
//     public:
//     Complex(int real,int imaginary){
//         this->real=real;
//         this->imaginary=imaginary;
//         cout<<real<<"+"<<imaginary<<"i"<<endl;
//     }
//     void Add(Complex const &c2){
//         this->real=real+(c2.real);
//         this->imaginary=imaginary+(c2.imaginary);

//     }
//     void Multiply(Complex const &c2){
//         this->real=real*(c2.real);
//         this->imaginary=imaginary*(c2.imaginary);

//     }
//     void print(){
//         cout<<this->real<<"+"<<this->imaginary<<"i"<<endl;

//     }

// };
// int main(){
//     Complex c1(4,5);
//     Complex c2(6,7);
//     int choice;
//     cout<<"Enter Choice\n";
//     cin>>choice;
//     if (choice==1)
//     {
//         c1.Add(c2);
//         c1.print();
//     }else if(choice==2){
//         c1.Multiply(c2);
//         c1.print();

//     }else{
//         return 0;
//     }
    
    
//     return 0;
// }