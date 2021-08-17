//LEONARDO GUTIERREZ    @YLeonardo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void cover();
void dices();
void secondary(int *,int *);
void sequel();
int wager(int *,int *);
int craps_game();

int main(){
//system("color A0");
srand(time(NULL));
craps_game();	
}

int craps_game(){
	
    int option1=0, option2=0, i=0, j=0, k=0;
    int saldo = 1000, apuesta = 0;
    int *ptrsaldo, *ptrapuesta;
	ptrsaldo = &saldo;
	ptrapuesta = &apuesta;
	
    cover();
    system("PAUSE");
    for(;;){
    	system("cls");
        wager(&saldo,&apuesta);
        do
        {
            system("cls");  
            printf("\n");
            for(i=0;i<2;i++)
            {
                if(i==0)
                {
                    fflush(stdin);
                    printf(" PULSA 'ENTER' PARA LANZAR EL DADO 1 \n");
                    getchar();
                }
                if(i==1)
                {
                    printf("\n\n  PULSA 'ENTER' PARA LANZAR EL DADO 2 \n");
                    getchar();
                }
                option1 = (rand()%6)+1;
                dices(option1);	
                j += option1;
            }
            if(j==2)
            {
                printf("\n  LA CASA GANA! \n");
                saldo = saldo - apuesta;
                if(saldo<=0){
                	printf("\n\n  LO SIENTO, SU SALDO SE AGOTO! \n");
	                printf("\n\n  GRACIAS POR JUGAR! \n");
	                exit(0);
				}
				printf("SU SALDO BANCO ES %d", saldo);
                break;
            }
            if(j==3)
            {
                printf("\n  LA CASA GANA! \n");
                saldo = saldo - apuesta;
                if(saldo<=0){
                	printf("\n\n  LO SIENTO, SU SALDO SE AGOTO! \n");
	                printf("\n\n  GRACIAS POR JUGAR! \n");
	                exit(0);
				}
				printf("SU SALDO BANCO ES %d", saldo);
                break;
            }
            if(j==4)
            {
                printf("\n  OBTIENE UN 4 \n ");
                option2 = 4;
            }
            if(j==5)
            {
                printf("\n  OBTIENE UN 5 \n");
                option2 = 5;
            }
            if(j==6)
            {
                printf("\n  OBTIENE UN 6 \n");
                option2 = 6;
            }
            if(j==7)
            {   
                printf("\n  USTED GANA! \n");
                saldo = saldo + apuesta;
                printf("SU SALDO BANCO ES %d", saldo);
                break;
            }
            if(j==8)
            {
                printf("\n  OBTIENE UN 8 \n");
                option2 = 8;
            }
            if(j==9)
            {
                printf("\n  OBTIENE UN 9 \n");
                option2 = 9;
            }
            if(j==10)
            {
                printf("\n  OBTIENE UN 10 \n");
                option2 = 10;
            }
            if(j==11)
            {
                printf("\n  USTED GANA! \n");
                saldo = saldo + apuesta;
                printf("SU SALDO BANCO ES %d", saldo);
                break;
            }
            if(j==12)
            {
                printf("\n  LA CASA GANA! \n");
                saldo = saldo - apuesta;
                if(saldo<=0){
                	printf("\n\n  LO SIENTO, SU SALDO SE AGOTO! \n");
	                printf("\n\n  GRACIAS POR JUGAR! \n");
	                exit(0);
				}
				printf("SU SALDO BANCO ES %d", saldo);
                break;
            }
            j = 0;
            printf("\n\n  PULSA 'ENTER' PARA SEGUIR LANZANDO \n");
            getchar();
            
            do
            {
                system("cls");
                printf("\n");
                printf("  NECESITA OBTENER UN %d PARA GANAR \n", option2);
                for(i=0;i<2;i++)
                {
                    if(i==0)
                    {  
                        fflush(stdin);
                        printf("\n\n  PULSA 'ENTER' PARA LANZAR EL DADO 1 ");
                        getchar();
                    }
                    if(i==1)
                    {
                        printf("\n\n  PULSA 'ENTER' PARA LANZAR EL DADO 2 ");
                        getchar();
                    }
                    option1 = (rand()%6)+1;
                    dices(option1);	
                    j += option1;
                }
                if(j==option2)
                {
                    printf("\n  USTED GANA! \n");
                    saldo = saldo + apuesta;
                    printf("SU SALDO BANCO ES %d", saldo);
                    break;
                }
                else if(j==7)
                {
                    printf("\n  LA CASA GANA! \n");
                    saldo = saldo - apuesta;
                    if(saldo<=0){
                	saldo=0;
				    }
                    printf("SU SALDO BANCO ES %d", saldo);
                    break;
                }
                else
                {
                    j = 0;
                    printf("\n  PULSA 'ENTER' PARA SEGUIR LANZANDO \n");
                    getchar();
                }
            }
            while(k==0);
            printf("\n  ");
            j = 0;
            system("PAUSE");
            secondary(&saldo,&apuesta);
        }
        while(k==0);
        printf("\n  ");
        j = 0;
        system("PAUSE");
        sequel();
        
            
 }
}

void secondary(int*saldo,int*apuesta){
	int option;
	if(*saldo==0 || saldo==NULL){
	printf("\n\n  LO SIENTO, SU SALDO SE AGOTO! \n");
	printf("\n\n  GRACIAS POR JUGAR! \n");
	exit(0);
	}else{
	printf("\n\n  DESEA SEGUIR JUGANDO? \n");
	printf("\n  1) Si ");
	printf("\n  2) NO \n");
	scanf("%d",&option);
	
	switch(option){
		
	case 1:
		wager(saldo,apuesta);
	break;
	case 2:
		printf("GRACIAS POR JUGAR!");
	exit(0);
	break;		
	}
  }
}

