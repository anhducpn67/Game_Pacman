#include "creatWallandPoint.h"
#include "externVariables.h"
#include "Motion_Collision.h"

int x1= 16, x2= 72, x3= 143, x4= 157, x5= 214, x6= 243, x7= 300, x8= 313, x9= 328, x10= 362, x11= 385, x0= 400;
int y2= 74, y3= 130, y4= 187, y5= 215, y6= 273, y7= 286, y8= 300, y9= 357, y10= 369, y11= 386, y12= 442;
int y13= 458, y14= 472, y15= 527, y16= 541, y17= 556, y18= 612, y19= 640, y20= 697, y21= 726, y22= 782, y23= 812, y24= 867;
SDL_Rect point, cherry;
int pointX[30][30], pointY[30][30];
int cherryX[5], cherryY[5];
int Score = 20;
bool isEateanPoint[30][30];

SDL_Rect walls[NUMBER_WALLS];

void createWalls() {
    walls[1].x = 0;
    walls[1].y = 0;
    walls[1].w = 800;
    walls[1].h = 17;
    walls[2].x = 0;
    walls[2].y = 0;
    walls[2].w = x1;
    walls[2].h = y7;
    walls[3].x = x2;
    walls[3].y = y2;
    walls[3].w = x4 - x2;
    walls[3].h = y3 - y2;
    walls[4].x = x5;
    walls[4].y = y2;
    walls[4].w = x9 - x5;
    walls[4].h = y3 - y2;
    walls[5].x = x11;
    walls[5].y = 0;
    walls[5].w = 800 - x11 - x11;
    walls[5].h = y3;
    walls[6].x = 800 - x9;
    walls[6].y = y2;
    walls[6].w = x9 - x5;
    walls[6].h = y3 - y2;
    walls[7].x = 800 - x4;
    walls[7].y = y2;
    walls[7].w = x4 - x2;
    walls[7].h = y3 - y2;
    walls[8].x = 800 - x1;
    walls[8].y = 0;
    walls[8].w = x1;
    walls[8].h = y7;
    walls[9].x = 800 - x4;
    walls[9].y = y4;
    walls[9].w = x4 - x2;
    walls[9].h = y5 - y4;

    walls[10].x = 800 - x6;
    walls[10].y = y4;
    walls[10].w = x6 - x5;
    walls[10].h = y11 - y4;
    walls[11].x = x7;
    walls[11].y = y4;
    walls[11].w = 800 - x7 - x7;
    walls[11].h = y5 - y4;
    walls[12].x = x5;
    walls[12].y = y4;
    walls[12].w = x6 - x5;
    walls[12].h = y11 - y4;
    walls[13].x = x2;
    walls[13].y = y4;
    walls[13].w = x4 - x2;
    walls[13].h = y5 - y4;
    walls[14].x = 0;
    walls[14].y = y6;
    walls[14].w = x4;
    walls[14].h = y11 - y6;
    walls[15].x = x5;
    walls[15].y = y6;
    walls[15].w = x9 - x5;
    walls[15].h = y8 - y6;
    walls[16].x = x11;
    walls[16].y = y4;
    walls[16].w = 800 - x11 - x11;
    walls[16].h = y8 - y4;
    walls[17].x = 800 - x9;
    walls[17].y = y6;
    walls[17].w = x9 - x5;
    walls[17].h = y8 - y6;
    walls[18].x = 800 - x4;
    walls[18].y = y6;
    walls[18].w = x4;
    walls[18].h = y7 - y6;
    walls[19].x = 800 - x4;
    walls[19].y = y6;
    walls[19].w = x4 - x3;
    walls[19].h = y11 - y6;

    walls[20].x = 800 - x10;
    walls[20].y = y9;
    walls[20].w = x10 - x7;
    walls[20].h = y10 - y9;
    walls[21].x = x7;
    walls[21].y = y9;
    walls[21].w = x10 - x7;
    walls[21].h = y10 - y9;
    walls[22].x = x3;
    walls[22].y = y6;
    walls[22].w = x4 - x3;
    walls[22].h = y11 - y6;
    walls[23].x = 0;
    walls[23].y = y10;
    walls[23].w = x4;
    walls[23].h = y11 - y10;

    walls[24].x = x7;
    walls[24].y = y9;
    walls[24].w = x8 - x7;
    walls[24].h = y14 - y9;
    walls[25].x = 800 - x8;
    walls[25].y = y9;
    walls[25].w = x8 - x7;
    walls[25].h = y14 - y9;
    walls[26].x = 800 - x4;
    walls[26].y = y10;
    walls[26].w = x4;
    walls[26].h = y11 - y10;
    walls[27].x = 800 - x4;
    walls[27].y = y12;
    walls[27].w = x4;
    walls[27].h = y17 - y12;
    walls[28].x = 800 - x6;
    walls[28].y = y12;
    walls[28].w = x6 - x5;
    walls[28].h = y17 - y12;
    walls[29].x = x7;
    walls[29].y = y13;
    walls[29].w = 800 - x7 - x7;
    walls[29].h = y14 - y13;

    walls[30].x = x5;
    walls[30].y = y12;
    walls[30].w = x6 - x5;
    walls[30].h = y17 - y12;
    walls[31].x = 0;
    walls[31].y = y12;
    walls[31].w = x4;
    walls[31].h = y13 - y12;
    walls[32].x = x3;
    walls[32].y = y12;
    walls[32].w = x4 - x3;
    walls[32].h = y17 - y12;
    walls[33].x = x7;
    walls[33].y = y15;
    walls[33].w = 800 - x7 - x7;
    walls[33].h = y17 - y15;
    walls[34].x = 800 - x4;
    walls[34].y = y12;
    walls[34].w = x4 - x3;
    walls[34].h = y17 - y12;
    walls[35].x = 800 - x4;
    walls[35].y = y16;
    walls[35].w = x4;
    walls[35].h = y17 - y16;
    walls[36].x = 0;
    walls[36].y = y16;
    walls[36].w = x4;
    walls[36].h = y17 - y16;
    walls[37].x = 0;
    walls[37].y = y16;
    walls[37].w = x1;
    walls[37].h = 886 - y16;
    walls[38].x = x2;
    walls[38].y = y18;
    walls[38].w = x4 - x2;
    walls[38].h = y19 - y18;
    walls[39].x = x5;
    walls[39].y = y18;
    walls[39].w = x9 - x5;
    walls[39].h = y19 - y18;

    walls[40].x = x11;
    walls[40].y = y15;
    walls[40].w = 800 - x11 - x11;
    walls[40].h = y19 - y15;
    walls[41].x = 800 - x9;
    walls[41].y = y18;
    walls[41].w = x9 - x5;
    walls[41].h = y19 - y18;
    walls[42].x = 800 - x4;
    walls[42].y = y18;
    walls[42].w = x4 - x2;
    walls[42].h = y19 - y18;
    walls[43].x = 800 - x4;
    walls[43].y = y18;
    walls[43].w = x4 - 129;
    walls[43].h = y21 - y18;
    walls[44].x = 800 - x6;
    walls[44].y = y20;
    walls[44].w = x6 - x5;
    walls[44].h = y23 - y20;
    walls[45].x = x7;
    walls[45].y = y20;
    walls[45].w = 800 - x7 - x7;
    walls[45].h = y21 - y20;
    walls[46].x = x5;
    walls[46].y = y20;
    walls[46].w = x6 - x5;
    walls[46].h = y23 - y20;

    walls[47].x = 129;
    walls[47].y = y18;
    walls[47].w = x4 - 129;
    walls[47].h = y21 - y18;
    walls[48].x = x2;
    walls[48].y = y22;
    walls[48].w = x9 - x2;
    walls[48].h = y23 - y22;
    walls[49].x = x11;
    walls[49].y = y20;
    walls[49].w = 800 - x11 - x11;
    walls[49].h = y23 - y20;

    walls[50].x = 800 - x9;
    walls[50].y = y22;
    walls[50].w = x9 - x2;
    walls[50].h = y23 - y22;
    walls[51].x = 0;
    walls[51].y = y24;
    walls[51].w = 800;
    walls[51].h = 886 - y24;
    walls[52].x = 0;
    walls[52].y = y20;
    walls[52].w = x2;
    walls[52].h = y21 - y20;
    walls[53].x = 800 - x2;
    walls[53].y = y20;
    walls[53].w = x2;
    walls[53].h = y21 - y20;
    walls[54].x = 800 - x1;
    walls[54].y = y16;
    walls[54].w = x1;
    walls[54].h = 886 - y16;
}

