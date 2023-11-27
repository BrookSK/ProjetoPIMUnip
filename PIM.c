#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#include <stdbool.h>

#include <conio.h>

// Estruturas e funcões anteriores...
// Estrutura para representar os dados da indústria do cliente
typedef struct
{
  char nomeResponsavel[50];
  char nomeEmpresa[50];
  char cnpj[20];
  char razaoSocial[50];
  char nomeFantasia[50];
  char telefone[15];
  char endereco[100];
  char cidade[50];
  char estado[3];
  char cep[10];
  char email[50];
  char dataAbertura[15];
  char dadosRelevantes[200];
} DadosIndustriaCliente;

// Estrutura para criar as variaveis de quantidade de residuos e valores de custo
typedef struct
{
  int quantidadeResiduos[50];
  float valorCusto[50];
} QuantidadeValor;

// Estrutura para representar um funcionario
typedef struct
{
  char nome[50];
  char cargo[50];
  // Adicione outros campos necessarios para o funcionario
} Funcionario;

#define MAX_FUNCIONARIOS 100
Funcionario funcionarios[MAX_FUNCIONARIOS];
int numFuncionarios = 0;

#define MAX_LEN 50

// Estrutura para representar dados dos clientes
typedef struct
{
  DadosIndustriaCliente dados; // A estrutura DadosIndustriaCliente que definimos antes
  int quantidadeResiduosSemestral;
  float gastosMensais;
} ClienteDados;

#define MAX_CLIENTES 100
ClienteDados clientes[MAX_CLIENTES]; // Array para armazenar dados dos clientes
int numClientes = 0;                 // Número atual de clientes cadastrados

// Funcao para criptografar uma string usando a cifra de Cesar
void criptografar(char *texto, int chave)
{
  int i = 0;
  while (texto[i] != '\0')
  {
    if (texto[i] >= 'a' && texto[i] <= 'z')
    {
      texto[i] = 'a' + (texto[i] - 'a' + chave) % 26;
    }
    else if (texto[i] >= 'A' && texto[i] <= 'Z')
    {
      texto[i] = 'A' + (texto[i] - 'A' + chave) % 26;
    }
    i++;
  }
}

// Funcao para descriptografar uma string usando a cifra de Cesar
void descriptografar(char *texto, int chave)
{
  criptografar(texto, 26 - chave); // A descriptografia e o inverso da criptografia com a chave negativa
}

// Prototipos de funcões
void descriptografar(char *dados, int chave);
void atualizarDadosMensais(int quantidadeResiduos, float valorCusto);

// Funcao para login
int realizarLogin()
{
  // Implemente a logica de login aqui
  char usuario[20];
  char senha[20];

  printf("=== Login ===\n");
  printf("Usuario: ");

  // Loop para garantir que o usuario nao digite uma string vazia ou apenas espacos em branco
  do
  {
    scanf("%19s", usuario); // Limitando a leitura para 19 caracteres para prevenir buffer overflow
    if (strlen(usuario) == 0 || strspn(usuario, " ") == strlen(usuario))
    {
      printf("Digite um nome de usuario valido: ");
    }
  } while (strlen(usuario) == 0 || strspn(usuario, " ") == strlen(usuario));

  printf("Senha: ");

  // Loop para garantir que a senha nao seja vazia ou apenas espacos em branco
  do
  {
    scanf("%19s", senha); // Limitando a leitura para 19 caracteres para prevenir buffer overflow
    if (strlen(senha) == 0 || strspn(senha, " ") == strlen(senha))
    {
      printf("Digite uma senha valida: ");
    }
  } while (strlen(senha) == 0 || strspn(senha, " ") == strlen(senha));

  // Criptografando usuario e senha antes de comparar ou armazenar
  criptografar(usuario, 5); // Usando chave '5', por exemplo
  criptografar(senha, 5);   // Mesma chave para senha

  // Logica para verificar o usuario e a senha
  // Aqui você pode implementar a logica de autenticacao
  // Se as credenciais estiverem corretas, retorne 1 (login bem-sucedido)
  // Caso contrario, retorne 0 (falha no login)

  // Retorne 1 se o login for bem-sucedido, 0 se falhar
  return 1; // Retornando 1 temporariamente para simular um login bem-sucedido
}

