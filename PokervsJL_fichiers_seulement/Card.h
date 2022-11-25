#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <map>

enum Colors { COEUR=67, CARREAU=75, PIQUE=80, TREFLE=84 } ;
enum Values { UN=1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI, AS } ;

class Card
{
    public:
        static std::vector<std::string> StringValues ;
        static std::map<int, std::string> StringColors ;
    public:
        Card(int color, int value);
        virtual ~Card();
        Card(const Card& other);
        Card& operator=(const Card& other);

        friend std::ostream& operator<<(std::ostream& o, const Card& c) ;
        //GETTER POUR AVOIR LES VALEURS DES CARTES
        int Get_value() const { return value_card; }
        int Get_color() const { return color_card; }
        std::string& Get_str() const { return (std::string&)info_card ; }

        bool operator==(const Card& other) const ;
        bool operator<(const Card& other) const ;
        bool operator>(const Card& other) const ;

    protected:
        //SETTER POUR DEFINIR LES VALEURS POUR LE GETTER
        void Set_value(unsigned int value) ;
        void Set_color(unsigned int color) ;
        void _make_string() ;

    private:
        int value_card;
        int color_card;
        std::string info_card ;

};

#else

extern std::vector<std::string> StringValues ;
extern std::map<int, std::string> StringColors ;

#endif // CARD_H
