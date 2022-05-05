#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

/*
	Name: Sistema de Gerenciamento das Olimpíadas 2024 (PIM II - Olimipadas de Paris 2024)
	Copyright: UNIP - Sorocaba 
	Author: Ederson do Amaral (ADS1)
	Date: Inicio - 15/10/21 / Término - 20/11/21 
	Description: Programa com todas as funcões necessárias para o gerenciamento administrativo das Olimpíadas
*/

bool funcionando = false;

void sair () {
	printf ("Obrigado por utilizar o nosso sistema!!!");
	exit(1);
}

void linhaDivisoria () {
	printf ("\n**************************************************\n");
}

void loginSenha () {
	
	char usuario [20] = "usuario";
	char chaveDeAcesso [20] = "123456";
	char login [20];
	char senha [20];	
	bool loginEfetuado = false;
	
	while (!loginEfetuado) {
		
		printf ("\nDIGITE SEU LOGIN: ");
		gets (login);
		
		printf ("DIGITE SUA SENHA: ");
		gets (senha);

		for (int i = 0; i < strlen(login); i++) {
			if ((login[i] >= 65) && (login[i] <= 90)) {
				login[i] = login [i] + 32;
				}
		}		
		
		if (strcmp(usuario, login) == 0 && strcmp(chaveDeAcesso, senha) == 0) {
			printf ("\nUSUARIO LOGADO COM SUCESSO!!!\n");
			loginEfetuado = true;
			funcionando = true;
			} else {
				printf ("\nLogin ou Senha incorretos!\n");
				printf ("\nTENTE NOVAMENTE!!!\n");
			}
	}
	
}

void validacaoAcesso () {
	
	char entrada[20];	
	
	printf ("*****---BENVINDO AS OLIMPIADAS DE PARIS 2024---*****\n");
	printf ("\nPossui cadastro? (S / N) = ");
	gets (entrada);
	
	if (strcmp(entrada, "S") == 0 || strcmp(entrada, "s") == 0) {
		loginSenha();
	} else if (strcmp(entrada, "N") == 0 || strcmp(entrada, "n") == 0) {
		printf ("\nPara ter acesso e preciso fazer o cadastro!\n\n");
		sair();
	} else {
		printf ("\n\nRESPOSTA INVALIDA!!!\n\n");
		sair ();
	}
}

int menuInicial () {	
	
	int menu = 99;
	
	printf ("\n########## MENU INICIAL ##########\n");
	printf ("ESCOLHA UMA OPCAO: \n\n");
	
	printf ("1) CADASTRO ATLETAS\n");
	printf ("2) CADASTRO EQUIPE OLIMPICA\n");
	printf ("3) CADASTRO MODALIDADE OLIMPICA\n");
	printf ("4) CADASTRO ALOJAMENTO\n");
	printf ("5) CADASTRO EQUIPAMENTOS\n");
	printf ("6) CADASTRO FUNCIONARIOS e VOLUNTARIOS\n");
	printf ("7) CADASTRO MEDICOS\n");
	printf ("8) CADASTRO EVENTOS\n");
	printf ("9) CADASTRO DE AGENDAMENTOS\n");
	printf ("10) RELATORIOS  OLIMPICOS GERENCIAIS\n");
	printf ("11) PROTOCOLOS SANITARIOS - COVID-19\n");
	printf ("0) PARA SAIR DO SISTEMA\n\n");
	
	scanf ("%d", &menu);
	
	return menu;
}

void retornoMenu () {
	menuInicial();
}

struct pessoaAtleta {
	char nome [60];
	int idade;
	float altura;
	float peso;
	char sexo [5];
	char nacionalidade [20];
	char modalidade [20];	
}; 

void opcaoCadAtleta () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar Atleta\n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Atletas Cadastrados\n");
	printf ("0 - Sair do Sistema\n\n");
}

