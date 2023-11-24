#include <stdio.h>
#include <string.h>


int valor(char c) {
  switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}

int converter_romano(char *romano) {
  int numero = 0;
  int i, len = strlen(romano);
  for (i = 0; i < len; i++) {
    int atual = valor(romano[i]);
    int proximo = valor(romano[i+1]);
    if (atual < proximo) {
      numero -= atual;
    } else {
      numero += atual;
    }
  }
  return numero;
}


void mostrar_base(int numero, int divisor) {
  char base16[] = "0123456789abcdef";
  char resultado[32];
  int i = 0;
  while (numero > 0) {
    resultado[i] = base16[numero % divisor];
    numero /= divisor;
    i++;
  }

  while (i > 0 && resultado[i-1] == '0') {
    i--;
  }

  while (i > 0) {
    printf("%c", resultado[i-1]);
    i--;
  }
  printf("\n");
}

int main() {
  char romano[13];
  int numero;
  scanf("%s", romano);
  numero = converter_romano(romano);
  printf("%s na base 2: ", romano);
  mostrar_base(numero, 2);
  printf("%s na base 10: ", romano);
  mostrar_base(numero, 10);
  printf("%s na base 16: ", romano);
  mostrar_base(numero, 16);
  return 0;
}