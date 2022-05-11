#define primo_punto_h_included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6
#define M 99

void base_5_nodi();										
void avanzata_5_nodi();
int dijkstra_5_nodi(int grafo[][N], int partenza, int arrivo);

void base_5_nodi()
{
	int i=0;							//Variabile di controllo e per i cicli
	int j=0;							//Variabile di controllo e per i cicli
	int tmp;							//Variabile di appoggio
	int num=1;							//Variabile di appoggio	per la stampa della tabella
	int cont=0;							//Variabile utilizzata come contatore 
	int cammino=0;						//Variabile che contiene il cammino minimo
	int partenza, arrivo;				//Variabili che contengono i nodi di partenza e di arrivo
	int grafo[N][N];					//Matrice dei nodi

	FILE *fp;							//Puntatore al file				

	if ((fp=fopen("Dijkstra.txt","w"))==NULL)        		//Apro il file in scrittura e controllo l'apertura                                
    {
        printf("Errore nell’apertura del file");
    }

	//METTO TUTTI I VALORI DEL GRAFO A 99
	for(i=1 ; i<N ; i++)
	{
		for(j=1 ; j<N ; j++)
		{
			grafo[i][j]=M;									
		}
	}

	//IMPOSTO IL GRAFO A 5 NODI 
	grafo[1][2]=5;
	grafo[2][3]=6;
	grafo[2][4]=8;
	grafo[3][4]=1;
	grafo[3][5]=5;
	grafo[4][5]=3;

	i=0;
	j=0;

	//STAMPO IL GRAFO A 5 NODI SU FILE
	fprintf(fp, "\n");
	fprintf(fp, "\t\t  Grafo Dijkstra \n\n");
	fprintf(fp, "\t 1\t 2\t 3\t 4\t 5\n");
	fprintf(fp, "  \t_______________________________________________\n");
	for(i=1 ; i<N ; i++)
	{
		fprintf(fp, "%d            │ \t",num);
		num++;
		for(j=1 ; j<N ; j++)
		{
			tmp=grafo[i][j];
			fprintf(fp, " %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==5)									//Ogni 5 caratteri la riga va a capo per la stampa
		{
			fprintf(fp, "\n");
			cont=0;
		}
	}
	num=1;
	cont=0;

	//STAMPO IL GRAFO A 5 NODI 
	printf("\n");
	printf("\t\t  Grafo Dijkstra \n\n");
	printf("\t 1\t 2\t 3\t 4\t 5\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	for(i=1 ; i<N ; i++)
	{
		printf("%d %c\t",num,179);
		num++;
		for(j=1 ; j<N ; j++)
		{
			tmp=grafo[i][j];
			printf(" %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==5)										//Ogni 5 caratteri la riga va a capo per la stampa
		{
			printf("\n");
			cont=0;
		}
	}

	//NODO DI PARTENZA E IL NODO DI ARRIVO
	fprintf(fp, "\nNodo di Partenza--> 1");
	printf("\nNodo di Partenza--> 1");
    partenza=1;
    fprintf(fp, "\nNodo di Arrivo--> 5");
	printf("\nNodo di Arrivo--> 5");
    arrivo=5;
	fprintf(fp, "\n\n");
	printf("\n\n");
	cammino = dijkstra_5_nodi(grafo,partenza,arrivo);
	fprintf(fp, "\nIl costo totale e' il seguente: %d",cammino);
	printf("\nIl costo totale e' il seguente: %d",cammino);
	fclose(fp);
}

void avanzata_5_nodi()
{
    int i=0;							//Variabile di controllo e per i cicli
	int j=0;							//Variabile di controllo e per i cicli
	int tmp;							//Variabile di appoggio
	int cont;							//Variabile utilizzata come contatore
	int num=1;							//Variabile di appoggio	per la stampa della tabella
	int cammino=0;						//Variabile che contiene il cammino minimo
	int nodi[N][N];						//Matrice dei nodi
	int grafo[N][N];					//Matrice dei pesi
	int partenza, arrivo;				//Variabili che contengono i nodi di partenza e di arrivo

    FILE *fp;							//Puntatore al file

	if ((fp=fopen("Dijkstra.txt","w"))==NULL)     			//Apro il file in scrittura e controllo l'apertura                                
	{
		printf("Errore nell’apertura del file");
	}                                  
	
	//METTO TUTTI I VALORI DEL GRAFO A 99
	for(i=1 ; i<N ; i++)
	{
		for(j=1 ; j<N ; j++)
		{
			grafo[i][j]=M;
		}
	}

	//RICHIEDO ALL'UTENTE DI SCEGLIERE I COLLEGAMENTI TRA I NODI E IL RELATIVO PESO 
	printf("Inserisci i Collegamenti fra i Nodi \n[1]Collegamento\t[0]No Collegamento\n\n");
	for(i=1 ; i<N ; i++)
	{
		for(j=1 ; j<N ; j++)
		{ 
			if(i>=j)
			{
				nodi[i][j]=0;
			}
			else
			{
				printf("Dal %d Nodo al %d Nodo: ", i, j);
	        	scanf("%d",&nodi[i][j]);
			}
			
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
			else if(nodi[i][j]!=1 && nodi[i][j]!=0)
			{
				printf("\n--Carattere Inserito Non Valido!--\n");
				printf("\n--Uscita dal Programma--\n");
				sleep(2);
				exit(0);
			}
			printf("\n");
		}
	}
	i=0;
	j=0;

	//STAMPO IL GRAFO A 5 NODI SU FILE
	fprintf(fp, "\n");
	fprintf(fp, "\t\t  Grafo Dijkstra \n\n");
	fprintf(fp, "\t 1\t 2\t 3\t 4\t 5\n");
	fprintf(fp, "  \t_______________________________________________\n");
	for(i=1 ; i<N ; i++)
	{
		fprintf(fp, "%d            │ \t",num);
		num++;
		for(j=1 ; j<N ; j++)
		{
			tmp=grafo[i][j];
			fprintf(fp, " %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==5)
		{
			fprintf(fp, "\n");
			cont=0;
		}
	}
	num=1;
	cont=0;

	//STAMPO IL GRAFO A 5 NODI
	printf("\n");
	printf("\t  Grafo Dijkstra \n\n");
	printf("\t 1\t 2\t 3\t 4\t 5\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	for(i=1 ; i<N ; i++)
	{
		printf("%d %c\t",num,179);
		num++;
		for(j=1 ; j<N ; j++)
		{
			tmp=grafo[i][j];
			printf(" %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==5)
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
		if(partenza>N-1)
		{
			printf("Errore!Il Nodo inserito e' troppo grande [MAX -> %d]\n",N-1);
		}
	}
	while(partenza<=0 || partenza>N-1);
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
		if(arrivo>N-1)
		{
			printf("Errore!Il Nodo inserito e' troppo grande [MAX -> %d]\n",N-1);
		}
		printf("\n");
    }
	while(arrivo<=0 || arrivo>N-1 || partenza == arrivo);

	fprintf(fp, "\n");
	fprintf(fp, "Nodo di Partenza --> %d \n",partenza);
	fprintf(fp, "Nodo di Arrivo --> %d \n",arrivo);
	cammino = dijkstra_5_nodi(grafo,partenza,arrivo);
	fprintf(fp, "\nIl costo totale e' il seguente: %d",cammino);
	printf("\nIl costo totale e' il seguente: %d",cammino);
	fclose(fp);
}        

int dijkstra_5_nodi(int grafo[][N], int partenza, int arrivo)
{
	int dist[N];											//Variabile che contiene la distanza dal nodo di partenza
	int prec[N];												//Variabile che contiene il nodo precedente
	int selez[N]={0};									//Variabile che contiene i nodi selezionati
	int i,m,min,start,d,j;										//Variabili di controllo
    char path[N];											//Variabile che contiene il percorso
	int lunghezza;										//Variabile che contiene la lunghezza della stringa del percorso minimo

    for(i=1 ; i<N ; i++)										//Inizializzo tutti i nodi a 99
    {
        dist[i] = M;										//Inizializzo tutti i nodi a 99										
        prec[i] = -1;										//Inizializzo tutti i nodi precedenti a -1
    }
    start = partenza;										//Nodo di partenza
    selez[start]=1;											//Nodo di partenza selezionato
    dist[start] = 0;										//Nodo di partenza distanza 0
    while(selez[arrivo] ==0)									//Ciclo che si ripete finchè il nodo di arrivo non è stato selezionato
    {
        min = M;											//Inizializzo la variabile min a M
        m = 0;
        for(i=1; i<N ; i++)									//Ciclo che scorre tutti i nodi
        {
            d = dist[start]+grafo[start][i];					//Calcolo la distanza dal nodo di partenza
            if(d< dist[i] && selez[i]==0)				//Se la distanza è minore della distanza attuale e il nodo non è selezionato
			{
				dist[i] = d;									//Aggiorno la distanza
				prec[i] = start;									//Aggiorno il nodo precedente
			}
            if(min>dist[i] && selez[i]==0)				//Se la distanza è minore della distanza minore e il nodo non è selezionato
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
        path[j++] = start+48;									//Aggiungo il nodo alla stringa partendo da 0
        start = prec[start];										//Aggiorno il nodo di partenza
    }
    path[j]='\0';											//Aggiungo il carattere di fine stringa
    strrev(path);  												//Inverto la stringa con la funzione strrev();
	lunghezza=strlen(path);
	printf("Il percorso piu' breve e' il seguente: ");
	for(j=0; j<lunghezza ; j++)
    {
		printf("%c ", path[j]);								//Stampo il percorso
	}
    return dist[arrivo];									//Restituisco la distanza
}

