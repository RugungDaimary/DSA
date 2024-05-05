//Pattern Using Stars(*)


#include<iostream>
using namespace std;
int main(){
   int n;
   cin>>n;
   int row=1;
   while (row<=n) {
       int space=n-row;
       while (space) {
           cout<<"  ";         //        *
           space--;            //      * *
       }                       //    * * *
       int col=1;              //  * * * *
       while (col<=row) {
           cout<<"* ";
           col++;

       }
       cout<<endl;
       row++;
   }

   return 0;
}
//
//

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int star=n-row+1;
//        while (star) {
//            cout<<"* ";  //            * * * *
//            star--;       //           * * *
//                          //           * *
//        }                 //           *
//
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
//}
//



/* still not solved*/

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int space=row-1;
//        while (space) {
//            cout<<"  ";
//            space++;
//
//        }
//        int col=1;
//        while ((col=(n-row+1))) {
//            cout<<"* ";
//            col--;
//
//
//        }
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
//}
//


// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int row=1;
//     while (row<=n) {
//         //print karo space         //                 1
//         int space=n-row;           //               1 2 1
//         while (space) {            //             1 2 3 2 1
//             cout<<"  ";            //           1 2 3 4 3 2 1
//             space--;                //        1 2 3 4 5 4 3 2 1
//         }
//         //print karo 1st triangle
//         int col=1;
//         while (col<=row) {
//             cout<<col<<" ";
//             col++;
//         }
//         //print karo 2nd tringle
//         int start=row-1;
//         while (start) {
//             cout<<start<<" ";
//             start--;
//         }
//          cout<<endl;
//         row++;

//     }

//     return 0;
// }

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int space=n-row;
//        while (space) {          //             1
//            cout<<"  ";          //           2 2
//            space--;              //        3 3 3
//                                 //       4 4 4 4
//        }
//        int col=1;
//        while (col<=row) {
//            cout<<row<<" ";
//            col++;
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
//    while (row<=n) {
//        int col=n-row+1;
//        while (col) {
//            cout<<row;
//            col--;
//
//        }
//        int space=row-1;
//        while (space) {
//            cout<<" ";
//            space++;
//        }
//
//        cout<<endl;
//        row++;
//
//    }
//
//    return 0;
//}
//
