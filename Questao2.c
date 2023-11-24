#include <stdio.h>

int main() {
  int meses, i;
  double quantia, taxa, final;
  scanf("%d %lf %lf", &meses, &quantia, &taxa);
  final = 0;
  for (i = 1; i <= meses; i++) {
    final = (final + quantia) * (1 + taxa);
    printf("Montante ao fim do mes %d: R$ %.2lf\n", i, final);
  }
  return 0;
}