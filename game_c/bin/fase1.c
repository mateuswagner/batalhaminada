#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>   //atoi
#include <string.h>

#include <wchar.h>
#include <locale.h>

    int menu(int a){
        //menu
        wprintf(L"            MENU\n ");
        wprintf(L"Aperte: \n");
        wprintf(L"\n[1]JOGAR");
        wprintf(L"\n[2]REINICIAR");
        wprintf(L"\n[3]SCORE");
        wprintf(L"\n[4]INSTRUÇÕES");
        wprintf(L"\n[5]SAIR\n");
        scanf("%d", &a);
        switch (a){
            case 1:
                wprintf(L"o jogo vai começar!\n");
                return(1);
            case 2:
                wprintf(L"O jogo será reiniciado!\n");
                return(2);
            case 3:
                //wprintf(L"Pressione [S] para som ativo!\nPressione [N] para som desligado!\n");
                return(3);
            case 4:
                //wprintf(L"O seu score atual é de : 0\n");
                return(4);
            case 5:
                wprintf(L"Obrigado por jogar! :)\n");
                break;
                return(5);
            default:
                if (a < 0 || a > 5){
                    wprintf(L"Por favor, digite um valor válido!\n\n");
                    //scanf("%d", );
                    return(0);
                    
                }
            
        }
    return(0);
}


