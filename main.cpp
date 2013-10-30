#include <iostream.h>
#include "list.cpp"

class ConsoleList: public List{

   public:
    void output (ostream &out) const;
      ConsoleListList();
      ConsoleListList(const NewList &original);
      ~ConsoleListList();


};

ConsoleList::ConsoleList():
   List()
{

}

ConsoleList::ConsoleList(const ConsoleList &l):
   List()
{

}

ConsoleList::~ConsoleList()
{

}


void ConsoleList::output(ostream &out) const
{
    int datum;
    if (nextDatum(true, datum))
        out<<datum<<" ";
    while (nextDatum(false, datum))
        out<<datum<<" ";
}
int main()
{
    int t,p,k;
    NewList list, list_t;
    cout<<"vvedi kol-vo elementov dlia vstavki v konec"<<endl;
    cin>>t;
    cout<<"vvedi elementi dlia vstavki v konec"<<endl ;
    while(t)
    {
        cin>>p;
        list.pushSpis()(p);
        t--;
    }
    list.show();
    cout<<"vvedi kol-vo elementov dlia vstavki v nacalo"<<endl;
    cin>>t;
    cout<<"vvedi elementi dlia vstavki v nacalo"<<endl;
    while(t)
    {
        cin>>p;
        list.pushFront(p);
        t--;
    }
    list.show();
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
    list_t.show();
    list.addElement(&list_t ,k);
    list.show();
    cout<<"vvedite kol-voelementov dlia udalenie iz nacala"<<endl;
    cin>>t;
    while(t)
    {
        list.removeFront();
        t--;
    }
    list.show();
    cout<<"vvedite kol-voelementov dlia udalenie pered indexom"<<endl;
    cin>>t;
    cout<<"vvedi index"<<endl;
    while(t)
    {
        cin>>k;
        list.removeElement(k);
        t--;
    }
    list.show();
    cout<<"vvedite kol-voelementov dlia udalenie iz konca"<<endl;
    cin>>t;
    while(t)
    {
        list.removeBack();
        t--;
    }
    list.show();
    system("pause");
}


