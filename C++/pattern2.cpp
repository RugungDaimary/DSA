/*Pattern Using characters */

//#include<iostream>
//using namespace std;
//int main(){
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//    int a,n,c,b;
//    cin>>n;
//    for(a=1;a<=n;a++)
//    {
//        c=a;
//        for(b=1;b<=n;b++)
//        {
//            cout<<c<<"\t";
//            c+=3;
//
//        }
//        cout<<endl;
//    }
//
//
//    return 0;
//
//}
//

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//
//    int row=1;
//    while (row<=n) {
//        int col=1;
//        while (col<=n) {
//            char ch='A'+row-1;
//            cout<<ch<<" ";
//            col++;
//        }cout<<endl;
//        row++;
//    }
//
//    return 0;
//}
//


//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int col=1;
//        while (col<=n) {
//            char ch='A'+col-1;
//            cout<<ch<<" ";
//            col++;
//        }
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    char ch='A';
//    while (row<=n) {          // A B C
//        int col=1;            // D E F
//        while (col<=n) {      // G H I
//
//
//            cout<<ch<<" ";
//            ch++;
//            col++;
//        }
//        cout<<endl;
//        row++;
//    }
//    return 0;
//}
//


//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int col=1;                   // A B C
//        while (col<=n) {             // B C D
//            char ch='A'+row+col-2;   // C D E
//            cout<<ch<<" ";
//            col++;
//
//        }
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
//}
//

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    char value='A';
//    while (row<=n) {
//        int col=1;              // A
//        while (col<=row) {      // B C
//            cout<<value<<" ";   // C D E
//            value++;            // F G H I
//            col++;
//        }
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
//}
//

#include<iostream>
using namespace std;
int main(){
   int n;
   cin>>n;
   int row=1;
       while (row<=n) {         // D
       int col=1;               // C D
       char ch='A'+n-row;       // B C D
       while (col<=row) {       // A B C D
           cout<<ch<<" ";
           ch++;

           col++;
       }
       cout<<endl;
       row++;
   }


   return 0;
}



