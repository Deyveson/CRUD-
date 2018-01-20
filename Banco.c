#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

typedef struct cliente{
	
	char nomecliente[10],senhacliente[10];
	int conta,agencia,liberado;
	float saldo,emprestimo;
	
}cliente;

FILE *pc;
void Menu_Gerente();
void Menu_Cliente(char *nick);
void CadastrarCliente();
void AlterarCliente();
void ExcluirCliente();
void ExtratoCliente(char *nick);
void DepositoCliente(char *nick);
void SaqueCliente(char *nick);
void SolicitarEmprestimo(char *nick);
void ConsultarEmprestimo(char *nick);

int main(){
		
	printf("Inicializando Sistema.....");
	Sleep(3000);
		
	cliente cliente;
	
	char nick[10],senha[10];
	
	char adm[10]= "adm";
	char senhaadm[10]= "123";
	
	int menu=0,login=0;
	
	do{
	
	system("cls");	
	system("color 0a");
	printf("\t \t \t \t \t \t \t \tDate: %s Hora: %s\n",__DATE__,__TIME__);	
	 
	printf("\nDigite seu Nick:\n");
	fflush(stdin);
	gets(nick);
	
	printf("Digite sua senha\n");
	fflush(stdin);
	gets(senha);		
		
	if(strcmp(strupr(adm),strupr(nick))==0 && strcmp(strupr(senha),strupr(senhaadm))==0){
		login=1;
	};
	
	if(login!=1){
	
	pc = fopen("Cliente.txt","rb");
	
	rewind(pc);
	
	while(!feof(pc)){
		fread(&cliente,sizeof(cliente),1,pc);
		if(!feof(pc)){
			
		if(strcmp(strupr(cliente.nomecliente),strupr(nick))==0 && strcmp(strupr(senha),strupr(cliente.senhacliente))==0){
				login=2;							
			};
		
		}
	};
	
	fclose(pc);	
	};
	
	system("pause");
	
	if(login==1){
		
		login=0;
		Menu_Gerente();
		menu=1;	
		
	}else if(login==2){
		
		login=0;
		Menu_Cliente(nick);
		menu=1;
		
	}else{
		
		system("cls");	
		system("color 1f");
		printf("\n---------------------------------------------------------------------------------------------------\n");
		printf("\n \t \t \t \t Nick ou senha Invalidos \n");
		printf("\n---------------------------------------------------------------------------------------------------\n");
		printf("\n \t \t \t     DESEJA SAIR OU TENTAR NOVAMENTE \n");
		printf("\n \t \t \t      1-Tentar novamente  0 - SAIR \n");
		scanf("%d",&menu);
		
	}
			
	}while(menu!=0);
	
	}

void Menu_Gerente(){
	
	int menu=0;
	do{	
	system("cls");	
	system("color 4f");
	printf("\n-----------------------------------------BANCO DO BRASIL-----------------------------------------:\n");
	printf("\nSEJA BEM VINDO GERENTE: adm");
	printf("\n          \t \t \t \t           Date:%s Hora:%s\n",__DATE__,__TIME__);
	printf("__________________________________________________________________________________________________");
	printf("\n\n");
	printf("\t\t\t1 - Abrir conta:\n");
	printf("\t\t\t2 - Atualizar Dados\n");
	printf("\t\t\t3 - Encerrar Conta\n");
	printf("\t\t\t0 - Sair\n");
	printf("__________________________________________________________________________________________________\n");
	
	scanf("%d",&menu);
	
	switch(menu){
	
	case 1:
		CadastrarCliente();
		break;
	case 2:
		AlterarCliente();
		break;
	case 3:
		ExcluirCliente();
		break;
	case 0:
		menu=0;
		break;
	default:
	printf("Opcao invalida\n");
    system("pause");
	}
	}while(menu!=0);
		
};

