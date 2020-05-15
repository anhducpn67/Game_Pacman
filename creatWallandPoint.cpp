#include "creatWallandPoint.h"
#include "externVariables.h"

int x1= 16, x2= 72, x3= 143, x4= 157, x5= 214, x6= 243, x7= 300, x8= 313, x9= 328, x10= 362, x11= 385, x0= 400;
int y2= 74, y3= 130, y4= 187, y5= 215, y6= 273, y7= 286, y8= 300, y9= 357, y10= 369, y11= 386, y12= 442;
int y13= 458, y14= 472, y15= 527, y16= 541, y17= 556, y18= 612, y19= 640, y20= 697, y21= 726, y22= 782, y23= 812, y24= 867;

SDL_Rect wall[numbers_Wall];

void createWalls()
{
    wall[1].x = 0;    wall[1].y = 0;  wall[1].w = 800;    wall[1].h = 17;
    wall[2].x = 0;      wall[2].y = 0;   wall[2].w = x1;   wall[2].h = y7;
    wall[3].x = x2;      wall[3].y = y2;   wall[3].w = x4-x2;   wall[3].h = y3-y2;
    wall[4].x = x5;      wall[4].y = y2;   wall[4].w = x9-x5;   wall[4].h = y3-y2;
    wall[5].x = x11;    wall[5].y = 0;  wall[5].w = 800-x11-x11;    wall[5].h = y3;
    wall[6].x = 800-x9;    wall[6].y = y2;  wall[6].w = x9-x5;    wall[6].h = y3-y2;
    wall[7].x = 800-x4;    wall[7].y = y2;  wall[7].w = x4-x2;    wall[7].h = y3-y2;
    wall[8].x = 800-x1;    wall[8].y = 0;  wall[8].w = x1;    wall[8].h = y7;
    wall[9].x = 800-x4;    wall[9].y = y4;  wall[9].w = x4-x2;    wall[9].h = y5-y4;

    wall[10].x = 800-x6;    wall[10].y = y4;  wall[10].w = x6-x5;    wall[10].h = y11-y4;
    wall[11].x = x7;    wall[11].y = y4;  wall[11].w = 800-x7-x7;    wall[11].h = y5-y4;
    wall[12].x = x5;    wall[12].y = y4;  wall[12].w = x6-x5;    wall[12].h = y11-y4;
    wall[13].x = x2;      wall[13].y = y4;   wall[13].w = x4-x2;   wall[13].h = y5-y4;
    wall[14].x = 0;      wall[14].y = y6;   wall[14].w = x4;   wall[14].h = y11-y6;
    wall[15].x = x5;    wall[15].y = y6;  wall[15].w = x9-x5;    wall[15].h = y8-y6;
    wall[16].x = x11;    wall[16].y = y4;  wall[16].w = 800-x11-x11;    wall[16].h = y8-y4;
    wall[17].x = 800-x9;    wall[17].y = y6;  wall[17].w = x9-x5;    wall[17].h = y8-y6;
    wall[18].x = 800-x4;    wall[18].y = y6;  wall[18].w = x4;    wall[18].h = y7-y6;
    wall[19].x = 800-x4;    wall[19].y = y6;  wall[19].w = x4-x3;    wall[19].h = y11-y6;

    wall[20].x = 800-x10;    wall[20].y = y9;  wall[20].w = x10-x7;    wall[20].h = y10-y9;
    wall[21].x = x7;    wall[21].y = y9;  wall[21].w = x10-x7;    wall[21].h = y10-y9;
    wall[22].x = x3;    wall[22].y = y6;  wall[22].w = x4-x3;    wall[22].h = y11-y6;
    wall[23].x = 0;      wall[23].y = y10;   wall[23].w = x4;   wall[23].h = y11-y10;

    wall[24].x = x7;      wall[24].y = y9;   wall[24].w = x8-x7;   wall[24].h = y14-y9;
    wall[25].x = 800-x8;    wall[25].y = y9;  wall[25].w = x8-x7;    wall[25].h = y14-y9;
    wall[26].x = 800-x4;    wall[26].y = y10;  wall[26].w = x4;    wall[26].h = y11-y10;
    wall[27].x = 800-x4;    wall[27].y = y12;  wall[27].w = x4;    wall[27].h = y17-y12;
    wall[28].x = 800-x6;    wall[28].y = y12;  wall[28].w = x6-x5;    wall[28].h = y17-y12;
    wall[29].x = x7;    wall[29].y = y13;  wall[29].w = 800-x7-x7;    wall[29].h = y14-y13;

    wall[30].x = x5;    wall[30].y = y12;  wall[30].w = x6-x5;    wall[30].h = y17-y12;
    wall[31].x = 0;    wall[31].y = y12;  wall[31].w = x4;    wall[31].h = y13-y12;
    wall[32].x = x3;    wall[32].y = y12;  wall[32].w = x4-x3;    wall[32].h = y17-y12;
    wall[33].x = x7;      wall[33].y = y15;   wall[33].w = 800-x7-x7;   wall[33].h = y17-y15;
    wall[34].x = 800-x4;      wall[34].y = y12;   wall[34].w = x4-x3;   wall[34].h = y17-y12;
    wall[35].x = 800-x4;    wall[35].y = y16;  wall[35].w = x4;    wall[35].h = y17-y16;
    wall[36].x = 0;    wall[36].y = y16;  wall[36].w = x4;    wall[36].h = y17-y16;
    wall[37].x = 0;    wall[37].y = y16;  wall[37].w = x1;    wall[37].h = 886-y16;
    wall[38].x = x2;    wall[38].y = y18;  wall[38].w = x4-x2;    wall[38].h = y19-y18;
    wall[39].x = x5;    wall[39].y = y18;  wall[39].w = x9-x5;    wall[39].h = y19-y18;

    wall[40].x = x11;    wall[40].y = y15;  wall[40].w = 800-x11-x11;    wall[40].h = y19-y15;
    wall[41].x = 800-x9;    wall[41].y = y18;  wall[41].w = x9-x5;    wall[41].h = y19-y18;
    wall[42].x = 800-x4;    wall[42].y = y18;  wall[42].w = x4-x2;    wall[42].h = y19-y18;
    wall[43].x = 800-x4;      wall[43].y = y18;   wall[43].w = x4-129;   wall[43].h = y21-y18;
    wall[44].x = 800-x6;      wall[44].y = y20;   wall[44].w = x6-x5;   wall[44].h = y23-y20;
    wall[45].x = x7;    wall[45].y = y20;  wall[45].w = 800-x7-x7;    wall[45].h = y21-y20;
    wall[46].x = x5;    wall[46].y = y20;  wall[46].w = x6-x5;    wall[46].h = y23-y20;

    wall[47].x = 129;    wall[47].y = y18;  wall[47].w = x4-129;    wall[47].h = y21-y18;
    wall[48].x = x2;    wall[48].y = y22;  wall[48].w = x9-x2;    wall[48].h = y23-y22;
    wall[49].x = x11;    wall[49].y = y20;  wall[49].w = 800-x11-x11;    wall[49].h = y23-y20;

    wall[50].x = 800-x9;    wall[50].y = y22;  wall[50].w = x9-x2;    wall[50].h = y23-y22;
    wall[51].x = 0;          wall[51].y = y24;  wall[51].w = 800;    wall[51].h = 886-y24;
    wall[52].x = 0;    wall[52].y = y20;  wall[52].w = x2;    wall[52].h = y21-y20;
    wall[53].x = 800-x2;      wall[53].y = y20;   wall[53].w = x2;   wall[53].h = y21-y20;
    wall[54].x = 800-x1;      wall[54].y = y16;   wall[54].w = x1;   wall[54].h = 886-y16;
}
