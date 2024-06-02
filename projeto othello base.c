#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


int  l, c, lo, co, lp, cp, op, op1,  ponto1=0, ponto2=0, ponto3=0, teste, lteste, cteste, sem_opcoes=0, game_over=1;
char jogador, jogador1 = 177, jogador2 = 219, jogada [8][8][2],  ponto, marca = 248, i, j, x, z, jogador_op;


void tela_inicio()
{
    printf("      ******************* CURSO LICENCIATURA EM COMPUTACAO *******************\n\n\n\n\n");


printf("    8888888b.  8888888888 888     888 8888888888 8888888b.   .d8888b.  8888888 \n");
printf("    888   Y88b 888        888     888 888        888   Y88b d88P  Y88b   888   \n");
printf("    888    888 888        888     888 888        888    888 Y88b.        888   \n");
printf("    888   d88P 8888888    Y88b   d88P 8888888    888   d88P  ""Y888b.      888   \n");
printf("    8888888P""   888         Y88b d88P  888        8888888P""      ""Y88b.     888   \n");
printf("    888 T88b   888          Y88o88P   888        888 T88b         ""888    888   \n");
printf("    888  T88b  888           Y888P    888        888  T88b  Y88b  d88P   888   \n");
printf("    888   T88b 8888888888     Y8P     8888888888 888   T88b  ""Y8888P""    8888888 \n");


printf("\n\n\n\t***************** ALUNO: NEI RODRIGO MOREIRA *****************\n");
printf("\t   *****************   2%c semestre  T-LC6   *****************\n", 248);

printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t  %c %c%c %c%c\n\t\t\t\t\t\t\t\t %c%c %c%c\n\t\t\t\t\t\t\t\t %c%c %c%c %c%c\n\t\t\t\t\t\t\t\t %c%c %c%c\n\t\t\t\t\t\t\t\t INSTITUTO\n\t\t\t\t\t\t\t\t FEDERAL\n\t\t\t\t\t\t\t\t Farroupilha\n\n", 184,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);


system("pause");
system("cls");
}

void zerar_jogo()
{

    for (i=0 ; i<=7; i++)
    {
    for (j=0 ; j<=7; j++)
        {
            jogada [i][j] [0]== ' ';
        }
    }
        jogada [3][3][0] = jogador1;
        jogada [3][4][0] = jogador2;
        jogada [4][3][0] = jogador2;
        jogada [4][4][0] = jogador1;
}

void tabuleiro ()
{
    system ("cls");
    //pontuação:
    ponto1=0;
    ponto2=0;
    ponto3=0;
    for (i=0 ; i<=7; i++)
   {
       for (j=0 ; j<=7; j++)
       {
          ponto = jogada [i][j][0];
          if (ponto==jogador1) {ponto1 = ponto1 +1;}
          if (ponto==jogador2) {ponto2 = ponto2 +1;}
          if (ponto==marca) {ponto3 = ponto3 +1;}
       }

    }
    printf("\n\n\tJOGADOR %c = %d pontos\t\tJOGADOR %c = %d pontos\n", jogador1, ponto1, jogador2, ponto2);




printf("\n\n");
printf("\t\t  1   2   3   4   5   6   7   8\n");
printf("\t\t ___ ___ ___ ___ ___ ___ ___ ___\n");
   for (i=0 ; i<=7; i++)
   {    printf("\t\t|");
       for (j=0 ; j<=7; j++)
       {
          printf("   |");
       }

    printf("\n");
    printf("\t     %d  |", (1+i));


           for (j=0 ; j<=7; j++)
       {
          if ((jogada[i][j][0] == (jogador1))||jogada[i][j][0] == (jogador2)||(jogada[i][j][0] == marca)||(jogada[i][j][0] == ' ')  )
                {
                printf(" %c |", jogada[i][j][0]);
                }else
                    {
                        printf("   |");
                    }
       }

    printf("\n");
   printf("\t\t|");

        for (j=0 ; j<=7; j++)
       {
            printf("___|");
       }

       printf("\n");
   }

   printf("\nVez do jogador: %c\n", jogador);
}