void cadastroAtleta () {
	
	printf ("\n**********CADASTRO DE ATLETAS***********\n");
		
	FILE *atleta;
	struct pessoaAtleta input;
	int qtd;
		
	atleta = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/atleta.txt", "a+");
	
	if (!atleta) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (atleta, -1 * sizeof(struct pessoaAtleta), SEEK_END);
	fread (&input, sizeof(struct pessoaAtleta), 1, atleta);
	
	printf ("Quantos atletas deseja cadastrar? ");
	scanf ("%d", &qtd);	
	
	for (int i = 0; i < qtd; i++) {
		
		printf ("Entre com o nome completo (separado por _ ) do atleta: ");
		scanf ("%s", &input.nome);
			
		printf ("\nIdade: ");
		scanf ("%d", &input.idade);
		
		printf ("\nAltura: ");
		scanf ("%f", &input.altura);
	
		printf ("\nPeso: ");
		scanf ("%f", &input.peso);
		
		printf ("\nSexo: ");
		scanf ("%s", &input.sexo);

		printf ("\nNacionalidade: ");
		scanf ("%s", &input.nacionalidade);

		printf ("\nModalidade: ");
		scanf ("%s", &input.modalidade);
	
		fseek (atleta, 0, SEEK_END);
		fwrite (&input, sizeof (struct pessoaAtleta), 1, atleta);
	}

	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose (atleta);
	
}

void consCadAtleta () {
	
	FILE *atleta;
	struct pessoaAtleta input;
		
	atleta = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/atleta.txt", "r");
	
	if (!atleta) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---ATLETAS CADASTRADOS---##########");
	
	while (fread (&input, sizeof(struct pessoaAtleta), 1, atleta)) {
		printf ("\nNome Completo: %s \nIdade: %d \nAltura: %.2f \nPeso: %.2f \nGenero: %s \nNacionalidade: %s \nModalidade: %s ", input.nome, input.idade, input.altura, input.peso, input.sexo, input.nacionalidade, input.modalidade);
		linhaDivisoria();
	}
		
	fclose (atleta);
}

void cadastrarAtleta () {
	
	int opcao;
	
	opcaoCadAtleta();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadastroAtleta();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consCadAtleta();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct equipeOlimpica {
	int qtdPessoas;
	char modalidadeEquipe [40];
	char paisEquipe [30];	
};

void opcaoCadEquipe () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar Equipe\n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Equipes Cadastradas\n");
	printf ("0 - Sair do Sistema\n\n");
	
}

void cadEquipeOlimpica () {
	
	printf ("\n**********CADASTRO DE EQUIPE OLIMPICA***********\n");
		
	FILE *equipe;
	struct equipeOlimpica input;
	int qtd;
		
	equipe = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/equipe.txt", "a+");
	
	if (!equipe) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (equipe, -1 * sizeof(struct equipeOlimpica), SEEK_END);
	fread (&input, sizeof(struct equipeOlimpica), 1, equipe);
	
	printf ("Quantas equipes deseja cadastrar?");
	scanf ("%d", &qtd);
	
	for (int i = 0; i < qtd; i++) {
			
		printf ("Informe a quantas pessoas fazem parte da equipe: ");
		scanf ("%d", &input.qtdPessoas);
	
		printf ("\nInforme a modalidade da equipe: ");
		scanf ("%s", &input.modalidadeEquipe);
	
		printf ("\nInforme o pais da equipe: ");
		scanf ("%s", &input.paisEquipe);
	
		fseek (equipe, 0, SEEK_END);
		fwrite (&input, sizeof (struct equipeOlimpica), 1, equipe);
	}
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(equipe);
	
}

void consCadEquipe () {
	
	FILE *equipe;
	struct equipeOlimpica input;
		
	equipe = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/equipe.txt", "r");
	
	if (!equipe) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---EQUIPES CADASTRADAS---##########");
	
	while (fread (&input, sizeof(struct equipeOlimpica), 1, equipe)) {
		printf ("\nQuantidade de pessoas: %d \nModalidade da Equipe: %s \nPais da Equipe: %s ", input.qtdPessoas, input.modalidadeEquipe, input.paisEquipe);
		linhaDivisoria();
	}
		
	fclose (equipe);
	
}

void cadastrarEquipe () {
	
	int opcao;
	
	opcaoCadEquipe();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadEquipeOlimpica();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consCadEquipe();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct modalidadeOlimpica {
	
	char modalidade [50];
};

void opcaoCadModalidade () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar uma Modalidade Olimpica\n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Modalidades Cadastradas\n");
	printf ("0 - Sair do Sistema\n\n");
	
}