// Funcao para cadastrar um novo funcionario
void cadastrarFuncionario()
{
  if (numFuncionarios >= MAX_FUNCIONARIOS)
  {
    printf("Limite de funcionarios atingido. Nao e possivel cadastrar mais.\n");
    return;
  }

  printf("\n=== Cadastro de Funcionario ===\n");

  // Loop para garantir que o usuario nao digite uma string vazia ou apenas espacos em branco para o nome
  do
  {
    printf("Nome: ");
    scanf(" %[^\n]s", funcionarios[numFuncionarios].nome);
    if (strlen(funcionarios[numFuncionarios].nome) == 0 || strspn(funcionarios[numFuncionarios].nome, " ") == strlen(funcionarios[numFuncionarios].nome))
    {
      printf("Digite um nome valido: ");
    }
  } while (strlen(funcionarios[numFuncionarios].nome) == 0 || strspn(funcionarios[numFuncionarios].nome, " ") == strlen(funcionarios[numFuncionarios].nome));

  // Loop para garantir que o usuario nao digite uma string vazia ou apenas espacos em branco para o cargo
  do
  {
    printf("Cargo: ");
    scanf(" %[^\n]s", funcionarios[numFuncionarios].cargo);
    if (strlen(funcionarios[numFuncionarios].cargo) == 0 || strspn(funcionarios[numFuncionarios].cargo, " ") == strlen(funcionarios[numFuncionarios].cargo))
    {
      printf("Digite um cargo valido: ");
    }
  } while (strlen(funcionarios[numFuncionarios].cargo) == 0 || strspn(funcionarios[numFuncionarios].cargo, " ") == strlen(funcionarios[numFuncionarios].cargo));

  // Adicione outras informacões relevantes do funcionario
  // Criptografando nome e cargo do funcionario
  criptografar(funcionarios[numFuncionarios].nome, 3);  // Usando chave '3', por exemplo
  criptografar(funcionarios[numFuncionarios].cargo, 3); // Mesma chave para cargo

  numFuncionarios++;
  printf("Funcionario cadastrado com sucesso!\n");
}

