#include<windows.h>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#define N 10
#define PI 3.14159265

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

wchar_t  ProgName[] = L"Лабораторна робота 3";
int A[N][N] = {
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
};

int B[N][N] = {
        {0, 1, 1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 1, 0, 0, 1, 1},
        {0, 0, 1, 0, 1, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 0, 1, 0},
};



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;
    WNDCLASS w;

    w.lpszClassName = ProgName;
    w.hInstance = hInstance;
    w.lpfnWndProc = WndProc;
    w.hCursor = LoadCursor(NULL, IDC_ARROW);
    w.hIcon = 0;
    w.lpszMenuName = 0;
    w.hbrBackground = LTGRAY_BRUSH;
    w.style = CS_HREDRAW | CS_VREDRAW;
    w.cbClsExtra = 0;
    w.cbWndExtra = 0;

    if (!RegisterClass(&w))
        return 0;

    hWnd = CreateWindow(ProgName,
        L"LAB 4. Koval Maksym",
        WS_OVERLAPPEDWINDOW,
        100,
        100,
        1200,
        600,
        (HWND)NULL,
        (HMENU)NULL,
        (HINSTANCE)hInstance,
        (HINSTANCE)NULL);

    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&lpMsg, hWnd, 0, 0)) {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return(lpMsg.wParam);
}

void arrow(int px, int py, int dx, int dy, HDC hdc) {
    int lx, ly = py, rx = px, ry;
    if (dx == 0 && dy == 0) return;
    if (dx == 0) {
        ly = py + (15 * dy / abs(dy));
        ry = ly;
        lx = px - 15;
        rx = px + 15;
    }
    else lx = px + (dx / abs(dx)) * 15;
    if (dy == 0) {
        ly = py - 15;
        ry = py + 15;
        lx = px + (15 * dx / abs(dx));
        rx = lx;
    }
    else ry = py + (dy / abs(dy)) * 15;
    MoveToEx(hdc, lx, ly, NULL);
    LineTo(hdc, px, py);
    LineTo(hdc, rx, ry);
}

void mulmr(int* matrix[N][N], float k) {
    int element;
    float num;
    srand(0507);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num = (rand() / (float)RAND_MAX * 2) * k;
            if (num < 1) element = 0;
            else element = 1;
            matrix[i][j] = element;
        }
    }
}

void printEdge(int B[N][N], HDC hdc, int height, int type) {
    char text[15];
    int counter[N] = { 0,0,0,0,0,0,0,0,0,0 };
    int counter2[N] = { 0,0,0,0,0,0,0,0,0,0 };
    int checker = -1, flag = 1, isolatedFlag = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] == 1) {
                if (i == j && !type) counter[i]++;
                counter[i]++;
                if (type) counter2[j]++;
            }
        }
        if (checker == -1) checker = counter[i];
        else if (checker != counter[i]) flag = 0;
        sprintf_s(text, sizeof(text), "deg%d= %d", i, counter[i]);
        TextOutA(hdc, 5 + 80 * i, height, text, 8);
    }
    if (type) {
        for (int count = 0; count < N; count++) {
            sprintf_s(text, sizeof(text), "deg%d-= %d", count, counter2[count]);
            TextOutA(hdc, 5 + 80 * count, height + 20, text, 9);

            if (counter[count] == 0 && counter2[count] == 0) {
                sprintf_s(text, sizeof(text), "Isolat=%d", count);
                TextOutA(hdc, 5, height - 310, text, 9);
            }

            if ((counter[count] == 1 && counter2[count] == 0) || (counter[count] == 0 && counter2[count] == 1)) {
                sprintf_s(text, sizeof(text), "Self = %d", count);
                TextOutA(hdc, 5, height - 340 - 10 * count, text, 9);
            }
        }
    }
    if (flag) {
        sprintf_s(text, sizeof(text), "Odinr=%d", checker);
        TextOutA(hdc, 5, height + 300, text, 9);
    }
}