void cadModalidadeOlimpica () {
	
	printf ("\n**********CADASTRO DE MODALIDADE OLIMPICA***********\n");
		
	FILE *modalidade;
	struct modalidadeOlimpica input;
	int qtd;
			
	modalidade = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/modalidade.txt", "a+");
	
	if (!modalidade) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (modalidade, -1 * sizeof(struct modalidadeOlimpica), SEEK_END);
	fread (&input, sizeof(struct modalidadeOlimpica), 1, modalidade);
	
	printf ("Quantas modalidades deseja cadastrar? = ");
	scanf ("%d", &qtd);
		
	for (int i = 0; i < qtd; i++) {
		printf ("Informe o nome da modalidade: ");
		scanf ("%s", &input.modalidade);
		
		fseek (modalidade, 0, SEEK_END);
		fwrite (&input, sizeof (struct modalidadeOlimpica), 1, modalidade);
	}
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(modalidade);
}

void consModalOlimpica () {
	
	FILE *modalidade;
	struct modalidadeOlimpica input;
		
	modalidade = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/modalidade.txt", "r");
	
	if (!modalidade) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---MODALIDADES CADASTRADAS---##########");

	while (fread (&input, sizeof(struct modalidadeOlimpica), 1, modalidade)) {
		printf ("\nModalidade Olimpica: %s", input.modalidade);
	}
		linhaDivisoria();
		
	fclose (modalidade);
}

void cadastrarModalidade () {
	
	int opcao;
	
	opcaoCadModalidade();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadModalidadeOlimpica();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consModalOlimpica();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct alojamentoOlimpico {
	
	char nomeAlojamento [50];
	char localAlojamento [30];
	int capacidadeAlojamento;
};

void opcaoCadAlojamento () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar um Alojamento: \n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Alojamentos Cadastrados\n");
	printf ("0 - Sair do Sistema\n\n");
}

void cadAlojamentoOlimpico () {
	
	printf ("\n**********CADASTRO DE ALOJAMENTO OLIMPICO***********\n");
		
	FILE *alojamento;
	struct alojamentoOlimpico input;
	int qtd;
		
	alojamento = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/alojamento.txt", "a+");
	
	if (!alojamento) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (alojamento, -1 * sizeof(struct alojamentoOlimpico), SEEK_END);
	fread (&input, sizeof(struct alojamentoOlimpico), 1, alojamento);
	
	printf ("Quantos alojamentos deseja cadastrar? = ");
	scanf ("%d", &qtd);
		
	for (int i = 0; i < qtd; i++) {
		
		printf ("Informe o nome do alojamento: ");
		scanf ("%s", &input.nomeAlojamento);
		
		printf ("\nInforme o local do alojamento:");
		scanf ("%s", &input.localAlojamento);
		
		printf ("\nInforme a capacidade do alojamento: ");
		scanf ("%d", &input.capacidadeAlojamento);
		
		fseek (alojamento, 0, SEEK_END);
		fwrite (&input, sizeof (struct alojamentoOlimpico), 1, alojamento);
	}
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(alojamento);
	
}

void consAlojOlimpico () {
	
	FILE *alojamento;
	struct alojamentoOlimpico input;
		
	alojamento = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/alojamento.txt", "r");
	
	if (!alojamento) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---ALOJAMENTOS CADASTRADOS---##########");

	while (fread (&input, sizeof(struct alojamentoOlimpico), 1, alojamento)) {
		printf ("\nNome do Alojamento: %s \nLocal do Alojamento: %s \nCapacidade do alojamento: %d pessoas ", input.nomeAlojamento, input.localAlojamento, input.capacidadeAlojamento);
	}
		linhaDivisoria();
		
	fclose (alojamento);
}

void cadastrarAlojamento () {
	
	int opcao;
	
	opcaoCadAlojamento();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadAlojamentoOlimpico();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consAlojOlimpico();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct equipamentoOlimpico {
	
	char nomeEquipamento [20];
	char modalidadeEquipamento [20];
	int qtdEquipamento;
};

void opcaoEquipamentos () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar um Equipamento: \n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Equipamentos Cadastrados\n");
	printf ("0 - Sair do Sistema\n\n");
	
}

