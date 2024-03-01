#include<iostream>
using namespace std;
class Student{
    char *name;
    int age;
    public:
    Student(int age,char *name){
       // this->name=name;//shallow copy
        this->age=age;
        this->name=new char[strlen(name)+1];//Deep Copy
        strcpy(this->name,name);

    }
    void display(){
        cout<<name<<" "<<age<<endl;

    }
        

};
int main(){
    char name[]="Rugung";
    Student s1(19,name);
    s1.display();
    name[5]='D';
    Student s2(20,name);
    s2.display();
    s1.display();
    s2.display();

    return 0;
}


/* Deep Copy Constructor

#include <iostream>
using namespace std;
class Student
{
    int age;
public:
    char *name;
    Student(int age, char *name)
    {
        this->age = age;
        this->name = new char[strlen(name) + 1]; // Deep Copy
        strcpy(this->name, name);
    }
    void display()
    {
        cout << "Name : "<<name << ", " <<"Age : "<< age << endl;
    }
    //Copy Constructor(Our Own)
    Student(Student const &s){//here this=address of s2 and s means arguments of s1
        //shallow copy(By default)
        
        //this->age=s.age;
        //this->name=s.name;
        
       //Deep Copy
       this->age=s.age;
       this->name=new char[strlen(s.name)+1];
       strcpy(this->name,s.name);
    }
};
int main()
{
    char name[] = "abcd";
    Student s1(19, name);
    s1.display();
    Student s2(s1);//copy constructor
    s2.name[0]='X';
    s2.display();
    s1.display();
    return 0;
}
*/



//Constant Variable & Initialization List
/*
#include<iostream>
using namespace std;
class Student{
    public:
    int age;
    //const int rollNo;//here initialized with garbage value
   // const int rollNo=151; //in object creation for 10 students,rollNo will be same for all
    int const rollNo;
    int &x;//reference variable of age


    Student(int r):rollNo(r){

    }


    // Student(int r,int age):rollNo(r),age(age),x(this->age) {//Normal variable can also be initialized using 
    //                                         //initialization list
    //     cout<<"This is also allowed\n";
    // }
};

int main(){
    Student s1(151);
   // Student s2(151,19);
    s1.age=20;
    // s1.rollNo=151;
    cout<<s1.age<<" "<<s1.rollNo<<endl;
    
    return 0;
}
*/


//Constant Function
// #include<iostream>
// using namespace std;
// class Fraction{
  
//     int numerator;
//     int denomerator;
//     public:
//     // Fraction(){

//     // }
//     Fraction(int numerator,int denomerator){
//         this->numerator=numerator;
//         this->denomerator=denomerator;
//     }
//     void setNumerator(int numerator) {// not a const func
//         this->numerator=numerator;

//     } 
//     void setDenomerator(int denomerator){// not a const func
//         this->denomerator=denomerator;

//     }
//     int getNumerator() const {
//         return numerator;
//     }
//     int getDenomerator() const{
//         return denomerator; 

//     }
//     void print() const{
//         cout<<numerator<<"/"<<denomerator<<endl;
//     }
//     void Sum(Fraction const &f2){//not a const func
//         int LCM=this->denomerator*(f2.denomerator);
//         int nume=(this->numerator)*(LCM/this->denomerator)+(f2.numerator)*(LCM/f2.denomerator);
//         this->numerator=nume;
//         this->denomerator=LCM;        
//     }


// };
// int main(){
//     // Fraction f1(11,5);    
//     // Fraction f2(3,2);    
//     // f1.print();
//     // f2.print();
//     // f1.Sum(f2);
//     // f1.print();

//     //Constant Object
//     const Fraction f3(20,151);//No further chanages allowed in f3,compiler doesn't allow to call any 
//     //function call in f3 ,allows only constant function call
//     cout << f3.getNumerator() << "/" << f3.getDenomerator()<< endl;

//     return 0;
// }



// #include<iostream>
// using namespace std;
// class Student
// {
//     int rollNumber;

// public:
//     int age;

//     Student(int r)
//     {
//         rollNumber = r;
//     }

//     int getRollNumber() //here 'const' should be marked
//     {
//         return rollNumber;
//     }
// };

// int main()
// {
//     Student s1(101);
//     s1.age = 20;

//     Student const s2 = s1;
//     cout << s2.getRollNumber();
// }





//STATIC DATA MEMBERS
/*
#include<iostream>
using namespace std;
class Student{
    public:
    int age;
    int rollNo;
    static int totalStudents;//total no of students ,now this property belongs to a class
    Student(int r,int a){
        rollNo=r;
        age=a;
        totalStudents++;
    }

};
int Student::totalStudents=0;//initialize static data members
int main(){
    Student s1(151,20);  
    cout<<"Roll No "<<s1.rollNo<<endl;
    cout<<"Age "<<s1.age<<endl;
    // cout<<"Total Students "<<Student::totalStudents<<endl;
    // cout<<s1.totalStudents<<endl;//logically incorrect,since 'totalStudent' is no longer  
    // a property of an object
    // s1.totalStudents=10;
    // cout << "Total Students " << Student::totalStudents << endl;
    Student s2(10,1002);
    
    // cout<<s2.totalStudents<<endl;
    cout << "Total Students " << Student::totalStudents << endl;
  
}
*/