void drawgraph(HDC hdc, int startA[N][N], int components[N][N]) {
    int xPos[N] = { 75,275,275,75,150,200,200,150,50,300 };
    int yPos[N] = { 75,75,225,225,50,50,250,250,150,150 };
    int drawVert[N] = { 0,0,0,0,0,0,0,0,0,0};
    char* ellipseName[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int dtx = 5, radius = 16, end, xDif, yDif, dx, dy, koef;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (components[i][j] == 0) continue;
            for (int count = 0; count < N; count++) {
                if (startA[j][count]) {
                    for (int count2 = 0; count2 < N; count2++) {
                        if (components[count2][count]) {
                            MoveToEx(hdc, xPos[i], yPos[i], NULL);
                            LineTo(hdc, xPos[count2], yPos[count2]);
                            xDif = xPos[i] - xPos[count2];
                            yDif = yPos[i] - yPos[count2];
                            if (xDif == 0 && yDif == 0) {
                                dx = 0;
                                dy = 0;
                            }
                            else {
                                koef = sqrt(xDif * xDif + yDif * yDif) / radius;
                                dx = xDif / koef;
                                dy = yDif / koef;
                            }
                            arrow(xPos[count2] + dx, yPos[count2] + dy, dx, dy, hdc);
                        }
                    }
                }
            }
            drawVert[i] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (drawVert[i]) {
            Ellipse(hdc, xPos[i] - radius, yPos[i] - radius, xPos[i] + radius, yPos[i] + radius);
            TextOut(hdc, xPos[i] - dtx, yPos[i] - 8, ellipseName[i], 1);
        }
    }
}

