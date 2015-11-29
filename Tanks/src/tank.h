#ifndef __TANK_H
#define __TANK_H

#include <minix/syslib.h>
#include <minix/drivers.h>
#include <stdio.h>
#include "bitmap.h"
#include "stdbool.h"

//***************************************Tank struct**************************************************//

typedef struct{
	int x_coord;
	int y_coord;
	int orientation;
	double velocity;
	Bitmap *bmap;
	int lifes;
} Tank;

Tank *InitTank();
void rotateTank(Tank *t);
void rotateCanon(Tank *t);
void checkBordersCollision(Tank *t);
void checkTankCollision(Tank *t);
void moveTank(Tank *t);
void updateTank(Tank *t);
void drawTank(Tank *t);
void deleteTank(Tank *t);


//*********************************Enemy Tank struct**************************************************//

typedef struct {
	int x_coord;
	int y_coord;
	int orientation;
	double velocity;
	Bitmap *bmap;
	int spawnTime;
} EnemyTank;

EnemyTank *InitEnemyTank();
void updateEnemyTank(EnemyTank *et);
void rotateEnemyTank(EnemyTank *et);
void checkEnemyTankCollision(EnemyTank *et);
void drawEnemyTank(EnemyTank *et);
void deleteEnemyTank(EnemyTank *et);

#endif
