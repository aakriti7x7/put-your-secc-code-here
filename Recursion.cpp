#include<iostream>
using namespace std;
int fact(int n);

int sum(int n)  //for sum
{
    if(n<1){                                  
        return 0;
    }
    else{
        return n + sum(n-1);
    }
}

/* int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}*/

int main()
{
    int n;
    cout<<"enter n \n";
    cin>>n;
    cout<< "sum of first " <<n<<" numbers is "<< sum(n)<<endl;
    cout<<"Factorial will be "<<fact(n);
}

//for factorial
int fact(int n)
{
    if (n <= 1) // base case
        return 1;
    else    
        return n*fact(n-1);    
}