void Menu_Cliente(char *nick){
	
	cliente cliente;
	int menu=0;
	
	do{
	
	system("cls");
	system("color 81");
	printf("\n-----------------------------------------BANCO DO BRASIL-----------------------------------------:\n");
	printf("\nSEJA BEM VINDO CLIENTE: %s", nick);
	printf("\n          \t \t \t \t           Date:%s Hora:%s\n",__DATE__,__TIME__);
	printf("__________________________________________________________________________________________________");
	printf("\n\n");
	printf("\t\t\t1 - Consultar Extrato\n");
	printf("\t\t\t2 - Realizar Deposito\n");
	printf("\t\t\t3 - Realizar Saque\n");
	printf("\t\t\t4 - Realizar Emprestimo\n");
	printf("\t\t\t5 - Consultar Emprestimo\n");
	printf("\t\t\t0 - Sair\n");
	printf("__________________________________________________________________________________________________\n");
	scanf("%d",&menu);
	
	switch(menu){
	
	case 1:
		ExtratoCliente(nick);
		break;		
	case 2:
		DepositoCliente(nick);
		break;	
	case 3:
	 	SaqueCliente(nick);
	 	break;
	case 4:
		SolicitarEmprestimo(nick);
		break;
	case 5:
		ConsultarEmprestimo(nick);
		break;
	case 0:
		menu=0;
		break;
	default:
	printf("Opcao invalida\n");
    system("pause");
	}
	}while(menu!=0);
}

void CadastrarCliente(){
	
	cliente cliente;
	
	pc = fopen("Cliente.txt","ab+");
	
	system("cls");
	printf("\n-------------------------------CADASTRO DE CLIENTE-------------------------------:\n");
	printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
	
	printf("\nDigite nome do cliente:\n");	
	fflush(stdin);
	gets(cliente.nomecliente);

	printf("\nDigite uma senha:\n");	
	fflush(stdin);
	gets(cliente.senhacliente);	
	
	printf("\n \t Digite numero da conta Corrente:\n");
    scanf("%d", &cliente.conta);
                 	
    printf("\n \t Digite numero da Agencia:\n");
    scanf("%d", &cliente.agencia);
    				
	printf("\n \t Digite o saldo do Cliente:\n");
    scanf("%f", &cliente.saldo);
    
    cliente.emprestimo=cliente.saldo/2;
    
	system("cls");
	printf("\n Cadastro Realizado com Sucesso\n");
	
	printf("\n Nome: %s \n",cliente.nomecliente);
	printf("\n Conta: %d \n",cliente.conta);
	printf("\n Agencia: %d \n",cliente.agencia);
	printf("\n Saldo: %.2f \n",cliente.saldo);
	
	system("pause");
	
	fwrite(&cliente,sizeof(cliente),1,pc);
	
	fclose(pc);	
}

void AlterarCliente(){
	
	cliente cliente;
		
	int pesqconta,cont=0,menu=0,teste=0;
	
	pc = fopen("Cliente.txt","rb+");
	do{
	
	printf("\nDigite numero da Conta\n");
	scanf("%d", &pesqconta);
	
	rewind(pc);
	
	while(!feof(pc)){
		
		fread(&cliente,sizeof(cliente),1,pc);
		
		if(!feof(pc)){
			
			if(pesqconta==cliente.conta){
				
				system("cls");
				printf("\n-----------------------------ATUALIZAR CONTA-----------------------------:\n");
				printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
						
				printf("\nDigite nome do cliente:\n");	
				fflush(stdin);
				gets(cliente.nomecliente);

				printf("\nDigite uma senha:\n");	
				fflush(stdin);
				gets(cliente.senhacliente);	
	
				printf("\n \t Digite numero da conta Corrente:\n");
    			scanf("%d", &cliente.conta);
                 	
    			printf("\n \t Digite numero da Agencia:\n");
    			scanf("%d", &cliente.agencia);
    				
				printf("\n \t Digite o saldo do Cliente:\n");
    			scanf("%f", &cliente.saldo);
    
				system("cls");
				printf("\n Atualizado com Sucesso\n");	
				
				system("pause");
				fseek(pc,cont*sizeof(cliente),SEEK_SET); // Jogou o ponteiro pra Linha que eu quero do ARQUIVO

				fwrite(&cliente,sizeof(cliente),1,pc); // Salvando arquivo
			teste=1;
				break;
				
			}else{
					teste=2;
				cont++;
				
			}
			
		}
		
	}
	
	fclose(pc);
	
			if(teste==2){
				system("cls");
				printf("\n Conta nao exite, ou foi digitado incorreto \n");
				printf("\n 1 - Tentar Novamente 0 - Sair \n");
				scanf("%d",&menu);
			}
					
			
			if(menu==1){
				pesqconta=0;
				
			}
	
	}while(menu!=0);
		
}