//Static Function
/*
#include<iostream>
using namespace std;
class Student{
    static int totalStudents;

public:
    int age;
    int rollNo;
    
    Student(){
        totalStudents++;
    }

    int getRollNo(){//By default it's non static. Also it's dependent on object,must not
    //be static
        return rollNo;
    }

    static int getTotalStudents(){//this property belongs to class
        return totalStudents;
    }

};
int Student::totalStudents=0;
int main(){
    Student s1,s2,s3,s4,s5,s6;
    // cout<<"Total Students : "<<Student::totalStudents<<endl;
    cout<<"Total Students : "<<Student::getTotalStudents()<<endl;
    return 0;
}


*/

//OPERATOR OVERLOADING(binary Operator)
// #include<iostream>
// using namespace std;
// class Fraction{
//     int numerator;
//     int denomerator;
//     public:
//     Fraction(int numerator,int denomerator){
//         this->numerator=numerator;
//         this->denomerator=denomerator;
//     }
//     void display(){
//         cout<<numerator<<"/"<<denomerator<<endl;
//     }
//     void simplify(){
//         int GCD=1;
//         int j=min(this->denomerator,this->denomerator);
//         for (int i = 1; i <=j; i++)
//         {
//             if (this->numerator%i==0 && this->denomerator%i==0)
//             {
//                 GCD=i;
//             }
//             this->numerator=this->numerator/GCD;
//             this->denomerator=this->denomerator/GCD;    
//         }
//         cout<<numerator<<"/"<<denomerator<<endl;
       
//         }
//     Fraction add(Fraction const &f2){
//         int LCM=this->denomerator*f2.denomerator;
//         int numer=this->numerator*(LCM/this->denomerator)+f2.numerator*(LCM/f2.denomerator);
        
//        // cout << numerator << "/" << denomerator << endl;
//         Fraction fNew(numer,LCM);
//         return fNew;
//     }
//     //without using add function
//     Fraction operator+ (Fraction const &f2) const{//since no changes in 'this'
//         int LCM=this->denomerator*f2.denomerator;
//         int numer=this->numerator*(LCM/this->denomerator)+f2.numerator*(LCM/f2.denomerator);
        
//        // cout << numerator << "/" << denomerator << endl;
//         Fraction fNew(numer,LCM);
//         return fNew;
//     }
//     Fraction operator*(Fraction const &f2) const  { //since no changes in 'this'
//         int numer=this->numerator*f2.numerator;
//         int deno=this->denomerator*f2.denomerator;
//         Fraction fnew(numer,deno);
//         // fnew.simplify();
//         return fnew;
//     }

//     bool operator==(Fraction const &f2) const{
//         if (this->numerator==f2.numerator && this->denomerator==f2.denomerator)
//         {
//             return true;
//         }
//         return false;

//     }

// };
// int main(){
//     Fraction f1(1,3);
//     Fraction f2(2,2);
//     //f1.add(f2);
    
//     Fraction f4=f1.add(f2);
//     Fraction f3=f1+f2;
//     Fraction f5=f1*f2;
//     //Fraction f6=(f1==f2);

//     f1.display();
//     f2.display();
//     f3.display();
//     f4.display();
//     f5.display();
//     // cout<<(f1==f2)<<endl; //or
//     if (f1==f2)
//     {
//         cout<<"Equal\n";
//     }
//     else{
//         cout<<"Not Equal\n";
//     }
    
    
    
//     return 0;
// }



//Unary Operator Overloading(Pre Increment)

/*
#include<iostream>
using namespace std;
class Fraction{
    public:
    int numerator;
    int denomerator;
    Fraction(int numerator,int denomerator){
        this->numerator=numerator;
        this->denomerator=denomerator;
    }
    void simplify(){
        int GCD=1;
        int j=min(numerator,denomerator);
        for (int i =1; i <=j; i++)
        {
            if (numerator%i==0 && denomerator%i==0)
            {
                GCD=i;
            }
            this->numerator = this->numerator / GCD;
            this->denomerator = this->denomerator / GCD;
        }
        
        
    }
    void print(){
        cout<<numerator<<"/"<<denomerator<<endl;
    }
    //Pre increment
    Fraction& operator++(){//here this=address of f1;no need to pass argument
        numerator=numerator+denomerator;
        // cout<<numerator<<"/"<<denomerator<<endl;
        simplify();//f1.simplify(); 
        return *this;  //returning the whole object
    }

};

int main(){
    Fraction f1(10,2);
    // cout<<"Before : ";
    // f1.print();
    // cout<<"After : ";
    // ++f1;
    // cout<<"After Simplified : ";
    // f1.print();



    // Fraction f2=++f1;
    // f1.print();
    // f2.print();
    Fraction f3=++(++f1);
    f1.print();
    f3.print();

    
    return 0;
}

*/


