#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

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
    
    if (valores == NULL) // erro na alocação de memória
    {
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
    //codigo novo


    float temp = 0, amp_elems = 0,val_min ,val_max , amp_classes = 0, media, sum_elems = 0, dp, sum_dp = 0;
    
    int n, j;

    do //algoritmo para organizar os elementos por ordem crescente
    {
        n = 0;

        for (j = 0; j < (nelems - 1); j++)
        {
            if (valores[j] > valores[j + 1])
            {
                temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = temp;

                n++;
            }
        }
        
    } while (n > 0);

    val_min = valores[0];
    val_max = valores[nelems - 1];

    amp_elems = val_max - val_min; //amplitude dos elementos

    amp_classes = amp_elems / nclasses; //amplitude por classe

    //titulos das colunas
    printf("%12s     | %5s | %8s | %s\n", "Valores", "Freq Abs", "Freq Rel", "Histograma");

    for (int b = 0; b < nclasses; b++) //loop por linha
    {
        int fa = 0;
        float lim_inf, lim_sup, fr = 0;
        char hg = '*'; 

        lim_inf = val_min + (amp_classes * b);
        lim_sup = val_min + (amp_classes * (b + 1));

        printf(" %5.2f a %.2f ", lim_inf, lim_sup); //coluna de valores
        
        if (b < nclasses - 1)
        {
            printf("  |");
        } else printf(" |");
        
        for (int c = 0; c < nelems; c++) //coluna frequencia absoluta
        {
            if (lim_sup == val_max)
            {
                if (valores[c] >= lim_inf && valores[c] <= lim_sup)
                {
                    fa++;
                }
            }
            
            else if (valores[c] >= lim_inf && valores[c] < lim_sup)
            {
                fa++;
            }
        }

        printf("%6d   ", fa);

        printf(" |");

        fr = (fa * 100) / nelems; //coluna frequencia relativa
        printf("%7.1f  ", fr);
        
        printf(" |");

        printf("   ");
        for (int d = 0; d < fa; d++) //coluna representação grafica
        {
            printf("%c", hg);
        }

        printf("\n");
    }
    
    for (int e = 0; e < nelems; e++) //loop para somatorio
    {
        sum_elems += valores[e];
    }
    media = sum_elems / nelems; //calculo da media
    printf("\nMédia: %.2f\n", media);

    for (int f = 0; f < nelems; f++) //loop para somatorio do desvio-padrao
    {
        sum_dp += pow(valores[f] - media, 2);
    }
    dp = sqrt(sum_dp / nelems); // calculo do desvio-padrao
    printf("Desvio padrão: %.2f\n\n\n", dp);


    delete[] valores; // libertação da memória ocupada pelo array dinâmico
    
    return 0;
}