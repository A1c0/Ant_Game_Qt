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
    harvester(){
        this.healthPoints = 50;
        this.moveSpeed = 1;
        this.attackSpeed = 0.5;
        this.cost = 5;
        this.harvestQuantity = 5;
        this.harvestSpeed = 1;
        this.isFull = 0;
    }
    ~harvester();
    void harvest() const;
    //getters :
    float getHarvestSpeed() const{
        return this.harvestSpeed;
    }
    int getHarvestQuantity() const{
        return this.harvestQuantity;
    }
    bool getIsFull() const{
        return this.isFull;
    }
    //Seters
    void setIsFull(bool parameter){
        this.isFull = parameter;
    }
private:
    float const harvestSpeed;
    int const harvestQuantity;
    bool isFull;
};
#endif // HARVESTER_H
