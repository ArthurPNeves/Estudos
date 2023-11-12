#include "io.hpp"
class intCell
{
    protected:
    int value;
    intCell *link;
    public:

    intCell(){
        this->setvalue( 0 );
        this->setlink  ( nullptr );
    }

    intCell(int value){
        this->setvalue( value );
        this->setlink  ( nullptr );
    }

    intCell(int value, intCell *new_link){
        this->setvalue( value );
        this->setlink  ( new_link );
    }

    ~ intCell()
    {

    }

    void setvalue(int value)
    {
        this->value = value;
    }
    void setlink(intCell *New_Link)
    {
        this->link = New_Link;
    }

    int getvalue()
    {   

        if (this)
        {
            return(this->value);
        } 
    }

    intCell* getlink()
    {
        if (this->link != nullptr)
        {
            return(this->link);
        }
        
    }

    void print()
    {
        intCell *cursor = this;
        while (cursor)
        {
        std::cout<<" "<< cursor->value<< " ";
        cursor = cursor->link;
        }
    }

    int getlength(){
        intCell *cursor = this;
        int length = 0;
        while (cursor)
        {
        length++;
        cursor = cursor->link;
        }
        return(length);
    }

    void conect(intCell *second)
    {
        if (this)
        {
            this->link = second;
        }
    }

    void disconect( intCell *second)
    {
        if (this->link == second)
        {
            this->link = nullptr;
        }
    }

    void pushBack(intCell *novaCelula)
    {
        intCell *cursor = this;
        while (cursor->link)
        {
        
        cursor = cursor->link;
        }
        cursor->link = novaCelula;
    }

    intCell* popBack()
    {
        intCell *cursor = this;
        intCell *back = nullptr;
        while (cursor->link)
        {
        cursor = cursor->link;
        }
        back = cursor;
        cursor = this;
        while (cursor->link != back)
        {
            cursor = cursor->link;
        }
        
        if (cursor != back)
        {
            cursor->disconect(back);
        }
        
    return(back);
    }


        void push_front ( int new_Value )
    {
         intCell *tmp = new intCell ( this->getvalue(), this->getlink()  );
         if ( tmp )
         {
            this->setvalue ( new_Value );
            this->setlink  ( tmp );
         } 
    }


    intCell* Popfront()
    {
        intCell *temp = new intCell (this->getvalue());
        intCell *garbage = this->link;
        if(garbage)
        {
            this->value = (garbage->value);
            this->link = (garbage->link);
        }
        return(temp);
        delete(garbage);

    }
};
