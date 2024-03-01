/*Pattern  using Numbers */

// #include<iostream>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int i=1;
//    while (i<=n) {
//        int j;
//        j=1;
//        while (j<=n) {
//            cout<<"*";
//            j++;
//
//
//        }
//        cout<<endl;
//        i++;
//
//    }
//
//    return 0;
// }



// #include<iostream>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int i=1;
//    while (i<=n) {
//        int j=1;
//        while (j<=n) {
//            cout<<i;
//            j++;
//        }
//        cout<<endl;
//        i++;
//    }
//    return 0;
// }


//
// #include<iostream>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int i=1;
//    while (i<=n) {
//        int j=1;
//        while (j<=n) {
//            cout<<j<<" ";
//            j++;
//        }
//        cout<<endl;
//        i++;
//
//    }
//
//
//    return 0;
// }



//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int count=1;
//    int i=1;
//    while (i<=n) {
//        int j=1;
//        while (j<=n) {
//            cout<<count<<" ";
//            count++;
//            j++;
//        }cout<<endl;
//        i++;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//    int a;
//    for(a=1;a<=3;a++)
//    {
//        cout<<a<<"\t"<<(a+3)<<"\t"<<(a+6)<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int col=1;
//        while (col<=row) {
//            cout<<"*";
//            col++;
//        }
//        cout<<endl;
//        row++;
//
//    }
//
//    return 0;
//}


// #include<iostream>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int col=1;
//        while (col<=row) {
//            cout<<row;
//            col++;
//        }
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
// }


// #include<iostream>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    int count=1;
//    while (row<=n) {
//        int col=1;
//        while (col<=row) {
//            cout<<count<<" ";
//            count++;
//            col++;
//        }
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
// }


//
//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int col=1;
//        int value=row;
//        while (col<=row) {
//            cout<<value<<" ";
//            value++;
//            col++;
//
//        }
//        cout<<endl;
//        row++;
//    }
//    return 0;
//}



//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int row=1;
//    while (row<=n) {
//        int col=1;
//        int value=row;
//        while (col<=row) {
//            cout<<value<<" ";
//            value--;
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
//    while (row<=n) {
//        int col=1;
//        while (col<=row) {
//            cout<<(row-col)+1<<" ";
//            col++;
//        }
//        cout<<endl;
//        row++;
//    }
//
//    return 0;
//}

 #include<iostream>
 using namespace std;
 int main()
 {
     int a,n,c,b;
     cin>>n;
     for(a=1;a<=n;a++)
     {
         c=a;
         for(b=1;b<=n;b++)
         {
             cout<<c<<"\t";
             c+=3;
            
         }
         cout<<endl;
     }
     return 0;

 }