void cadEquipaOlimpico () {
	
	printf ("\n**********CADASTRO DE EQUIPAMENTO OLIMPICO***********\n");
		
	FILE *equipamento;
	struct equipamentoOlimpico input;	
	int qtd;
		
	equipamento = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/equipamento.txt", "a+");
	
	if (!equipamento) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (equipamento, -1 * sizeof(struct equipamentoOlimpico), SEEK_END);
	fread (&input, sizeof(struct equipamentoOlimpico), 1, equipamento);
	
	printf ("\nQuantos equipamentos deseja cadastrar? = ");
	scanf ("%d", &qtd);
	
	for (int i = 0; i < qtd; i++) {
			
		printf ("\nInforme o nome do equipamento: ");
		scanf ("%s", &input.nomeEquipamento);
		
		printf ("\nInforme a modalidade do equipamento:");
		scanf ("%s", &input.modalidadeEquipamento);
		
		printf ("\nInforme a quantidade de equipamentos: ");
		scanf ("%d", &input.qtdEquipamento);
		
		fseek (equipamento, 0, SEEK_END);
		fwrite (&input, sizeof (struct equipamentoOlimpico), 1, equipamento);
	}
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(equipamento);
	
}

void consEquipaOlimpico () {
	
	FILE *equipamento;
	struct equipamentoOlimpico input;
		
	equipamento = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/equipamento.txt", "r");
	
	if (!equipamento) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---EQUIPAMENTOS CADASTRADOS---##########");

	while (fread (&input, sizeof(struct equipamentoOlimpico), 1, equipamento)) {
		printf ("\nNome do Equipamento: %s \nModalidade do Equipamento: %s \nQuantidade de equipamentos: %d \n", input.nomeEquipamento, input.modalidadeEquipamento, input.qtdEquipamento);
	}
		linhaDivisoria();
		
	fclose (equipamento);
}

void cadastrarEquipamento () {
	
	int opcao;
	
	opcaoEquipamentos();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadEquipaOlimpico();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consEquipaOlimpico();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct equipeFuncVoluntario {
	
	char nome [30];
	int idade;
	char atividade [30];
	char areaAtuacao [30];
};

void opcaoFuncVoluntario () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar um Funcionario ou Voluntario: \n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Funcionario/Voluntarios Cadastrados\n");
	printf ("0 - Sair do Sistema\n\n");
}

void cadFuncVoluntario () {
	
	printf ("\n**********CADASTRO DE FUNCIONARIOS E VOLUNTARIOS***********\n");
		
	FILE *funcionarioVoluntario;
	struct equipeFuncVoluntario input;
	
	int qtd;
		
	funcionarioVoluntario = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/funcionarioVoluntario.txt", "a+");
	
	if (!funcionarioVoluntario) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (funcionarioVoluntario, -1 * sizeof(struct equipeFuncVoluntario), SEEK_END);
	fread (&input, sizeof(struct equipeFuncVoluntario), 1, funcionarioVoluntario);
	
	printf ("\nQuantos funcionarios/voluntarios deseja cadastrar? = ");
	scanf ("%d", &qtd);
	
	for (int i = 0; i < qtd; i++) {
				
		printf ("\nInforme o nome: ");
		scanf ("%s", &input.nome);
		
		printf ("\nInforme a idade:");
		scanf ("%d", &input.idade);
		
		printf ("\nInforme a atividade: ");
		scanf ("%s", &input.atividade);
		
		printf ("\nInforme a area de atuacao: ");
		scanf ("%s", &input.areaAtuacao);
		
		fseek (funcionarioVoluntario, 0, SEEK_END);
		fwrite (&input, sizeof (struct equipeFuncVoluntario), 1, funcionarioVoluntario);
	}
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(funcionarioVoluntario);
	
}

void consFunVoluntario () {
	
	FILE *funcionarioVoluntario;
	struct equipeFuncVoluntario input;
		
	funcionarioVoluntario = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/funcionarioVoluntario.txt", "r");
	
	if (!funcionarioVoluntario) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---FUNCIONARIOS E VOLUNTARIOS CADASTRADOS---##########");

	while (fread (&input, sizeof(struct equipeFuncVoluntario), 1, funcionarioVoluntario)) {
		printf ("\nNome: %s \nIdade: %d \nAtividade: %s \nArea de atuacao: %s \n", input.nome, input.idade, input.atividade, input.areaAtuacao);
	}
		linhaDivisoria();
		
	fclose (funcionarioVoluntario);
}

void cadastrarFunVoluntario () {
	
	int opcao;
	
	opcaoFuncVoluntario();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadFuncVoluntario();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consFunVoluntario();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct equipeMedica {
	
	char nome [50];
	int idade;
	char profissao [30];
	char especialidade [30];
	char areaAtuacao [30];
};

void opcaoEquipeMedica () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar Equipe Medica\n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Medicos e Enfermeiros Cadastrados\n");
	printf ("0 - Sair do Sistema\n\n");
}

