#include <stdio.h>
#include <string.h>

// Definição da estrutura da Carta Super Trunfo - Países
typedef struct
{
    char Continente_Grupo;     // Adaptado de 'Estado': 'A' a 'H' para agrupar as cartas
    char Codigo_da_Carta[5];   // Letra do grupo + número (ex: A01)
    char Nome_do_Pais[50];     // Adaptado de 'Nome da Cidade': O nome do País
    long População_Milhoes;    // População em milhões de habitantes (usando long para números grandes)
    float Area_Km2_Milhares;   // Área em milhares de km²
    float PIB_Trilhoes_USD;    // PIB em trilhões de US$
    int Num_Pontos_Turisticos; // Número de Pontos Turísticos relevantes (índice de comparação)
} SuperTrunfoPais;

// Função para exibir os dados de uma carta
void exibir_carta(SuperTrunfoPais carta)
{
    printf("\n");
    printf(" SUPER TRUNFO PAÍSES \n");
    printf("\n");
    printf(" Código da Carta: %s\n", carta.Codigo_da_Carta);
    printf(" País: %s\n", carta.Nome_do_Pais);
    printf(" Grupo: %c\n", carta.Continente_Grupo);
    printf("\n");
    printf(" ATRIBUTOS:\n");
    // Multiplicação por 1.000.000 para clareza ao ler, mas o valor real é o 'long'
    printf(" 1. População (Habitantes): %ld.000.000\n", carta.População_Milhoes);
    printf(" 2. Área (km²): %.2f Milhões\n", carta.Area_Km2_Milhares / 1000.0);
    printf(" 3. PIB (USD): %.2f Trilhões\n", carta.PIB_Trilhoes_USD);
    printf(" 4. Nro. Pontos Turísticos: %d\n", carta.Num_Pontos_Turisticos);
    printf("\n");
}