//Pre decrement
// #include<iostream>
// using namespace std;
// class Fraction{
//     public:
//     int numerator;
//     int denomerator;
//     Fraction(int numerator,int denomerator){
//         this->numerator=numerator;
//         this->denomerator=denomerator;
//     }
//     void simplify(){
//         int LCM=1;
//         int j=min(numerator,denomerator);
//         for (int i = 1; i <=j; i++)
//         {
//             if (numerator%i==0 && denomerator%i==0)
//             {
//                 LCM=i;
//             }
//             numerator=numerator/LCM;
//             denomerator=denomerator/LCM;
//         }
//         cout<<numerator<<"/"<<denomerator<<endl;
        
//     }
    
//     Fraction& operator--(){
//         numerator=numerator-denomerator;
//         simplify();
//         return *this;
//     }

// };
// int main(){
//     Fraction f1(11,2);
//     Fraction f2=--(--(--(--(--(--f1)))));
//     f2.simplify();
//     return 0;
// }




//POST INCREMENR and Post Decremnt
//Nesting is not allowed in post Incremnt/Decrement
/*
#include <iostream>
using namespace std;
class Fraction
{
public:
    int numerator;
    int denomerator;
    Fraction(int numerator, int denomerator)
    {
        this->numerator = numerator;
        this->denomerator = denomerator;
    }
    void simplify()
    {
        int GCD = 1;
        int j = min(numerator, denomerator);
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denomerator % i == 0)
            {
                GCD = i;
            }
            numerator = numerator / LCM;
            denomerator = denomerator / LCM;
        }
        cout << numerator << "/" << denomerator << endl;
    }

    Fraction operator++(int)//post increment
    {
        Fraction fNew(numerator,denomerator);//previous numerator and prevoius denomerator
        numerator=numerator+denomerator;
        simplify();
        fNew.simplify();
        return fNew;
    }
    Fraction operator--(int){
        Fraction fNew(numerator,denomerator);
        numerator=numerator-denomerator;
        cout<<"Prevoius Value : ";
        simplify();
        cout<<"New Updated Value : ";
        fNew.simplify();
        return fNew;
    }
};
int main()
{
    Fraction f1(10, 2);
    Fraction f2=f1--;
    // f1.simplify();
    // f2.simplify();
   
    return 0;
}

*/


//OPEARTOR OVERLOADING of ' +='
//Nesting is allowed in case of integers
// #include<iostream>
// using namespace std; 
// class Fraction{
//     public:
//     int numerator;
//     int denominator;
//     Fraction(int numerator,int denominator){
//         this->numerator=numerator;
//         this->denominator=denominator;

//     }
//     void simplify(){
//         int GCD=1;
//         int j=min(numerator,denominator);
//         for (int i =1; i <=j; i++)
//         {
//             if (numerator%i==0 && denominator%i==0)
//             {
//                 GCD=i;

//             }
//             numerator=numerator/GCD;
//             denominator=denominator/GCD;
            
//         }
//         cout<<numerator<<"/"<<denominator<<endl;
        
//     }
//     // void add(Fraction const &f2){
//     //     int LCM=denominator*f2.denominator;
//     //     int numer=numerator*(LCM/denominator)+f2.numerator*(LCM/f2.denominator);
//     //     numerator=numer;
//     //     denominator=LCM;
//     //     simplify();

//     // }


//     // void operator+= (Fraction const &f2){//Nesting in not allowed here
//     //     int LCM=denominator*f2.denominator;
//     //     int numer=numerator*(LCM/denominator)+(f2.numerator*(LCM/f2.denominator));
//     //     numerator=numer;
//     //     denominator=LCM;
//     //     simplify();
        
//     // }
//     Fraction &operator+=(Fraction const &f2)
//     { // Nesting in not allowed
//         int LCM = denominator * f2.denominator;
//         int x = LCM / denominator;
//         int y = LCM / f2.denominator;
//         int num = x * numerator + y * (f2.numerator);
//         numerator = num;
//         denominator = LCM;
//         simplify();
//         return *this;
//     }
// };
// int main(){
//     // int i=3;
//     // int j=4;
//     // (i+=j)+=j;
//     // cout<<i<<" "<<j<<endl;


//     Fraction f1(11,3);
//     Fraction f2(5,2);
//     (f1+=f2)+=f2;

    
//     // f1.simplify();
//     // f2.simplify();
//     // f3.simplify();
//     // f1.simplify();
    

    
//     return 0;
// }





// //DYNAMIC ARRAY & POLYNOMIAL CLASS