void cadEquipeMedica () {
	
	printf ("\n**********CADASTRO DE MEDICOS E ENFERMEIROS***********\n");
		
	FILE *medicina;
	struct equipeMedica input;
	
	int qtd;
		
	medicina = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/medicina.txt", "a+");
	
	if (!medicina) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (medicina, -1 * sizeof(struct equipeMedica), SEEK_END);
	fread (&input, sizeof(struct equipeMedica), 1, medicina);
	
	printf ("\nQuantos medicos/enfermeiros deseja cadastrar? = ");
	scanf ("%d", &qtd);
	
	for (int i = 0; i < qtd; i++) {
		
		printf ("\nInforme o nome: ");
		scanf ("%s", &input.nome);
		
		printf ("\nInforme a idade:");
		scanf ("%d", &input.idade);
		
		printf ("\nInforme a profissao: ");
		scanf ("%s", &input.profissao);
		
		printf ("\nInforme a especialidade: ");
		scanf ("%s", &input.especialidade);
		
		printf ("\nInforme a area de atuacao: ");
		scanf ("%s", &input.areaAtuacao);
		
		fseek (medicina, 0, SEEK_END);
		fwrite (&input, sizeof (struct equipeMedica), 1, medicina);
	}
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(medicina);
	
	
}

void consEquipeMedica () {
	
	FILE *medicina;
	struct equipeMedica input;
		
	medicina = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/medicina.txt", "r");
	
	if (!medicina) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---MEDICOS E ENFERMEIROS CADASTRADOS---##########");

	while (fread (&input, sizeof(struct equipeMedica), 1, medicina)) {
		printf ("\nNome: %s \nIdade: %d \nProfissao: %s \nEspecialidade: %s \nArea de atuacao: %s \n", input.nome, input.idade, input.profissao, input.especialidade, input.areaAtuacao);
	}
		linhaDivisoria();
		
	fclose (medicina);
}

void cadastrarEquipeMedica () {
	
	int opcao;
	
	opcaoEquipeMedica();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadEquipeMedica();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consEquipeMedica();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct localEventos {
	
	char nomeArena [30];
	char cidadeArena [30];
	char diaEvento [10];
	char horaEvento [10];
};

void opcaoLocalEvento () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Cadastrar Local dos Jogos/Eventos\n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Jogos/Eventos Cadastrados\n");
	printf ("0 - Sair do Sistema\n\n");
	
}

void cadLocalEvento () {
	
	printf ("\n**********CADASTRO DE JOGOS E EVENTOS***********\n");
		
	FILE *evento;
	struct localEventos input;
	
	int qtd;
		
	evento = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/evento.txt", "a+");
	
	if (!evento) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (evento, -1 * sizeof(struct localEventos), SEEK_END);
	fread (&input, sizeof(struct localEventos), 1, evento);
	
	printf ("\nQuantos jogos/eventos deseja cadastrar? = ");
	scanf ("%d", &qtd);
	
	for (int i = 0; i < qtd; i++) {
				
		printf ("\nInforme o nome da arena: ");
		scanf ("%s", &input.nomeArena);
		
		printf ("\nInforme a cidade da arena:");
		scanf ("%s", &input.cidadeArena);
		
		printf ("\nInforme a data (DD/MM/AA) do evento: ");
		scanf ("%s", &input.diaEvento);
		
		printf ("\nInforme o horario (HH:MM) do evento: ");
		scanf ("%s", &input.horaEvento);
		
		fseek (evento, 0, SEEK_END);
		fwrite (&input, sizeof (struct localEventos), 1, evento);
	}
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(evento);
	
}

void consLocalEvento () {
	
	FILE *evento;
	struct localEventos input;
		
	evento = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/evento.txt", "r");
	
	if (!evento) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---JOGOS E EVENTOS CADASTRADOS---##########");

	while (fread (&input, sizeof(struct localEventos), 1, evento)) {
		printf ("\nNome da Arena: %s \nCidade da Arena: %s \nDia do Evento: %s \nHorario do Evento: %s \n", input.nomeArena, input.cidadeArena, input.diaEvento, input.horaEvento);
	}
		linhaDivisoria();
		
	fclose (evento);
}

