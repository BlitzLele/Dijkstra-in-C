#define secondo_punto_h_included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define P 11
#define M 99

void base_10_nodi();
void avanzata_10_nodi();
int dijkstra_10_nodi(int grafo[][P], int partenza, int arrivo);

void base_10_nodi()
{
	int i=0;								//Variabile di controllo e per i cicli
	int j=0;								//Variabile di controllo e per i cicli
	int tmp;								//Variabile di appoggio
	int num=1;								//Variabile di appoggio	per la stampa della tabella
	int cont=0;								//Variabile utilizzata come contatore
	int cammino=0;							//Variabile che contiene il cammino minimo
	int partenza, arrivo;					//Variabili che contengono i nodi di partenza e di arrivo
	int grafo[P][P];						//Matrice dei nodi

	FILE *fp;								//Puntatore al file

	if ((fp=fopen("Dijkstra.txt","w"))==NULL)        		//Apro il file in scrittura e controllo l'apertura                                
	{
		printf("Errore nell’apertura del file");
	}                               

	//METTO TUTTI I VALORI DEL GRAFO A 99
	for(i=1 ; i<P ; i++)
	{
		for(j=1 ; j<P ; j++)
		{
			grafo[i][j]=M;
		}
	}

	//IMPOSTO IL GRAFO A 10 NODI 
	grafo[1][2]=3;
	grafo[1][5]=11;
	grafo[2][3]=5;
	grafo[3][6]=7;
	grafo[3][4]=7;
	grafo[4][6]=2;
	grafo[4][10]=12;
	grafo[5][6]=1;
	grafo[6][7]=6;
	grafo[7][8]=4;
	grafo[8][9]=2;
	grafo[9][10]=4;
	
	i=0;
	j=0;

	//STAMPO IL GRAFO A 10 NODI SU FILE
	fprintf(fp, "\n");
	fprintf(fp, "\t\t\t\t  Grafo Dijkstra \n\n");
	fprintf(fp, "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\n");
	fprintf(fp, "  \t______________________________________________________________________________________________________\n");
	for(i=1 ; i<P ; i++)
	{
		if(num==10)
		{
			fprintf(fp, "%d            |\t",num);
		}
		else
		{
			fprintf(fp, "%d              |\t",num);
		}
		num++;		
		for(j=1 ; j<P ; j++)
		{
			tmp=grafo[i][j];
			fprintf(fp, " %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==10)
		{
			fprintf(fp, "\n");
			cont=0;
		}
	}
	num=1;
	cont=0;

	//STAMPO IL GRAFO A 10 NODI 
	printf("\n");
	printf("\t\t\t\t  Grafo Dijkstra \n\n");
	printf("\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	for(i=1 ; i<P ; i++)
	{
		if(num==10)
		{
			printf("%d%c\t",num,179);
		}
		else
		{
			printf("%d %c\t",num,179);
		}
		num++;
		for(j=1 ; j<P ; j++)
		{
			tmp=grafo[i][j];
			printf(" %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==10)
		{
			printf("\n");
			cont=0;
		}
	}

	//NODO DI PARTENZA E IL NODO DI ARRIVO
	fprintf(fp, "\nNodo di Partenza--> 1");
	printf("\nNodo di Partenza--> 1");
    partenza=1;
    fprintf(fp, "\nNodo di Arrivo--> 10");
    printf("\nNodo di Arrivo--> 10");
    arrivo=10;
	fprintf(fp, "\n\n");
	printf("\n\n");
	cammino = dijkstra_10_nodi(grafo,partenza,arrivo);
	fprintf(fp, "\nIl costo totale e' il seguente: %d",cammino);
	printf("\nIl costo totale e' il seguente: %d",cammino);
	fclose(fp);
}

void avanzata_10_nodi()
{
    int i=0;						//Variabile di controllo e per i cicli
	int j=0;						//Variabile di controllo e per i cicli
	int tmp;						//Variabile di appoggio
	int cont;						//Variabile usata come contatore
	int num=1;						//Variabile usata per stampare il grafo
	int cammino=0;					//Variabile che contiene il cammino minimo
	int nodi[P][P];					//Matrice dei nodi
	int grafo[P][P];				//Matrice dei pesi
	int partenza, arrivo;			//Nodi di partenza e arrivo
	
    FILE *fp;						//Puntatore al file

	if ((fp=fopen("Dijkstra.txt","w"))==NULL)         	//Apro il file e controllo l'apertura                               
	{
		printf("Errore nell’apertura del file");
	}

	//METTO TUTTI I VALORI DEL GRAFO A 99
	for(i=1 ; i<P ; i++)
	{
		for(j=1 ; j<P ; j++)
		{
			grafo[i][j]=M;
		}
	}

	//RICHIEDO ALL'UTENTE DI SCEGLIERE I COLLEGAMENTI TRA I NODI E IL RELATIVO PESO 
	printf("Inserisci i Collegamenti fra i Nodi \n[1]Collegamento\t[0]No Collegamento\n\n");
	for(i=1 ; i<P ; i++)
	{
		for(j=1 ; j<P ; j++)
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

	//STAMPO IL GRAFO A 10 NODI SU FILE
	fprintf(fp, "\n");
	fprintf(fp, "\t\t\t\t  Grafo Dijkstra \n\n");
	fprintf(fp, "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\n");
	fprintf(fp, "  \t______________________________________________________________________________________________________\n");
	for(i=1 ; i<P ; i++)
	{
		if(num==10)
		{
			fprintf(fp, "%d            |\t",num);
		}
		else
		{
			fprintf(fp, "%d              |\t",num);
		}
		num++;		
		for(j=1 ; j<P ; j++)
		{
			tmp=grafo[i][j];
			fprintf(fp, " %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==10)
		{
			fprintf(fp, "\n");
			cont=0;
		}
	}
	num=1;
	cont=0;

	//STAMPO IL GRAFO A 10 NODI
	printf("\n");
	printf("\t\t\t\t  Grafo Dijkstra \n\n");
	printf("\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\n");
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	for(i=1 ; i<P ; i++)
	{
		if(num==10)
		{
			printf("%d%c\t",num,179);
		}
		else
		{
			printf("%d %c\t",num,179);
		}
		num++;
		for(j=1 ; j<P ; j++)
		{
			tmp=grafo[i][j];
			printf(" %d\t",grafo[i][j]);
			cont++;
		}
		if(cont==10)
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
		if(partenza>P-1)
		{
			printf("Errore!Il Nodo inserito e' troppo grande [MAX -> %d]\n",P-1);
		}
	}
	while(partenza<=0 || partenza>P-1);
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
		if(arrivo>P-1)
		{
			printf("Errore!Il Nodo inserito e' troppo grande [MAX -> %d]\n",P-1);
		}
		printf("\n");
    }
	while(arrivo<=0 || arrivo>P-1 || partenza == arrivo);

	fprintf(fp, "\n");
	fprintf(fp, "Nodo di Partenza --> %d \n",partenza);
	fprintf(fp, "Nodo di Arrivo --> %d \n",arrivo);
	cammino = dijkstra_10_nodi(grafo,partenza,arrivo);
	fprintf(fp, "\nIl costo totale e' il seguente: %d",cammino);
	printf("\nIl costo totale e' il seguente: %d",cammino);
	fclose(fp);
}        

int dijkstra_10_nodi(int grafo[][P], int partenza, int arrivo)
{
	int dist[P];											//Variabile che contiene la distanza dal nodo di partenza
	int prec[P];												//Variabile che contiene il nodo precedente
	int selez[P]={0};									//Variabile che contiene i nodi selezionati
	int i,m,min,start,d,j;										//Variabili di controllo
    char path[P];											//Variabile che contiene il percorso
	int lunghezza;										//Variabile che contiene la lunghezza del percorso
    for(i=1 ; i<P ; i++)										//Inizializzo tutti i nodi a 99
    {
        dist[i] = M;									//Inizializzo tutti i nodi a 99										
        prec[i] = -1;									//Inizializzo tutti i nodi precedenti a -1
    }
    start = partenza;										//Nodo di partenza
    selez[start]=1;											//Nodo di partenza selezionato
    dist[start] = 0;										//Nodo di partenza distanza 0
    while(selez[arrivo] ==0)									//Ciclo che si ripete finchè il nodo di arrivo non è stato selezionato
    {
        min = M;											//Inizializzo la variabile min a M
        m = 0;
        for(i=1; i<P ; i++)									//Ciclo che scorre tutti i nodi
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
	lunghezza=strlen(path);									//Calcolo la lunghezza della stringa
	printf("Il percorso piu' breve e' il seguente: ");
	for(j=0; j<lunghezza ; j++)
    {
		if(path[j]>57)											//Se il carattere della stringa e' maggiore di 9 in ASCII 
		{
			printf("%d",arrivo);									//Stampo l'arrivo dato che in ASCII il numero 10 non esiste
		}
		else
		{
			printf("%c ", path[j]);								//Stampo il carattere della stringa
		}
	}
    return dist[arrivo];							//Restituisco la distanza
}

