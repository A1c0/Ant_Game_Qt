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
#include "constant.h"

class Ant : public Unit
{
public:
    Ant(QPointF *pos, QString imagePath);
    ~Ant();
private:
};

#endif // ANT_H
