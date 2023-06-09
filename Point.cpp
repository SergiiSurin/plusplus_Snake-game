#include "Point.h"

void Point::gotoxy() const
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { short(m_x), short(m_y) };

    SetConsoleCursorPosition(hStdout, position);
}
void Point::copyFrom(const Point& b)
{
    // �� ����� ������ ������ � �������� ������ ������� b
    m_x = b.m_x;
    m_y = b.m_y;
    m_sym = b.m_sym;
}

void Point::move(int offset, Direction direction)
{
    switch (direction)
    {
    case RIGHT: {m_x += offset; break; }
    case LEFT: {m_x -= offset; break; }
    case UP: {m_y -= offset; break; }
    case DOWN: {m_y += offset; break; }
    default: break;
    }
}

void Point::print_point() const
{
    gotoxy();
    std::cout << m_sym;
}

void Point::clear()
{
    gotoxy();
    std::cout << ' ';
}

bool Point::isHit(Point p)
{
    return p.m_x == this->m_x && p.m_y == this->m_y;
}

bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1.m_x == p2.m_x &&
        p1.m_y == p2.m_y);
}
