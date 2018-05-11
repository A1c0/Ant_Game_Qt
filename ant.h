/*
---------------------------------------------------------------------------------------------------------------------------------
|	ESME Sudria 2017-2018								CONTASSOT Alexandre														|
|														LAPORTE Nathan															|
|	Modelisation objet									PASTRE Raphael								 							|
|	Interfaces Homme-Machine							Ingé 2C - 1					https://github.com/Sysmetryx/Game-Project	|
|																																|
---------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef ANT_H
#define ANT_H
#include "unit.h"

class Ant : public Unit
{
public:
    Ant(Point *pos);
    ~Ant();
private:
    //bool const owner = 0; //owner represents the controller of the unit (either 0 for player or 1 for the CPU) --> Innutile car Ant ne sera que allié
    int const cost = 200; //Cost in food of the unit.
    bool selected = false;
};

#endif // ANT_H
