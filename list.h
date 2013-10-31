#ifndef LIST_H
#define LIST_H

class List
{
	class ListIm;
    ListIm *pimpl;
public:
    List();
   List(const List& l);
    ~List();
    void pushFront(int value);
    void pushBack(int value);
    void pushSpis(int value);
    void addElement(List*, int i);
    int removeFront();
    int removeBack();
protected:
	bool nextDatum(bool first, int &value) const;
};


#endif // LIST_H
