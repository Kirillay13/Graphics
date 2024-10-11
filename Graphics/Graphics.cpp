// Graphics.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Graphics.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GRAPHICS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAPHICS));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GRAPHICS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GRAPHICS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HPEN hPen;
            // Дом с Крышей
            MoveToEx(hdc, 200, 300, NULL);
            LineTo(hdc, 200, 600);
            LineTo(hdc, 800, 600);
            LineTo(hdc, 800, 300);
            LineTo(hdc, 150, 300);
            LineTo(hdc, 500, 130);
            LineTo(hdc, 850, 300);
            LineTo(hdc, 800, 300);

            // Окно
            MoveToEx(hdc, 300, 375, NULL);
            LineTo(hdc, 300, 505);
            LineTo(hdc, 500, 505);
            LineTo(hdc, 500, 375);
            LineTo(hdc, 300, 375);

            MoveToEx(hdc, 400, 505, NULL);
            LineTo(hdc, 400, 375);

            MoveToEx(hdc, 400, 420, NULL);
            LineTo(hdc, 500, 420);

            //Дверь
            MoveToEx(hdc, 750, 600, NULL);
            LineTo(hdc, 750, 340);
            LineTo(hdc, 600, 340);
            LineTo(hdc, 600, 600);

            // Окно на чердаке
            Ellipse(hdc, 450, 180, 550, 280);
            //Вертикальная
            MoveToEx(hdc, 500 ,180, NULL);
            LineTo(hdc, 500, 280);
            //Горизонтальная
            MoveToEx(hdc, 450, 230, NULL);
            LineTo(hdc, 550, 230);



                //Chevrolet
    
            //Внешний
            HBRUSH hBrush;
            hBrush = CreateSolidBrush(RGB(236, 240, 235));
            SelectObject(hdc, hBrush);
            POINT pt[12];
            pt[0].x = 200;
            pt[0].y = 800;
            pt[1].x = 250;
            pt[1].y = 700;
            pt[2].x = 350;
            pt[2].y = 700;
            pt[3].x = 350;
            pt[3].y = 680;
            pt[4].x = 460;
            pt[4].y = 680;
            pt[5].x = 460;
            pt[5].y = 700;
            pt[6].x = 610;
            pt[6].y = 700;
            pt[7].x = 560;
            pt[7].y = 800;
            pt[8].x = 460;
            pt[8].y = 800;
            pt[9].x = 460;
            pt[9].y = 820;
            pt[10].x = 350;
            pt[10].y = 820;
            pt[11].x = 350;
            pt[11].y = 800;
            Polygon(hdc, pt, 12);


            //Внутренний
            HBRUSH hBrush2;
            hBrush2 = CreateSolidBrush(RGB(209, 173, 87));
            SelectObject(hdc, hBrush2);
            POINT Pt[12];
            Pt[0].x = 240;
            Pt[0].y = 780;
            Pt[1].x = 270;
            Pt[1].y = 720;
            Pt[2].x = 370;
            Pt[2].y = 720;
            Pt[3].x = 370;
            Pt[3].y = 700;
            Pt[4].x = 440;
            Pt[4].y = 700;
            Pt[5].x = 440;
            Pt[5].y = 720;
            Pt[6].x = 570;
            Pt[6].y = 720;
            Pt[7].x = 540;
            Pt[7].y = 780;
            Pt[8].x = 440;
            Pt[8].y = 780;
            Pt[9].x = 440;
            Pt[9].y = 800;
            Pt[10].x = 370;
            Pt[10].y = 800;
            Pt[11].x = 370;
            Pt[11].y = 780;
            Polygon(hdc, Pt, 12);


            EndPaint(hWnd, &ps);
        }



        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
