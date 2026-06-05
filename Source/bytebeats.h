#pragma once

#include "include.h"

//SOUND THREADS
namespace Bytebeats
{
    DWORD WINAPI Sound1(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>((t * (t >> 45 | t >> 12) | t >> 19 ^ t) + 1);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound2(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(t * t + (1 * (t >> 9 & t >> 8)) & 128);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound3(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>((t * (t >> 13 | t >> 16) | t >> 56 ^ t) + 64);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound4(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(t * ((t >> 6 | t >> 17) & 55) & 36);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound5(LPVOID lpParam)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(13 * (t * ((t >> 6 | t >> 17) & 55) & 76));
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound6(LPVOID lpParam)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(13 * (t * ((t >> 6 | t >> 17) & 55) & 12));
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound7(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };
        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }
        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];
        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(t * ((t >> 5 | t >> 8) & 63) & (t >> 16));
        }
        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;
        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }
        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);
        delete[] buffer;
        return 0;
    }

    DWORD WINAPI Sound8(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(13 * (t * (t >> 456) * t << 231) * t);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound9(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(t * (t >> 8 | t | t >> 9 | t >> 13) * t);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound10(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(t * (t >> 8 | t | t >> 23 | t >> 675) * t);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound11(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(t * (t >> 1273 | t >> 4234) * t);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }

    DWORD WINAPI Sound12(LPVOID lpvd)
    {
        HWAVEOUT hWaveOut = 0;
        WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };

        if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
            return 1;
        }

        DWORD bufferSize = 22050 * 30;
        char* buffer = new char[bufferSize];

        for (DWORD t = 0; t < bufferSize; ++t) {
            buffer[t] = static_cast<char>(t * (t >> 321 | t >> 123) * t);
        }

        WAVEHDR header = { 0 };
        header.lpData = buffer;
        header.dwBufferLength = bufferSize;

        waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));

        while (!(header.dwFlags & WHDR_DONE)) {
            Sleep(100);
        }

        waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
        waveOutClose(hWaveOut);

        delete[] buffer;

        return 0;
    }
}