void createPoint()
{
    //Clip for point and cherry
    point.x = 560; point.y = 600; point.h = 30; point.w = 30;
    cherry.x = 605; cherry.y = 5; cherry.h = 40; cherry.w = 40;

    memset(isEateanPoint, false, sizeof isEateanPoint);

    // Row 1
    pointX[1][1] = 20; pointY[1][1] = 26;
    for (int coli = 2; coli <= NUMBER_COL; coli++) {
        pointX[1][coli] = pointX[1][coli - 1] + 30;
        pointY[1][coli] = pointY[1][coli - 1];
    }
    // Row 2 - 10
    for (int rowi = 2; rowi <= 10; rowi++)
        for (int coli = 1; coli <= NUMBER_COL; coli++) {
            pointX[rowi][coli] = pointX[rowi - 1][coli];
            pointY[rowi][coli] = pointY[rowi - 1][coli] + 41;
        }
    //Fix row 10 && row 4
    for (int coli = 1; coli <= NUMBER_COL; coli++) {
        pointY[10][coli] = pointY[10][coli] + 4;
        pointY[4][coli] = pointY[4][coli] - 4;
    }
    // Row 11 - NUMBER_ROW
    for (int rowi = 11; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 1; coli <= NUMBER_COL; coli++) {
            pointX[rowi][coli] = pointX[rowi - 1][coli];
            pointY[rowi][coli] = pointY[rowi - 1][coli] + 41;
        }
    // Fix row 14 & row 16
    for (int coli = 1; coli <= NUMBER_COL; coli++) {
        pointY[14][coli] = pointY[14][coli] + 5;
        pointY[15][coli] = pointY[15][coli] + 6;
        pointY[16][coli] = pointY[16][coli] + 8;
    }
    for (int rowi = 17; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 1; coli <= NUMBER_COL; coli++) {
            pointX[rowi][coli] = pointX[rowi][coli];
            pointY[rowi][coli] = pointY[rowi][coli] + 8;
        }
    for (int rowi = 18; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 1; coli <= NUMBER_COL; coli++) {
            pointX[rowi][coli] = pointX[rowi][coli];
            pointY[rowi][coli] = pointY[rowi][coli] + 7;
        }
    for (int coli = 1; coli <= NUMBER_COL; coli++) pointY[17][coli] = pointY[17][coli] + 5;
    for (int coli = 1; coli <= NUMBER_COL; coli++) pointY[20][coli] = pointY[20][coli] + 3;
    // Fix col
    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 14; coli <= NUMBER_COL; coli++)
            pointX[rowi][coli] += 8;

    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 7; coli <= 12; coli++)
            pointX[rowi][coli] += 10;
    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++) pointX[rowi][11] += 5;
    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++) pointX[rowi][11] += 5;
    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++) pointX[rowi][6] += 3;

    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 8; coli <= 10; coli++)
            pointX[rowi][coli] += 8;

    for (int coli = 0; coli <= 3; coli++)
        isEateanPoint[8][NUMBER_COL - coli] = true;
    isEateanPoint[9][13] = true;
    for (int coli = 11; coli <= 15; coli++)
        isEateanPoint[10][coli] = true;
    for (int coli = 1; coli <= 4; coli++)
        isEateanPoint[12][coli] = true;

    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 1; coli <= NUMBER_COL; coli++) {
            if (coli == 12) {
                isEateanPoint[rowi][coli] = true;
                continue;
            }
            SDL_Rect pointi;
            pointi.x = pointX[rowi][coli];
            pointi.y = pointY[rowi][coli];
            pointi.h = 30;
            pointi.w = 30;
            for (int walli = 1; walli <= NUMBER_WALLS; walli++) {
                if (checkCollision(pointi, walls[walli])) {
                    isEateanPoint[rowi][coli] = true;
                    break;
                }
            }
    }

    //Creat cherry
    for (int i = 1; i <= 4; i++) {
        int rowi = rand() % NUMBER_ROW + 1;
        int coli = rand() % NUMBER_COL + 1;
        while (isEateanPoint[rowi][coli]) {
            rowi = rand() % NUMBER_ROW + 1;
            coli = rand() % NUMBER_COL + 1;
        }
        isEateanPoint[rowi][coli] = true;
        cherryX[i] = pointX[rowi][coli];
        cherryY[i] = pointY[rowi][coli];
    }
}



