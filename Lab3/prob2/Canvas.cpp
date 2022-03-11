#include "Canvas.h"
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height)
    : m_width{ width }, m_height{ height }
{
    m_canvas = new char*[width]{};

    for (int i{ 0 }; i < width; ++i)
    {
        m_canvas[i] = new char[height] {};
    }

    for (int i{ 0 }; i < width; ++i)
    {
        for (int j{ 0 }; j < height; ++j)
        {
            m_canvas[i][j] = ' '; // pentru a afisa normal toate figurile
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    if (ray < 0) return;

    int nx, ny;
    long double theta = 0;
    while (theta <= M_PI) 
    {
        ny = sin(theta) * ray;
        nx = cos(theta) * ray;
        theta += 0.02;
        if (0 <= nx + x && nx + x < m_width && 0 <= ny + y && ny + y < m_height) 
        {
            m_canvas[nx + x][ny + y] = ch;
        }
        if (0 <= x - nx && x - nx < m_width && 0 <= ny + y && ny + y < m_height) 
        {
            m_canvas[x - nx][ny + y] = ch;
        }
        if (0 <= nx + x && nx + x < m_width && 0 <= y - ny && y - ny < m_height) 
        {
            m_canvas[nx + x][y - ny] = ch;
        }
        if (0 <= x - nx && x - nx < m_width && 0 <= y - ny && y - ny < m_height) 
        {
            m_canvas[x - nx][y - ny] = ch;
        }

    }

}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    if (ray < 0) return;

    int nx, ny;
    long double theta = 0;
    while (theta <= M_PI_2) 
    {
        ny = sin(theta) * ray;
        nx = cos(theta) * ray;
        theta += 0.002;
        if (0 <= nx + x && nx + x < m_width && 0 <= ny + y && ny + y < m_height) 
        {
            m_canvas[nx + x][ny + y] = ch;
        }
        if (0 <= x - nx && x - nx < m_width && 0 <= ny + y && ny + y < m_height) 
        {
            m_canvas[x - nx][ny + y] = ch;
        }
        if (0 <= nx + x && nx + x < m_width && 0 <= y - ny && y - ny < m_height) 
        {
            m_canvas[nx + x][y - ny] = ch;
        }
        if (0 <= x - nx && x - nx < m_width && 0 <= y - ny && y - ny < m_height) 
        {
            m_canvas[x - nx][y - ny] = ch;
        }
        for (int i = x - nx; i < x + nx; ++i) 
        {
            m_canvas[i][y - ny] = ch;
            m_canvas[i][y + ny] = ch;
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left, top, right, top, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(left, bottom, right, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i{ left }; i <= right; ++i)
    {
        for (int j{ top }; j <= bottom; ++j)
        {
            m_canvas[i][j] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= m_width || y >= m_height || x < 0 || y < 0)
        return;

    m_canvas[x][y] = ch;
}

void Canvas::DrawLineLow(int x1, int y1, int x2, int y2, char ch)
{
    int diff_x{ x2 - x1 };
    int diff_y = { y2 - y1 };

    int yi{ 1 };
    if (diff_y < 0)
    {
        yi = -1;
        diff_y = -diff_y;
    }

    int diff = (2 * diff_y) - diff_x;
    int y{ y1 };

    for (int x{ x1 }; x <= x2; ++x)
    {
        m_canvas[x][y] = ch;
        if (diff > 0)
        {
            y = y + yi;
            diff = diff + (2 * (diff_y - diff_x));
        }
        else
        {
            diff = diff + 2 * diff_y;
        }
    }
}

void Canvas::DrawLineHigh(int x1, int y1, int x2, int y2, char ch)
{
    int diff_x{ x2 - x1 };
    int diff_y = { y2 - y1 };

    int xi{ 1 };
    if (diff_x < 0)
    {
        xi = -1;
        diff_x = -diff_x;
    }

    int diff = (2 * diff_x) - diff_y;
    int x{ x1 };

    for (int y{ y1 }; y <= y2; ++y)
    {
        m_canvas[x][y] = ch;
        if (diff > 0)
        {
            x = x + xi;
            diff = diff + (2 * (diff_x - diff_y));
        }
        else
        {
            diff = diff + 2 * diff_x;
        }
    }

}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    if (x1 >= m_width || y1 >= m_height || x2 >= m_width || y2 >= m_height
        || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
        return;

    if (abs(y2 - y1) < abs(x2 - x1))
    {
        if (x1 > x2)
        {
            DrawLineLow(x2, y2, x1, y1, ch);
        }
        else
        {
            DrawLineLow(x1, y1, x2, y2, ch);
        }
    }
    else
    {
        if (y1 > y2)
        {
            DrawLineHigh(x2, y2, x1, y1, ch);
        }
        else
        {
            DrawLineHigh(x1, y1, x2, y2, ch);
        }
    }
}

void Canvas::Print()
{
    if (m_canvas == nullptr)
        return;
    for (int i{ 0 }; i < m_height; ++i)
    {
        for (int j{ 0 }; j < m_width; ++j)
        {
            std::cout << m_canvas[j][i] << "  ";
        }
        std::cout << "\n";
    }
}

void Canvas::Clear()
{
    for (int i{ 0 }; i < m_width; ++i)
    {
        for (int j{ 0 }; j < m_height; ++j)
        {
            m_canvas[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()
{
    for (int i{ 0 }; i < m_width; ++i)
    {
        delete[] m_canvas[i];
    }
    delete[] m_canvas;
    m_canvas = nullptr;
    m_width = 0;
    m_height = 0;
}
