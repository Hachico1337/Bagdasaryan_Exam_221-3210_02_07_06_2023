#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "QDebug"
#include <string>


void sift(double *A, int i, int m)
{
   int j = i, k = i*2+1;	 // левый сын
   while (k <= m)
   {
       if (k<m && A[k]<A[k+1]) k++; // больший сын
       if (A[j] < A[k])
       {  std::swap(A[j], A[k]); j = k; k = k*2+1; }
       else break;
   }
}

void heap_sort(double *A, int n, int len)
{
   int i, m;
   // построение пирамиды
   for (i = n/2; i >= 0; i--)
       sift(A, i, n-1);
   // сортировка массива
   for (m = n-1; m >= 1; m--)
   {
       std::swap(A[0], A[m]);
       sift(A, 0, m-1);
   }

}


QString parsing(QString data, QString id)
{

    QList<QString> parametrs = data.split("&");
   if(parametrs.count() == 3 && parametrs[0] == "sort" )
    {
        auto step = parametrs[1].toInt();
        auto arr_str = parametrs[2].remove(" ");
        auto base = new double[arr_str.length()];

        for (int i = 0; i < arr_str.length(); i++)
        {
            base[i] = QString(arr_str[i]).toDouble();
        }

        heap_sort(base, step, arr_str.length());
        auto len = arr_str.length();
        arr_str.clear();
        for (int l  = 0; l < len; l++)
        {
            arr_str += QString::number(base[l]) + " ";
        }
        return arr_str;
    }

    return "Error data parsing\r\n";
}

#endif // FUNCTIONS_H
