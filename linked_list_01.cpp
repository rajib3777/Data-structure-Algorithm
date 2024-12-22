#include<bits/stdc++.h>
using namespace std;

int main()
{
void fun(int *p){
*p = 20;
}

int main(){
int val = 10;
int *ptr = &val;
fun(ptr);
cout << *ptr << endl;
return 0;
}
}