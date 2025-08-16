#include<stdio.h>
#include<stdlib.h>
#include<time.o>

int main(){
    // ===== Variáveis =====
    // Aqui guardamos os dados de cada carta (dois países)
    char pais1[50], pais2[50];
    char codigodacarta1[10], codigodacarta2[10];
    unsigned long int populacao1, populacao2; // População pode ser bem grande, por isso "unsigned long int"
    float area1, area2, PIB1, PIB2;           // Área e PIB podem ter casas decimais
    int pontosturisticos1, pontosturisticos2; // Pontos turísticos são números inteiros
    float densidade1, densidade2;             // Densidade demográfica = população / área
    float pibpercapita1, pibpercapita2;       // PIB per capita = PIB / população
    float superpoder1, superpoder2;           // Soma de todos os atributos
    int opcao1, opcao2;                       // Guardam as escolhas de atributos do jogador

    // ===== Entrada de dados da Carta 1 =====
    printf("Digite o Pais 1: "); scanf("%s", pais1);
    printf("Digite o codigo da carta 1: "); scanf("%s", codigodacarta1);
    printf("Digite a populacao: "); scanf("%lu", &populacao1);
    printf("Digite a area em km²: "); scanf("%f", &area1);
    printf("Digite o PIB: "); scanf("%f", &PIB1);
    printf("Digite o numero de pontos turisticos: "); scanf("%d", &pontosturisticos1);

    // ===== Entrada de dados da Carta 2 =====
    printf("\nDigite o Pais 2: "); scanf("%s", pais2);
    printf("Digite o codigo da carta 2: "); scanf("%s", codigodacarta2);
    printf("Digite a populacao: "); scanf("%lu", &populacao2);
    printf("Digite a area em km²: "); scanf("%f", &area2);
    printf("Digite o PIB: "); scanf("%f", &PIB2);
    printf("Digite o numero de pontos turisticos: "); scanf("%d", &pontosturisticos2);

    // ===== Cálculos derivados =====
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibpercapita1 = PIB1 / (float)populacao1;
    pibpercapita2 = PIB2 / (float)populacao2;

    // "superpoder" é a soma de todos os atributos.
    // Na densidade eu inverti com (1.0f/densidade), pois nesse atributo vence o menor valor.
    superpoder1 = populacao1 + area1 + PIB1 + pontosturisticos1 + pibpercapita1 + (1.0f/densidade1);
    superpoder2 = populacao2 + area2 + PIB2 + pontosturisticos2 + pibpercapita2 + (1.0f/densidade2);

    // ===== Menu para escolher o primeiro atributo =====
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("1. População\n2. Área\n3. Pontos turísticos\n4. Densidade (menor vence)\n5. PIB\n6. PIB per capita\n7. Super poder\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &opcao1);

    // ===== Menu dinâmico para o segundo atributo =====
    // Esse switch mostra apenas as opções que sobraram, para evitar repetir o mesmo atributo
    printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO (diferente do primeiro) ===\n");
    switch(opcao1){
        case 1: printf("2. Área\n3. Pontos turísticos\n4. Densidade\n5. PIB\n6. PIB per capita\n7. Super poder\n"); break;
        case 2: printf("1. População\n3. Pontos turísticos\n4. Densidade\n5. PIB\n6. PIB per capita\n7. Super poder\n"); break;
        case 3: printf("1. População\n2. Área\n4. Densidade\n5. PIB\n6. PIB per capita\n7. Super poder\n"); break;
        case 4: printf("1. População\n2. Área\n3. Pontos turísticos\n5. PIB\n6. PIB per capita\n7. Super poder\n"); break;
        case 5: printf("1. População\n2. Área\n3. Pontos turísticos\n4. Densidade\n6. PIB per capita\n7. Super poder\n"); break;
        case 6: printf("1. População\n2. Área\n3. Pontos turísticos\n4. Densidade\n5. PIB\n7. Super poder\n"); break;
        case 7: printf("1. População\n2. Área\n3. Pontos turísticos\n4. Densidade\n5. PIB\n6. PIB per capita\n"); break;
        default: printf("Opcao invalida!\n"); return 0;
    }
    printf("Escolha o segundo atributo: ");
    scanf("%d", &opcao2);

    // Se a pessoa digitar o mesmo atributo duas vezes, não faz sentido continuar
    if(opcao1 == opcao2){ 
        printf("Erro: não pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    // ===== Comparação =====
    // Aqui vamos guardar os valores dos atributos escolhidos
    float valor1a=0, valor1b=0, valor2a=0, valor2b=0; 

    // Primeiro atributo escolhido
    switch(opcao1){
        case 1: valor1a=populacao1; valor2a=populacao2; break;
        case 2: valor1a=area1; valor2a=area2; break;
        case 3: valor1a=pontosturisticos1; valor2a=pontosturisticos2; break;
        case 4: valor1a=densidade1; valor2a=densidade2; break;
        case 5: valor1a=PIB1; valor2a=PIB2; break;
        case 6: valor1a=pibpercapita1; valor2a=pibpercapita2; break;
        case 7: valor1a=superpoder1; valor2a=superpoder2; break;
    }

    // Segundo atributo escolhido
    switch(opcao2){
        case 1: valor1b=populacao1; valor2b=populacao2; break;
        case 2: valor1b=area1; valor2b=area2; break;
        case 3: valor1b=pontosturisticos1; valor2b=pontosturisticos2; break;
        case 4: valor1b=densidade1; valor2b=densidade2; break;
        case 5: valor1b=PIB1; valor2b=PIB2; break;
        case 6: valor1b=pibpercapita1; valor2b=pibpercapita2; break;
        case 7: valor1b=superpoder1; valor2b=superpoder2; break;
    }

    // ===== Resultado final =====
    // Se o atributo for densidade (opcao 4), vence o menor valor.
    // Por isso aqui eu inverto com "1/valor" para facilitar a soma.
    float soma1 = ((opcao1==4)? (1/valor1a):(valor1a)) + ((opcao2==4)? (1/valor1b):(valor1b));
    float soma2 = ((opcao1==4)? (1/valor2a):(valor2a)) + ((opcao2==4)? (1/valor2b):(valor2b));

    // Mostra os valores que foram comparados
    printf("\n=== RESULTADO ===\n");
    printf("%s -> %.2f + %.2f = %.2f\n", pais1, valor1a, valor1b, soma1);
    printf("%s -> %.2f + %.2f = %.2f\n", pais2, valor2a, valor2b, soma2);

    // ===== Decisão final =====
    // Aqui usei operador ternário para simplificar o if/else.
    (soma1 > soma2) ? printf("Vencedor: %s\n", pais1) :
    (soma2 > soma1) ? printf("Vencedor: %s\n", pais2) :
    printf("*** Empate! ***\n");

    return 0;
}
