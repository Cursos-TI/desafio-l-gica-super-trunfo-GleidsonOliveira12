#include <stdio.h>

// Programa para comparar duas cartas com dados de cidades

int main() {
    // Declaração das variáveis para armazenar os dados de cada carta
    char estado1[50], estado2[50];
    char codigodacarta1[50], codigodacarta2[50];
    char nomedacidade1[50], nomedacidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float PIB1, PIB2;
    int pontosturisticos1, pontosturisticos2;
    float densidade1, densidade2;
    float pibpercapita1, pibpercapita2;
    float superpoder1, superpoder2;

    // Entrada dos dados da primeira carta
    printf("Digite o estado: \n");
    scanf("%s", estado1);

    printf("Digite o codigo da carta: \n");
    scanf("%s", codigodacarta1);

    printf("Digite o nome da cidade: \n");
    scanf("%s", nomedacidade1);

    printf("Digite a populacao: \n");
    scanf("%lu", &populacao1);

    printf("Digite a area em km²: \n");
    scanf("%f", &area1);

    printf("Digite o PIB: \n");
    scanf("%f", &PIB1);

    printf("Digite o numero de pontos turisticos: \n");
    scanf("%d", &pontosturisticos1);

    // Entrada dos dados da segunda carta
    printf("Digite o estado: \n");
    scanf("%s", estado2);

    printf("Digite o codigo da carta: \n");
    scanf("%s", codigodacarta2);

    printf("Digite o nome da cidade: \n");
    scanf("%s", nomedacidade2);

    printf("Digite a populacao: \n");
    scanf("%lu", &populacao2);

    printf("Digite a area em km²: \n");
    scanf("%f", &area2);

    printf("Digite o PIB: \n");
    scanf("%f", &PIB2);

    printf("Digite o numero de pontos turisticos: \n");
    scanf("%d", &pontosturisticos2);

    // Cálculo da densidade populacional e do PIB per capita para cada carta
    densidade1 = populacao1 / area1;
    pibpercapita1 = PIB1 / (float)populacao1;
    densidade2 = populacao2 / area2;
    pibpercapita2 = PIB2 / (float)populacao2;

    // Soma de todos os atributos para gerar o "superpoder" da carta
    superpoder1 = populacao1 + area1 + PIB1 + pontosturisticos1 + pibpercapita1 + (float)1 / densidade1;
    superpoder2 = populacao2 + area2 + PIB2 + pontosturisticos2 + pibpercapita2 + (float)1 / densidade2;

    // Impressão dos dados da primeira carta
    printf("==== CARTA 1 ====\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo da carta: %s\n", codigodacarta1);
    printf("Nome da cidade: %s\nPopulacao: %lu\n", nomedacidade1, populacao1);
    printf("Area em KM²: %f\nPIB : %f\n", area1, PIB1);
    printf("Numero de pontos turisticos: %d\n", pontosturisticos1);
    printf("Densidade populacional: %f\n", densidade1);
    printf("PIB PER CAPITA: %f\n", pibpercapita1);

    // Impressão dos dados da segunda carta
    printf("\n==== CARTA 2 ====\n");
    printf("Estado: %s\nCodigo da carta: %s\n", estado2, codigodacarta2);
    printf("Nome da cidade: %s\nPopulacao: %lu\n", nomedacidade2, populacao2);
    printf("Area em KM²: %f\nPIB : %f\n", area2, PIB2);
    printf("Numero de pontos turisticos: %d\n", pontosturisticos2);
    printf("Densidade populacional: %f\n", densidade2);
    printf("PIB PER CAPITA: %f\n", pibpercapita2);

    // Comparação entre as cartas (por enquanto só está comparando o atributo área)
    printf("\n**** COMPARACOES ****\n");
    if (area1 > area2) {
        printf("Carta 1 venceu em: Area em km²: %f\n", area1);
    } else {
        printf("Carta 2 venceu em: Area em km²: %f\n", area2);
    }

    return 0;
}
