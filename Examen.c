/* Fernanda Arely Moreno De León
Proyecto final */


#include <stdio.h>

#define MAX_OYENTES 100
#define MAX_CANCIONES 10

// Función 1: Leyendo votos y ver cuántos oyentes participaron
int leerVotos(int votos[][3]) {
    int c1, c2, c3;
    int n = 0;

    printf("Ingresar 3 números del 0 al 9 por oyente. Usar -1 para terminar.\n");

    while (n < MAX_OYENTES) {
        printf("Oyente %d: ", n);
        scanf("%d", &c1);

        if (c1 == -1) {
            break;
        }

        scanf("%d %d", &c2, &c3);

        votos[n][0] = c1;
        votos[n][1] = c2;
        votos[n][2] = c3;

        n++;
    }

    return n;
}

// Función 2: Calculando puntos por canción
void calcularPuntosCanciones(int votos[][3], int n, int puntos[]) {

    int i;
    for (i = 0; i < MAX_CANCIONES; i++)
        puntos[i] = 0;

    for (i = 0; i < n; i++) {
        puntos[votos[i][0]] += 3;
        puntos[votos[i][1]] += 2;
        puntos[votos[i][2]] += 1;
    }
}

// Función 3A: Obtener la canción más votada
int obtenerPrimera(int puntos[]) {
    int i, mayor = 0;

    for (i = 1; i < MAX_CANCIONES; i++) {
        if (puntos[i] > puntos[mayor]) {
            mayor = i;
        }
    }

    return mayor;
}

// Función 3B: Obtener la segunda canción más votada (diferente a la primera)
int obtenerSegunda(int puntos[], int primera) {
    int i, segunda = -1;

    for (i = 0; i < MAX_CANCIONES; i++) {

        if (i == primera)
            continue;

        if (segunda == -1 || puntos[i] > puntos[segunda]) {
            segunda = i;
        }
    }

    return segunda;
}

// Función 4: Calcular puntos de cada oyente
void calcularPuntosOyentes(int votos[][3], int n, int primera, int segunda, int puntosOyente[]) {

    int i;

    for (i = 0; i < n; i++) {

        int tiene1 = 0;
        int tiene2 = 0;

        if (votos[i][0] == primera || votos[i][1] == primera || votos[i][2] == primera)
            tiene1 = 1;

        if (votos[i][0] == segunda || votos[i][1] == segunda || votos[i][2] == segunda)
            tiene2 = 1;

        puntosOyente[i] = 0;

        if (tiene1) puntosOyente[i] += 30;
        if (tiene2) puntosOyente[i] += 20;
        if (tiene1 && tiene2) puntosOyente[i] += 10;
    }
}

// Función 5: Obtener ganador
int obtenerGanador(int puntosOyente[], int n) {

    int g = 0;
    int i;

    for (i = 1; i < n; i++) {
        if (puntosOyente[i] > puntosOyente[g]) {
            g = i;
        }
    }

    return g;
}

// Función 6: Mostrar resultados
void mostrarResultados(int puntosCancion[], int primera, int segunda, int puntosOyente[], int n, int ganador) {

    int i;

    printf("\nPuntos por canción:\n");
    for (i = 0; i < MAX_CANCIONES; i++)
        printf("Cancion %d: %d puntos\n", i, puntosCancion[i]);

    printf("\nPrimera más votada: %d\n", primera);
    printf("Segunda más votada: %d\n", segunda);

    printf("\nPuntos por oyente:\n");
    for (i = 0; i < n; i++)
        printf("Oyente %d: %d puntos\n", i, puntosOyente[i]);

    printf("\nGanador: Oyente %d\n", ganador);
}

int main() {

    int votos[MAX_OYENTES][3];
    int puntosCancion[MAX_CANCIONES];
    int puntosOyente[MAX_OYENTES];
    int n, primera, segunda, ganador;
    n = leerVotos(votos);
    calcularPuntosCanciones(votos, n, puntosCancion);

    primera = obtenerPrimera(puntosCancion);
    segunda = obtenerSegunda(puntosCancion, primera);

    calcularPuntosOyentes(votos, n, primera, segunda, puntosOyente);

    ganador = obtenerGanador(puntosOyente, n);

    mostrarResultados(puntosCancion, primera, segunda, puntosOyente, n, ganador);

    return 0;
}
