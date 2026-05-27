#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define mapWidth 80    
#define mapHeight 25      

typedef struct SObject {
    float x, y;
    float width, height;
    float vertSpeed;
    float horizonSpeed;
    BOOL IsFly;
    char cType;
} TObject;

char map[mapHeight][mapWidth + 1];
TObject mario;
TObject* brick = NULL;
int brickLength;
TObject* moving = NULL;
int movingLength;
int level = 1;
int score;
int maxLvl;

void createLevel(int lvl);

void clearMap()
{
    for (int i = 0; i < mapWidth; ++i)
        map[0][i] = ' ';
    map[0][mapWidth] = '\0';
    for (int j = 1; j < mapHeight; ++j)
        sprintf(map[j], map[0]);
}

void showMap()
{
    map[mapHeight - 1][mapWidth - 1] = '\0';
    for (int j = 0; j < mapHeight; ++j)
        printf("%s\n", map[j]);
}

void setObjectPos(TObject* obj, float xPos, float yPos)
{
    (*obj).x = xPos;
    (*obj).y = yPos;
}

void initObject(TObject* obj, float xPos, float yPos, float oWidth, float oHeight, char inType)
{
    setObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
    (*obj).horizonSpeed = 0.2;
    (*obj).IsFly = FALSE;
    (*obj).cType = inType;
}

void playerDead()
{
    system("color 4F");
    Sleep(500);
    createLevel(level);
}

BOOL isCollision(TObject o1, TObject o2);
TObject* getNewMoving();

void vertMoveObject(TObject* obj)
{
    (*obj).IsFly = TRUE;
    (*obj).vertSpeed += 0.05;
    setObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed);

    for (int i = 0; i < brickLength; ++i)
    {
        if (isCollision(*obj, brick[i]))
        {
            if (obj[0].vertSpeed > 0)
                obj[0].IsFly = FALSE;

            if ((brick[i].cType == '?') && (obj[0].vertSpeed < 0) && (obj == &mario))
            {
                brick[i].cType = '-';
                initObject(getNewMoving(), brick[i].x, brick[i].y - 3, 3, 2, '$');
                moving[movingLength - 1].vertSpeed = -0.7;
            }

            (*obj).y -= (*obj).vertSpeed;
            (*obj).vertSpeed = 0;
            if (brick[i].cType == '+')
            {
                level++;
                if (level > maxLvl) level = 1;

                system("color 2F");
                Sleep(500);
                createLevel(level);
            }
            break;
        }
    }
}

void deleteMoving(int i)
{
    movingLength--;
    moving[i] = moving[movingLength];
    moving = (TObject*)realloc(moving, sizeof(*moving) * movingLength);
}

void marioCollision()
{
    for (int i = 0; i < movingLength; ++i)
    {
        if (isCollision(mario, moving[i]))
        {
            if (moving[i].cType == 'o')
            {
                if ((mario.IsFly == TRUE) && (mario.vertSpeed > 0) && (mario.y + mario.height < moving[i].y + moving[i].height * 0.5))
                {
                    score += 50;
                    deleteMoving(i);
                    i--;
                    continue;
                }
                else
                {
                    playerDead();

                }
            }

            if (moving[i].cType == '$')
            {
                score += 100;
                deleteMoving(i);
                i--;
                continue;
            }
        }
    }
}

void horizonMoveObject(TObject* obj)
{
    obj[0].x += obj[0].horizonSpeed;

    for (int i = 0; i < brickLength; ++i)
    {
        if (isCollision(obj[0], brick[i]))
        {
            obj[0].x -= obj[0].horizonSpeed;
            obj[0].horizonSpeed = -obj[0].horizonSpeed;
            return;
        }
    }

    if (obj[0].cType == 'o')
    {
        TObject tmp = *obj;
        vertMoveObject(&tmp);
        if (tmp.IsFly == TRUE)
        {
            obj[0].x -= obj[0].horizonSpeed;
            obj[0].horizonSpeed = -obj[0].horizonSpeed;
        }
    }
}

BOOL isPosInMap(int x, int y)
{
    return ((x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight));
}

void putObjectOnMap(TObject obj)
{
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);

    for (int i = ix; i < (ix + iWidth); ++i)
        for (int j = iy; j < (iy + iHeight); ++j)
            if (isPosInMap(i, j))
                map[j][i] = obj.cType;
}

void putScoreOnMap()
{
    char c[30];
    sprintf(c, "Score: %d", score);
    int len = strlen(c);
    for (int i = 0; i < len; i++) {
        map[1][i + 5] = c[i];
    }
}

