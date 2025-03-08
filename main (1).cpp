#include <iostream>
#include <cmath>
#include "libq.h"
using namespace std;

int main() 
{
    Quaternion q1, q2;
    q1 = Quaternion(8, 2, 9, 5);
    q2 = Quaternion(7, 6, 1, 4);
    cout << "Quaternion q1: " << endl;
    q1.Print_q();
    cout << "Quaternion q2: " << endl;
    q2.Print_q();
    cout << endl;
    cout << "modul q1 " << q1.Count_q()<< endl;
   /* cout << "~q: " << q2.Print_q1() << endl;*/
    cout << "norm(q) = " << q1.Norm() << endl;
    cout << "q^-1 = " << q1.Count_unq() << endl;
    cout << "summ: " << q1.Sumq(q1, q2) << endl;
    cout << "minus: " << q1.minus(q1, q2) << endl;
    cout << "multiplication: " << q1.mul(q1, q2) << endl;
   /* cout << "del: " << q1.del(q1, q2);*/
    cout << "Euclidean distance: " << q1.evkl(q1, q2)<< endl;
    cout << "Norm of Cheburash" << q1.norm_of_chebush(q1, q2)<< endl;



}