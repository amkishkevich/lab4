#include <iostream>
#include <cstdlib>
#include "list.cpp"
using namespace std;

class ConsoleList: public List{

   public:
    void output (ostream &out) const;
};

ostream &operator<<(ostream &out,const ConsoleList &list)
{
    list.output(out);
    return out;
}

void ConsoleList::output(ostream &out) const
{
    int value;
    if (nextDatum(true, value))
        out<<value<<" ";
    while (nextDatum(false, value))
        out<<value<<" ";
}
int main()
{
    int t,p,k;
    ConsoleList list, list_t;
    cout<<"vvedi kol-vo elementov dlia vstavki v konec"<<endl;
    cin>>t;
    cout<<"vvedi elementi dlia vstavki v konec"<<endl ;
    while(t)
    {
        cin>>p;
        list.pushSpis(p);
        t--;
    }
    cout<<list<<endl;
    cout<<"vvedi kol-vo elementov dlia vstavki v nacalo"<<endl;
    cin>>t;
    cout<<"vvedi elementi dlia vstavki v nacalo"<<endl;
    while(t)
    {
        cin>>p;
        list.pushFront(p);
        t--;
    }
    cout<<list<<endl;
    cout<<"vvedi kol-vo elementov dlia vstavki pered indexom"<<endl;
    cin>>t;
    cout<<"vvedi index"<<endl;
    cin>>k;
    cout<<"vvedi element"<<endl;
    while(t)
    {
        cin>>p;
        list_t.pushSpis(p);

        t--;
    }
    cout<<list_t<<endl;
    list.addElement(&list_t ,k);
    cout<<list<<endl;
    cout<<"vvedite kol-voelementov dlia udalenie iz nacala"<<endl;
    cin>>t;
    while(t)
    {
        list.removeFront();
        t--;
    }
    cout<<list<<endl;
    cout<<"vvedite kol-voelementov dlia udalenie iz konca"<<endl;
    cin>>t;
    while(t)
    {
        list.removeBack();
        t--;
    }
    cout<<list<<endl;
system("pause");
return 0;
}