int main()
{
    // --- CARTA 1: BRASIL ---
    SuperTrunfoPais carta1;
    carta1.Continente_Grupo = 'A'; // América do Sul
    strcpy(carta1.Codigo_da_Carta, "A01");
    strcpy(carta1.Nome_do_Pais, "Brasil");
    carta1.População_Milhoes = 217;     // 217 milhões
    carta1.Area_Km2_Milhares = 8515.77; // 8.515.770 km²
    carta1.PIB_Trilhoes_USD = 2.30;     // ~2.30 trilhões USD
    carta1.Num_Pontos_Turisticos = 95;  // Exemplo de índice

    // --- CARTA 2: CANADÁ ---
    SuperTrunfoPais carta2;
    carta2.Continente_Grupo = 'B'; // América do Norte
    strcpy(carta2.Codigo_da_Carta, "B03");
    strcpy(carta2.Nome_do_Pais, "Canadá");
    carta2.População_Milhoes = 41;      // 41 milhões
    carta2.Area_Km2_Milhares = 9984.67; // 9.984.670 km²
    carta2.PIB_Trilhoes_USD = 2.20;     // ~2.20 trilhões USD
    carta2.Num_Pontos_Turisticos = 70;  // Exemplo de índice

    // Exibição das cartas
    exibir_carta(carta1);
    exibir_carta(carta2);

    // calcular densidade populacional (habitantes por km²)
    double densidade1 = (double)carta1.População_Milhoes * 1000000 / (carta1.Area_Km2_Milhares * 1000);
    double densidade2 = (double)carta2.População_Milhoes * 1000000 / (carta2.Area_Km2_Milhares * 1000);

    printf("Densidade Populacional do %s: %.2f habitantes/km²\n", carta1.Nome_do_Pais, densidade1);
    printf("Densidade Populacional do %s: %.2f habitantes/km²\n", carta2.Nome_do_Pais, densidade2);

    // calcular PIB per capita
    double pib_per_capita1 = (carta1.PIB_Trilhoes_USD * 1000000000000) / (carta1.População_Milhoes * 1000000);
    double pib_per_capita2 = (carta2.PIB_Trilhoes_USD * 1000000000000) / (carta2.População_Milhoes * 1000000);

    printf("PIB per capita do %s: %.2f USD\n", carta1.Nome_do_Pais, pib_per_capita1);
    printf("PIB per capita do %s: %.2f USD\n", carta2.Nome_do_Pais, pib_per_capita2);

       // Função para comparar as carta
 //comparar população
    if (carta1.População_Milhoes > carta2.População_Milhoes)
        printf("%s tem maior população que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
    else if (carta1.População_Milhoes < carta2.População_Milhoes)
        printf("%s tem maior população que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
    else
        printf("Ambos os países têm a mesma população.\n");
  
        //comparar área
    if (carta1.Area_Km2_Milhares > carta2.Area_Km2_Milhares)
        printf("%s é maior em área que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
    else if (carta1.Area_Km2_Milhares < carta2.Area_Km2_Milhares)
        printf("%s é maior em área que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
    else
        printf("Ambos os países têm a mesma área.\n");

    //comparar PIB
    if (carta1.PIB_Trilhoes_USD > carta2.PIB_Trilhoes_USD)
        printf("%s tem maior PIB que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
    else if (carta1.PIB_Trilhoes_USD < carta2.PIB_Trilhoes_USD)
        printf("%s tem maior PIB que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
    else
        printf("Ambos os países têm o mesmo PIB.\n");

        //comparar pontos turísticos
    if (carta1.Num_Pontos_Turisticos > carta2.Num_Pontos_Turisticos)
        printf("%s tem mais pontos turísticos que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
    else if (carta1.Num_Pontos_Turisticos < carta2.Num_Pontos_Turisticos)
        printf("%s tem mais pontos turísticos que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
    else
        printf("Ambos os países têm o mesmo número de pontos turísticos.\n");

        //comparar PIB per capita
    if (pib_per_capita1 > pib_per_capita2)
        printf("%s tem maior PIB per capita que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
    else if (pib_per_capita1 < pib_per_capita2)
        printf("%s tem maior PIB per capita que %s,\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
    else
        printf("Ambos os países têm o mesmo PIB per capita.\n");

    //comparar densidade populacional
    if (densidade1 > densidade2)
        printf("%s tem maior densidade populacional que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
    else if (densidade1 < densidade2)
        printf("%s tem maior densidade populacional que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
    else
        printf("Ambos os países têm a mesma densidade populacional.\n");

        //declararação de carta vencedora geral
    int vitorias1 = 0;
    int vitorias2 = 0;
if (carta1.População_Milhoes > carta2.População_Milhoes) {
    vitorias1++;
} else if (carta1.População_Milhoes < carta2.População_Milhoes) {
    vitorias2++;
}

if (carta1.Area_Km2_Milhares > carta2.Area_Km2_Milhares) {
    vitorias1++;
} else if (carta1.Area_Km2_Milhares < carta2.Area_Km2_Milhares) {
    vitorias2++;
}

if (carta1.PIB_Trilhoes_USD > carta2.PIB_Trilhoes_USD) {
    vitorias1++;
} else if (carta1.PIB_Trilhoes_USD < carta2.PIB_Trilhoes_USD) {
    vitorias2++;
}

if (carta1.Num_Pontos_Turisticos > carta2.Num_Pontos_Turisticos) {
    vitorias1++;
} else if (carta1.Num_Pontos_Turisticos < carta2.Num_Pontos_Turisticos) {
    vitorias2++;
}

if (pib_per_capita1 > pib_per_capita2) {
    vitorias1++;
} else if (pib_per_capita1 < pib_per_capita2) {
    vitorias2++;
}

if (densidade1 > densidade2) {
    vitorias1++;
} else if (densidade1 < densidade2) {
    vitorias2++;
}

// Exibir resultado geral
    printf("\nResultado Geral:\n");
    if (vitorias1 > vitorias2)
        printf("%s é a carta vencedora com %d vitórias!\n", carta1.Nome_do_Pais, vitorias1);
    else if (vitorias2 > vitorias1)
        printf("%s é a carta vencedora com %d vitórias!\n", carta2.Nome_do_Pais, vitorias2);
    else
        printf("Empate! Ambos os países têm %d vitórias.\n", vitorias1);

        //menu interativo de cartas
    int escolha;
    printf("\nMenu Interativo de Cartas:\n");
    printf("1. Ver Carta do Brasil\n");
    printf("2. Ver Carta do Canadá\n");
    printf("3. Sair\n");
    do {
        printf("Escolha uma opção (1-3): ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                exibir_carta(carta1);
                break;
            case 2:
                exibir_carta(carta2);
                break;
            case 3:
                printf("Saindo do menu.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 3);

    //comparar cartas com base na escolha do usuário
    for (escolha = 0; escolha != 3; escolha++) {
        printf("Escolha uma carta para comparar (1 para Brasil, 2 para Canadá, 3 para sair): ");
        scanf("%d", &escolha);
        if (escolha == 1) {
            exibir_carta(carta1);
        } else if (escolha == 2) {
            exibir_carta(carta2);
        } else if (escolha == 3) {
            printf("Saindo da comparação de cartas.\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
        
        //regra de comparação simples
        if (escolha == 1 || escolha == 2) {
            printf("Comparando as cartas selecionadas:\n");
            if (carta1.População_Milhoes > carta2.População_Milhoes)
                printf("%s tem maior população que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
            else if (carta1.População_Milhoes < carta2.População_Milhoes)
                printf("%s tem maior população que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
            else
                printf("Ambos os países têm a mesma população.\n");
        }

        //exibir resultados da comparação
    for (int resultado = 0; resultado != 3; resultado++) {
        printf("Resultado da comparação:\n");
        if (carta1.População_Milhoes > carta2.População_Milhoes)
            printf("%s tem maior população que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
        else if (carta1.População_Milhoes < carta2.População_Milhoes)
            printf("%s tem maior população que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
        else
            printf("Ambos os países têm a mesma população.\n");

            //escolha dois atributos para comparar
        int atributo1, atributo2;
        printf("Escolha dois atributos para comparar (1-6): ");
        scanf("%d %d", &atributo1, &atributo2);
        if (atributo1 == 1 && atributo2 == 2) {
            
            //comparação de múltiplos atributos
            if (carta1.População_Milhoes > carta2.População_Milhoes)
                printf("%s tem maior população que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
            else if (carta1.População_Milhoes < carta2.População_Milhoes)
                printf("%s tem maior população que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
            else
                printf("Ambos os países têm a mesma população.\n");
        }

        //soma dos atributos escolhidos
        long soma_atributos1 = 0;
        long soma_atributos2 = 0;
        if (atributo1 == 1)
            soma_atributos1 += carta1.População_Milhoes;
        if (atributo2 == 1)
            soma_atributos2 += carta2.População_Milhoes;
        if (atributo1 == 2)
            soma_atributos1 += carta1.Area_Km2_Milhares;
        if (atributo2 == 2)
            soma_atributos2 += carta2.Area_Km2_Milhares;
        if (soma_atributos1 > soma_atributos2)
            printf("%s tem maior soma dos atributos escolhidos que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
        else if (soma_atributos1 < soma_atributos2)
            printf("%s tem maior soma dos atributos escolhidos que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
        else
            printf("Ambos os países têm a mesma soma dos atributos escolhidos.\n");
    }

    //tratamento de empates em comparações
    if (vitorias1 == vitorias2)
        printf("Empate na comparação geral entre %s e %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
       printf("Favor revisar os atributos para desempate.\n");
       printf("Considerar atributos adicionais ou critérios de desempate.\n");
        }

        //Menus Dinâmicos
        printf("\nMenus Dinâmicos:\n");
        printf("1. Ver Carta do Brasil\n");
        printf("2. Ver Carta do Canadá\n");
        printf("3. Comparar Cartas\n");
        printf("4. Sair\n");
        int opcao;
        do {
            printf("Escolha uma opção (1-4): ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    exibir_carta(carta1);
                    break;
                case 2:
                    exibir_carta(carta2);
                    break;
                case 3:
                    printf("Comparando as cartas selecionadas:\n");
                    // Reutilizar a lógica de comparação aqui
                    if (carta1.População_Milhoes > carta2.População_Milhoes)
                        printf("%s tem maior população que %s.\n", carta1.Nome_do_Pais, carta2.Nome_do_Pais);
                    else if (carta1.População_Milhoes < carta2.População_Milhoes)
                        printf("%s tem maior população que %s.\n", carta2.Nome_do_Pais, carta1.Nome_do_Pais);
                    else
                        printf("Ambos os países têm a mesma população.\n");
                    break;
                case 4:
                    printf("Saindo do menu dinâmico.\n");
                    break;
                default:
                    printf("Opção inválida. Tente novamente.\n");
            }
        } while (opcao != 4);
     
        //exibição final de resultados
        printf("\nExibição Final de Resultados:\n");
        printf("Carta do Brasil:\n");
        exibir_carta(carta1);
        printf("Carta do Canadá:\n");
        exibir_carta(carta2);
        // Fim do programa
        return 0;
}
