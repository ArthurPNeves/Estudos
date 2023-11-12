#include <iostream>

using namespace std;

#include "intCell.hpp"

int main ()
{
    intCell *a1 = new intCell ( 1 );
    intCell *b1 = new intCell ( 2 );
    int x = 3;
    cout<< "\nTeste1\n";
    a1->print();
    cout<<endl;
    a1->conect(b1);

    cout<< "\nTeste2\n";
    a1->print();
    cout<<endl;
    while (x < 8)
    {
       a1->pushBack( new intCell ( x ));
       a1->print();
       cout<<endl;
        x++;
    }

    
    cout<< "\nTeste3\n";

    int y = 0;
    while (y < 6)
    {

        cout << endl << a1->popBack()->getvalue() << endl;
        a1->print();
       cout<<endl;
       y++;
    }

    cout<< "\nTeste4\n";
        x = 2;
        while (x <= 8)
    {
       a1->pushBack( new intCell ( x ));
       a1->print();
       cout<<endl;
        x++;
    }

    cout<< "\nTeste5\n";
    x = 0 ;
    while (x > -9)
    {
        a1->push_front(x);
        a1->print();
        cout<<endl;
        x--;
    }

    cout<< "\nTeste6\n";
    
    x = 0;
    while (x <=8)
    {
        cout << endl << a1->Popfront()->getvalue() << endl;
        a1->print();
        cout<<endl;
        x++;
    }
    


    cout<< "\nTeste7\n";

    return(0);
}