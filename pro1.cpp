#include<bits/stdc++.h>
using namespace std;

//////////////start page/display//////////

void start_page()
{
    cout<<endl;
    cout<<right<<setw(50)<<"EWU Blood Bank & Pharmacy"<<endl;
}
void start_page2()
{
    cout<<".........................................................................."<<endl;;
    cout<<endl<<" 1 . Blood Bank"<<endl<<" 2 . Pharmacy"<<endl<<" 3 . Exit"<<endl<<endl;
    cout<<".........................................................................."<<endl;;
}
void pharmacy_start_page()
{
    cout<<endl;
    cout<<".........................................................................."<<endl;;
    cout<<right<<setw(30)<<"Pharmacy"<<endl;
     cout<<"........................................................................."<<endl;;
    cout<<" 1 . Search Medicine"<<endl
        <<" 2 . All Medicine"<<endl
        <<" 3 . Add Medicine"<<endl
        <<" 4 . Delete Medicine"<<endl
        <<" 5 . Update Price"<<endl
        <<" 6 . Sell Medicine"<<endl<<endl
        <<" Press 0 for back to main menu"<<endl;
    cout<<"..........................................................................."<<endl;;
}

////////////////////////////////////////////////

///////////////////Pharmacy/////////////////////

struct node
{
    string s;
    int price;
    int piece;
    node *next;
    node *prev;
};
node *head,*temp;
int m_s=0;
void insert(string s,int price,int piece)
{
    node *n=new node;
    n->s=s;
    n->price=price;
    n->piece=piece;
    n->next=NULL;
    n->prev=NULL;
    if(head==NULL)
    {
        head=n;
        temp=n;
    }
    else
    {
        if(s<=head->s)
        {
            temp=n;
            n->next=head;
            head->prev=n;
            head=n;

        }
        else if(s>=temp->s)
        {
            node *temp1;
            while(s>temp->s && temp->next!=NULL)
            {
                temp=temp->next;
            }
            if(temp->next==NULL && s>temp->s)
            {
                temp->next=n;
                n->prev=temp;
                temp=temp->next;
            }
            else
            {
                temp1=temp->prev;
                temp1->next=n;
                n->prev=temp1;
                n->next=temp;
                temp->prev=n;
                temp=n;
            }
        }
        else
        {
            node *temp2;
            while(s<temp->s)
            {
                temp=temp->prev;
            }
            temp2=temp->next;
            temp->next=n;
            n->prev=temp;
            n->next=temp2;
            temp2->prev=n;
            temp=n;
        }
    }
    m_s++;
}
void display()
{
    node *t=head;
    int c=1;
    while(t)
    {
        cout<<endl<<c<<". Name : "<<t->s<<endl<<"   Price : "<<t->price<<" /="<<endl<<"   Pieces : "<<t->piece<<endl;
        t=t->next;
        c++;
    }
}

void search_medicine(string name)
{
    node *t=head;
    while(t)
    {
        if(t->s==name)
        {
            cout<<endl<<"Yes Availabe"<<endl;
            cout<<endl<<"Name : "<<t->s<<endl<<"Price : "<<t->price<<endl<<"Pieces : "<<t->piece<<endl;
            return;
        }
        else
        {
             t=t->next;
        }
    }
    cout<<endl<<"Not Available"<<endl;
}
int search_medicine_1(string name)
{
    node *t=head;
    while(t)
    {
        if(t->s==name)
        {
            return 1;
        }
        else
        {
             t=t->next;
        }
    }
    return 0;
}

void delete_medicine(string name)
{
    if(head->s==name)
    {
        node *temp=head;
        head=head->next;
        free(temp);
    }
    else
    {
        node *temp=head;
        while(temp->s!=name)
        {
            temp=temp->next;
        }
        node *temp1,*temp2;
        temp1=temp->prev;
        if(temp->next==NULL)
        {
            free(temp);
            temp1->next=NULL;
        }
        else
        {
            temp2=temp->next;
            temp1->next=temp2;
            temp2->prev=temp1;
            free(temp);
        }
    }
    m_s--;
}
void update_price(string name,int price)
{
    node *temp=head;
    while(temp->s!=name)
    {
        temp=temp->next;
    }
    temp->price=price;
}
void update_piece(string name,int piece)
{
    node *temp=head;
    while(temp->s!=name)
    {
        temp=temp->next;
    }
    temp->piece=temp->piece-piece;
}
int check_quantity(string name,int q)
{
    node *temp=head;
    while(temp->s!=name)
    {
        temp=temp->next;
    }
    if(temp->piece>=q)
    {
        return temp->price;
    }
    return 0;
}
/////////////////////////node_sell//////////
struct node_sell
{
    string name;
    int sell_price;
    int sell_quantity;

};
/////////////////////pharmacy/////////////////////////

