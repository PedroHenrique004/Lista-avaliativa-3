#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char placa[9], dia_da_semana[20];
    int ultimo_numero, numero_do_dia;
    char letras[4], numeros[5];
    int n;
    int dia_valido = 1;
    int placa_valida = 1;

    scanf("%s", placa);
    scanf("%s", dia_da_semana);

    int comprimento = strlen(placa);

    if (strcmp(dia_da_semana, "SEGUNDA-FEIRA") == 0 || strcmp(dia_da_semana, "TERCA-FEIRA") == 0 || strcmp(dia_da_semana, "QUARTA-FEIRA") == 0 || strcmp(dia_da_semana, "QUINTA-FEIRA") == 0 || strcmp(dia_da_semana, "SEXTA-FEIRA") == 0 || strcmp(dia_da_semana, "SABADO") == 0 || strcmp(dia_da_semana, "DOMINGO") == 0) {
        
    } else {
        dia_valido = 0;
    }

    if (comprimento >= 7 && comprimento <= 8) { 
        n = sscanf(placa, "%3s-%1s%3s", letras, &numeros[0], &numeros[1]);
        if (n == 3) {
            if (isupper(letras[0]) && isupper(letras[1]) && isupper(letras[2]) && isalnum(numeros[0]) && isalnum(numeros[1]) && isalnum(numeros[2])){
                ultimo_numero = atoi(&numeros[2]);
            } else {
                placa_valida = 0;
            }
        } else {
            n = sscanf(placa, "%3s%1s%3s", letras, &numeros[0], &numeros[1]);
            if (n == 3) {
                if (isupper(letras[0]) && isupper(letras[1]) && isupper(letras[2]) && isalnum(numeros[0]) && isalnum(numeros[1]) && isalnum(numeros[2])) {
                    ultimo_numero = atoi(&numeros[2]);
                } else {
                    placa_valida = 0;
                }
            } else {
                placa_valida = 0;
            }
        }
    } else {
        placa_valida = 0;
    }

    if (dia_valido) {
        if (strcmp(dia_da_semana, "SEGUNDA-FEIRA") == 0) {
            numero_do_dia = 1;
        } else if (strcmp(dia_da_semana, "TERCA-FEIRA") == 0) {
            numero_do_dia = 2;
        } else if (strcmp(dia_da_semana, "QUARTA-FEIRA") == 0) {
            numero_do_dia = 3;
        } else if (strcmp(dia_da_semana, "QUINTA-FEIRA") == 0) {
            numero_do_dia = 4;
        } else if (strcmp(dia_da_semana, "SEXTA-FEIRA") == 0) {
            numero_do_dia = 5;
        } else if (strcmp(dia_da_semana, "SABADO") == 0 || strcmp(dia_da_semana, "DOMINGO") == 0) {
            numero_do_dia = 6;
        }
    }

    if (!placa_valida) {
        printf("Placa invalida\n");
    }

    if (!dia_valido) {
        printf("Dia da semana invalido\n");
    }

    if (placa_valida && dia_valido) {
        switch (numero_do_dia) {
            case 1:
                if (ultimo_numero == 0 || ultimo_numero == 1) {
                    printf("%s nao pode circular %s\n", placa, strlwr(dia_da_semana));
                } else {
                    printf("%s pode circular %s\n", placa, strlwr(dia_da_semana));
                }
                break;

            case 2:
                if (ultimo_numero == 2 || ultimo_numero == 3) {
                    printf("%s nao pode circular %s\n", placa, strlwr(dia_da_semana));
                } else {
                    printf("%s pode circular %s\n", placa, strlwr(dia_da_semana));
                }
                break;

            case 3:
                if (ultimo_numero == 4 || ultimo_numero == 5) {
                    printf("%s nao pode circular %s\n", placa, strlwr(dia_da_semana));
                } else {
                    printf("%s pode circular %s\n", placa, strlwr(dia_da_semana));
                }
                break;

            case 4:
                if (ultimo_numero == 6 || ultimo_numero == 7) {
                    printf("%s nao pode circular %s\n", placa, strlwr(dia_da_semana));
                } else {
                    printf("%s pode circular %s\n", placa, strlwr(dia_da_semana));
                }
                break;

            case 5:
                if (ultimo_numero == 8 || ultimo_numero == 9) {
                    printf("%s nao pode circular %s\n", placa, strlwr(dia_da_semana));
                } else {
                    printf("%s pode circular %s\n", placa, strlwr(dia_da_semana));
                }
                break;

            case 6:
                printf("Nao ha proibicao no fim de semana\n");
                break;
        }
    }

    return 0;
}
