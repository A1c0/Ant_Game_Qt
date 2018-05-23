/*
---------------------------------------------------------------------------------------------------------------------------------
|	ESME Sudria 2017-2018								CONTASSOT Alexandre														|
|														LAPORTE Nathan															|
|	Modelisation objet									PASTRE Raphael								 							|
|	Interfaces Homme-Machine							Ingé 2C - 1					https://github.com/Sysmetryx/Game-Project	|
|																																|
---------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef HARVESTER_H
#define HARVESTER_H
#include "ant.h"

class Harvester : public Ant
{
public:
    Harvester(QPointF * pos);
    ~Harvester();
    void harvest();
    void loopPoints();
    void setCanHarvest(bool condition);
    bool getBringBack();
    void setBringBack(bool condition);
    bool getIsHarvester();
private:
    int harvestTime;
};
#endif // HARVESTER_H
