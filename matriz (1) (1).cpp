#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>

using namespace std;

class Jogo_Logica
{
	private:
		
	int Posicao_Macho;
	int Posicao_Femea;
	
	public:
	
	void Envio_Pino (int* Macho, int* Femea)
	{
		if (*(Macho+Qnt_Discos)==0)
		{
			cout<<"\nO pino remetente esta vazio, operacao invalida.\n";
		}
		
		else
		{
			Posicao_Femea=0;
			for (int i=1;i<Qnt_Discos+1;i++)
			{
				if (*(Femea+i)!=0&&Posicao_Femea==0)
				{
					Posicao_Femea=i-1;
				}
				
				else if (*(Femea+i)==0&&i==Qnt_Discos)
				{
					Posicao_Femea=Qnt_Discos;
				}
			}
			
			
			Posicao_Macho=0;
			for (int i=1;i<Qnt_Discos+1;i++)
			{
				if (*(Macho+i)!=0&&Posicao_Macho==0)
				{
					Posicao_Macho=i;
				}
			}
			
			if (*(Macho+Posicao_Macho)<*(Femea+Posicao_Femea+1)&&Posicao_Femea!=Qnt_Discos)
			{
				*(Femea+Posicao_Femea)=*(Macho+Posicao_Macho);
				*(Macho+Posicao_Macho)=0;
				cout<<"\nO pino foi movido.\n";
			}
			
			else if (Posicao_Femea==Qnt_Discos)
			{
				*(Femea+Posicao_Femea)=*(Macho+Posicao_Macho);
				*(Macho+Posicao_Macho)=0;
				cout<<"\nO pino foi movido.\n";
			}
			
			else 
			{
				cout<<"\nO pino remetente e maior que o destinatario, escolha uma opcao valida.\n";
			}
		}
	}
	
	char Macho;
	char Femea;
	bool Valido;
	bool Termino;
	int Qnt_Discos;
	bool Verificacao;
	int Qnt_Max_Discos;
	int* Ponteiro_Haste_1=NULL;
	int* Ponteiro_Haste_2=NULL;
	int* Ponteiro_Haste_3=NULL;
	int* Ponteiro_Haste_Gab=NULL;

};

