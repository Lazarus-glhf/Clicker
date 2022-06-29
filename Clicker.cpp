#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;

/*
    
    void mouse_event(
        [in] DWORD     dwFlags,
        [in] DWORD     dx,
        [in] DWORD     dy,
        [in] DWORD     dwData,
        [in] ULONG_PTR dwExtraInfo
    );
    MOUSEEVENTF_ABSOLUTE    
    MOUSEEVENTF_LEFTDOWN        The left button is down.
    MOUSEEVENTF_LEFTUP          The left button is up.
    MOUSEEVENTF_MIDDLEDOWN      The middle button is down.
    MOUSEEVENTF_MIDDLEUP        The middle button is up.
    MOUSEEVENTF_MOVE            Movement occurred.  
    MOUSEEVENTF_RIGHTDOWN       The right button is down.
    MOUSEEVENTF_RIGHTUP         The right button is up.
    MOUSEEVENTF_WHEEL           The wheel has been moved, if the mouse has a wheel. The amount of movement is specified in dwData
    MOUSEEVENTF_XDOWN           An X button was pressed.
    MOUSEEVENTF_XUP             An X button was released.
    MOUSEEVENTF_WHEEL           The wheel button is rotated
    MOUSEEVENTF_HWHEEL          The wheel button is tilted


    void keybd_event(
        [in] BYTE      bVk,
        [in] BYTE      bScan,
        [in] DWORD     dwFlags,
        [in] ULONG_PTR dwExtraInfo
    );
*/

vector<int> KEYS;
int SleepTime = 1000;

void ClickLeft()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void ClickRight()
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}


void TapKey(int KeyVal)
{
    if (KeyVal < 7)
    {
        switch (KeyVal)
        {
        case VK_LBUTTON:
        {
            ClickLeft();
            break;
        }

        case VK_RBUTTON:
        {
            ClickRight();
            break;
        }

        default:
            break;
        }
    }
    else
    {
        keybd_event(KeyVal, 0, 0, 0);
        keybd_event(KeyVal, 0, KEYEVENTF_KEYUP, 0);
    }
}

void Loop(int Time = -1)
{
    printf("Press f to start!");

    char flag;
    cin >> flag;

    if (flag != 'f')
    {
        cin >> flag;
    }
    else
    {
        while (Time--)
        {
            for (int &key : KEYS)
            {
                TapKey(key);
                Sleep(SleepTime);
            }
        }
    }
}


int main()
{
    while (1)
    {
        KEYS.clear();
        printf("Set up sleep time: ");
        cin >> SleepTime;
        printf("Entering keys, enter 0 to end....");
        while (1)
        {
            // printf("Press F to enter next key:");
            if (GetAsyncKeyState('F'))
            {
                char KeyM;
                // if (GetAsyncKeyState(VK_LBUTTON))
                // {
                //     KeyM = VK_LBUTTON;
                // }
                // else if (GetAsyncKeyState(VK_RBUTTON))
                // {
                //     KeyM = VK_RBUTTON;
                // }
                if (_kbhit())
                {
                    KeyM = _getch();
                    if (KeyM == '0')
                    {
                        break;
                    }
                }
                cout << KeyM << " ";
                KEYS.push_back(KeyM);
            }
        }
        Loop();

    return 0;
    }
}