int wager(int *saldo,int *apuesta){

	printf(" SU SALDO BANCO ES %d", *(saldo)); 
	*apuesta = 0;
	if(*apuesta<=*saldo){
	printf("\n\n  INTRODUCIR APUESTA\n");
    scanf(" %d", apuesta);  

    if(*apuesta==0){
	printf("REINTRODUZCA UNA CANTIDAD VALIDA\n");
    printf("\n\n  INTRODUCIR APUESTA\n");
    scanf(" %d", apuesta); 
    }
    
    char letra;
    if(*apuesta==letra){
    system("cls");
    printf("\n");
    printf("SE AH ACTIVADO 'TIRO DE PRACTICA' \n");
    printf("\n");
    system("pause");
    }

    while(*apuesta>*saldo){
	printf("REINTRODUZCA UNA CANTIDAD VALIDA\n");
	printf("\n\n  INTRODUCIR APUESTA\n");
    scanf(" %d", apuesta);
    }
    return *saldo, *apuesta;
    }     
}

void sequel(){
    int option;
    printf("\n\n  DESEA SEGUIR JUGANDO? \n");
	printf("\n  1) Si ");
	printf("\n  2) NO \n");
	scanf("%d",&option);
	
	switch(option){
	case 1:

	break;
	case 2:
		printf("GRACIAS POR JUGAR!");
	exit(0);
	break;	
   }
}

void dices(option1){
	
	if(option1==1){
	printf("\n");	
	printf("	*****************\n");
    printf("	*               *\n");
    printf("	*               *\n");
    printf("	*               *\n");
    printf("	*       **      *\n");
    printf("	*       **      *\n");
    printf("	*               *\n");
    printf("	*               *\n");
    printf("	*               *\n");
    printf("	*****************\n");
	}
	if(option1==2){
	printf("\n");	
	printf("	*****************\n");
    printf("	*               *\n");
    printf("	*    **         *\n");
    printf("	*    **         *\n");
    printf("	*               *\n");
    printf("	*               *\n");
    printf("	*         **    *\n");
    printf("	*         **    *\n");
    printf("	*               *\n");
    printf("	*****************\n");
	
	}
	if(option1==3){
	printf("\n");	
	printf("	*****************\n");
    printf("	*               *\n");
    printf("	*  **           *\n");
    printf("	*  **           *\n");
    printf("	*       **      *\n");
    printf("	*       **      *\n");
    printf("	*            ** *\n");
    printf("	*            ** *\n");
    printf("	*               *\n");
    printf("	*****************\n");
	}
	if(option1==4){
	printf("\n");	
	printf("	*****************\n");
    printf("	*               *\n");
    printf("	*  **       **  *\n");
    printf("	*  **       **  *\n");
    printf("	*               *\n");
    printf("	*               *\n");
    printf("	*  **       **  *\n");
    printf("	*  **       **  *\n");
    printf("	*               *\n");
    printf("	*****************\n");
	}
	if(option1==5){
	printf("\n");	
	printf("	*****************\n");
    printf("	*               *\n");
    printf("	*  **       **  *\n");
    printf("	*  **       **  *\n");
    printf("	*       **      *\n");
    printf("	*       **      *\n");
    printf("	*  **       **  *\n");
    printf("	*  **       **  *\n");
    printf("	*               *\n");
    printf("	*****************\n");
	}
	if(option1==6){
	printf("\n");	
	printf("	*****************\n");
    printf("	*               *\n");
    printf("	*  **   **   ** *\n");
    printf("	*  **   **   ** *\n");
    printf("	*               *\n");
    printf("	*               *\n");
    printf("	*  **   **   ** *\n");
    printf("	*  **   **   ** *\n");
    printf("	*               *\n");
    printf("	*****************\n");
	}
	
}

void cover(){
	
	printf("\n");
	printf("                 BIENVENIDO AL JUEGO DE CRAPS!    \n\n");
	
	printf("	      DADO 1			      DADO 2            \n");
	printf("\n");	 
	printf("	*****************		*****************		\n");		
    printf("	*               *		*               *		\n");
    printf("	*  **   **   ** *		*  **       **  *		\n");
    printf("	*  **   **   ** *		*  **       **  *		\n");
    printf("	*               *		*       **      *		\n");
    printf("	*               *		*       **      *		\n");
    printf("	*  **   **   ** *		*  **       **  *		\n");
    printf("	*  **   **   ** *		*  **       **  *		\n");
    printf("	*               *		*               *		\n");
    printf("	*****************		*****************		\n");	
	printf("\n");
	printf(" REGLAS DE JUEGO: \n\n Las reglas de juego son muy simples, el jugador tira dos dados. Si la suma de puntos en las caras es 7 u 11 \n en el primer tiro el jugador gana. Si la suma es 2, 3 o 12 en el primer tiro lanzado, el jugador pierde (es decir la \n casa gana). En cualquier otro caso la suma obtenida en el primer tiro se convierte en el punto del jugador. \n Para ganar el jugador debe seguir tirando los dados hasta obtener su punto. El jugador pierde si obtiene un 7 \n antes de obtener su punto. \n El jugador tiene un saldo banco inicial de 1000 para apostar.\n\n INSTRUCCIONES:\n\n Pulse 'Enter' para lanzar cada dado. \n\n");
}


