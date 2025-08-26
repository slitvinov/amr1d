#include "grid/bitree.h"
void write_level (scalar * list, const char * tag, FILE * fp)
{
  for (int l = 0; l <= depth(); l++)
    foreach_level (l, serial) {
      fprintf (fp, "%s%d %g ", tag, l, x);
      for (scalar s in list)
        fprintf (fp, "%g ", s[]);
      fputc ('\n', fp);
    }
}
int main()
{
  init_grid (128);
  periodic (right);
  size (2);
  scalar s[], w[], s2[];
  foreach()
    s[] = sin(2.*pi*x) + 0.4*sin(15*pi*x)*max(sin(2.*pi*x), 0);
  wavelet (s, w);
  inverse_wavelet (s2, w);
  foreach()
    assert (fabs (s2[] - s[]) < 1e-12);
  write_level ({s,w}, "", stderr);
  for (int l = 5; l <= 6; l++) {
    foreach_level (l)
      w[] *= (x <= 1);
    boundary_level ({w}, l);
  }
  inverse_wavelet (s2, w);
  write_level ({s2,w}, "a", stdout);
  wavelet (s, w);
  for (int l = 0; l < 5; l++) {
    foreach_level (l)
      w[] = 0.;
    boundary_level ({w}, l);
  }
  inverse_wavelet (s2, w);
  write_level ({s2,w}, "b", stdout);
  wavelet (s, w);
  unrefine (fabs(w[]) < 0.1);
  write_level ({s,w}, "c", stdout);
}
