#include <iostream>
#include "Manipulator.h"
#include "Point.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");

    // creating two manipulators
    Manipulator* M1 = new Manipulator;
    Manipulator* M2 = new Manipulator;

    //setting coordinates and radius
    cout << "Настройки первого манипулятора :" << endl;
    M1->entry_x_y_r();
    cout << " Настройки второго манипулятора :" << endl;
    M2->entry_x_y_r();

    double p1,p2;
    
    cout << "Введите точку P " << endl;
    cout << "Введите точку x= ";
    cin >> p1;
    cout << "Введите точку y= ";
    cin >> p2;

    // creating a point 
    Point* pDot = new Point (p1,p2);

    
    cout << "Координаты точки P";
    pDot->showDisplay();

   //selecting an effective manipulator
    cout << "Проверка каким манипулятором пользоватья эффективнее " << endl;

    if ((M1->proverkaEntry(pDot->get_x(), pDot->get_y()) == true) && (M2->proverkaEntry(pDot->get_x(), pDot->get_y()) == false))
    {
        cout << "Наиболее эффективный  первый манипулятор  0" << endl;
    }
    else
    {
        if ((M1->proverkaEntry(pDot->get_x(), pDot->get_y()) == false) && (M2->proverkaEntry(pDot->get_x(), pDot->get_y()) == true))
        {
            cout << "Наиболее эффективный второй манипулятор 0" << endl;
        }
        else
        {
            if ((M1->proverkaEntry(pDot->get_x(), pDot->get_y()) == false) && (M2->proverkaEntry(pDot->get_x(), pDot->get_y()) == false))
            {

                if ((sqrt((pow((pDot->get_x() - M1->get_x()), 2) + pow((pDot->get_y() - M1->get_y()), 2))) - M1->getRadius()) <= ((sqrt((pow((pDot->get_x() - M2->get_x()), 2) + pow((pDot->get_y() - M2->get_y()), 2)))) - M2->getRadius()))
                {
                    cout << "Наиболее эффективный первый манипулятор 1" << endl;
                }
                else
                {
                    cout << "Наиболее эффективный второй манипулятор 1" << endl;
                }
            }
            else
            if ((M1->proverkaEntry(pDot->get_x(), pDot->get_y()) == true) && ((M2->proverkaEntry(pDot->get_x(), pDot->get_y())) == true))
            {
                if ((sqrt((pow((pDot->get_x() - M1->get_x()), 2) + pow((pDot->get_y() - M1->get_y()), 2)) )) <= ((sqrt((pow((pDot->get_x() - M2->get_x()), 2) + pow((pDot->get_y() - M2->get_y()), 2))) )))
                {
                    cout << "Наиболее эффективный первый манипулятор 1" << endl;
                }
                else
                {
                    cout << "Наиболее эффективный второй манипулятор 1" << endl;
                }
            }
        }


    }

    delete M1, M2, pDot;
}