// Funcao para cadastrar um novo cliente
void cadastrarDadosIndustriaCliente(DadosIndustriaCliente *dadosCliente)
{
  printf("\n=== Cadastro de Dados da Industria do Cliente ===\n");
  // Nome do Responsavel
  do
  {
    printf("Nome do Responsavel: ");
    scanf(" %[^\n]", dadosCliente->nomeResponsavel);
  } while (strlen(dadosCliente->nomeResponsavel) == 0 || strspn(dadosCliente->nomeResponsavel, " ") == strlen(dadosCliente->nomeResponsavel));

  // Nome da Empresa
  do
  {
    printf("Nome da Empresa: ");
    scanf(" %[^\n]", dadosCliente->nomeEmpresa);
  } while (strlen(dadosCliente->nomeEmpresa) == 0 || strspn(dadosCliente->nomeEmpresa, " ") == strlen(dadosCliente->nomeEmpresa));

  // CNPJ
  do
  {
    printf("CNPJ: ");
    scanf(" %[^\n]", dadosCliente->cnpj);
  } while (strlen(dadosCliente->cnpj) == 0 || strspn(dadosCliente->cnpj, " ") == strlen(dadosCliente->cnpj));

  // Razao Social
  do
  {
    printf("Razao Social: ");
    scanf(" %[^\n]", dadosCliente->razaoSocial);
  } while (strlen(dadosCliente->razaoSocial) == 0 || strspn(dadosCliente->razaoSocial, " ") == strlen(dadosCliente->razaoSocial));

  // Nome Fantasia
  do
  {
    printf("Nome Fantasia: ");
    scanf(" %[^\n]", dadosCliente->nomeFantasia);
  } while (strlen(dadosCliente->nomeFantasia) == 0 || strspn(dadosCliente->nomeFantasia, " ") == strlen(dadosCliente->nomeFantasia));

  // Telefone
  do
  {
    printf("Telefone: ");
    scanf(" %[^\n]", dadosCliente->telefone);
  } while (strlen(dadosCliente->telefone) == 0 || strspn(dadosCliente->telefone, " ") == strlen(dadosCliente->telefone));

  // Endereco
  do
  {
    printf("Endereco: ");
    scanf(" %[^\n]", dadosCliente->endereco);
  } while (strlen(dadosCliente->endereco) == 0 || strspn(dadosCliente->endereco, " ") == strlen(dadosCliente->endereco));

  // Cidade
  do
  {
    printf("Cidade: ");
    scanf(" %[^\n]", dadosCliente->cidade);
  } while (strlen(dadosCliente->cidade) == 0 || strspn(dadosCliente->cidade, " ") == strlen(dadosCliente->cidade));

  // Estado
  do
  {
    printf("Estado: ");
    scanf(" %[^\n]", dadosCliente->estado);
  } while (strlen(dadosCliente->estado) == 0 || strspn(dadosCliente->estado, " ") == strlen(dadosCliente->estado));

  // CEP
  do
  {
    printf("CEP: ");
    scanf(" %[^\n]", dadosCliente->cep);
  } while (strlen(dadosCliente->cep) == 0 || strspn(dadosCliente->cep, " ") == strlen(dadosCliente->cep));

  // Email
  do
  {
    printf("E-mail: ");
    scanf(" %[^\n]", dadosCliente->email);
  } while (strlen(dadosCliente->email) == 0 || strspn(dadosCliente->email, " ") == strlen(dadosCliente->email));

  // Data de Abertura
  do
  {
    printf("Data de Abertura: ");
    scanf(" %[^\n]", dadosCliente->dataAbertura);
  } while (strlen(dadosCliente->dataAbertura) == 0 || strspn(dadosCliente->dataAbertura, " ") == strlen(dadosCliente->dataAbertura));

  // Dados Relevantes para Cadastro
  do
  {
    printf("Dados Relevantes para Cadastro: ");
    scanf(" %[^\n]", dadosCliente->dadosRelevantes);
  } while (strlen(dadosCliente->dadosRelevantes) == 0 || strspn(dadosCliente->dadosRelevantes, " ") == strlen(dadosCliente->dadosRelevantes));

  // Criptografando dados do cliente
  criptografar(dadosCliente->nomeResponsavel, 7); // Usando chave '7', por exemplo
  criptografar(dadosCliente->nomeEmpresa, 7);     // Mesma chave para nome da empresa
  criptografar(dadosCliente->cnpj, 7);            // Mesma chave para cnpj da empresa
  criptografar(dadosCliente->razaoSocial, 7);     // Mesma chave para razao social da empresa
  criptografar(dadosCliente->nomeFantasia, 7);    // Mesma chave para nome fantasia da empresa
  criptografar(dadosCliente->telefone, 7);        // Mesma chave para telefone da empresa
  criptografar(dadosCliente->endereco, 7);        // Mesma chave para endereco da empresa
  criptografar(dadosCliente->cidade, 7);          // Mesma chave para cidade da empresa
  criptografar(dadosCliente->estado, 7);          // Mesma chave para estado da empresa
  criptografar(dadosCliente->cep, 7);             // Mesma chave para cep da empresa
  criptografar(dadosCliente->email, 7);           // Mesma chave para email da empresa
  criptografar(dadosCliente->dataAbertura, 7);    // Mesma chave para data de abertura da empresa
  criptografar(dadosCliente->dadosRelevantes, 7); // Mesma chave para outros dados relevantes da empresa

  printf("\nCadastro realizado com sucesso!\n");
}

// Craindo e setando valores de quantidade de residuos e valores de custo
void criaValoresEdados(QuantidadeValor *dadosValores)
{
  printf("\n=== Cadastro de Valores ===\n");

  bool entradaValida = false;
  while (!entradaValida)
  {
    printf("Digite a quantidade de residuos: ");
    if (scanf("%d", &dadosValores->quantidadeResiduos[0]) != 1)
    {
      printf("Entrada invalida. Digite um numero.\n");
      // Limpar o buffer do scanf para evitar loops infinitos
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }
    else if (dadosValores->quantidadeResiduos[0] <= 0)
    {
      printf("Digite um valor maior que zero.\n");
    }
    else
    {
      entradaValida = true;
      while (getchar() != '\n')
        ; // Limpar o buffer do scanf
    }
  }

  entradaValida = false;
  while (!entradaValida)
  {
    printf("Digite o valor de custo: ");
    if (scanf("%f", &dadosValores->valorCusto[0]) != 1)
    {
      printf("Entrada invalida. Digite um numero.\n");
      // Limpar o buffer do scanf para evitar loops infinitos
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }
    else if (dadosValores->valorCusto[0] <= 0)
    {
      printf("Digite um valor maior que zero.\n");
    }
    else
    {
      entradaValida = true;
      while (getchar() != '\n')
        ; // Limpar o buffer do scanf
    }
  }

  criptografar((char *)&dadosValores->quantidadeResiduos[0], 9);
  criptografar((char *)&dadosValores->valorCusto[0], 9);

  // Abrir o arquivo em modo de escrita
  FILE *arquivo = fopen("dados_mensais.txt", "w");
  if (arquivo != NULL)
  {
    // Escrever os valores no arquivo
    fprintf(arquivo, "Quantidade de Residuos: %d\n", dadosValores->quantidadeResiduos[0]);
    fprintf(arquivo, "Valor de Custo: %.2f\n", dadosValores->valorCusto[0]);
    fclose(arquivo);

    printf("\nCadastro realizado com sucesso!\n");
    printf("Os dados foram salvos no arquivo 'dados_mensais.txt'.\n");
    printf("Saia do sistema e entre novamente para ler o arquivo!\n");
  }
  else
  {
    printf("\nErro ao criar o arquivo.\n");
  }
}