int main()
{
	
	//	Declaração dos objetos das classes.
	
	Jogo_Logica Logica;
	
	// Contagem do tempo de jogo
		// Armazenamento do valor de clock() quando o jogo comeca
	double tempo_de_inicio_do_jogo = clock();
	
	//	Leitura da quantidade de Discos.
	
	cout<<"Digite a quantidade de discos: ";
	Logica.Qnt_Max_Discos=10;
	Logica.Verificacao=false;
	while (Logica.Verificacao!=true) //Limita a quantidade de discos entre 0 e 10
	{
		cin>>Logica.Qnt_Discos;
		if (Logica.Qnt_Discos<Logica.Qnt_Max_Discos&&Logica.Qnt_Discos>0)
		{
			Logica.Verificacao=true;
		}
		else
		{
			cout<<"\nEntrada invalida, digite um numero positivo menor do que "<<Logica.Qnt_Max_Discos<<": ";	
		}
		cout<<endl;
	}
	
	//	Declaração das hastes para o jogo e Tabuleiro.
	
	int Haste_Gabarito[Logica.Qnt_Discos+1];
	int Haste_1[Logica.Qnt_Discos+1];
	int Haste_2[Logica.Qnt_Discos+1]={0};
	int Haste_3[Logica.Qnt_Discos+1]={0}; 
	
	// Declaração das matrizes para impressão do jogo.
	
	//char Tabuleiro[((Logica.Qnt_Discos)*6)-1][((Logica.Qnt_Discos)*6)-1] = {NULL};
	char Haste_1M[Logica.Qnt_Discos+1][(6*(Logica.Qnt_Discos))-1] = {" "};
	char Haste_2M[Logica.Qnt_Discos+1][(6*(Logica.Qnt_Discos))-1] = {" "};
	char Haste_3M[Logica.Qnt_Discos+1][(6*(Logica.Qnt_Discos))-1] = {" "};
	
	//	Atribuição dos discos.
	
	for (int i=0;i<Logica.Qnt_Discos+1;i++)
	{
		Haste_Gabarito[i]=i;
		Haste_1[i]=i;
	}
	
	//	Atribuição dos ponteiros.
	
	Logica.Ponteiro_Haste_Gab=&Haste_Gabarito[0];
	Logica.Ponteiro_Haste_1=&Haste_1[0];
	Logica.Ponteiro_Haste_2=&Haste_2[0];
	Logica.Ponteiro_Haste_3=&Haste_3[0];
	
	//	Criação de 3 matrizes, uma para cada Pino (Haste)
		
		
		for (int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for (int j=0;j<(6*(Logica.Qnt_Discos))-1;j++)
			{
				
				if(Haste_1[i] == 0)
				{
					if(j == (3*Logica.Qnt_Discos))
					{
						Haste_1M[i][j] = '|';
					}
					else
					{
						Haste_1M[i][j] = ' ';
					}
				}
				
				else
				{
					if ((j>((3*Logica.Qnt_Discos)-3*Haste_1[i] +1)) && (j <=((3*Logica.Qnt_Discos)+3*Haste_1[i] -2)))
					{
						Haste_1M[i][j] = 'X';
					}
				}
			}
			
		}
		
		for (int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for (int j=0;j<(6*(Logica.Qnt_Discos))-1;j++)
			{
				
				if(Haste_2[i] == 0)
				{
					if(j == (3*Logica.Qnt_Discos)-1)
					{
						Haste_2M[i][j] = '|';
					}
					else
					{
						Haste_2M[i][j] = ' ';
					}
				}
				else
				{
					if ((j>((3*Logica.Qnt_Discos)-3*Haste_2[i] +1)) && (j <=((3*Logica.Qnt_Discos)+3*Haste_2[i] -2)) )
					{
						Haste_2M[i][j] = 'X';
					}
				}
			}
			
		}
		
		for (int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for (int j=0;j<(6*(Logica.Qnt_Discos))-1;j++)
			{
				
				if(Haste_3[i] == 0)
				{
					if(j == (3*Logica.Qnt_Discos)-1)
					{
						Haste_3M[i][j] = '|';
					}	
					else
					{
						Haste_3M[i][j] = ' ';
					}
				}
				else
				{
					if ((j>((3*Logica.Qnt_Discos)-3*Haste_3[i] +1)) && (j <=((3*Logica.Qnt_Discos)+3*Haste_3[i] -2)) )
					{
						Haste_3M[i][j] = 'X';
					}
				}
			}
			
		}
		
		//Impressão gráfica.
		
		for(int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for(int j=0;j<(18*(Logica.Qnt_Discos))-3;j++)
			{
				if(j<6*(Logica.Qnt_Discos)-1)
				{
					cout<<Haste_1M[i][j];
				}
				else if (j>12*(Logica.Qnt_Discos)-2)
				{
					cout<<Haste_3M[i][j-(12*(Logica.Qnt_Discos)-2)];
				}
				else
				{
					cout<<Haste_2M[i][j-(6*(Logica.Qnt_Discos)-1)];
				}
				
				
			}
			cout<<endl;
		}
	
	//	Jogo.
	
	Logica.Termino=false;
	while (Logica.Termino!=true)
	{	
		
		//	Escolha do haste remetente.
		
		cout<<"\nDigite a haste da qual se removera um disco: ";
		Logica.Verificacao=false;
		while (Logica.Verificacao!=1) //Limita as escolhas das hastes em '1', '2' ou '3'.
		{
			cin>>Logica.Macho;
			if (Logica.Macho=='1'||Logica.Macho=='2'||Logica.Macho=='3')
			{
				Logica.Verificacao=true;
			}
			else
			{
				cout<<"\nEntrada invalida, digite '1', '2' ou '3': ";
			}
		}
		
		//	Escolha da haste destinatária.
		
		cout<<"\nDigite a haste que recebera um disco: ";
		Logica.Verificacao=false;
		while (Logica.Verificacao!=1) //Limita as escolhas das hastes em '1', '2' ou '3'.
		{
			cin>>Logica.Femea;
			if (Logica.Macho==Logica.Femea)
			{
				cout<<"\nEntrada invalida, digite uma haste destinatario diferente da haste remetente: ";
			}
			else if (Logica.Femea=='1'||Logica.Femea=='2'||Logica.Femea=='3')
			{
				Logica.Verificacao=true;
			}
			else
			{
				cout<<"\nEntrada invalida, digite '1', '2' ou '3': ";
			}
		}
		
		//	Possibilidades de permutação dos discos.
		
		if (Logica.Macho=='1'&&Logica.Femea=='2')
		{
			Logica.Envio_Pino(Logica.Ponteiro_Haste_1,Logica.Ponteiro_Haste_2);
		}
		
		else if (Logica.Macho=='1'&&Logica.Femea=='3')
		{
			Logica.Envio_Pino(Logica.Ponteiro_Haste_1,Logica.Ponteiro_Haste_3);
		}
		
		else if (Logica.Macho=='2'&&Logica.Femea=='1')
		{
			Logica.Envio_Pino(Logica.Ponteiro_Haste_2,Logica.Ponteiro_Haste_1);
		}
		
		else if (Logica.Macho=='2'&&Logica.Femea=='3')
		{
			Logica.Envio_Pino(Logica.Ponteiro_Haste_2,Logica.Ponteiro_Haste_3);
		}
		
		else if (Logica.Macho=='3'&&Logica.Femea=='1')
		{
			Logica.Envio_Pino(Logica.Ponteiro_Haste_3,Logica.Ponteiro_Haste_1);
		}
		
		else if (Logica.Macho=='3'&&Logica.Femea=='2')
		{
			Logica.Envio_Pino(Logica.Ponteiro_Haste_3,Logica.Ponteiro_Haste_2);
		}
			
		//	Impressão vetorial dos discos.
		
		cout<<endl;
		for (int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for (int j=0;j<(6*(Logica.Qnt_Discos))-1;j++)
			{
				
				if(Haste_1[i] == 0)
				{
					if(j == (3*Logica.Qnt_Discos))
					{
						Haste_1M[i][j] = '|';
					}	
					
					else
					{
						Haste_1M[i][j] = ' ';
					}
				}
				else
				{
					if ((j>((3*Logica.Qnt_Discos)-3*Haste_1[i] +1)) && (j <=((3*Logica.Qnt_Discos)+3*Haste_1[i] -2)))
					{
						Haste_1M[i][j] = 'X';
					}
				}
			}
			
		}
		
		for (int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for (int j=0;j<(6*(Logica.Qnt_Discos))-1;j++)
			{
				
				if(Haste_2[i] == 0)
				{
					if(j == (3*Logica.Qnt_Discos))
					{
						Haste_2M[i][j] = '|';
					}	
					else
					{
						Haste_2M[i][j] = ' ';
					}
				}
				else
				{
					if ((j>((3*Logica.Qnt_Discos)-3*Haste_2[i] +1)) && (j <=((3*Logica.Qnt_Discos)+3*Haste_2[i] -2)) )
					{
						Haste_2M[i][j] = 'X';
					}
				}
			}
			
		}
		
		for (int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for (int j=0;j<(6*(Logica.Qnt_Discos))-1;j++)
			{
				
				if(Haste_3[i] == 0)
				{
					if(j == (3*Logica.Qnt_Discos))
					{
						Haste_3M[i][j] = '|';
					}	
					else
					{
						Haste_3M[i][j] = ' ';
					}
				}
				else
				{
					if ((j>((3*Logica.Qnt_Discos)-3*Haste_3[i] +1)) && (j <=((3*Logica.Qnt_Discos)+3*Haste_3[i] -2)) )
					{
						Haste_3M[i][j] = 'X';
					}
				}
			}
			
		}
		cout<<endl;
		
		//Impressão gráfica.
		
		for(int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			for(int j=0;j<(18*(Logica.Qnt_Discos))-3;j++)
			{
				if(j<6*(Logica.Qnt_Discos)-1)
				{
					cout<<Haste_1M[i][j];
				}
				else if (j>12*(Logica.Qnt_Discos)-2)
				{
					cout<<Haste_3M[i][j-(12*(Logica.Qnt_Discos)-2)];
				}
				else
				{
					cout<<Haste_2M[i][j-(6*(Logica.Qnt_Discos)-1)];
				}
				
				
			}
			cout<<endl;
		}
	
		//	Verificação de término do jogo.
		
		Logica.Termino=true;
		for (int i=0;i<Logica.Qnt_Discos+1;i++)
		{
			if (Haste_2[i]!=Haste_Gabarito[i]&&Haste_3[i]!=Haste_Gabarito[i])
			{
				Logica.Termino=false;
			}
		}
	}
	
	cout<<"\nJogo Concluido.\n";
	
	// Contagem do tempo de jogo
		// Calculo e exibicao do tempo de jogo
	cout << "\nEsta partida de Torres de Hanoi levou " << (clock() - tempo_de_inicio_do_jogo)/1000.0 << " segundos."; 
}
