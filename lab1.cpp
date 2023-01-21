#include <iostream>
#include <vector>
const int N = 5;
struct point
{
    double x, y;
};
int main()
{
   std::vector <point> mas(N);
   std::vector <point> nosort(N);
   std::vector <point> sort(N);


   point one, two, three, four, five;

   one.x = 2;
   one.y = 1;
   two.x = 1;
   two.y = 4;
   three.x = 4;
   three.y = 5;
   four.x = 5;
   four.y = 2;
   five.x = 3;
   five.y = 3;



   mas[0] = one;
   mas[1] = two;
   mas[2] = three;
   mas[3] = four;
   mas[4] = five;

   //for (int i = 0; i < N; i++) {
     //  point temp;
     //  std::cin >> temp.x;
     //  std::cin>> temp.y;
     //  mas[i] = temp;
 //  }

   for (int i = 0; i < N; i++) {
       nosort[i] = mas[i];
   }
    
   sort[0] = mas[0];


   for (int i = 0; i < N; i++) {
       if (sort[0].y > mas[i].y) {
           sort[0] = mas[i];
       }
       else if (sort[0].y == mas[i].y) {
           if (sort[0].x < mas[i].x) {
               sort[0] = mas[i];
           }
  }
   }





  

   int t = 0;
   int schet = 0;
   int ii;

   while (1) {

       for (int e = 0; e < nosort.size(); e++) {

           for (int i = 0; i < nosort.size(); i++) {

               if (i != e && nosort[e].x != sort[t].x && nosort[e].y != sort[t].y ) {
                   double d = (nosort[i].x - sort[t].x) * (nosort[e].y - sort[t].y) - (nosort[i].y - sort[t].y) * (nosort[e].x - sort[t].x);
                   if (d < 0) {
                       schet++;
                   }
                   
               }

               if (nosort[e].x == sort[t].x && nosort[e].y ==  sort[t].y) {
                   schet++;
               }
           }

           if (schet == 0) {
               ii = e;


           }

           schet = 0;

       }






       if (sort[0].x != nosort[ii].x && sort[0].y != nosort[ii].y) {
           t++;
           sort[t] = nosort[ii];
           auto iter = nosort.cbegin();
           nosort.erase(iter + ii);
       }
       else {
           break;
       }


   }


   for (int i = 0; i < sort.size(); i++) {
       if (sort[i].x !=0 && sort[i].y!=0)
       std::cout << sort[i].x << ' ' << sort[i].y << std::endl;
   }

}