void selecionar_vs()
{
    do{

    printf("\n\n\n\t\t\t\tSELECIONE MODO DE JOGO:\n");
    printf("\n\t\t\t\t1 - HUMANO VERSUS HUMANO");
    printf("\n\t\t\t\t2 - HUMANO VERSUS MAQUINA");
    printf("\n\t\t\t\t3 - MAQUINA VERSUS MAQUINA\n");
    printf("\t\t\t\tOPCAO -> ");
    scanf("%d", &op1);
    system ("cls");
    switch(op1)
    {
    case 1:{jogo_vs_humano();
        break;
        }

    case 2: {jogo_vs_computador();
        break;
        }
    case 3: {computador_vs_computador();
        break;
        }
    }
    }while ((op!=1)&& (op1!=2)&& (op1!=3));
}

void selecionar_jogador()
{

    switch(op)
    {
    case 1:
        {
            jogador = jogador1;
            jogador_op = jogador2;

        break;
        }

    case 2:
        {
            jogador = jogador2;
            jogador_op = jogador1;
        break;
        }

    }
}

void selecionar_casa()
{

// ============== SELECIONAR CASA PARA JOGAR ==================================
    do{

    printf("\nSelecione jogada:\n");
    printf("linha -> ");
    scanf("%d", &lp);
        l=lp-1;
    printf("coluna -> ");
    scanf("%d", &cp);
        c=cp-1;


    if(jogada [l][c][0] != marca)
            {
                system ("cls");
                tabuleiro ();
                printf("\n\tSELECAO INVALIDA!! TENTE NOVAMENTE\n");
                system ("pause");
                system ("cls");
            }
    tabuleiro ();
    }while(jogada [l][c][0] != marca);


    system("cls");
    tabuleiro();


}

void limpar_marcar()
{


       for (i=0 ; i<=7; i++)
   {
       for (j=0 ; j<=7; j++)
       {

           if (jogada [i][j][0] == marca) {jogada [i][j][0]='\0';}
       }
   }
}