void ExcluirCliente(){
	
	cliente *pcont;
	pcont=(cliente*)malloc(1000*sizeof(cliente));
	cliente c;
	
	int pesqconta,cont=0,i=0,teste=0,menu=0,aux=0;
	
	pc = fopen("Cliente.txt","rb+");
	
	do{
	
	pesqconta=0;
	
	system("cls");
	printf("\n-----------------------------ENCERRAR CONTA-----------------------------:\n");
	printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
	
	printf("\nDigite numero da Conta\n");
	scanf("%d", &pesqconta);
	
		rewind(pc);
	
		while(!feof(pc)){
		
		fread(&c,sizeof(cliente),1,pc);
		
		if(!feof(pc)){
			
			if(pesqconta==c.conta){
				aux=1;
				printf("Excluindo dados\n");
      			Sleep(4000);
      			system("cls"); 
				
			}else{
			
				strcpy(pcont[i].nomecliente,c.nomecliente);
				strcpy(pcont[i].senhacliente,c.senhacliente);
		 		pcont[i].conta=c.conta;
		 		pcont[i].agencia=c.agencia;
		 		pcont[i].saldo=c.saldo;
		 		pcont[i].emprestimo=c.emprestimo;
		 		pcont[i].liberado=c.liberado;
		 		i++;
		
			}
			
		}
		
	}

	fclose(pc);
	
	pc = fopen("Cliente.txt","wb");
	
	fwrite(pcont,sizeof(cliente),i,pc);
	
 	fclose(pc);
 	
	free(pcont);
	
	system("cls");
	printf("\n-----------------------------ENCERRAR CONTA-----------------------------:\n");
	printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
	
	if(aux==1){
		
			printf("\n Conta Excluida com sucesso \n");
	
	}else{
		
			printf("\n Conta nao existe \n");
			aux=0;
	};    
	
	printf("\n\n");
	
	printf("\nDeseja Finalizar outra Conta \n 1 - sim \n 0 - nao \n");
	scanf("%d",&menu);
	
	}while(menu!=0);
		
}

void ExtratoCliente(char *nick){
	
	cliente cliente;
		
	int pesqconta,cont=0,menu=0,teste=0;
	
	pc = fopen("Cliente.txt","rb");
	
	rewind(pc);
	
	while(!feof(pc)){
		
		fread(&cliente,sizeof(cliente),1,pc);
		
		if(!feof(pc)){
			
			if(strcmp(strupr(cliente.nomecliente),strupr(nick))==0){
				
				system("cls");
				printf("\n--------------------------------EXTRATO--------------------------------:\n");
				printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
				
				printf("\nNome: %s\n", cliente.nomecliente);
				printf("\nConta: %d\n", cliente.conta);
				printf("\nAgencia: %d\n", cliente.agencia);
				printf("\nSaldo: %.2f\n", cliente.saldo);
				
				system("pause");
				
				fseek(pc,cont*sizeof(cliente),SEEK_SET); // Jogou o ponteiro pra Linha que eu quero do ARQUIVO

				fwrite(&cliente,sizeof(cliente),1,pc); // Salvando arquivo
				teste=1;
				break;
				
			}else{
					teste=2;
				cont++;
				
			}
			
		}
		
	}
	
	fclose(pc);
		
}