void setCur(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void horizonMoveMap(float dx)
{
    mario.x -= dx;
    for (int i = 0; i < brickLength; ++i) {
        if (isCollision(mario, brick[i])) {
            mario.x += dx;
            return;
        }
    }
    mario.x += dx;

    for (int i = 0; i < brickLength; i++)
        brick[i].x += dx;

    for (int i = 0; i < movingLength; i++)
        moving[i].x += dx;
}

BOOL isCollision(TObject o1, TObject o2) {
    return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
        ((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}

TObject* getNewBrick()
{
    brickLength++;
    brick = (TObject*)realloc(brick, sizeof(*brick) * brickLength);
    return brick + brickLength - 1;
}

TObject* getNewMoving()
{
    movingLength++;
    moving = (TObject*)realloc(moving, sizeof(*moving) * movingLength);
    return moving + movingLength - 1;
}

void createLevel(int lvl)
{
    system("color 9F");

    brickLength = 0;
    brick = (TObject*)realloc(brick, 0);
    movingLength = 0;
    moving = (TObject*)realloc(moving, 0);

    initObject(&mario, 39, 10, 3, 3, '@');
    score = 0;

    if (lvl == 1)
    {
        initObject(getNewBrick(), 20, 20, 40, 5, '#');
        initObject(getNewBrick(), 30, 10, 5, 3, '?');
        initObject(getNewBrick(), 50, 10, 5, 3, '?');
        initObject(getNewBrick(), 60, 15, 40, 10, '#');
        initObject(getNewBrick(), 60, 5, 10, 3, '-');
        initObject(getNewBrick(), 70, 5, 5, 3, '?');
        initObject(getNewBrick(), 75, 5, 5, 3, '-');
        initObject(getNewBrick(), 80, 5, 5, 3, '?');
        initObject(getNewBrick(), 85, 5, 10, 3, '-');
        initObject(getNewBrick(), 100, 20, 20, 5, '#');
        initObject(getNewBrick(), 120, 15, 10, 10, '#');
        initObject(getNewBrick(), 150, 20, 40, 5, '#');
        initObject(getNewBrick(), 210, 15, 10, 10, '+');
        initObject(getNewMoving(), 25, 10, 3, 2, 'o');
        initObject(getNewMoving(), 80, 10, 3, 2, 'o');
    }

    if (lvl == 2)
    {
        initObject(getNewBrick(), 20, 20, 40, 5, '#');
        initObject(getNewBrick(), 60, 15, 10, 10, '#');
        initObject(getNewBrick(), 80, 20, 20, 5, '#');
        initObject(getNewBrick(), 120, 15, 10, 10, '#');
        initObject(getNewBrick(), 150, 20, 40, 5, '#');
        initObject(getNewBrick(), 210, 15, 10, 10, '+');

        initObject(getNewMoving(), 25, 10, 3, 2, 'o');
        initObject(getNewMoving(), 80, 10, 3, 2, 'o');
        initObject(getNewMoving(), 65, 10, 3, 2, 'o');
        initObject(getNewMoving(), 120, 10, 3, 2, 'o');
        initObject(getNewMoving(), 160, 10, 3, 2, 'o');
        initObject(getNewMoving(), 175, 10, 3, 2, 'o');
    }

    if (lvl == 3)
    {
        initObject(getNewBrick(), 20, 20, 40, 5, '#');
        initObject(getNewBrick(), 80, 20, 15, 5, '#');
        initObject(getNewBrick(), 120, 15, 15, 10, '#');
        initObject(getNewBrick(), 160, 10, 15, 15, '+');

        initObject(getNewMoving(), 25, 10, 3, 2, 'o');
        initObject(getNewMoving(), 50, 10, 3, 2, 'o');
        initObject(getNewMoving(), 80, 10, 3, 2, 'o');
        initObject(getNewMoving(), 90, 10, 3, 2, 'o');
        initObject(getNewMoving(), 120, 10, 3, 2, 'o');
        initObject(getNewMoving(), 130, 10, 3, 2, 'o');
    }

}


int main()
{
    createLevel(level);

    do
    {
        clearMap();

        if ((mario.IsFly == FALSE) && (GetKeyState(VK_SPACE) < 0)) mario.vertSpeed = -1;

        if (GetKeyState('A') < 0) horizonMoveMap(1);
        if (GetKeyState('D') < 0) horizonMoveMap(-1);

        if (mario.y > mapHeight)playerDead();

        vertMoveObject(&mario);
        marioCollision();

        for (int i = 0; i < brickLength; ++i)
        {
            putObjectOnMap(brick[i]);
        }

        for (int i = 0; i < movingLength; ++i)
        {
            vertMoveObject(moving + i);
            horizonMoveObject(moving + i);
            if (moving[i].y > mapHeight)
            {
                deleteMoving(i);
                i--;
                continue;
            }
            putObjectOnMap(moving[i]);
        }

        putObjectOnMap(mario);
        putScoreOnMap();

        setCur(0, 0);
        showMap();

        Sleep(10);
    } while (GetKeyState(VK_ESCAPE) >= 0);

    free(brick);
    free(moving);
    return 0;
}