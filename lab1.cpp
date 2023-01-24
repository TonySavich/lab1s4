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
    two.x = 4;
    two.y = 4;
    three.x = 5;
    three.y = 3;
    four.x = 4;
    four.y = 7;
    five.x = 9;
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
    bool up = false;
    bool down = false;

    while (1) {

        for (int e = 0; e < nosort.size(); e++) {

            for (int i = 0; i < nosort.size(); i++) {

                if (i != e && (nosort[e].x != sort[t].x || nosort[e].y != sort[t].y)) {
                    double d = (nosort[i].x - sort[t].x) * (nosort[e].y - sort[t].y) - (nosort[i].y - sort[t].y) * (nosort[e].x - sort[t].x);

                    if (sort[t].y == nosort[e].y) {
                        if (sort[t].y > nosort[i].y) {
                            up = true;
                        }
                        if (sort[t].y < nosort[i].y) {
                            down = true;
                        }


                    }
                    else if (d < 0) {
                        schet++;
                    }

                }

                if (nosort[e].x == sort[t].x && nosort[e].y == sort[t].y) {
                    schet++;
                }


            }

            if (schet == 0 && (up == false || down == false)) {

                if (t > 0) {
                    if (nosort[e].x != sort[t - 1].x || nosort[e].y != sort[t - 1].y) {
                        ii = e;
                    }
                }
                else {
                    ii = e;
                }




            }

            schet = 0;
            up = false; 
            down = false;

        }






        if (sort[0].x != nosort[ii].x || sort[0].y != nosort[ii].y) {
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
        if (sort[i].x != 0 && sort[i].y != 0)
            std::cout << sort[i].x << ' ' << sort[i].y << std::endl;
    }

}