void marcar()
{


    for (i=0 ; i<=7; i++)
   {
       for (j=0 ; j<=7; j++)
       {
          if (jogada [i][j][0]==jogador)
            {
        //jogada para direita
             x = i;
             z = j;
             do {

                z = z +1;
                } while (jogada [x] [z][0] == jogador_op );

                if((jogada[x][z][0]=='\0')&& (x=i)&&(z-j>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                        {jogada[x][z][0] = marca;}

            //jogada para esquerda
            x = i;
            z = j;
            do {
                z = z-1;
                } while (jogada [x] [z][0] == jogador_op );
                        if((jogada[x][z][0]=='\0')&& (x=i)&&(j-z>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                        {jogada[x][z][0] = marca;}

           // jogada para baixo
            x = i;
            z = j;
            do {
                x = x +1;
                } while (jogada [x] [z][0] == jogador_op );
                        if((jogada[x][z][0]=='\0')&& (z=j)&&(x-i>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                        {jogada[x][z][0] = marca;}


            //jogada para cima
            x = i;
            z = j;
            do {
                x = x -1;
                } while (jogada [x] [z][0] == jogador_op );
                        if((jogada[x][z][0]=='\0')&& (z=j)&&(i-x>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                        {jogada[x][z][0] = marca;}


            //jogada para diagonal
            x = i;
            z = j;
            do {
                x = x +1;
                z = z +1;
                } while (jogada [x] [z][0] == jogador_op );

                        if((jogada[x][z][0]=='\0')&& (x-i>=2)&&(z-j>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                        {jogada[x][z][0] = marca;}

            x = i;
            z = j;
            do {
                x = x +1;
                z = z -1;
                } while (jogada [x] [z][0] == jogador_op );

                       if((jogada[x][z][0]=='\0')&& (x-i>=2)&&(j-z>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                        {jogada[x][z][0] = marca;}

            x = i;
            z = j;
             do {
                x = x -1;
                z = z -1;
                } while (jogada [x] [z][0] == jogador_op );
                       if((jogada[x][z][0]=='\0')&& (i-x>=2)&&(j-z>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                        {jogada[x][z][0] = marca;}

            x = i;
            z = j;
            do {
                x = x - 1;
                z = z + 1;
                } while (jogada [x] [z][0] == jogador_op );
                        if((jogada[x][z][0]=='\0')&& (i-x>=2)&& (z-j>=2)&&(x<=7)&& (x>=0)&&(z<=7)&&(z>=0))
                       {jogada[x][z][0] = marca;}
            }
       }

   } tabuleiro();


}

void trocar_jogador()
{
    if (op==1)
    {op=2;} // troca de jogador
    else {  op=1;}
    selecionar_jogador();
    tabuleiro();
}

void testar()
{
  // l e c são as coordenadas selecionadas


            x = l;
            z = c;


             do {
                z = z +1;
                } while (jogada [x] [z][0] == jogador_op );

                if(jogada[x][z][0]==jogador)
                        {
                        lo = x;
                        co = z;
                        jogar();
                        }



            //jogada para esquerda
            x = l;
            z = c;
            do {
                z = z-1;
                } while (jogada [x] [z][0] == jogador_op );
                        if(jogada[x][z][0]==jogador)
                        {
                        lo = x;
                        co = z;
                        jogar();
                        }

           // jogada para baixo
            x = l;
            z = c;
            do {
                x = x +1;
                } while (jogada [x] [z][0] == jogador_op );
                        if(jogada[x][z][0]==jogador)
                        {
                        lo = x;
                        co = z;
                        jogar();
                        }


            //jogada para cima
            x = l;
            z = c;
            do {
                x = x -1;
                } while (jogada [x] [z][0] == jogador_op );
                        if(jogada[x][z][0]==jogador)
                        {
                        lo = x;
                        co = z;
                        jogar();
                        }


            //jogada para diagonal
            x = l;
            z = c;
            do {
                x = x +1;
                z = z +1;
                } while (jogada [x] [z][0] == jogador_op );

                        if(jogada[x][z][0]==jogador)
                       {
                        lo = x;
                        co = z;
                        jogar();
                        }

            x = l;
            z = c;
            do {
                x = x +1;
                z = z -1;
                } while (jogada [x] [z][0] == jogador_op );

                       if(jogada[x][z][0]==jogador)
                       {
                        lo = x;
                        co = z;
                        jogar();
                        }

            x = l;
            z = c;
             do {
                x = x -1;
                z = z -1;
                } while (jogada [x] [z][0] == jogador_op );
                       if(jogada[x][z][0]==jogador)
                        {
                        lo = x;
                        co = z;
                        jogar();
                        }
            x = l;
            z = c;
            do {
                x = x - 1;
                z = z + 1;
                } while (jogada [x] [z][0] == jogador_op );
                        if(jogada[x][z][0]==jogador)
                       {
                        lo = x;
                        co = z;
                        jogar();
                        }





}

void jogar()
{

      lteste = lo;
      cteste = co;

        if((lteste == l)&&(cteste<c))
			{
             for ( i=0; cteste <c; i++)
                {
			    cteste=cteste+1;
                (jogada [lteste] [cteste][0]  = jogador);
                }
			}

      lteste = lo;
      cteste = co;
		if((lteste == l)&&(cteste>c))
			{
			 for ( i=0; cteste>c; i++)
                {
			    cteste=cteste-1;
			    (jogada [lteste] [cteste][0]  = jogador);
                }
			}


      lteste = lo;
      cteste = co;
		if((lteste < l)&&(cteste==c))
			{
			 for ( i=0; lteste<l; i++)
                {
			    lteste=lteste+1;
			    (jogada [lteste] [cteste][0]  = jogador);
                }
			}

      lteste = lo;
      cteste = co;
		if((lteste >l)&&(cteste==c))
			{
			 for ( i=0; lteste>l; i++)
                {
			    lteste=lteste-1;
			    (jogada [lteste] [cteste][0]  = jogador);
                }
			}

      lteste = lo;
      cteste = co;
		if((lteste < l)&&(cteste<c))
			{
			 for ( i=0; lteste<l; i++)
                {
			    cteste=cteste+1;
			    lteste=lteste+1;
			    (jogada [lteste] [cteste][0]  = jogador);
                }
			}

      lteste = lo;
      cteste = co;
		if((lteste >l)&&(cteste>c))
			{
			 for ( i=0; lteste>l; i++)
                {
			    cteste=cteste-1;
			    lteste=lteste-1;
			    (jogada [lteste] [cteste][0]  = jogador);
                }
			}

      lteste = lo;
      cteste = co;
		if((lteste < l)&&(cteste>c))
			{
			 for ( i=0; lteste<l; i++)
                {
			    lteste=lteste+1;
			    cteste=cteste-1;
			    (jogada [lteste] [cteste][0]  = jogador);
			    }
			}

      lteste = lo;
      cteste = co;
		if((lteste >l)&&(cteste<c))
			{
			 for ( i=0; lteste>l; i++)
                {
                lteste=lteste-1;
			    cteste=cteste+1;
                (jogada [lteste] [cteste][0]  = jogador);
                }
			}




}

void fim_de_jogo()
{

    if (sem_opcoes>=2){printf("\nNAO HA JOGADAS POSSIVEIS\n");}
    printf("\nFIM DE JOGO\n");
    if(ponto1>ponto2){printf("VENCEDOR JOGADOR %c\n", jogador1);}
    if(ponto1<ponto2){printf("VENCEDOR JOGADOR %c\n", jogador2);}
    if(ponto1==ponto2){printf("EMPATE\n");}
    printf("\n\t\tOBRIGADO POR TER JOGADO\n\n");
    system("pause");
}

int IA()
{
    int m;

    m = -200;
        jogada [0][0][1] = 120;
        jogada [0][1][1] =  -20;
        jogada [0][2][1] =  20;
        jogada [0][3][1] =  5;
        jogada [0][4][1] =  5;
        jogada [0][5][1] = 20;
        jogada [0][6][1] = -20;
        jogada [0][7][1] = 120;
        jogada [1][0][1] =  -20;
        jogada [1][1][1] = -40;
        jogada [1][2][1] = -5;
        jogada [1][3][1] = -5;
        jogada [1][4][1] = -5;
        jogada [1][5][1] = -5;
        jogada [1][6][1] = -40;
        jogada [1][7][1] = -20;
        jogada [2][0][1] = 20;
        jogada [2][1][1] = -5;
        jogada [2][2][1] = 15;
        jogada [2][3][1] = 3;
        jogada [2][4][1] = 3;
        jogada [2][5][1] = 15;
        jogada [2][6][1] = -5;
        jogada [2][7][1] = 20;
        jogada [3][0][1] = 5;
        jogada [3][1][1] = -5;
        jogada [3][2][1] = 3;
        jogada [3][3][1] = 3;
        jogada [3][4][1] = 3;
        jogada [3][5][1] = 3;
        jogada [3][6][1] = -5;
        jogada [3][7][1] = -5;
        jogada [4][0][1] = 5;
        jogada [4][1][1] = -5;
        jogada [4][2][1] = 3;
        jogada [4][3][1] = 3;
        jogada [4][4][1] = 3;
        jogada [4][5][1] =3;
        jogada [4][6][1] = -5;
        jogada [4][7][1] = 5;
        jogada [5][0][1] = 20;
        jogada [5][1][1] = -5;
        jogada [5][2][1] = 15;
        jogada [5][3][1] = 3;
        jogada [5][4][1] = 3;
        jogada [5][5][1] = 15;
        jogada [5][6][1] = -5;
        jogada [5][7][1] = 20;
        jogada [6][0][1] = -20;
        jogada [6][1][1] = -40;
        jogada [6][2][1] = -5;
        jogada [6][3][1] = -5;
        jogada [6][4][1] = -5;
        jogada [6][5][1] = -5;
        jogada [6][6][1] = -40;
        jogada [6][7][1] = -20;
        jogada [7][0][1] = 120;
        jogada [7][1][1] = -20;
        jogada [7][2][1] = 20;
        jogada [7][3][1] = 5;
        jogada [7][4][1] = 5;
        jogada [7][5][1] = 20;
        jogada [7][6][1] = -20;
        jogada [7][7][1] = 120;


    switch((rand()%4)+1)
    {
    case 1:
        for (i=0 ; i<=7; i++)
        {
            for (j=0 ; j<=7; j++)
            {
            if (jogada [i][j][0]== marca)
                {
                if (jogada [i][j][1] >= m)
                    {
                    m = jogada [i][j][1];
                    l = i;
                    c = j;

                    }

                }
            }
        }
    break;

    case 2:
        for (i=7 ; i>=0; i--)
        {
            for (j=0 ; j<=7; j++)
            {
            if (jogada [i][j][0]== marca)
                {
                if (jogada [i][j][1] >= m)
                    {
                    m = jogada [i][j][1];
                    l = i;
                    c = j;

                    }

                }
            }
        }
    break;

    case 3:
        for (i=0 ; i<=7; i++)
        {
            for (j=7 ; j>=0; j--)
            {
            if (jogada [i][j][0]== marca)
                {
                if (jogada [i][j][1] >= m)
                    {
                    m = jogada [i][j][1];
                    l = i;
                    c = j;

                    }

                }
            }
        }
    break;

    case 4:
        for (i=7 ; i>=0; i--)
        {
            for (j=7 ; j>=0; j--)
            {
            if (jogada [i][j][0]== marca)
                {
                if (jogada [i][j][1] >= m)
                    {
                    m = jogada [i][j][1];
                    l = i;
                    c = j;

                    }

                }
            }
        }
    break;

    }

        printf("COMPUTADOR: Jogarei na casa %d %d \n", l+1 , c+1);
        system ("pause");
}

void jogo_vs_humano()
{


   do{
    system("cls");


    printf("\n\n\n\tSelecione quem vai iniciar a partida:\n\n\tJogador %c - digite 1\n\n\tJogador %c - digite 2\n\n\tJogador -> ", jogador1 , jogador2);
    scanf("%d", &op);
    }while ((op!=1)&& (op!=2));

    selecionar_jogador();

    system("cls");

    zerar_jogo();
    tabuleiro();



   while (game_over==1)
    {
    limpar_marcar();

    marcar ();

    if(ponto3==0 )
            {
                printf("VOCE NAO TEM OPCOES DE JOGADA - DEVE PASSAR A VEZ\n");
                system("pause");
                sem_opcoes=sem_opcoes+1;
             }else
             {
                selecionar_casa();
                testar();
                jogar();
             }

    trocar_jogador();

    if((ponto1 <= 0)||(ponto2 <= 0)|| ((ponto1+ponto2) >= 64)){game_over=0;}else{game_over=1;}
    }

    fim_de_jogo();
}

void jogo_vs_computador()
{
    do{
    printf("\n\n\n\tSelecione quem vai iniciar a partida:\n\n\tJogador %c - digite 1\n\n\tComputador %c - digite 2\n\n\tJogador -> ", jogador1 , jogador2);
    scanf("%d", &op);
    }while ((op!=1)&& (op!=2));

    selecionar_jogador();
    system ("cls");

    zerar_jogo();
    tabuleiro();

    do{
        limpar_marcar();

        marcar ();

         if(ponto3==0 )
            {
                printf("VOCE NAO TEM OPCOES DE JOGADA - DEVE PASSAR A VEZ\n");
                system("pause");
                sem_opcoes=sem_opcoes+1;
             }else
             {
                sem_opcoes = 0;

                 if(jogador == jogador1){selecionar_casa();}
                 if(jogador == jogador2) {IA();}

                testar();
                jogar();
             }

        trocar_jogador();

    if((ponto1 <= 0)||(ponto2 <= 0)|| ((ponto1+ponto2) >= 64)){game_over=0;}else{game_over=1;}

   }while (game_over==1);


    fim_de_jogo();
}

void computador_vs_computador()
{
    do{
    printf("\n\n\n\tSelecione quem vai iniciar a partida:\n\n\tComputador %c - digite 1\n\n\tComputador %c - digite 2\n\n\tOPCAO -> ", jogador1 , jogador2);
    scanf("%d", &op);
    }while ((op!=1)&& (op!=2));

    selecionar_jogador();
    system ("cls");

    zerar_jogo();
    tabuleiro();

    do{
        limpar_marcar();

        marcar ();

        if(ponto3==0 )
            {
                printf("VOCE NAO TEM OPCOES DE JOGADA - DEVE PASSAR A VEZ\n");
                system("pause");
                sem_opcoes=sem_opcoes+1;
            }else{
                sem_opcoes = 0;

        IA();

        testar();

        jogar();
                }

        trocar_jogador();

        if((ponto1 <= 0)||(ponto2 <= 0)|| ((ponto1+ponto2) >= 64)|| (sem_opcoes>=2)){game_over=0;}else{game_over=1;}

   }while (game_over==1);

    fim_de_jogo();
}

int main ()
{
    system ("mode con:cols=90 lines=42");
    tela_inicio();
    selecionar_vs();
}
