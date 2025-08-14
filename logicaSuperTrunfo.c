#include<stdio.h>   // Biblioteca padrão de entrada e saída
#include<stdlib.h>  // Biblioteca Nova
// NOVO COMMIT
// Função principal
int main(){
    // Declaração de variáveis para os dados de cada carta
    char pais1[50], pais2[50];               // Nomes dos países
    char codigodacarta1[50], codigodacarta2[50]; // Código das cartas
    unsigned long int populacao1, populacao2;    // População dos países
    float area1, area2;                          // Área em km²
    float PIB1, PIB2;                            // Produto Interno Bruto
    int pontosturisticos1, pontosturisticos2;   // Número de pontos turísticos
    float densidade1, densidade2;               // Densidade populacional (população/área)
    float pibpercapita1, pibpercapita2;         // PIB per capita (PIB/população)
    float superpoder1, superpoder2;             // Valor que representa a "força" da carta
    int opcao;                                   // Opção do menu para comparar atributos

    // ======== Entrada de dados para a carta 1 ========
    printf("Digite o Pais: \n");
    scanf("%s", pais1);  // Lê o nome do país

    printf("Digite o codigo da carta: \n");
    scanf("%s", codigodacarta1);  // Lê o código da carta

    printf("Digite a populaçao: \n");
    scanf("%lu", &populacao1);    // Lê a população (número grande)

    printf("Digite a area em km²: \n");
    scanf("%f", &area1);          // Lê a área em km²

    printf("Digite o PIB: \n");
    scanf("%f",&PIB1);            // Lê o PIB do país

    printf("Digite o numero de pontos turisticos: \n");
    scanf("%d", &pontosturisticos1); // Lê os pontos turísticos

    // ======== Entrada de dados para a carta 2 ========
    printf("Digite o Pais: \n");
    scanf("%s", pais2);

    printf("Digite o codigo da carta: \n");
    scanf("%s", codigodacarta2);

    printf("Digite a populaçao: \n");
    scanf("%lu", &populacao2);

    printf("Digite a area em km²: \n");
    scanf("%f", &area2);

    printf("Digite o PIB: \n");
    scanf("%f",&PIB2);

    printf("Digite o numero de pontos turisticos: \n");
    scanf("%d", &pontosturisticos2);

    // ======== Cálculos derivados ========
    densidade1= populacao1/area1;               // Calcula densidade populacional
    pibpercapita1 = PIB1 / (float)populacao1;   // Calcula PIB per capita
    densidade2 = populacao2/area2;
    pibpercapita2 = PIB2 / (float)populacao2;

    // Calcula o "superpoder" da carta, somando todos os atributos numéricos
    // Inclui o inverso da densidade para dar vantagem a países menos densos
    superpoder1 = populacao1 + area1 + PIB1 + pontosturisticos1 + pibpercapita1 + (float)1 / densidade1;
    superpoder2 = populacao2 + area2 + PIB2 + pontosturisticos2 + pibpercapita2 + (float)1 / densidade2;

    // ======== Menu de comparação ========
    printf("\n**** MENU DE COMPARAÇOES ****\n");
    printf("\n*** ESCOLHA UMA ATRIBUTO PARA COMPARAR ****\n: ");
    printf("1. População: \n");
    printf("2. Area em km²: \n");
    printf("3. Numero de ponto turisticos :\n");
    printf("4. Densidade populaconal (Menor vence):\n");
    printf("5. Pib :\n");
    printf("6. Pibpercapita :\n");
    printf("7. Super poder : \n");
    printf("Escolha uma opção : \n");
    scanf("%d", &opcao); // Lê a escolha do usuário

    // ======== Comparação de acordo com a opção ========
    switch (opcao)
    {
        case 1: // Comparação de população
            printf("Comparando população\n: ");
            printf("%s:%lu\n", pais1, populacao1);
            printf("%s:%lu\n", pais2, populacao2);
            if (populacao1 > populacao2)
                printf("Vencedor : %s", pais1);
            else if (populacao2 > populacao1)
                printf("Vencedor : %s", pais2);
            else
                printf("*** Empate ! ****\n");
            break;

        case 2: // Comparação de área
            printf("Comparando area:\n");
            printf("%s: %f\n", pais1, area1);
            printf("%s: %f\n", pais2, area2);
            if (area1 > area2)
                printf("Vencedor : %s", pais1);
            else if (area2 > area1)
                printf("Vencedor : %s", pais2);
            else
                printf("*** Empate ! ****\n");
            break;

        case 3: // Comparação de pontos turísticos
            printf("Comparando numero de pontos turisticos:\n");
            printf("%s: %d\n", pais1, pontosturisticos1);
            printf("%s: %d\n", pais2, pontosturisticos2);
            if (pontosturisticos1 > pontosturisticos2)
                printf("Vencedor : %s", pais1);
            else if (pontosturisticos2 > pontosturisticos1)
                printf("Vencedor : %s", pais2);
            else
                printf("*** Empate ! ****\n");
            break;

        case 4: // Comparação de densidade (menor vence)
            printf("Comparando Densidade populacional ( menor vence):\n");
            printf("%s: %f\n", pais1, densidade1);
            printf("%s: %f\n", pais2, densidade2);
            if (densidade1 < densidade2)
                printf("Vencedor : %s", pais1);
            else if (densidade2 < densidade1)
                printf("Vencedor : %s", pais2);
            else
                printf("*** Empate ! ****\n");
            break;

        case 5: // Comparação de PIB
            printf("Comparando PIB:\n");
            printf("%s: %f\n", pais1, PIB1);
            printf("%s: %f\n", pais2, PIB2);
            if (PIB1 > PIB2)
                printf("Vencedor : %s", pais1);
            else if (PIB2 > PIB1)
                printf("Vencedor : %s", pais2);
            else
                printf("*** Empate ! ****\n");
            break;

        case 6: // Comparação de PIB per capita
            printf("Comparando PIB PER CAPITA:\n");
            printf("%s: %f\n", pais1, pibpercapita1);
            printf("%s: %f\n", pais2, pibpercapita2);
            if (pibpercapita1 > pibpercapita2)
                printf("Vencedor : %s", pais1);
            else if (pibpercapita2 > pibpercapita1)
                printf("Vencedor : %s", pais2);
            else
                printf("*** Empate ! ****\n");
            break;

        case 7: // Comparação de superpoder
            printf("Comparando SUPER PODER:\n");
            printf("%s: %f\n", pais1, superpoder1);
            printf("%s: %f\n", pais2, superpoder2);
            if (superpoder1 > superpoder2)
                printf("Vencedor : %s", pais1);
            else if (superpoder2 > superpoder1)
                printf("Vencedor : %s", pais2);
            else
                printf("*** Empate ! ****\n");
            break;

        default: // Caso o usuário digite uma opção inválida
            printf("Opção Inválida\n");
            break;
    }

    return 0; // Finaliza o programa
}
