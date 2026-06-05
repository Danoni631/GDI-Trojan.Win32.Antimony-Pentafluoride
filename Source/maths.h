/*
    HOW THIS FILE FUNCTION?

    IS A MATHEMATICAL SYSTEM FOR TESSERACT AND WAVES
*/

#pragma once

#include "include.h"

#define PI 3.14159265358979

typedef struct
{
    float x;
    float y;
    float z;
} VERTEX;

typedef struct
{
    int vtx0;
    int vtx1;
} EDGE;

namespace Math
{
    FLOAT SineWave(FLOAT a, FLOAT b, FLOAT c, FLOAT d)
    {
        return a * sin(2 * PI * b * c / d);
    }

    int mandelbrot(float real, float imag, float maxiter, float shape) {
        int n = 0;

        float zr = 0.0;
        float zi = 0.0;

        while (n < maxiter && zr * zr + zi * zi <= 4.0) {
            float temp = zr * zr - zi * zi + real;

            zi = shape * zr * zi + imag;
            zr = temp;
            n++;
        }

        return n;
    }
}

namespace _3D {
    void RotateX(VERTEX* vtx, float angle) {
        float y = vtx->y * cos(angle) - vtx->z * sin(angle);
        float z = vtx->y * sin(angle) + vtx->z * cos(angle);
        vtx->y = y; vtx->z = z;
    }
    void RotateY(VERTEX* vtx, float angle) {
        float x = vtx->x * cos(angle) + vtx->z * sin(angle);
        float z = -vtx->x * sin(angle) + vtx->z * cos(angle);
        vtx->x = x; vtx->z = z;
    }
    void RotateZ(VERTEX* vtx, float angle) {
        float x = vtx->x * cos(angle) - vtx->y * sin(angle);
        float y = vtx->x * sin(angle) + vtx->y * cos(angle);
        vtx->x = x; vtx->y = y;
    }

    void DrawEdge(HDC dc, HICON icon, int x0, int y0, int x1, int y1, int steps) {
        for (int i = 0; i <= steps; i++) {
            int px = x0 + (x1 - x0) * i / steps;
            int py = y0 + (y1 - y0) * i / steps;
            DrawIcon(dc, px - 16, py - 16, icon);
        }
    }
}