// Funcao para atualizar as quantidades de residuos ambientais
void atualizarDadosMensais(int quantidadeResiduos, float valorCusto)
{
  int opcao;
  printf("Deseja criar um novo arquivo de texto com os dados mensais? (1 - Sim / 2 - Nao): ");
  scanf("%d", &opcao);

  if (opcao == 1)
  {
    // Lê os valores fornecidos pelo usuario
    printf("Digite a quantidade de residuos: ");
    scanf("%d", &quantidadeResiduos);
    printf("Digite o valor de custo: ");
    scanf("%f", &valorCusto);

    // Abre o arquivo para escrita e escreve os valores
    FILE *arquivo = fopen("dados_mensais.txt", "w");
    if (arquivo != NULL)
    {
      // Criptografa e escreve os valores no arquivo
      criptografar((char *)&quantidadeResiduos, 9);
      criptografar((char *)&valorCusto, 9);
      fprintf(arquivo, "Quantidade de Residuos: %d\n", quantidadeResiduos);
      fprintf(arquivo, "Valor de Custo: %.2f\n", valorCusto);
      fclose(arquivo);

      printf("Dados atualizados e salvos com sucesso!\n");
      printf("Saia do sistema e entre novamente para ler o arquivo!\n");
    }
    else
    {
      printf("Erro ao criar o arquivo.\n");
    }
  }
  else if (opcao == 2)
  {
    int quantidadeResiduos;
    float valorCusto;

    // Abre o arquivo para leitura
    FILE *arquivo = fopen("dados_mensais.txt", "r");

    if (arquivo != NULL)
    {
      // Se o arquivo existe, lê os valores atuais e exibe
      fscanf(arquivo, "Quantidade de Residuos: %d\n", &quantidadeResiduos);
      fscanf(arquivo, "Valor de Custo: %f\n", &valorCusto);
      fclose(arquivo);

      // Descriptografa e exibe os valores
      descriptografar((char *)&quantidadeResiduos, 9);
      descriptografar((char *)&valorCusto, 9);

      printf("Valores atuais:\nQuantidade de Residuos: %d\nValor de Custo: %.2f\n\n", quantidadeResiduos, valorCusto);
    }
    else
    {
      printf("Arquivo nao encontrado.\n");
      printf("Caso ja tenha criado um arquivo, saia do sistema e entre novamente!\n");
    }
  }
  else
  {
    printf("Opcao invalida.\n");
  }
}

// Funcao para verificar se o arquivo existe
bool verificaArquivo()
{
  FILE *arquivo = fopen("dados_mensais.txt", "r");
  if (arquivo != NULL)
  {
    fclose(arquivo);
    return true;
  }
  return false;
}

// Funcao para atualizar dados mensais se o arquivo existir, caso contrario, cadastra valores
void atualizarOuCadastrar(QuantidadeValor *dadosValores)
{
  if (verificaArquivo())
  {
    FILE *arquivo = fopen("dados_mensais.txt", "r");
    if (arquivo != NULL)
    {
      fscanf(arquivo, "%d %f", &dadosValores->quantidadeResiduos[0], &dadosValores->valorCusto[0]);
      fclose(arquivo);
      descriptografar((char *)&dadosValores->quantidadeResiduos[0], 9);
      descriptografar((char *)&dadosValores->valorCusto[0], 9);
      atualizarDadosMensais(dadosValores->quantidadeResiduos[0], dadosValores->valorCusto[0]);
    }
    else
    {
      printf("Erro ao abrir o arquivo para leitura.\n");
    }
  }
  else
  {
    printf("O arquivo nao existe. Cadastre valores primeiro!\n");
    criaValoresEdados(dadosValores);
  }
}

