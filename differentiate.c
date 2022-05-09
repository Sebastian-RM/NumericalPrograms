#include <stdio.h>
#include <math.h>

//
//     reports numerical approximations to a derivative
//     reports absolute error for different step sizes
//

int main()
{
  double h, fd, cd, x, exact,fpd;
  int i;

  FILE* file = fopen("diff_results.dat", "w");
    
  x = 1.0;
  exact = cos(x);

  for(i=1; i<=20; i++)
  {
    h = 0.5 * pow(5.0, -i);

    fd = (sin(x+h) - sin(x)) / h;
    cd = 0.5 * (sin(x+h) - sin(x-h)) / h;
      fpd = 1/(12*h) * (sin(x-2*h)+8*sin(x+h)-(sin(x+2*h)+8*sin(x-h)));

    fprintf(file, "%E %E %E %E\n", h, fabs(fd-exact), fabs(cd-exact),fabs(fpd-exact));
  }
  fclose(file);

  return 0;
}

