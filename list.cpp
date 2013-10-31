#include "list.h"

struct ListItem
{
    int value;
    ListItem* next;
    ListItem* previous;
};

class List::ListIm
{

public:
    ListIm(): head(0), tail(0) {}
    ListIm(const ListIm& l);
    ~ListIm();
    void pushFront(int value);
    void pushBack(int value);
    void pushSpis(int value);
    void addElement(ListIm*pushSpis, int index);
    int removeFront();
    int removeBack();
    bool nextDatum(bool first, int &datum) const;
private:
    ListItem* head;
    ListItem* tail;
};

List::List() : pimpl(0)
{
	pimpl = new ListIm;
}

List::~List()
{
    delete pimpl;
    pimpl=0;
}

void List::pushFront(int value)
{
  return pimpl->pushFront(value);
}
void List::pushBack(int value)
{
    return pimpl->pushBack(value);
}
void List::pushSpis(int value)
{
    return pimpl->pushSpis(value);
}
void List::addElement(List *pushSpis, int index)
{
    return pimpl->addElement(pushSpis->pimpl,index);
}
int List::removeFront()
{
   return pimpl->removeFront();
}
int List::removeBack()
{
    return pimpl->removeBack();
}


List::List(const List& l):pimpl(0)
{
    pimpl = new ListIm(*(l.pimpl));


}

bool List::nextDatum(bool first, int &datum) const
{
    return pimpl->nextDatum(first, datum);
}
void List::ListIm::pushFront(int value)
{
    ListItem* curentItem = new ListItem;
    curentItem->value = value;
    curentItem->previous = 0;
    curentItem->next = head;
    if(head)
        head->previous = curentItem;
    else
        tail = curentItem;
    head = curentItem;
}

void List::ListIm::pushBack(int value)
{
    ListItem* curentItem = new ListItem;
    curentItem->value = value;
    curentItem->previous = tail;
    curentItem->next = 0;
    if(tail)
        tail->next = curentItem;
    else
        head = curentItem;
    tail = curentItem;
}
void List::ListIm::pushSpis(int value)
{
    ListItem* curentItem = new ListItem;
    curentItem->value = value;
    curentItem->previous = tail;
    curentItem->next = 0;
    if(tail)
        tail->next = curentItem;
    else
        head = curentItem;
    tail = curentItem;
}
void List::ListIm::addElement(ListIm *pushSpis, int index)
{
    {
        ListItem* curentItem=head;
        for(int i=0;i<index;++i)
        curentItem=curentItem->next;


        ListItem* replasedPosition = curentItem->previous;

        replasedPosition->next= pushSpis->head;
            pushSpis->head->previous=replasedPosition;
            pushSpis->tail->next=curentItem;
            curentItem->previous=pushSpis->tail;

      }
}

int List::ListIm::removeFront()
{
    if(head)
    {
        int value = head->value;
        ListItem* itemToRemove = head;
        if(head->next)
            head->next->previous = 0;
        else
            tail = 0;
        head = head->next;
        delete itemToRemove;
        return value;
    }
return 0;
}
int List::ListIm::removeBack()
{
    if(tail)
    {
        int value = tail->value;
        ListItem* itemToRemove = tail;
        if(tail->previous)
            tail->previous->next = 0;
        else
            head = 0;
        tail = tail->previous;
        delete itemToRemove;
        return value;
    }
return 0;
}

List::ListIm::ListIm(const ListIm& A):head(0), tail(0)
{
    ListItem* m = A.head;
    while(m)
    {
        pushBack(m->value);
        m = m->next;
    }
}
List::ListIm::~ListIm()
{
    ListItem* m;
    while(head)
    {
        m = head;
        head = head->next;
        delete m;
    }
    head = tail = 0;
}

bool List::ListIm::nextDatum(bool first, int &value) const
{
    static ListItem *cur;
    if (first)
        cur=head;

    bool result=cur!=0;
    if (result)
    {
        value=cur->value;
        cur=cur->next;
    }
    return result;
}

