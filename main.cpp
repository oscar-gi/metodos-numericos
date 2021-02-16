#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

#define PRECISION 6

using namespace std;

double f(double x);

int main()
{
   cout << setprecision(PRECISION); // Establecemos la precisión

   double a, b, tolerancia,xraterior,error;

   cout << "\n-------------Biseccion-------------" << endl;
   cout << "\nIngrese el intervalo inicial [a, b]" << endl;
   cout << "\nintervalo inferior = ";
   cout << "\n Intervalo inferior = ";
   cin >> a;
   cout << "intervalo superior = ";
   cout << "Intervalo superior = ";
   cin >> b;

   double xr=0; // raiz de la función


   if (f(a) * f(b) > 0) {

      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque la funcion f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;

   } else {
      cout << "Tolerancia = ";
      cin >> tolerancia;
      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\t\terror\n" << endl;
      do {
         xraterior=xr;
         xr = (a + b) / 2.0;
         error= fabs((xr-xraterior)/xr)*100;
         cout << a << "\t" << b << "\t" << xr << "\t";
         cout << f(a) << "\t" << f(b) << "\t" << f(xr) << "\t" << error << endl;
        // cout << a << "\t" << b << "\t" << xr << "\t"<< f(a) << "\t" << f(b) << "\t" << f(xr) <<"\t"<< error << endl;

         // Vemos si cumple o no cumple
         if (abs(f(xr)) <= tolerancia) { // xr sería la raiz de f

            cout << "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es " << xr << endl;

            break;

         } else {
            if (f(xr) * f(a) > 0) {
               a = xr;
            } else if (f(xr) * f(b) > 0) {
               b = xr;
            }
         }

      } while (1);
   }

   return 0;
}
double f(double x)
{
   return pow(x , 3) - (3 * x) + 1;
}