void powMatrix(HDC hdc, int A[N][N], int startA[N][N], int reachA[N][N], int length) {
    int num, counter = 1, countery = 1;
    char text[20];
    int newA[N][N];
    int connA[N][N] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

    };
    int components[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    int usedVerticles[N] = { 0,0,0,0,0,0,0,0,0,0 };

    //multiply matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num = 0;
            for (int count = 0; count < N; count++) {
                num += A[i][count] * startA[count][j];
            }
            newA[i][j] = num;
            reachA[i][j] += num;
        }
    }
    //all tasks operations
    if (length == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //2
                //if (startA[i][j] == 1) {
                //    for (int count = 0; count < N; count++) {
                //        if (startA[j][count] == 1) {
                //                sprintf_s(text, sizeof(text), "%d->%d->%d", i, j, count);
                //                TextOutA(hdc, 5 + 65 * counter, 500 + 20*countery, text, 8);
                //                counter++;
                //                if ((float)counter / 17 > 1) {
                //                    countery++;
                //                    counter = 1;
                //                }
                //        }
                //    }
                //}

                //3
                //if (startA[i][j] == 1) {
                //    for (int count = 0; count < N; count++) {
                //        if (startA[j][count] == 1) {
                //            for (int count2 = 0; count2 < N; count2++) {
                //                if (startA[count][count2] == 1) {
                //                    sprintf_s(text, sizeof(text), "%d->%d->%d->%d", i, j, count, count2);
                //                    TextOutA(hdc, 0 + 80 * counter, 30 * countery, text, 15);
                //                    counter++;
                //                    if ((float)counter / 17 > 1) {
                //                        countery++;
                //                        counter = 1;
                //                    }
                //                }
                //            }
                //        }
                //    }
                //}

                //reach matrix
                reachA[i][j] += startA[i][j];
                if (reachA[i][j] >= 1) reachA[i][j] = 1;
                else {
                    connA[i][j] = 0;
                    connA[j][i] = 0;
                }
                //print reach matrix
                //sprintf_s(text, 2, "%d", reachA[i][j]);
                //TextOutA(hdc, 5 + 25 * j, 400 + 20 * i, text, 1);


            }
        }

        //print connection matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sprintf_s(text, 2, "%d", connA[i][j]);
                TextOutA(hdc, 350 + 25 * j, 400 + 20 * i, text, 1);
            }
        }
        countery = 0;
        //find components

        for (int count = 0; count < N; count++) {
            counter = 1;
            for (int i = 0; i < N; i++) {
                if (usedVerticles[i] == 1) continue;
                for (int j = 0; j < N; j++) {
                    if (connA[count][j] != connA[i][j]) break;
                    if (j == N - 1) {
                        usedVerticles[i] = 1;
                        components[countery][i] = 1;
                        sprintf_s(text, sizeof(text), "K%d", countery);
                        TextOutA(hdc, 10, 100 + 25 * countery, text, 2);
                        sprintf_s(text, sizeof(text), "%d", i);
                        TextOutA(hdc, 20 + 20 * counter, 100 + 25 * countery, text, 2);
                        counter++;
                    }
                }
            }
            if (components[countery][0] || components[countery][1] || components[countery][2] ||
                components[countery][3] || components[countery][4] || components[countery][5] ||
                components[countery][6] || components[countery][7] || components[countery][8] ||
                components[countery][9]) countery++;
        }

        //draw cond graph
        drawgraph(hdc, startA, components);
    }

    if (length > 2) powMatrix(hdc, newA, startA, reachA, length - 1);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (messg) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        int xPos[10];
        int yPos[10];
        int startCoordx = 20;
        int startCoordy = 560;
        char* ellipseName[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

        int R = 250;
        int step = 0;
        int Centre1_X = 300, Centre1_Y = 400;
        xPos[9] = Centre1_X;
        yPos[9] = Centre1_Y;
        for (int vertex = 0; vertex < N - 1; vertex++) {
            xPos[vertex] = Centre1_X + R * cos(step * PI / 180);
            yPos[vertex] = Centre1_Y + R * sin(step * PI / 180);
            step += 360 / N + 4;
        }

        int dtx = 5, radius = 16, divine = 1, dx, dy, xDif, yDif;
        float koef;
        int OrientGraph = 1;// 1 - Oriented Graph | 0- Not oriented
        int diagonalA[N][N] = {
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, },
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, },
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, },
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, },
            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, },
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, },
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, },
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
        };
        HPEN BluePen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN BlackPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));
        SelectObject(hdc, BlackPen);

        mulmr(A, (1.0 - 0 * 0.005 - 7 * 0.005 - 0.27));
        //printEdge(A, hdc, 680, 1);
        //powMatrix(hdc, A, A, diagonalA, N - 1);

        //
        //mulmr(A, (1.0 - 0 * 0.01 - 7 * 0.01 - 0.3));
        //printEdge(A, hdc, 680,1);
        //printEdge(B, hdc, 10,0);


        
        for (int start = 0; start < N; start++) {
            for (int end = 0; end < N; end++) {
                if (A[start][end] == 1) {
                    xDif = xPos[start] - xPos[end];
                    yDif = yPos[start] - yPos[end];
                    koef = sqrt(xDif * xDif + yDif * yDif) / radius;
                    dx = xDif / koef;
                    dy = yDif / koef;
                    if (start == end) {
                        MoveToEx(hdc, xPos[end], yPos[end], NULL);
                        LineTo(hdc, xPos[end] + 40, yPos[end] + 10);
                        LineTo(hdc, xPos[end] + 40, yPos[end] + 40);
                        LineTo(hdc, xPos[end] + 10, yPos[end] + 40);
                        LineTo(hdc, xPos[end], yPos[end]);
                        arrow(xPos[end] + 2, yPos[end] + 13, 2, 13, hdc);
                    }
                    else if (A[start][end] == 1 && A[end][start] == 1) {
                        MoveToEx(hdc, xPos[start], yPos[start], NULL);
                        LineTo(hdc, xPos[end] + xDif / 2 + (20 * divine), yPos[end] + yDif / 2 + (20 * divine));
                        LineTo(hdc, xPos[end], yPos[end]);
                        arrow(xPos[end] + dx, yPos[end] + dy, dx, dy, hdc);
                        divine = -divine;
                    }
                    else {
                        MoveToEx(hdc, xPos[start], yPos[start], NULL);
                        if (yDif == 0 && abs(xDif) > 300 && end <= 3) {
                            LineTo(hdc, xPos[end] + xDif / 2, yPos[end] - 35);
                            dx = xDif / 2 / koef;
                            dy = (yDif - 35) / koef;
                        }
                        else if (abs(xDif) == 300 && abs(yDif) == 300 && (end == 0 || end == 3)) {
                            LineTo(hdc, xPos[end] + xDif / 2, yPos[end] + yDif / 1);
                            dx = xDif / 2 / koef;
                            dy = yDif / koef;
                        }
                        LineTo(hdc, xPos[end], yPos[end]);
                        arrow(xPos[end] + dx, yPos[end] + dy, dx, dy, hdc);
                    }
                }
            }
        }
        int xPos1[10];
        int yPos1[10];
        int startCoordx1 = 20;
        int startCoordy1 = 560;
        char* ellipseName1[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        int R1 = 250;
        int step1 = 0;
        int Centre11_X = 900, Centre11_Y = 400;
        xPos1[9] = Centre11_X;
        yPos1[9] = Centre11_Y;
        for (int vertex = 0; vertex < N - 1; vertex++) {
            xPos1[vertex] = Centre11_X + R1 * cos(step1 * PI / 180);
            yPos1[vertex] = Centre11_Y + R1 * sin(step1 * PI / 180);
            step1 += 360 / N + 4;
        }
        int dtx1 = 5, radius1 = 16, divine1 = 1, dx1, dy1, xDif1, yDif1;
        float koef1;
        HPEN BluePen1 = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
        HPEN BlackPen1 = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));
        SelectObject(hdc, BlackPen1);
        for (int start = 0; start < N; start++) {
            for (int end = 0; end < N; end++) {
                if (A[start][end] == 1) {
                    xDif1 = xPos1[start] - xPos1[end];
                    yDif1 = yPos1[start] - yPos1[end];
                    koef1 = sqrt(xDif1 * xDif1 + yDif1 * yDif1) / radius1;
                    dx1 = xDif1 / koef1;
                    dy1 = yDif1 / koef1;
                    if (start == end) {
                        MoveToEx(hdc, xPos1[end], yPos1[end], NULL);
                        LineTo(hdc, xPos1[end] + 40, yPos1[end] + 10);
                        LineTo(hdc, xPos1[end] + 40, yPos1[end] + 40);
                        LineTo(hdc, xPos1[end] + 10, yPos1[end] + 40);
                        LineTo(hdc, xPos1[end], yPos1[end]);
                    }
                    else if (B[start][end] == 1 && B[end][start] == 1) {
                        MoveToEx(hdc, xPos1[start], yPos1[start], NULL);
                        LineTo(hdc, xPos1[end] + xDif1 / 2 + (20 * divine1), yPos1[end] + yDif1 / 2 + (20 * divine1));
                        LineTo(hdc, xPos1[end], yPos1[end]);
                        divine1 = -divine1;
                    }
                }
            }
        }
        SelectObject(hdc, BluePen);
        for (int i = 0; i < N; i++) {
            Ellipse(hdc, xPos[i] - radius, yPos[i] - radius, xPos[i] + radius, yPos[i] + radius);
            TextOut(hdc, xPos[i] - dtx, yPos[i] - 8, ellipseName[i], 1);
        }
        SelectObject(hdc, BluePen1);
        for (int i = 0; i < N; i++) {
            Ellipse(hdc, xPos1[i] - radius1, yPos1[i] - radius1, xPos1[i] + radius1, yPos1[i] + radius1);
            TextOut(hdc, xPos1[i] - dtx1, yPos1[i] - 8, ellipseName1[i], 1);
        }

        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return 0;
}
/*
//MATRIX GENERATION
int** randMatrix(float k) {
    srand(0507);
    int matrix[N][N];
    float num;
    int element;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num = (rand() / (float)RAND_MAX * 2) * k;
            if (num < 1) element = 0;
            else element = 1;
            matrix[i][j] = element;
            printf("%d ", element);
        }
        printf("\n");
    }
    return matrix;
}
int main()
{
    float koef = (1.0 - 0 * 0.005 - 7 * 0.005 - 0.27);
    randMatrix(koef);
    return 0;
}*/