// Funcao para criar ou visualizar relatorio
void relatorio(DadosIndustriaCliente *novoCliente, QuantidadeValor *dadosValores)
{
  int opcao1;

  printf("O Cliente foi criado? (1 - Sim / 2 - Nao): ");
  scanf("%d", &opcao1);

  if (opcao1 == 2)
  {
    printf("Cadastre um cliente primeiro!\n");
    ;
  }
  else if (opcao1 == 1)
  {
    int opcao;

    // Pergunta ao usuario se ele quer criar um arquivo de relatorio ou apenas visualizar as informacões
    printf("Deseja criar um arquivo de relatorio, ele ira substituir o arquivo antigo caso ja tenha criado? (1 - Sim / 2 - Nao): ");
    scanf("%d", &opcao);

    // Declarar a variavel relatorioArquivo apenas se a opcao for 1
    FILE *relatorioArquivo = NULL;

    if (opcao == 1)
    {
      // Cria um novo arquivo de relatorio
      relatorioArquivo = fopen("relatorio.txt", "w");
      if (relatorioArquivo != NULL)
      {
        // Escreve as informacões no arquivo de relatorio
        fprintf(relatorioArquivo, "Relatorio:\n");

        // Verifica se o cliente foi cadastrado
        if (strlen(novoCliente->nomeResponsavel) > 0)
        {
          descriptografar(novoCliente->nomeResponsavel, 7);
          fprintf(relatorioArquivo, "Nome do Responsavel: %s\n", novoCliente->nomeResponsavel);
        }
        else
        {
          printf("Cadastre um cliente primeiro!\n");
          fclose(relatorioArquivo);
          return;
        }

        if (dadosValores->quantidadeResiduos[0] <= 0)
        {
          printf("Quantidade de Residuos invalida!\n");
          printf("Cadastre uma nova quantidade de Residuos\n");
        }
        else
        {
          fprintf(relatorioArquivo, "Quantidade de Residuos Tratados: %d\n", dadosValores->quantidadeResiduos[0]);
        }

        if (dadosValores->valorCusto[0] <= 0)
        {
          printf("Quantidade de Residuos invalida!\n");
          printf("Cadastre um novo valor de custo\n");
        }
        else
        {
          fprintf(relatorioArquivo, "Valor de Custo: %.2f\n", dadosValores->valorCusto[0]);
        }

        // Fecha o arquivo de relatorio
        fclose(relatorioArquivo);

        printf("Relatorio criado com sucesso!\n");
        printf("Saia do sistema para ler o arquivo!\n");
      }
      else
      {
        printf("Erro ao criar o arquivo de relatorio.\n");
      }
    }
    else if (opcao == 2)
    {
      // Visualiza as informacões sem criar um arquivo de relatorio
      // Verifica se o cliente foi cadastrado
      if (strlen(novoCliente->nomeResponsavel) > 0)
      {
        descriptografar(novoCliente->nomeResponsavel, 7);
        printf("Nome do Responsavel: %s\n", novoCliente->nomeResponsavel);
      }
      else
      {
        printf("Cadastre um cliente primeiro!\n");
        return;
      }

      if (dadosValores->quantidadeResiduos[0] <= 0)
      {
        printf("Quantidade de Residuos invalida!\n");
        printf("Cadastre uma nova quantidade de Residuos\n");
      }
      else
      {
        printf("Quantidade de Residuos Tratados: %d\n", dadosValores->quantidadeResiduos[0]);
      }

      if (dadosValores->valorCusto[0] <= 0)
      {
        printf("Quantidade de Residuos invalida!\n");
        printf("Cadastre um novo valor de custo\n");
      }
      else
      {
        printf("Valor de Custo: %.2f\n", dadosValores->valorCusto[0]);
      }
    }
    // Fecha o arquivo de relatorio, se estiver aberto
    if (relatorioArquivo != NULL)
    {
      fclose(relatorioArquivo);
    }
    else
    {
      printf("Opcao invalida.\n");
    };
  }
  else
  {
    printf("Opcao invalida.\n");
  }
}

