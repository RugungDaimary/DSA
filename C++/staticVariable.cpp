// STATIC VARIABLE
/*Static variables have a property of preserving their value even after they are out of their scope!
 Hence, static variables preserve their previous value in their previous scope and are not initialized
 again in the new scope. */




// #include <iostream>
// using namespace std;
// int a;

// int main()
// {

//     // Static variables should not be declared inside structure
//     cout << "Value of a is " << a << endl;
//     static int x; // static variable is always intialized with 0 (if not 
////initialized explixitly)like global variable
//     cout << "The value of x is : " << x << endl;
//     int y;
//     cout << "The value of y is : " << y << endl;//will print some garbage value

//     return 0;
// }

/*1) A static int variable remains in memory while the program is running. 
A normal or auto variable is destroyed when a function call where the variable
was declared is over.For example, we can use static int to count a number of 
times a function is called, but an auto variable can’t be used for this purpose.
For example below program prints “1 2” */
// #include <iostream>
// using namespace std;
// int fun()
// {
//     static int count = 0;
//     count++;

//     return count;
// }

// int main()
// {
//     int ans=fun();//first function call
//     cout<<"Count : "<<ans<<endl;
//     int A=fun();//second function call
//     cout<<"Count : "<<A<<endl;

//     return 0;
// }


// But below program prints 1 1

#include <iostream>
using namespace std;
int fun()
{
    int count = 0;
    count++;

    return count;
}

int main()
{
    int ans = fun(); // first function call
    cout << "Count : " << ans << endl;
    int A = fun(); // second function call
    cout << "Count : " << A << endl;

    return 0;
}