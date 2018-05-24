/*
---------------------------------------------------------------------------------------------------------------------------------
|	ESME Sudria 2017-2018								CONTASSOT Alexandre														|
|														LAPORTE Nathan															|
|	Modelisation objet									PASTRE Raphael								 							|
|	Interfaces Homme-Machine							Ingé 2C - 1					https://github.com/Sysmetryx/Game-Project	|
|																																|
---------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef SOLDIER_H
#define SOLDIER_H
#include "ant.h"

class Soldier : public Ant
{
public:
    Soldier(QPointF * pos);
    ~Soldier();
    void setPath(QList<QPointF*> path);
    void loopPoints();
};
#endif // SOLDIER_H