void cadastrarEvento () {
	
	int opcao;
	
	opcaoLocalEvento();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadLocalEvento();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consLocalEvento();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

struct agendamento {
	
	char modalidade [30];
	char arena [30];
	char diaTreinamento [20];
	char horaTreinamento [10];
};

void opcaoAgendamento () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA REALIZAR: \n");
	printf ("1 - Realizar Agendamento\n");
	printf ("2 - Voltar ao Menu Inicial\n");
	printf ("3 - Consultar Lista de Agendamento\n");
	printf ("0 - Sair do Sistema\n\n");
}

void cadAgendamento () {
	
	printf ("\n**********AGENDA DE TREINAMENTO***********\n");
		
	FILE *agenda;
	struct agendamento input;	
	int qtd;
	char cadAtual;
		
	agenda = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/agenda.txt", "a+");
	
	if (!agenda) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 
	
	fflush(stdin);
	fseek (agenda, -1 * sizeof(struct agendamento), SEEK_END);
	fread (&input, sizeof(struct agendamento), 1, agenda);
	
	printf ("\n##########********ATENCAO********##########");
	printf ("\nOS AGENDAMENTOS DEVERAO SER DE HORA EM HORA");
	printf ("\n___________________________________________\n");	
	
	printf ("\nQuantos agendamentos deseja realizar? = ");
	scanf ("%d", &qtd);
	
	for (int i = 0; i < qtd; i++) {
				
		printf ("\nInforme a modalidade: ");
		scanf ("%s", &input.modalidade);
		
		printf ("\nInforme o nome da arena:");
		scanf ("%s", &input.arena);
		
		printf ("\nInforme o data (DD/MM/AA) do treinamento: ");
		scanf ("%s", &input.diaTreinamento);
		
		printf ("\nInforme a hora do treinamento: ");
		scanf ("%s", &input.horaTreinamento);
		
		fseek (agenda, 0, SEEK_END);
		fwrite (&input, sizeof (struct agendamento), 1, agenda);
	}	
	
	if (qtd == 0) {
		sair();
	} else {
		printf ("\nCadastro efetuado com sucesso!\n\n");
	}
	
	fclose(agenda);
}

void consAgendamento () {
	
	FILE *agenda;
	struct agendamento input;
		
	agenda = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/agenda.txt", "r");
	
	if (!agenda) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---LISTA DE AGENDAMENTOS CADASTRADOS---##########");

	while (fread (&input, sizeof(struct agendamento), 1, agenda)) {
		printf ("\nModalidade: %s \nArena: %s \nDia: %s \nHora: %s\n", input.modalidade, input.arena, input.diaTreinamento, input.horaTreinamento);
	}

	linhaDivisoria();
		
	fclose (agenda);
}

