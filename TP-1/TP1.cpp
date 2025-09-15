#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_NUMERIC, "C");

    FILE* pfile; // Apontador para uma estrutura de um ficheiro

    char nome_ficheiro[] = { "dados.txt" }; // String com o nome do ficheiro
    float* valores; // Apontador para o array dinâmico, que guarda os valores // lidos do ficheiro
    int nclasses, nelems; // nº de classes e nº de elementos da amostra
    int i;

    ///////////////////////////////////////////////////////////
    // Abertura do ficheiro e leitura dos dados do ficheiro para o array
    //

    pfile = fopen(nome_ficheiro, "r"); // Abertura do ficheiro em modo de leitura

    if (pfile == NULL)
    { // Erro na abertura do ficheiro, termina o programa

        printf("Erro na abertura do ficheiro: %s\n", nome_ficheiro);
        return 1;
    }

    // Leitura da 1ª linha com o número de classes do histograma
    fscanf(pfile, "%d", &nclasses);

    // Leitura da 2ª linha com o número de elementos da amostra
    fscanf(pfile, "%d", &nelems);

    valores = new float[nelems]; // criação do array dinâmico
    
    if (valores == NULL)
    {// erro na alocação de memória

        printf("Erro na alocação de memória\n");
        return 1; // termina o programa
    }

    // Leitura dos elementos da amostra
    for (i = 0; i < nelems; i++)
    {
        fscanf(pfile, "%f,", &valores[i]);
    }

    fclose(pfile); // fecho do ficheiro

    ///////////////////////////////////////////////////////////
    // C O M P L E T A R
    delete[] valores; // libertação da memória ocupada pelo array dinâmico
    return 0;
}