// Funcao para exibir o menu para o usuario logado
void exibirMenuLogado()
{
  int opcao;
  DadosIndustriaCliente novoCliente; // Declaracao da variavel para armazenar os dados do novo cliente
  // Declaracao da variavel para armazenar os dados dos novos valores
  QuantidadeValor dadosValores = {
      {0},
      {0}}; // Inicializando com zero os valores

  printf("\n\nBem-vindo ao Menu Logado!\n");

  do
  {
    printf("\n=== Menu Logado ===\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Cadastrar Funcionario\n");
    printf("3. Cadastrar/Atualizar dados mensais\n");
    printf("4. Gerar relatorio\n");
    printf("5. Logout\n");
    printf("Opcao: ");

    while (scanf("%d", &opcao) != 1)
    {
      printf("Entrada invalida. Digite um numero das opcoes do menu.\n");
      // Limpar o buffer do scanf para evitar loops infinitos
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }

    switch (opcao)
    {
    case 1:
      cadastrarDadosIndustriaCliente(&novoCliente); // Passando o endereco do novo cliente como argumento
      break;
    case 2:
      cadastrarFuncionario();
      break;
    case 3:
      if (verificaArquivo())
      {
        atualizarOuCadastrar(&dadosValores);
      }
      else
      {
        printf("Cadastre valores primeiro!\n");
        criaValoresEdados(&dadosValores);
      }
      break;
    case 4:
      relatorio(&novoCliente, &dadosValores);
      break;
    case 5:
      printf("Saindo do menu logado...\n");
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
      break;
    }
  } while (opcao != 5);
}

// Funcao para exibir o menu com todas as opcões possiveis
void exibirMenuTodo()
{
  int opcao;
  DadosIndustriaCliente novoCliente; // Declaracao da variavel para armazenar os dados do novo cliente
  // Declaracao da variavel para armazenar os dados dos novos valores
  QuantidadeValor dadosValores = {
      {0},
      {0}}; // Inicializando com zero os valores

  printf("Bem-vindo ao Sistema de Gestao de Residuos!\n");

  do
  {
    printf("\n=== Menu Principal ===\n");
    printf("1. Login\n");
    printf("2. Cadastrar Cliente\n");
    printf("3. Cadastrar Funcionario\n");
    printf("4. Cadastrar/Atualizar dados mensais\n");
    printf("5. Gerar relatorio\n");
    printf("6. Sair do sistema\n");
    printf("7. Mostrar dados\n");
    printf("Opcao: ");

    while (scanf("%d", &opcao) != 1)
    {
      printf("Entrada invalida. Digite um numero das opcões do meunu.\n");
      // Limpar o buffer do scanf para evitar loops infinitos
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }

    switch (opcao)
    {
    case 1:
      if (realizarLogin() == 1)
      {
        exibirMenuLogado();
      }
      else
      {
        printf("Faca login\n");
      }
      break;
    case 2:
      if (realizarLogin() == 1)
      {
        exibirMenuLogado();
      }
      else
      {
        printf("Faca login\n");
      }
      break;
    case 3:
      if (realizarLogin() == 1)
      {
        exibirMenuLogado();
      }
      else
      {
        printf("Faca login\n");
      }
      break;
    case 4:
      if (realizarLogin() == 1)
      {
        exibirMenuLogado();
      }
      else
      {
        printf("Faca login\n");
      }
      break;
    case 5:
      if (realizarLogin() == 1)
      {
        exibirMenuLogado();
      }
      else
      {
        printf("Faca login\n");
      }
      break;
    case 6:
      printf("Saindo do sistema...\n\n");
      printf("Sistema e documentacao desenvolvido por Lucas Vacari e Eduardo Kenzo\n");
      printf("Repositorio GitHub: https://github.com/BrookSK/ProjetoPIMUnip\n");
      printf("Versao do sistema 1.7.2\n\n");
      printf("Pressione qualquer tecla para fechar a janela...");
      getch(); // Aguarda o pressionamento de uma tecla
      exit(0);
      break;
    case 7:
      if (strlen(novoCliente.nomeResponsavel) > 0)
      {
        descriptografar(novoCliente.nomeResponsavel, 7); // Supondo que '7' foi a chave usada para criptografar
        printf("Nome do Responsavel: %s\n", novoCliente.nomeResponsavel);
      }
      else
      {
        printf("Cadastre um cliente primeiro!\n");
      }
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
      break;
    }
  } while (opcao != 100);
}

// Funcao principal
int main()
{
  // comando de regionalizacao
  setlocale(LC_ALL, "Portuguese_Brazil");

  exibirMenuTodo();
}