void DepositoCliente(char *nick){
	
	cliente cliente;
		
	int pesqconta,cont=0,menu=0,teste=0;
	float deposito;
	
	system("cls");
	printf("\n--------------------------------DEPOSITO-------------------------------:\n");
	printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
				
	printf("\nDigite valor do deposito: \n");
	scanf("%f",&deposito);
	
	system("cls");
	printf("\nDeposito realizado com Sucesso\n");
	system("pause");
	
	pc = fopen("Cliente.txt","rb+");
	
	rewind(pc);
	
	while(!feof(pc)){
		
		fread(&cliente,sizeof(cliente),1,pc);
		
		if(!feof(pc)){
			
			if(strcmp(strupr(cliente.nomecliente),strupr(nick))==0){
				
				system("cls");
				printf("\n--------------------------------DEPOSITO-------------------------------:\n");
				printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
							
				cliente.saldo=cliente.saldo+deposito;
						
				printf("\nNome: %s\n", cliente.nomecliente);
				printf("\nConta: %d\n", cliente.conta);
				printf("\nAgencia: %d\n", cliente.agencia);
				printf("\nSaldo: %.2f\n", cliente.saldo);
				
				system("pause");
				
				fseek(pc,cont*sizeof(cliente),SEEK_SET); // Jogou o ponteiro pra Linha que eu quero do ARQUIVO

				fwrite(&cliente,sizeof(cliente),1,pc); // Salvando arquivo
				teste=1;
				break;
				
			}else{
				
				teste=2;
				cont++;
				
			}
			
		}
		
	}
	
	fclose(pc);
	
}

void SaqueCliente(char *nick){
	
	cliente cliente;
		
	int pesqconta,cont=0,menu=0,teste=0;
	float saque;
		
	pc = fopen("Cliente.txt","rb+");
	
	rewind(pc);
	
	while(!feof(pc)){
		
		fread(&cliente,sizeof(cliente),1,pc);
		
		if(!feof(pc)){
			
			if(strcmp(strupr(cliente.nomecliente),strupr(nick))==0){
				
				system("cls");
				printf("\n--------------------------------DEPOSITO-------------------------------:\n");
				printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
				
				printf("\nDigite valor do Saque: \n");
				scanf("%f",&saque);
				
				printf("\nProcessando.....\n");
				Sleep(3000);
				
				if(saque<cliente.saldo){
					
					cliente.saldo=cliente.saldo-saque;
									
					printf("\n Saque Realizado com Sucesso\n");
					
				}else{
					printf("\n Saldo Insuficiente para Retirada \n");
					printf("\n Tente Novamente \n");				
				};
									
				printf("\nNome: %s\n", cliente.nomecliente);
				printf("\nConta: %d\n", cliente.conta);
				printf("\nAgencia: %d\n", cliente.agencia);
				printf("\nSaldo: %.2f\n", cliente.saldo);
				
				system("pause");
				
				fseek(pc,cont*sizeof(cliente),SEEK_SET); // Jogou o ponteiro pra Linha que eu quero do ARQUIVO

				fwrite(&cliente,sizeof(cliente),1,pc); // Salvando arquivo
				teste=1;
				break;
				
			}else{
				
				teste=2;
				cont++;
				
			}
			
		}
		
	}
	
	fclose(pc);
	
}