int main()
{
    head=NULL;
    char c;
    string name;
    int price,piece,t;
    start_page();
    vector<node_sell> v;
    while(1)
    {
        start_page2();
        cout<<endl<<"Enter Choice : ";
        cin>>c;
        getchar();
        if(c=='1')
        {

        }
        else if(c=='2')
        {
            while(1)
            {
                 pharmacy_start_page();
                 cout<<endl<<"Enter Choice : ";
                 cin>>c;
                 getchar();
                 if(c=='1')
                 {
                    cout<<endl<<"Eneter Name : ";
                    getline(cin,name);
                    search_medicine(name);
                 }
                 else if(c=='2')
                 {
                     display();
                 }
                 else if(c=='3')
                 {
                     cout<<endl<<"Enter Name : ";
                     getline(cin,name);
                     cout<<"Enter Price : ";
                     cin>>price;
                     cout<<"Enter Piece : ";
                     cin>>piece;
                     insert(name,price,piece);
                 }
                 else if(c=='4')
                 {
                     cout<<endl<<"Enter Name :";
                     getline(cin,name);
                     if(search_medicine_1(name))
                     {
                         delete_medicine(name);
                         cout<<endl<<"Deleted"<<endl;
                     }
                     else
                     {
                         cout<<endl<<"Not stored"<<endl;
                     }

                 }
                 else if(c=='5')
                 {
                     cout<<endl<<"Enter Name :";
                     getline(cin,name);
                     if(search_medicine_1(name))
                     {
                         cout<<"Enter new price : ";
                         cin>>price;
                         update_price(name,price);
                     }
                     else
                     {
                         cout<<endl<<"Not stored"<<endl;
                     }

                 }
                 else if(c=='6')
                 {
                     t=0;
                     while(1)
                     {
                         cout<<endl<<"Enter Name :";
                         getline(cin,name);
                         if(search_medicine_1(name))
                         {
                             cout<<endl<<"Enter quantity : ";
                             cin>>piece;
                             getchar();
                             if(check_quantity(name,piece))
                             {
                                 t++;
                                 node_sell z;
                                 z.sell_price=check_quantity(name,piece);
                                 z.sell_quantity=piece;
                                 z.name=name;
                                 v.push_back(z);
                                 update_piece(name,piece);
                                 cout<<"Sell More ? (y/n) :";
                                 cin>>c;
                                 getchar();
                                 if(c=='y' || c=='Y')
                                 {
                                     continue;
                                 }
                                 else
                                 {
                                     break;
                                 }
                             }
                             else
                             {
                                 cout<<endl<<"Insufficient"<<endl<<endl;
                                 cout<<"Sell More ? (y/n) :";
                                 cin>>c;
                                 getchar();
                                 if(c=='y' || c=='Y')
                                 {
                                     continue;
                                 }
                                 else
                                 {
                                     break;
                                 }
                            }
                         }
                         else
                         {
                             cout<<endl<<"Not stored"<<endl;
                             cout<<"Sell More ? (y/n) :";
                                 cin>>c;
                                 getchar();
                                 if(c=='y' || c=='Y')
                                 {
                                     continue;
                                 }
                                 else
                                 {
                                     break;
                                 }
                         }
                     }
                     if(t!=0)
                     {
                         cout<<endl<<"Enter P for printing memo : ";
                         cin>>c;
                         int total=0;
                         if(c=='p' || c=='P')
                         {

                                 cout<<endl<<endl;
                                 cout<<right<<setw(45)<<"East  West  Pharmacy"<<endl;
                                 cout<<right<<setw(43)<<"Aftab Nagar,Dhaka"<<endl;
                                 cout<<"\t......................................................"<<endl;
                                 cout<<right<<setw(15)<<"Name"<<setw(23)<<"Quantity"<<setw(20)<<"Price"<<endl;
                                 cout<<"\t......................................................"<<endl;

                                 for(int i=0;i<v.size();i++)
                                 {
                                     cout<<"         "<<i+1<<"."<<left<<setw(15)<<v[i].name<<right<<setw(9)<<v[i].sell_quantity<<right<<setw(21)<<v[i].sell_price*v[i].sell_quantity<<"/="<<endl;
                                     total=total+v[i].sell_price*v[i].sell_quantity;
                                 }
                                 cout<<"\t......................................................"<<endl;
                                 cout<<"         "<<"total price: "<<right<<setw(34)<<total<<"/=";

                             cout<<endl<<endl;
                         }
                         else
                         {
                             continue;
                         }
                         v.clear();
                     }
                 }
                 else if(c=='0')
                 {
                     break;
                 }
                 else
                 {
                     cout<<endl<<"Wrong Input"<<endl<<endl;
                     continue;
                 }
            }
        }
        else if(c=='3')
        {
            cout<<endl<<"|| Thank You ||"<<endl;
            exit(1);
        }
        else
        {
            cout<<endl<<"Wrong Input"<<endl<<endl;
            continue;
        }
    }
    return 0;
}