int main (void){
    int i=0,j=0,d=0, barco=0, bomba=0, score=0;
    int li,c,p,q, retorno=0, a=0;
    char lin=0, col=0;
    char tabuleiro1[12][12];
    wchar_t tabuleironovo[12][12]; // caracter unicode expandido
    time_t t;
    wchar_t n = 0x1F4A5;
    srand(time(NULL));
    setlocale(LC_CTYPE, "");
    
    wprintf(L"\n=====================================================================================\n");
    wprintf(L"                                                                                       \n");
    wprintf(L"                                           BEM VINDOS AO                               \n");
    wprintf(L"                                           BATALHA MINADA!                             \n");
    wprintf(L"\n=====================================================================================\n");
   
    sleep(1);
    system("clear");
    wprintf(L"BATALHA MINADA !!!\n");
    wprintf(L"Modo de jogar:\n");
    wprintf(L"Use as letras e números para fazer a jogada.\n");
    wprintf(L"Após selecionar a posição desejada, pressione Enter.\n");
    wprintf(L"A cada acerto no barco, o jogador contabiliza 10 pontos!\n");
    wprintf(L"Para passar de nível, o jogador deve acertar todos os barcos.\n");
    wprintf(L"Ao acertar bombas perde-se 5 pontos.\n");
    wprintf(L"Após 3 bombas, Game over!\n");
    wprintf(L"A qualquer momento, o jogador pode voltar a tela inicial.\n");
    sleep(9.5);
    
    system("clear");
    retorno = menu (a);
    while (retorno == 0){
    retorno = menu (a);
        
    }
    if (retorno == 1){
        for (i=0; i<12; i++){                         //for para criação do tabuleiro
            for ( j=0; j<12; j++){
                tabuleiro1[i][j] = '~';
                
                
            }
            //  wprintf(L"\n");
            
        }
        for(i=1; i<=5; i++){                           // for para implementação dos barcos no tabuleiro
            int b=0;
            do{
                b=0;
                li = 1 + rand()%9;                      //criação de locais aleatórios para barcos
                c  = 1 + rand()%9;
                for(j=li;j<li+i;j++){        //condição para verificar se o lugar é compatível para colocar barcos
                    if(tabuleiro1[j][c]!='~'){
                        b=1;
                        break;                         // para a execução do for;
                        
                    }
                    
                }
                
            }
            while(b==1);
            // wprintf(L"%d", li);
            // wprintf(L"-%d\n", c);
            if((i!=0) || (j!=0)){
                for(j=li;j<li+i;j++){
                    tabuleiro1[j][c]='@';
                    
                }
                
            }
            
        }
        int cont = 0;
        while (cont < 5){
            
            li = 1 + rand()%9;                      //criação de locais aleatórios para bombas
            c  =  1 + rand()%19;
            if((li!=0) || (c!=0)){
                if(tabuleiro1[li][c] == '~' || tabuleiro1[li][c] != '@') tabuleiro1[li][c]='*';
                cont++;
                
            }
            
        }
        sleep(0.5);
        system("clear");
        
        /*                                     para testes
        for ( i=0; i<12; i++){
            for ( j=0; j<12; j++){
                
                //if (j != 0 && i!=0){
                // wprintf(L"%c" ,tabuleiro1[i][j]);        // impressao do tabuleiro com tudo certo
                // Aqui printa o que eu quero que apareça!
                // Score precisa ser impresso toda vez com valor atualizado
                }
                wprintf(L"\n");
                
            }
            wprintf(L"\n");
            
        }
        */
        
        for(i=0; i<12; i++){
            for(j=0; j<12; j++){
                tabuleironovo[i][j]= ' ';
                
            }
            
        }  
        tabuleironovo[0][0] = L'-';
        tabuleironovo[1][0] = L'A';
        tabuleironovo[2][0] = L'B';
        tabuleironovo[3][0] = L'C';
        tabuleironovo[4][0] = L'D';
        tabuleironovo[5][0] = L'E';
        tabuleironovo[6][0] = L'F';
        tabuleironovo[7][0] = L'G';
        tabuleironovo[8][0] = L'H';
        tabuleironovo[9][0] = L'I';
        tabuleironovo[10][0]= L'J';
        tabuleironovo[0][1] = L'1';
        tabuleironovo[0][2] = L'2';
        tabuleironovo[0][3] = L'3';
        tabuleironovo[0][4] = L'4';
        tabuleironovo[0][5] = L'5';
        tabuleironovo[0][6] = L'6';
        tabuleironovo[0][7] = L'7';
        tabuleironovo[0][8] = L'8';
        tabuleironovo[0][9] = L'9';
        tabuleironovo[0][10]= L'X'; //usando letras para melhor comparacao de caracteres
                        
        for ( i=0; i<11; i++){
            for ( j=0; j<11; j++){
                if (j !=0 && i!=0){
                    tabuleironovo[i][j] = 0x1F30A;
                }
            }                    
        }
        
        for ( i=0; i<12; i++){
            for ( j=0; j<12; j++){
                wprintf(L"%2lc " ,tabuleironovo[i][j]);  //wprintf impressao de caracteres especiais 
            }
            wprintf(L"\n");
        }
        
//----------------------Entrada do usuario------------------               
        wprintf(L"\nSCORE = %d\n", score);
        char entrada[256];
        i=0;
        j=0;
        int controle = 0;
        while(bomba < 3 && barco < 15){
            wprintf(L"Para sair digite [sair]\n");
            wprintf(L"Digite a jogada!\n");
            wprintf(L"\n\n\n\n\nPara sair digite [sair].\n");
            wprintf(L"Para reiniciar digite [reiniciar].\n");
            setbuf(stdin, NULL);
            fgets(entrada, 256, stdin); 
            system("clear");
            if (strcmp(entrada, "sair\n")==0) break;
            if (strcmp(entrada, "reiniciar\n")==0){
                score = 0;
                for ( i=0; i<11; i++){
                    for ( j=0; j<11; j++){
                        if (j !=0 && i!=0){
                            tabuleironovo[i][j] = 0x1F30A;
                            wprintf(L"%2lc " ,tabuleironovo[i][j]);  //wprintf impressao de caracteres especiais 
                            
                        }
                    }
                    wprintf(L"\n");
                    
                }
                wprintf(L"\nSCORE = %d\n", score);
            }
            if (strcmp(entrada, "sair\n")==0) break;
            
            lin = entrada[0];
            if(strlen(entrada) == 4){
                col = 'x';
            }else if(strlen(entrada) == 3){
                col = entrada[1];
            }else{
                
            }
            //wprintf(L"col = %c\n", col);

            //wprintf(L"tamanho= %lu\n", strlen(entrada));
            setbuf(stdin, NULL);

            if      (lin=='A' || lin =='a') i=1;
            else if (lin=='B' || lin =='b') i=2;
            else if (lin=='C' || lin =='c') i=3;
            else if (lin=='D' || lin =='d') i=4;
            else if (lin=='E' || lin =='e') i=5;
            else if (lin=='F' || lin =='f') i=6;
            else if (lin=='G' || lin =='g') i=7;
            else if (lin=='H' || lin =='h') i=8;
            else if (lin=='I' || lin =='i') i=9;
            else if (lin=='J' || lin =='j') i=10;
            else{
                i = 20; 
            }

            if      (col=='1') {j=1; printf("  ");}
            else if (col=='2') {j=2; printf("  ");}
            else if (col=='3') {j=3; printf("  ");}
            else if (col=='4') {j=4; printf("  ");}
            else if (col=='5') {j=5; printf("  ");}
            else if (col=='6') {j=6; printf("  ");}
            else if (col=='7') {j=7; printf("  ");}
            else if (col=='8') {j=8; printf("  ");}
            else if (col=='9') {j=9; printf("  ");}
            else if ((col=='x') || (col=='X')) j=10; //printf(" ");}
            else{
                j = 20; 
            }
            controle = 0;
            if( (i < 1) || (i > 11) || (j<1) || (j>11) ){
                    wprintf(L"ENTRADA INVÁLIDA, DIGITE NOVAMENTE\n\n");
                    controle = 10;
            }
            
            if(controle !=10){ //Ele só entra se for válido
                wprintf(L"%c\n", tabuleiro1[i][j]);
                
                if(tabuleiro1[i][j]=='*'){
                //if (retorno = 3){
                    system("play bomba.mp3 > /dev/null 2>&1 &");
                    
                //}
                bomba += 1;
                score = score-5;
                wprintf(L"\nOLHA A BOMBA!\n\n");
                
                // novo tabuleiro
                tabuleironovo[i][j]= 0x1F4A5;
                
                wprintf(L"\nSCORE = %d\n\n", score);
                
                
                    if(bomba==3){  //chamar funcao game over
                        wprintf(L"\n  GAME OVER! :c \n\n");
                        wprintf(L"SCORE = %d", score);
                        break;
                    
                    }
                }
                
                
            }
            if(tabuleiro1[i][j]=='@'){
                //if (retorno = 3){
                    system("play buzina.mp3 > /dev/null 2>&1 &");
                    
                //}
                score = (score + 10);
                wprintf(L"\nFRAGMENTO ENCONTRADO!\n");
                
                // novo tabuleiro
                tabuleironovo[i][j]= 0x26F5;
                    
                wprintf(L"\nSCORE = %d\n", score);
                
                barco += 1;
                if(barco == 15){
                    wprintf(L"PARABÉNS, PASSOU DE NÍVEL!\n"); 
                    score = score + 50;
                    wprintf(L"\nSCORE = %d\n", score);
                    
                    /*
                    chamar funcao proximo nivel
                    
                    
                    */
                    
                }
                
            }
            if(tabuleiro1[i][j]=='~'){
                //if (retorno = 3){
                    system("play agua.mp3 > /dev/null 2>&1 &");
                    
                //}
                wprintf(L"\nACERTOU ÁGUA!\n");
                
                // novo tabuleiro
                
                        
                wprintf(L"\nSCORE = %d\n", score);
            
                
            }       
            
            for ( i=0; i<12; i++){
                for ( j=0; j<12; j++){
                        if (tabuleironovo[i][j] == 0x26F5)
                            wprintf(L"%lc ", tabuleironovo[i][j]);
                        else if (tabuleironovo[i][j] == 0x1F4A5 || tabuleironovo[i][j] == 0x1F30A)
                            wprintf(L"%lc", tabuleironovo[i][j]);
                        else 
                            wprintf(L"%lc ", tabuleironovo[i][j]);
                    }
                    wprintf(L"\n");
                }
            }
        }
        if (retorno == 4){
            system("clear");
            wprintf(L"BATALHA MINADA !!!\n");
            wprintf(L"Modo de jogar:\n");
            wprintf(L"Use as letras e números para fazer a jogada.\n");
            wprintf(L"Após selecionar a posição desejada, pressione Enter.\n");
            wprintf(L"A cada acerto no barco, o jogador contabiliza 10 pontos!\n");
            wprintf(L"Para passar de nível, o jogador deve acertar todos os barcos.\n");
            wprintf(L"Ao acertar bombas perde-se 5 pontos.\n");
            wprintf(L"Após 3 bombas, Game over!\n");
            wprintf(L"A qualquer momento, o jogador pode voltar a tela inicial.\n");
            
        }
        if (retorno == 3){
            wprintf(L"\n\n\nSCORE = %d", score);
        }
                             
        wprintf(L"\n\n   Obrigado por jogar! :)\n");
    return(0);
                
} 
            
    