void SolicitarEmprestimo(char *nick){
	
	cliente cliente;
		
	int pesqconta,cont=0,menu=0,teste=0;
	float emp;
		
	pc = fopen("Cliente.txt","rb+");
	
	rewind(pc);
	
	while(!feof(pc)){
		
		fread(&cliente,sizeof(cliente),1,pc);
		
		if(!feof(pc)){
			
			if(strcmp(strupr(cliente.nomecliente),strupr(nick))==0){
				
				system("cls");
				printf("\n--------------------------------SOLICITAR EMPRESTIMO-------------------------------:\n");
				printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
				
				printf("\nDigite valor do Emprestimo: \n");
				scanf("%f",&emp);
				
				if(emp<=cliente.emprestimo){
				cliente.liberado=1;	
				}else{
					printf("\n_________________________________________________________________________________________\n");
					printf("\n \t \t CREDITO NAO LIBERADO \n");
					printf("_________________________________________________________________________________________\n");
					printf("Tente Novamente.....");
					Sleep(3000);
				};
				
				if(cliente.liberado==1){
					printf("\n_________________________________________________________________________________________\n");
					printf("\n \t \t CREDITO LIBERADO \n");
					printf("_________________________________________________________________________________________\n");
					printf("\n\n");			
					printf("\nNome: %s\n", cliente.nomecliente);
					printf("\nConta: %d\n", cliente.conta);
					printf("\nAgencia: %d\n", cliente.agencia);
					printf("\nSaldo: %.2f\n", cliente.saldo);
					cliente.emprestimo=emp;
					printf("\nEmprestimo: %.2f\n", cliente.emprestimo);
					printf("\nConcluindo Transacao.....\n");
					Sleep(3000);
				};
				
				
				printf("\n\n");
				system("pause");
				
				fseek(pc,cont*sizeof(cliente),SEEK_SET); // Jogou o ponteiro pra Linha que eu quero do ARQUIVO

				fwrite(&cliente,sizeof(cliente),1,pc); // Salvando arquivo
				teste=1;
				break;
				
			}else{
				
				teste=2;
				cont++;
				
			}
			
		}
		
	}
	
	fclose(pc);
	
}

void ConsultarEmprestimo(char *nick){
	
	cliente cliente;
		
	int pesqconta,cont=0,menu=0,teste=0,ctl=1;
	float aux=0,aux2=0;
	
	pc = fopen("Cliente.txt","rb");
	
	rewind(pc);
	
	while(!feof(pc)){
		
		fread(&cliente,sizeof(cliente),1,pc);
		
		if(!feof(pc)){
			
			if(strcmp(strupr(cliente.nomecliente),strupr(nick))==0 && cliente.liberado==1){
				
				system("cls");
				printf("\n--------------------------------CONSULTAR DE EMPRESTIMO--------------------------------:\n");
				printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
				
				printf("\nNome: %s\n", cliente.nomecliente);
				printf("\nConta: %d\n", cliente.conta);
				printf("\nAgencia: %d\n", cliente.agencia);
				printf("\nSaldo: %.2f\n", cliente.saldo);
				
				aux=cliente.emprestimo;
				aux=aux*0.2;
				aux=aux+cliente.emprestimo;
				aux=aux/12;
				
					printf("\n_________________________________________________________________________________________\n");
					printf("\n \t \t MODO DE PAGAMENTO \n");
					for(ctl=1;ctl<=12;ctl++){
						printf("\n %d x Parcela: R$ %.2f \n",ctl,aux);
					}
					
					printf("_________________________________________________________________________________________\n");
					printf("\nValor do Emprestimo: %.2f Valor Total com Juros: %.2f \n",cliente.emprestimo,aux*12);
					printf("\n\n");	
							
				system("pause");
				
				fseek(pc,cont*sizeof(cliente),SEEK_SET); // Jogou o ponteiro pra Linha que eu quero do ARQUIVO

				fwrite(&cliente,sizeof(cliente),1,pc); // Salvando arquivo
				teste=1;
				break;
				
			}else{
				
				system("cls");
				printf("\n--------------------------------CONSULTAR DE EMPRESTIMO--------------------------------:\n");
				printf("\n                                                 Date:%s Hora:%s\n",__DATE__,__TIME__);
				
				printf("\nEmprestimo indisponivel: \n");
				printf("\n\n");
				system("pause");
				
				teste=2;
				cont++;
				
			}
			
		}
		
	}
	
	
	
	fclose(pc);
	
}


