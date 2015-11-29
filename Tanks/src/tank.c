#include "tank.h"

Tank *InitTank(){

}

void rotateTank(Tank *t);
void rotateCanon(Tank *t);
void checkBordersCollision(Tank *t);
void checkTankCollision(Tank *t);
void updateTank(Tank *t);
void drawTank(Tank *t);
void deleteTank(Tank *t);

EnemyTank *InitEnemyTank();
void updateEnemyTank(EnemyTank *et);
void rotateEnemyTank(EnemyTank *t);
void checkEnemyTankCollision(EnemyTank *t);
void drawEnemyTank(EnemyTank *et);
void deleteEnemyTank(EnemyTank *et);
