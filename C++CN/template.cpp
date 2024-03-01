/*
#include <iostream>
using namespace std;
template <typename T> // T is a temporary data type
//a class is used for multiple data types with the help of templates
class Pair
{
    T x;
    T y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    T getX()
    {
        return x;
    }
    T getY()
    {
        return y;
    }
};
int main()
{
    // while creating an object we need to specity T ,cuz memory is allocated accoeding to T
    Pair<int> p1;
    Pair<double> p2;
    Pair<char> p3;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << "  " << p1.getY() << endl;

    p2.setX(100.02);
    p2.setY(200.03);
    cout << p2.getX() << "  " << p2.getY() << endl;
    p3.setX('A');
    p3.setY('B');
    cout << p3.getX() << "  " << p3.getY() << endl;
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
template<typename T,typename V> //T & V are different type of data types
class Pair{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    T getX()
    {
        return x;
    }
    V getY()
    {
        return y;
    }
};
int main(){
    Pair<int,char>p;
    p.setX(10.01);
    p.setY('A');
    cout<<p.getX()<<"  "<<p.getY()<<endl;
    
    return 0;
}
*/


// #include<iostream>
// using namespace std;
// template<typename T,typename V,typename S> //T & V are different type of data types
// class Pair{
//     T x;
//     V y;
//     S z;

// public:
//     void setX(T x)
//     {
//         this->x = x;
//     }
//     void setY(V y)
//     {
//         this->y = y;
//     }
//     T getX()
//     {
//         return x;
//     }
//     V getY()
//     {
//         return y;
//     }
//     void setZ(S z)
//     {
//         this->z = z;
//     }
//     T getZ()
//     {
//         return z;
//     }
// };
// int main(){
//     Pair<int,int,int>p;
//     p.setX(1);
//     p.setY(2);
//     p.setZ(3 );
//     cout<<p.getX()<<"  "<<p.getY()<<"  "<<p.getZ()<<endl;
    
//     return 0;
// }

//MAKING TRIPLET
/*
#include<iostream>
using namespace std;
template<typename T,typename V> //T & V are different type of data types
class Pair{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    T getX()
    {
        return x;
    }
    V getY()
    {
        return y;
    }
};
int main(){
    Pair<Pair<int,int> ,int> p;
    p.setY(10);
    Pair<int,int>p1;
    p1.setX(15);
    p1.setY(16);
    p.setX(p1);
    cout<<p.getX().getX()<<" "<<p.getX().getY()<<" "<<p.getY()<<endl;
    
}
*/
#include<iostream>
using namespace std;
template<typename T,typename V> //T & V are different type of data types
class Pair{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(V y)
    {
        this->y = y;
    }
    T getX()
    {
        return x;
    }
    V getY()
    {
        return y;
    }
};
int main(){
    Pair<int,Pair<char,double>  >p;
    p.setX(1);
    Pair<char,double>p1;
    p1.setX('A');
    p1.setY(3.14);
    p.setY(p1);
    cout<<p.getX()<<" "<<p.getY().getX()<<" "<<p.getY().getY()<<endl;

    
    
}