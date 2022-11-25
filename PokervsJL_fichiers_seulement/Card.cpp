#include <stdexcept>
#include "Card.h"

Card::Card(int color, int value)
{
    Set_color(color) ;
    Set_value(value) ;
    _make_string() ;
}

Card::~Card()
{
    //DTOR
}

Card::Card(const Card& other)
{
    //COPY CTOR CAR ON PEUT APPELER LE CONSTRUCTEUR DIFFEREMENT
    Set_color(other.Get_color()) ;
    Set_value(other.Get_value()) ;
    _make_string() ;
}

Card& Card::operator=(const Card& rhs)
{
    if (this == &rhs) return *this;
    Set_color(rhs.Get_color()) ;
    Set_value(rhs.Get_value()) ;
    _make_string() ;
    return *this;
}

void Card::Set_value(unsigned int value)
{
    if( value < UN || value > AS)
    {
        throw std::invalid_argument("Value is a bad argument ") ;
    }

    value_card = value;
}

void Card::Set_color(unsigned int color)
{
    if( color != PIQUE && color != TREFLE && color != COEUR && color != CARREAU)
    {
        throw std::invalid_argument("Color is a bad argument ") ;
    }

    color_card = color;
}

bool Card::operator==(const Card& other) const
{
   return Get_value() == other.Get_value() ;
}
bool Card::operator<(const Card& other) const
{
   return Get_value() < other.Get_value() ;
}

bool Card::operator>(const Card& other) const
{
   return Get_value() > other.Get_value() ;
}

std::ostream& operator<<(std::ostream& o, const Card& c)
{
    o << "(" << (char)c.Get_color() << ", " << c.Get_value() << ")" ;
    return o ;
}

void Card::_make_string()
{
    info_card = '(' + Card::StringColors[Get_color()] + ", " + Card::StringValues[Get_value()] + ')' ;
}

std::vector<std::string> Card::StringValues = { "None", "1", "2", "3", "4", "5", "6", "7", "8", "9","10", "VALET", "DAME", "ROI", "AS" } ;
std::map<int, std::string> Card::StringColors =  { { CARREAU, "CARREAU" }, {COEUR, "COEUR"} , {TREFLE, "TREFLE"}, {PIQUE, "PIQUE"} } ;
