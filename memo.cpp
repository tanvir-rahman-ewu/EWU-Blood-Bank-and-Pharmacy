#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<string> s;
    vector<int> price;
    vector<int> piece;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        s.push_back(a);
        int x;
        cin>>x;
        price.push_back(x);
        int y;
        cin>>y;
        piece.push_back(y);
    }
    cout<<right<<setw(45)<<"East  West  Pharmacy"<<endl;
    cout<<right<<setw(43)<<"Aftab Nagar,Dhaka"<<endl;
    cout<<"\t......................................................"<<endl;
    cout<<right<<setw(15)<<"Name"<<setw(23)<<"Quantity"<<setw(20)<<"Price"<<endl;
    cout<<"\t......................................................"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"         "<<i+1<<"."<<left<<setw(15)<<s[i]<<right<<setw(9)<<price[i]<<right<<setw(21)<<piece[i]<<"/="<<endl;
    }
    cout<<"\t......................................................"<<endl;
    cout<<"         "<<"total price: ";

}
