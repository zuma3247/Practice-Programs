//dyad.h

#ifndef DYAD_H
#define DYAD_H

//*****************************************************************************************************

template < typename TYPE >
class Dyad
{
private:
    TYPE val1;
    TYPE val2;

public:
    Dyad ( TYPE value1 = 0, TYPE value2 = 0 );
    ~Dyad ();
    TYPE getFirst () const;
    TYPE getSecond () const;
    void get2Values ( TYPE & value1, TYPE & value2 ) const;
    void swapValues ( TYPE & value1, TYPE & value2 );

};

//*****************************************************************************************************

template < typename TYPE >
Dyad < TYPE > :: Dyad (TYPE value1, TYPE value2)
{
    val1 = value1;
    val2 = value2;
}

//*****************************************************************************************************

template < typename TYPE >
Dyad < TYPE> :: ~Dyad ()
{

}

//*****************************************************************************************************

template < typename TYPE >
TYPE Dyad < TYPE > :: getFirst () const
{
    return val1;
}

//*****************************************************************************************************

template < typename TYPE >
TYPE Dyad < TYPE > :: getSecond () const
{
    return val2;
}

//*****************************************************************************************************

template < typename TYPE >
void Dyad < TYPE > :: get2Values (TYPE & value1, TYPE & value2) const
{
    value1 = val1;
    value2 = val2;
}

//*****************************************************************************************************

template < typename TYPE >
void Dyad < TYPE > :: swapValues ( TYPE & value1, TYPE & value2)
{
    TYPE tempVal;

    tempVal = val1;
    val1 = val2;
    val2 = tempVal;
}

//*****************************************************************************************************

#endif //DYAD_H