void cadastrarAgendamento () {
	
	int opcao;
	
	opcaoAgendamento();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			cadAgendamento();
			break;
		case 2: 
			retornoMenu();
			break;
		case 3:
			consAgendamento();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

void opcaoRelatorio () {
	
	linhaDivisoria();
	
	printf ("\nO QUE DESEJA CONSULTAR?\n");
	printf ("1 - Calendario Olimpico\n");
	printf ("2 - Quadro de Medalhas\n");
	printf ("3 - Medalhistas Olimpicos\n");
	printf ("4 - Total de medalhas distribuidas\n");
	printf ("5 - Retornar ao Menu Inicial\n");
	printf ("0 - Sair do Sistema\n\n");
}

void calendarioOlimpico () {
	
	FILE *evento;
	struct localEventos input;
		
	evento = fopen ("C:/Users/55119/Desktop/PIM/Arquivos/evento.txt", "r");
	
	if (!evento) {
		printf ("\nErro ao abrir o arquivo!!\n");
		sair ();
	} 	
	linhaDivisoria();
	
	printf ("##########---CALENDARIO OLIMPICO---##########");

	while (fread (&input, sizeof(struct localEventos), 1, evento)) {
		printf ("\nNome da Arena: %s \nCidade da Arena: %s \nData da Disputa: %s \nHorario da Disputa: %s \n", input.nomeArena, input.cidadeArena, input.diaEvento, input.horaEvento);
	}
		linhaDivisoria();
		
	fclose (evento);
	
}

void quadroMedalhas () {
	
	printf ("******---QUADRO DE MEDALHAS---*****\n\n");
	
	printf ("           OURO   PRATA   BRONZE\n");
	printf ("EUA        39      41       33    \n");
	printf ("CHINA      38      32       18   \n");
	printf ("JAPAO      27      14       17    \n");
	printf ("RUSSIA     20      28       23    \n");
	printf ("AUSTRALIA  17       7       22    \n");
	printf ("BRASIL      7       6        8    \n");
	printf ("CUBA        7       3        5    \n");
	printf ("ARGENTINA   0       1        2    \n");
	
	linhaDivisoria();	
}

void medalhistasOlimpicos () {
		
	printf ("*****---MEDALHISTAS OLIMPICOS---*****\n\n");
	
	printf ("EUA:         Simone Biles, Michael Phelps, Sue Bird, Diana Taurasi.\n");
	printf ("BRASIL:      Alisson dos Santos, Rebeca Andrade, Rayssa Leal, Italo Ferreira.\n");
	printf ("CHINA:       Gong Lijiao, Liu Hong, Zhang Wenxiu, Wang Zheng, Lyu Huihui.\n");
	printf ("AUSTRALIA:   Chris Goulding, Patty Mills, Joe Ingles, Duop Thomas, Nic Kay\n");
	printf ("ARGENTINA:   Lionel Messi, Emilliano Martinez, Cristian Romero, Lautaro Martinez.\n");
	printf ("JAPAO:       Abe Uta, Ito Mima, Ueno Yukiko, Harimoto Tomokazu, Kiyuna Ryo, Naoya Kihara.\n");
	printf ("CUBA:        Laina Perez, Alejandro Valdes, Mijain Lopez, Yaime Perez, Juan Miguel, Ismael Rivera.\n");
	
	linhaDivisoria();
}

void totalMedalhas () {
	
	printf ("*****---TOTAL DE MEDALHAS DISTRIBUIDAS---*****\n\n");
	
	printf ("PAIS        TOTAL\n");
	printf ("EUA          113\n");
	printf ("CHINA         88\n");
	printf ("JAPAO         58\n");
	printf ("RUSSIA        71\n");
	printf ("AUSTRALIA     46\n");
	printf ("BRASIL        21\n");
	printf ("CUBA          15\n");
	printf ("ARGENTINA      3\n");
	
	linhaDivisoria();
}

void relatorioOlimpico () {
	
	int opcao;
	
	opcaoRelatorio();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			calendarioOlimpico();
			break;
		case 2: 
			quadroMedalhas();
			break;
		case 3:
			medalhistasOlimpicos();
			break;
		case 4:
			totalMedalhas();
			break;
		case 5:
			retornoMenu();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
}

void opcaoCovid () {
	
	linhaDivisoria();
	
	printf ("\nSOBRE O QUE DESEJA SABER? \n");
	printf ("1 - Texto explicativo  sobre a Covid-19\n");
	printf ("2 - Sintomas e Transmissao da Covid-19\n");
	printf ("3 - Protocolos Covid-19 para atletas e comissao tecnica\n");
	printf ("4 - Protocolos Covid-19 para o publico\n");
	printf ("5 - Voltar ao Menu Inicial\n");
	printf ("0 - Sair do Sistema\n\n");
	
}

void textoSobreCovid () {
	
	printf ("O QUE E A COVID-19?\n");
	printf ("\nCoronavirus (Covid-19), e um virus responsavel por causar, doencas respiratorias agudas, com altas taxas de mutacao, atualmente existem\n");
	printf ("4 generos desse virus: ALFA, BETA, DELTA e GAMA. Desses quatro, apenas dois (Alfa e Delta) e capaz de infectar humanos.\n");
	printf ("Obs. Esse virus tambem e capaz de infectar os animais!!!\n\n");
	printf ("Segundo a OMS (Organizacao Mundial da Saude), a Covid-19 foi descoberta em Dezembro/19 na China, na cidade de Wuhan.\n");
	printf ("Ainda segundo a OMS, o virus veio de um morcego, que passou para um mamifero e dele para um ser humano via alimentos.\n");
	printf ("Porem, ainda segundo o relatorio da OMS, essa possibilidade e remota.\n");
	
	linhaDivisoria();
	printf ("\n");
}

void sintomasCovid () {
	
	printf ("SINTOMAS DA COVID-19\n");
	printf ("\nOs sintomas da Covid-19 sao vastos, sendo muito semelhantes ao de uma gripe comum, mas com grande agravamento em poucas horas.\n");
	printf ("Principais Sintomas:\n");
	printf ("- FEBRE\n");
	printf ("- FALTA DE AR\n");
	printf ("- FADIGA\n");
	printf ("- TOSSE\n");
	printf ("- PERDA DE PALADAR E OLFATO\n");
	printf ("- DORES DE CABECA\n");
	printf ("- DESCONFORTOS E DIARREIA");
	
	linhaDivisoria();
		
	printf ("\nTRANSMISSAO DA COVID-19\n");
	printf ("\nSegundo Estevao Portela, medico com mestrado e doutorado pela universidade do Rio de Janeiro,\n");
	printf ("a transmissao da Covid-19, ocorre via goticulas respiratorias produzidas por tosse e ou espirros.\n");
	printf ("Essas goticulas atingem boca, nariz ou olhos de pessoas proximas, tambem sabe-se que podemos nos contaminar\n");
	printf ("atraves do contato com objetos contaminados.\n");
	
	linhaDivisoria();
}

void protocoloAtletas () {
	
	printf ("PROTOCOLO DE PREVENSAO E CONTROLE DA COVID-19 PARA ATLETAS e COMISSAO TECNICA\n");
	printf ("- Todos os atletas precisam estar vacinados com todas as doses necessarias!\n");
	printf ("- Todos os atletas serao testados constantementes!\n");
	printf ("- Restricoes de deslocamento pela cidade e distaciamento social rigido!\n");
	printf ("- Uso obrigatorio de alcool em gel e mascaras, exceto durante a competicao!\n");
	printf ("- Se o atleta/comissao entrar em contato com alguem contaminado, esse devera ficar isolado em quarentena por 72 horas!\n");
	printf ("- Caso nenhum desses requisitos sejam respeitados, o atleta ou toda a comissao sera multada e ate podem ser expulsos dos jogos!\n");

	linhaDivisoria();
}

void protocoloPublico () {
	
	printf ("PROTOCOLO DE PREVENCAO E CONTROLE DA COVID-19 PARA O PUBLICO\n");
	printf ("- Todos deverao estar vacinados com todas as doses necessarias!\n");
	printf ("- Apresentar o comprovante de vacinacao (Carteirinha e ou App)!\n");
	printf ("- Apresentar teste negativo para Covid-19, feito em ate 72 horas antes do jogo!\n");
	printf ("- Uso obrigatorio de alcool em gel e mascaras, principalmente durante as competicoes!\n");
	
	linhaDivisoria();
}

void protocoloCovid () {
	
	int opcao;
	
	opcaoCovid();
	scanf ("%d", &opcao);
	
	switch (opcao) {
		
		case 1:
			textoSobreCovid();
			break;
		case 2: 
			sintomasCovid();
			break;
		case 3:
			protocoloAtletas();
			break;
		case 4:
			protocoloPublico();
			break;
		case 5:
			retornoMenu();
			break;
		case 0:
			sair();
			break;
		default:
			printf ("ESCOLHA INVALIDA");
			sair();
			break;
	}
	
}

void opcaoMenuInicial (int opcaoEscolhida) {
	
	switch (opcaoEscolhida) {
		
		case 1:
			cadastrarAtleta();
			break;
		case 2:
			cadastrarEquipe();
			break;
		case 3:
			cadastrarModalidade();
			break;
		case 4:
			cadastrarAlojamento();
			break;
		case 5:
			cadastrarEquipamento();
			break;
		case 6:
			cadastrarFunVoluntario();
			break;
		case 7:
			cadastrarEquipeMedica();
			break;
		case 8:
			cadastrarEvento();
			break;
		case 9:
			cadastrarAgendamento();
			break;
		case 10:
			relatorioOlimpico();
			break;
		case 11:
			protocoloCovid();
			break;
		case 0:
			sair ();
			break;
		default:
			printf ("\nOPCAO INVALIDA!! POR FAVOR, TENTE NOVAMENTE!");
	}
}

int main () {
	
	int opcaoEscolhida = 0;
	
	validacaoAcesso();
	
	linhaDivisoria();
	
	while (funcionando) {
		opcaoEscolhida = menuInicial();
		opcaoMenuInicial(opcaoEscolhida);
	}
	
	linhaDivisoria();

	return 0;
}
