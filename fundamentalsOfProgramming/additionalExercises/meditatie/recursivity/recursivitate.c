
/*
    STIVA:

    n = 1 STOP
    n = 2 1 * 2
    n = 3 2 * 3
    n = 4 6 * 4
    n = 5 24 * 5

    fiecare apel recursiv creeaza un cadru pe STIVA
    //adresa de intoarcere (unde sa revina dupa rezolvare)
*/

int factorial( int n ) {

    if( n == 1 ) return 1;
                    //factorial(2-1)
    else return n * factorial( n - 1 );//fiecare autoapel genereaza in STIVA program un nou nivel
}

/*
level5: factorial(1) se opreste, si revina la adresa anterioara |
level4: factorial(2) rezolva expresia si revina la adresa anterioara |
level3: factorial(3)  |
level2: factorial(4)  |
level1: factorial(5)  |

dupa ce ajuns inapoi se intoare in functia main()

*/

//0! = 1
//1! = 1

//n! = n(n-1)!
//factorial(5) = 5! = 5 * 4! =

int main(int argc, char const *argv[]) {


  int n = 5;

  printf("factorial(%d) = %d", n, factorial(n));//adresa
  return 0;
}

