#define terzo_punto_h_included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 99
#define G 21

void base_finale();
void dijkstra_finale();
int dijkstra_base(int grafo[][G], int partenza, int arrivo);

void base_finale()
{
	int i=0;										//Variabile di controllo e per i cicli
	int j=0;										//Variabile di controllo e per i cicli
	int tmp;										//Variabile di appoggio
	int num=1;										//Variabile di appoggio	per la stampa della tabella
	int cont=0;										//Variabile utilizzata come contatore
	int cammino=0;									//Variabile che contiene il cammino minimo
	int partenza, arrivo;							//Variabili che contengono i nodi di partenza e di arrivo
	int grafo[G][G];								//Matrice dei nodi			

	FILE *fp;										//Puntatore al file

	if ((fp=fopen("Dijkstra.txt","w"))==NULL)             		//Apro il file in scrittura e controllo l'apertura                                
	{
		printf("Errore nell’apertura del file");
	}                          

	//METTO TUTTI I VALORI DEL GRAFO A 99
	for(i=1 ; i<G ; i++)
	{
		for(j=1 ; j<G ; j++)
		{
			grafo[i][j]=M;
		}
	}

	//IMPOSTO IL GRAFO A 20 NODI 
	grafo[1][2]=5;
	grafo[1][15]=1;
	grafo[2][3]=6;
	grafo[3][1]=8;
	grafo[3][4]=1;
	grafo[3][5]=5;
	grafo[4][5]=3;
	grafo[5][6]=3;
	grafo[5][19]=17;
	grafo[6][7]=6;
	grafo[7][20]=2;
	grafo[7][8]=1;
	grafo[8][10]=1;
	grafo[9][8]=2;
	grafo[9][10]=3;
	grafo[10][11]=2;
	grafo[11][12]=5;
	grafo[11][20]=1;
	grafo[12][13]=2;
	grafo[13][14]=1;
	grafo[14][15]=4;
	grafo[15][16]=3;
	grafo[16][13]=5;
	grafo[16][17]=4;
	grafo[16][18]=10;
	grafo[17][3]=3;
	grafo[17][19]=3;
	grafo[18][20]=9;
	grafo[19][20]=12;

	i=0;
	j=0;

	//STAMPO IL GRAFO A 20 NODI 
	printf("\n");
	printf("\t\t\t  Grafo Dijkstra \n\n");
	printf("\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\t 11\t 12\t 13\t 14\t 15\t 16\t 17\t 18\t 19\t 20\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	for(i=1 ; i<G ; i++)
	{
		if(num>=10)
		{
			printf("%d%c\t",num,179);
		}
		else
		{
			printf("%d %c\t",num,179);
		}
		num++;
		for(j=1 ; j<G ; j++)
		{
			tmp=grafo[i][j];
			printf(" %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==20)
		{
			printf("\n");
			cont=0;
		}
	}

	//NODO DI PARTENZA E IL NODO DI ARRIVO
	printf("\nNodo di Partenza--> 1");
    partenza=1;
	printf("\nNodo di Arrivo--> 20");
    arrivo=20;
	printf("\n\n");
	cammino = dijkstra_base(grafo,partenza,arrivo);
	printf("\nIl costo totale e' il seguente: %d",cammino);
	fclose(fp);
}

void avanzata_finale()
{
    int i=0;													//Variabile di controllo e per i cicli
	int j=0;													//Variabile di controllo e per i cicli
	int m=0;													//Variabile di controllo e di appoggio
	int d=0;													//Variabile di controllo e di appoggio
	int min;													//Variabile di appoggio
	int tmp;													//Variabile di appoggio
	int cont;													//Variabile usata come contatore
	int MAX=0;													//Variabile che contiene il numero di nodi inseriti dall'utente
	int start;													//Variabile di appoggio
	int cammino=0;												//Variabile che contiene il costo totale del cammino
	int partenza, arrivo, lunghezza;							//Variabili che contengono i nodi di partenza e di arrivo e la lunghezza della stringa del cammino
	int dist[MAX];											//Variabile che contiene la distanza dal nodo di partenza
	int prec[MAX];												//Variabile che contiene il nodo precedente
	int selez[MAX];											//Variabile che contiene i nodi selezionati
	char path[MAX];												//Variabile che contiene il percorso
	memset(selez, 0, sizeof(selez));							//Inizializzo la variabile selez con tutti i valori a 0

	printf("N.B.\n");
	printf("Per il corretto Funzionamento del Programma \nInserire sempre un Nodo in piu' di quelli Desiderati\n\n"); 
	printf("Es: Per un Grafo 5x5 Inserire --> 6 Nodi ecc...\n\n"); 
	printf("Quanti Nodi vuoi Inserire all'Interno del Grafo?--> ");
	scanf("%d",&MAX);
	printf("\n");

	int nodi[MAX][MAX];										//Matrice dei nodi
	int grafo[MAX][MAX];									//Matrice del grafo
	
	//METTO TUTTI I VALORI DEL GRAFO A 99
	for(i=1 ; i<MAX ; i++)
	{
		for(j=1 ; j<MAX ; j++)
		{
			grafo[i][j]=M;
		}
	}

	//RICHIEDO ALL'UTENTE DI SCEGLIERE I COLLEGAMENTI TRA I NODI E IL RELATIVO PESO 
	printf("Inserisci i Collegamenti fra i Nodi \n[1]Collegamento\t[0]No Collegamento\n\n");
	for(i=1 ; i<MAX ; i++)
	{
		for(j=1 ; j<MAX ; j++)
		{ 
			if(i>=j)
			{
				nodi[i][j]=0;
			}
			else
			{
				if(i==j)
				{
					i++;
				}
				printf("Dal %d Nodo al %d Nodo: ", i, j);
	        	scanf("%d",&nodi[i][j]);
	        	if(nodi[i][j]==1)
				{	
					printf("\n");
					printf("Nodo Creato! Inserisci il Peso dal %d Nodo al %d Nodo: ", i, j);
					scanf("%d",&grafo[i][j]);
					if(grafo[i][j]<=0)
					{
						printf("\n");
						printf("Peso non valido! Inserisci il Peso dal %d Nodo al %d Nodo: ", i, j);
						scanf("%d",&grafo[i][j]);
					}
				}
	        	if(j==MAX-1)
				{		
					for(i=1 ; i<MAX-1 ; i++)
					{
						for(j=1 ; j<MAX ; j++)
						{ 
							printf("\n");
							printf("Dal %d Nodo al %d Nodo: ", i+1, j);
							scanf("%d",&nodi[i][j]);
							if(nodi[i][j]==1)
							{	
								printf("\n");
								printf("Nodo Creato! Inserisci il Peso dal %d Nodo al %d Nodo: ", i, j);
								scanf("%d",&grafo[i][j]);
								if(grafo[i][j]<=0)
								{
									printf("\n");
									printf("Peso non valido! Inserisci il Peso dal %d Nodo al %d Nodo: ", i, j);
									scanf("%d",&grafo[i][j]);
								}	
							}
							if(i==j)
							{
								j++;
							}		
						}
					}
				}
			}
			printf("\n");
		}
	}
	i=0;
	j=0;

	//STAMPO IL GRAFO
	printf("\n");
	printf("\t  Grafo Dijkstra \n\n");
	for(i=1 ; i<MAX ; i++)
	{
		for(j=1 ; j<MAX ; j++)
		{
			tmp=grafo[i][j];
			printf(" %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==MAX-1)
		{
			printf("\n");
			cont=0;
		}
	}

	//RICHIEDO ALL'UTENTE IL NODO DI PARTENZA E IL NODO DI ARRIVO
	do
    {
		printf("\nInserisci il Nodo di Partenza--> ");
		scanf("%d", &partenza);
		if(partenza<=0)
		{
			printf("Errore!Non e' possibile Partire da un Nodo negativo o pari a 0\n");
		}
		if(partenza>MAX-1)
		{
			printf("Errore!Il Nodo inserito e' troppo grande [MAX -> %d]\n",MAX-1);
		}
	}
	while(partenza<0 || partenza>MAX-1);
	printf("\n");
	do
	{
		printf("\nInserisci il Nodo di Arrivo--> ");
		scanf("%d", &arrivo);	
		if (partenza == arrivo)
		{
			printf("Errore!Non e' possibile Partire e Arrivare dallo stesso Nodo\n");
		}	
		if(arrivo<=0)
		{
			printf("Errore!Non e' possibile Arrivare a un Nodo negativo o pari a 0\n");
		}
		if(arrivo>MAX-1)
		{
			printf("Errore!Il Nodo inserito e' troppo grande [MAX -> %d]\n",MAX-1);
		}
		printf("\n");
    }
	while(arrivo<0 || arrivo>MAX-1 || partenza == arrivo);

	printf("\n");
	i=0;
	j=0;

	//ALGORITMO DIJSKTRA 
    for(i=1 ; i<MAX ; i++)									//Ciclo for per la partenza 
    {
        dist[i] = M;											//Inizializzo tutti i nodi a 99										
        prec[i] = -1;											//Inizializzo i nodi precedenti a -1
    }
    start = partenza;										//Nodo di partenza inizializzato 
    selez[start]=1;												//Nodo di partenza selezionato
    dist[start]=0;													//Nodo di partenza distanza 0
    while(selez[arrivo] ==0)								//Ciclo che si ripete finche' il nodo di arrivo non e' stato selezionato
    {
        min = M;											//Inizializzo la variabile min a M
        m = 0;
        for(i=1; i<MAX ; i++)									//Ciclo che scorre tutti i nodi
        {
            d = dist[start]+grafo[start][i];					//Calcolo la distanza dal nodo di partenza
            if(d<dist[i] && selez[i]==0)				//Se la distanza e' minore della distanza attuale e il nodo non e' selezionato
			{
				dist[i] = d;									//Aggiorno la distanza
				prec[i] = start;									//Aggiorno il nodo precedente
			}
            if(min>dist[i] && selez[i]==0)				//Se la distanza e' minore della distanza minore e il nodo non e' selezionato
            {
                min = dist[i];									//Aggiorno la distanza minore
                m = i;												//Aggiorno il nodo minore
            }
        }
        start = m;											//Aggiorno il nodo di partenza
        selez[start] = 1;									//Aggiorno il nodo selezionato
		system("pause");
    }
    start = arrivo;											//Nodo di arrivo
    j = 0;		
												
    while(start != -1)										//Ciclo che scorre il percorso
    {
        path[j++] = start+48;									//Aggiungo il nodo alla stringa partendo da 0
        start = prec[start];										//Aggiorno il nodo di partenza
    }
    path[j]='\0';											//Aggiungo il carattere di fine stringa
    strrev(path);  												//Inverto la stringa con la funzione strrev();
	lunghezza=strlen(path);									//Calcolo la lunghezza della stringa
	printf("Il percorso piu' breve e' il seguente: ");
	printf("%d ",partenza);
	for(j=0; j<lunghezza ; j++)									//Stampo il percorso
	{
		if(path[j]=='B')
		{
			printf("2 ");
		}
		if(path[j]=='C')
		{
			printf("3 ");
		}
		if(path[j]=='D')
		{
			printf("4 ");
		}
		if(path[j]=='E')
		{
			printf("5 ");
		}
		if(path[j]=='F')
		{
			printf("6 ");
		}
		if(path[j]=='G')
		{
			printf("7 ");
		}
		if(path[j]=='H')
		{
			printf("8 ");
		}
		if(path[j]=='I')
		{
			printf("9 ");
		}
		if(path[j]=='J')
		{
			printf("10 ");
		}
		if(path[j]=='K')
		{
			printf("11 ");
		}
		if(path[j]=='L')
		{
			printf("12 ");
		}
		if(path[j]=='M')
		{
			printf("13 ");
		}
		if(path[j]=='N')
		{
			printf("14 ");
		}
		if(path[j]=='O')
		{
			printf("15 ");
		}
		if(path[j]=='P')
		{
			printf("16 ");
		}
		if(path[j]=='Q')
		{
			printf("17 ");
		}
		if(path[j]=='R')
		{
			printf("18 ");
		}
		if(path[j]=='S')
		{
			printf("19 ");
		}
		if(path[j]=='T')
		{
			printf("20 ");
		}
		if(path[j]=='U')
		{
			printf("21 ");
		}
		if(path[j]=='V')
		{
			printf("22 ");
		}
		if(path[j]=='W')
		{
			printf("23 ");
		}
		if(path[j]=='X')
		{
			printf("24 ");
		}
		if(path[j]=='Y')
		{
			printf("25 ");
		}
		if(path[j]=='Z')
		{
			printf("26 ");
		}
	}
	printf("%d",arrivo);
    printf("\nIl costo totale e' il seguente: %d",dist[arrivo]);
	printf("\n\n");
}        

int dijkstra_base(int grafo[][G], int partenza, int arrivo)
{
	int dist[G];											//Variabile che contiene la distanza dal nodo di partenza
	int prec[G];												//Variabile che contiene il nodo precedente
	int selez[G]={0};									//Variabile che contiene i nodi selezionati
	int i,m,min,start,d,j;										//Variabili di controllo
    char path[G];											//Variabile che contiene il percorso
	int lunghezza;

    for(i=1 ; i<G ; i++)										//Inizializzo tutti i nodi a 99
    {
        dist[i] = M;											
        prec[i] = -1;
    }
    start = partenza;										//Nodo di partenza
    selez[start]=1;											//Nodo di partenza selezionato
    dist[start] = 0;										//Nodo di partenza distanza 0
    while(selez[arrivo] ==0)									//Ciclo che si ripete finche' il nodo di arrivo non e' stato selezionato
    {
        min = M;											//Inizializzo la variabile min a M
        m = 0;
        for(i=1 ; i<G ; i++)									//Ciclo che scorre tutti i nodi
        {
            d = dist[start]+grafo[start][i];					//Calcolo la distanza dal nodo di partenza
            if(d<dist[i] && selez[i]==0)				//Se la distanza e' minore della distanza attuale e il nodo non e' selezionato
			{
				dist[i] = d;									//Aggiorno la distanza
				prec[i] = start;									//Aggiorno il nodo precedente
			}
            if(min>dist[i] && selez[i]==0)				//Se la distanza e' minore della distanza minore e il nodo non e' selezionato
            {
                min = dist[i];									//Aggiorno la distanza minore
                m = i;												//Aggiorno il nodo minore
            }
        }
        start = m;											//Aggiorno il nodo di partenza
        selez[start] = 1;									//Aggiorno il nodo selezionato
    }
    start = arrivo;											//Nodo di arrivo
    j = 0;													
    while(start != -1)										//Ciclo che scorre il percorso
    {
        path[j++] = start+65;									//Aggiungo il nodo alla stringa partendo da 'A'
        start = prec[start];										//Aggiorno il nodo di partenza
    }
    path[j]='\0';											//Aggiungo il carattere di fine stringa
    strrev(path);  												//Inverto la stringa con la funzione strrev();
	lunghezza=strlen(path);									//Calcolo la lunghezza della stringa
	printf("Il percorso piu' breve e' il seguente: ");
	printf("%d ",partenza);
	for(j=0; j<lunghezza ; j++)										//Stampo il percorso
	{
		if(path[j]=='B')
		{
			printf("2 ");
		}
		if(path[j]=='C')
		{
			printf("3 ");
		}
		if(path[j]=='D')
		{
			printf("4 ");
		}
		if(path[j]=='E')
		{
			printf("5 ");
		}
		if(path[j]=='F')
		{
			printf("6 ");
		}
		if(path[j]=='G')
		{
			printf("7 ");
		}
		if(path[j]=='H')
		{
			printf("8 ");
		}
		if(path[j]=='I')
		{
			printf("9 ");
		}
		if(path[j]=='J')
		{
			printf("10 ");
		}
		if(path[j]=='K')
		{
			printf("11 ");
		}
		if(path[j]=='L')
		{
			printf("12 ");
		}
		if(path[j]=='M')
		{
			printf("13 ");
		}
		if(path[j]=='N')
		{
			printf("14 ");
		}
		if(path[j]=='O')
		{
			printf("15 ");
		}
		if(path[j]=='P')
		{
			printf("16 ");
		}
		if(path[j]=='Q')
		{
			printf("17 ");
		}
		if(path[j]=='R')
		{
			printf("18 ");
		}
		if(path[j]=='S')
		{
			printf("19 ");
		}
	}
	printf("%d",arrivo);
    return dist[arrivo];							//Restituisco la distanza
}

