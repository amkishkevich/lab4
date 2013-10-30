#ifndef LIST_H
#define LIST_H

class List
{
public:
   List(const List& l);
    ~List();
    void show();
    void pushFront(int value);
    void pushBack(int value);
    void pushSpis(int value);
    void addElement(List*, int i);
    int removeFront();
    int removeBack();

private:
    class ListIm;
    ListIm *pimpl;
protected:
bool nextDatum(bool first, int &value) const;

};

#endif // LIST_H
