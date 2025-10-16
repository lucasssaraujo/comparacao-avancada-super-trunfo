#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char sigla1[5], sigla2[5], cidade1[30], cidade2[30], codigo[5];
    int pontosTuristicos1, pontosTuristicos2;
    float area1, area2, pib1, pib2, densidade1, pibPerCapta1, densidade2, pibPerCapta2;
    
    int populacao1 = (unsigned long int)populacao1;
    int populacao2 = (unsigned long int)populacao2;

    printf("Jogo de Cartas Super Trunfo!! \n\n");
    printf("Este jogo será baseado em cidades, você irá preencher as informações das cidade conforme é solicitado \n\n");
    

    //printf("Carta 1\n");
    printf("Estado: ");
    fgets(sigla1, sizeof(sigla1), stdin);
    sigla1[strcspn(sigla1, "\n")] = 0;

    /* Foi preciso utilizar getchar e limpar o /n, pois estava dando conflito entre fgets e o scanf.
    haviam campos que estavam sendo ignorados */

    printf("Código: ");    
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    printf("Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &populacao1);
    getchar();

    printf("Área: ");
    scanf("%f", &area1);
    getchar();

    printf("PIB: ");
    scanf("%f", &pib1);
    getchar();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);
    getchar();

    densidade1 = populacao1 / area1;     //implementação do desafio densidade populacional e pib per capta
    pibPerCapta1 =  pib1 / populacao1;

       //população deve ser armazenada como unsigned long int 
    


    printf("\n\n\nPrimeira Carta\n"
        "Estado: %s\n"
        "Código: %s\n"
        "Cidade: %s\n"
        "População: %d\n"
        "Área: %.2fkm²\n"
        "PIB: %.2f\n"
        "Número de Pontos Turísticos: %d\n"
        "Densidade Populacional: %.2f hab/km²\n"
        "PIB per Capita: %.2f reais\n"
        , sigla1, codigo, cidade1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapta1);




    //printf("\n\nCarta 2\n");
    printf("\n\n\n\nEstado: ");
    fgets(sigla2, sizeof(sigla2), stdin);
    sigla2[strcspn(sigla2, "\n")] = 0;

    printf("Código: ");    
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    printf("Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &populacao2);
    getchar();

    printf("Área: ");
    scanf("%f", &area2);
    getchar();

    printf("PIB: ");
    scanf("%f", &pib2);
    getchar();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    getchar();

    densidade2 = populacao2 / area2;     //implementação do desafio
    pibPerCapta2 =  pib2 / populacao2;


    printf("\n\n\n\nSegunda Carta\n"
        "Estado: %s\n"
        "Código: %s\n"
        "Cidade: %s\n"
        "População: %d\n"
        "Área: %.2fkm²\n"
        "PIB: %.2f\n"
        "Número de Pontos Turísticos: %d\n"
        "Densidade Populacional: %.2f hab/km²\n"
        "PIB per Capita: %.2f reais\n\n"
        , sigla2, codigo, cidade2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapta2);

/* Comentei este desafio, pois o menu interativo será uma versão melhorada dele
    //Implementação do desafio de comparação
    printf("Comparação de cartas (Atributo: PIB):\n"
           "Carta 1 - %s (%s): %.2f\n"
           "Carta 2 - %s (%s): %.2f\n",
            cidade1, sigla1, pib1,
            cidade2, sigla2, pib2
        );
    
    if(pib1 > pib2) { //estrutura de decisão para fazer comparação do valor do pib das duas cartas e imprimir de acordo com o resultado
        printf("Resultado: Carta 1 (%s) Venceu", cidade1);
    } else {
        printf("Resultado: Carta 2 (%s) Venceu", cidade2);
    };
 */

// _______________________________________________________________________________________________________
    //Implementação do desafio utilizando menu interativo


    int opcao; //variável para armazenar a opção digitada pelo usuário

    //irei criar um array com um ponteiro com as opções disponíveis para deixar mais automatizado 
    // o código e para não ter que ficar repetindo toda hora
    char *textoOpcao[] = {"Populaçao", "Área", "PIB", "Número de pontos turísticos", "Densidade demográfica"};
     
    printf(
        "Selecione uma opção para comparar atributos das duas cartas:\n"
         "1. População\n"
         "2. Área\n"
         "3. PIB\n"
         "4. Número de pontos turísticos\n"
         "5. Densidade demográfica\n"
    ); 

    scanf("%d", &opcao);
    opcao--; //irei decrementar o valor para usar como indice no array textoOpcao
    
    //criei estes arrays para armazenar as variáveis que serão comparadas, para deixar mais automatizado
    //e o código não ficar repetitivo, comparando variável por variável
    float variaveisCarta1[] = {populacao1, area1, pib1, pontosTuristicos1, densidade1};
    float variaveisCarta2[] = {populacao2, area2, pib2, pontosTuristicos2, densidade2};
    

    switch (opcao) {
    case 0:
    case 1:
    case 2:
    case 3:
        printf("\n\n%s x %s\n"
               "Atributo usado: %s\n"
                "(%s) %.2f - (%s) %.2f\n", 
                cidade1, cidade2, 
                textoOpcao[opcao],
                sigla1, variaveisCarta1[opcao], sigla2, variaveisCarta2[opcao]);

        if(variaveisCarta1[opcao] > variaveisCarta2[opcao]) {
           printf("%s venceu!\n", cidade1);
        } else if (variaveisCarta1[opcao] < variaveisCarta2[opcao]) {
            printf("%s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }
        break;
    
    case 4: //case para comparação da densidade populacional
         printf("%s x %s\n"
               "Atributo usado: %s\n"
                "(%s) %.2f - (%s) %.2f\n", 
                cidade1, cidade2, 
                textoOpcao[opcao],
                sigla1, variaveisCarta1[opcao], sigla2, variaveisCarta2[opcao]);   

         if(densidade1 < densidade2) {
                printf("%s venceu!\n", cidade1);    
            } else if(densidade2 < densidade1) {
                printf("%s venceu!\n", cidade2);    
            } else {
                printf("Empate!");
            }
        break;

    default:
            printf("Opção inválida\n");
        break;
    }


    //____________________________________________________________________________________________________________________
    //Implementação do desafio Comparações Avançadas
    
    //gerar número aleatório
    srand(time(NULL)); 
    int ataque1 = (rand() % 100) + 1;
    int ataque2 = (rand() % 100) + 1;
    int defesa1 = (rand() % 100) + 1;
    int defesa2 = (rand() % 100) + 1;
    int recuo1 = (rand() % 100) + 1;
    int recuo2 = (rand() % 100) + 1;

    //Inicio
    char opcaoAtributo1;
    char opcaoAtributo2; //var para armazenar a opcao escolhida
    int placar1, placar2;

    placar1 = 0; //deixando os placares zerados, para a cada vez que for reiniciado, não armazenar valor anterior
    placar2 = 0;

    printf("Escolha o primeiro atributo.\n"
            "A. Ataque - D. Defesa - R. Recuo\n");
    getchar();
    scanf("%c", &opcaoAtributo1);
    getchar();

   switch (opcaoAtributo1)
    {
    case 'A':
    case 'a':
        printf("\n\nOpção escolhida: Ataque - %d\n", ataque1);
        placar1 += ataque1; // incrementando valor no placar final, somando com o segundo atributo para comparar com o adversário
        break;

    case 'D':
    case 'd':
        printf("\n\nOpção escolhida: Defesa - %d\n", defesa1);
        placar1 += defesa1;
        break;

    case 'R':
    case 'r':
        printf("\n\nOpção escolhida: Recuo - %d\n", recuo1);
        placar1 += recuo1;
        break;

    default: //aqui fiz uma prevenção de erro, caso tenha digitado a letra errada. 
        printf("\n\nOpção inválida. Escolha uma opção válida:\n");

        printf("\nEscolha o primeiro atributo.\n"
            "A. Ataque - D. Defesa - R. Recuo\n");        
        scanf("%c", &opcaoAtributo1);
        getchar();
        
        switch (opcaoAtributo1)
        {
        case 'A':
        case 'a':
            printf("\n\nOpção escolhida: Ataque - %d\n", ataque1);
            placar1 += ataque1;
            break;

        case 'D':
        case 'd':
            printf("\n\nOpção escolhida: Defesa - %d\n", defesa1);
            placar1 += defesa1;
            break;

        case 'R':
        case 'r':
            printf("\n\nOpção escolhida: Recuo - %d\n", recuo1);
            placar1 += recuo1;
            break;
        }          

        break;
    }
 



    //escolha do segundo atributo
     printf("\n\nEscolha o segundo atributo.\n"
            "A. Ataque - D. Defesa - R. Recuo\n");
    scanf("%c", &opcaoAtributo2);
    getchar();

    if(opcaoAtributo2 == opcaoAtributo1) { //tratamento de erro caso tenha escolhido o mesmo atributo
        printf("\nAtributo já escolhido. Escolha outro:\n");

        printf("A. Ataque - D. Defesa - R. Recuo\n");
        scanf("%c", &opcaoAtributo2);
        getchar();

            switch (opcaoAtributo2)
        {


        case 'A':
        case 'a':
            printf("\n\nOpção escolhida: Ataque - %d\n", ataque1);
            placar1 += ataque1;
            break;

        case 'D':
        case 'd':
            printf("\n\nOpção escolhida: Defesa - %d\n", defesa1);
            placar1 += defesa1;
            break;

        case 'R':
        case 'r':
            printf("\n\nOpção escolhida: Recuo - %d\n", recuo1);
            placar1 += recuo1;
            break;

        default:
            printf("\n\nOpção inválida. Escolha uma opção válida:\n");

            printf("\nEscolha o segundo atributo.\n"
                "A. Ataque - D. Defesa - R. Recuo\n");
            scanf("%c", &opcaoAtributo2);
            getchar();
            break;
        }
    } else {
        switch (opcaoAtributo2)
    {


    case 'A':
    case 'a':
        printf("\n\nOpção escolhida: Ataque - %d\n", ataque1);
        placar1 += ataque1;
        break;

    case 'D':
    case 'd':
        printf("\n\nOpção escolhida: Defesa - %d\n", defesa1);
        placar1 += defesa1;
        break;

    case 'R':
    case 'r':
        printf("\n\nOpção escolhida: Recuo - %d\n", recuo1);
        placar1 += recuo1;
        break;

    default: // tratamento de erro caso tenha escolhido uma letra que não está nos atributos
        printf("\n\nOpção inválida. Escolha uma opção válida:\n");

        printf("\nEscolha o segundo atributo.\n"
            "A. Ataque - D. Defesa - R. Recuo\n");
        scanf("%c", &opcaoAtributo2);
        getchar();

            switch (opcaoAtributo2)
        {


        case 'A':
        case 'a':
            printf("\n\nOpção escolhida: Ataque - %d\n", ataque1);
            placar1 += ataque1;
            break;

        case 'D':
        case 'd':
            printf("\n\nOpção escolhida: Defesa - %d\n", defesa1);
            placar1 += defesa1;
            break;

        case 'R':
        case 'r':
            printf("\n\nOpção escolhida: Recuo - %d\n", recuo1);
            placar1 += recuo1;
            break;
            break;
        }


    }
}



    //gerar aleatóriamente os atributos do oponente
    char letras[] = {'A', 'D', 'R'}; //array que armazenará as três opções
    char atributosOponente[3] = {};  //array que irá armazenar as duas opções geradas aleatóriamente

    int sorteada1 = rand() % 3; // será gerado um número que servirá como indice no array para selecionar uma letra
    int sorteada2 = rand() % 3;

    atributosOponente[0] += letras[sorteada1]; // será armazenada a letra, com base no número aleatório que servirá como indice no array para ser buscado
    
    atributosOponente[1] += letras[sorteada2];

    if (atributosOponente[1] == atributosOponente[0]) { //tratamento de erro caso acabe gerando o mesmo atributo repetido
    sorteada2 = rand() % 3;
    atributosOponente[1] = letras[sorteada2];
    }; 
    
    if (atributosOponente[1] != atributosOponente[0]) {
        printf("\n\nAtributos do oponente:\n");

        switch (atributosOponente[0])
        {
            case 'A':
            printf("Ataque - %d\n", ataque2);
            placar2 += ataque2;
            break;

            case 'D':
            printf("Defesa - %d\n", defesa2);
            placar2 += defesa2;
            break;

            case 'R':
            printf("Recuo - %d\n", recuo2);
            placar2 += recuo2;
            break;
    
            default:
            printf("erro");
            break;
        } 

        switch (atributosOponente[1])
        {
            case 'A':
            printf("Ataque - %d\n", ataque2);
            placar2 += ataque2;
            break;

            case 'D':
            printf("Defesa - %d\n", defesa2);
            placar2 += defesa2;
            break;

            case 'R':
            printf("Recuo - %d\n", recuo2);
            placar2 += recuo2;
            break;
    
            default:
            printf("erro");
            break;
        } 

        
    }

    char* resultado;
    resultado = (placar1 > placar2) ? "Você venceu!" : "Você perdeu!"; 
    printf("\n\nResultado: %s\n", resultado);

    printf("Seu placar: %d - Adversário: %d", placar1, placar2);


    
    return 0;    
}
