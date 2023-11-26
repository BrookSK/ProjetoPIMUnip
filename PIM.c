#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

// Estruturas e funções anteriores...
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

// Estrutura para representar um funcionário
typedef struct
{
    char nome[50];
    char cargo[50];
    // Adicione outros campos necessários para o funcionário
} Funcionario;

#define MAX_FUNCIONARIOS 100
Funcionario funcionarios[MAX_FUNCIONARIOS];
int numFuncionarios = 0;

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

// Função para criptografar uma string usando a cifra de César
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

// Função para descriptografar uma string usando a cifra de César
void descriptografar(char *texto, int chave)
{
    criptografar(texto, 26 - chave); // A descriptografia é o inverso da criptografia com a chave negativa
}

// Função para login
int realizarLogin()
{
    // Implemente a lógica de login aqui
    char usuario[20];
    char senha[20];

    printf("=== Login ===\n");
    printf("Usuario: ");

    // Loop para garantir que o usuário não digite uma string vazia ou apenas espaços em branco
    do {
        scanf("%19s", usuario); // Limitando a leitura para 19 caracteres para prevenir buffer overflow
        if (strlen(usuario) == 0 || strspn(usuario, " ") == strlen(usuario)) {
            printf("Digite um nome de usuário válido: ");
        }
    } while (strlen(usuario) == 0 || strspn(usuario, " ") == strlen(usuario));

    printf("Senha: ");

    // Loop para garantir que a senha não seja vazia ou apenas espaços em branco
    do {
        scanf("%19s", senha); // Limitando a leitura para 19 caracteres para prevenir buffer overflow
        if (strlen(senha) == 0 || strspn(senha, " ") == strlen(senha)) {
            printf("Digite uma senha válida: ");
        }
    } while (strlen(senha) == 0 || strspn(senha, " ") == strlen(senha));

    // Criptografando usuário e senha antes de comparar ou armazenar
    criptografar(usuario, 5); // Usando chave '5', por exemplo
    criptografar(senha, 5);   // Mesma chave para senha

    // Lógica para verificar o usuário e a senha
    // Aqui você pode implementar a lógica de autenticação
    // Se as credenciais estiverem corretas, retorne 1 (login bem-sucedido)
    // Caso contrário, retorne 0 (falha no login)

    // Retorne 1 se o login for bem-sucedido, 0 se falhar
    return 1; // Retornando 1 temporariamente para simular um login bem-sucedido
}

// Função para cadastrar um novo funcionário
void cadastrarFuncionario()
{
    if (numFuncionarios >= MAX_FUNCIONARIOS)
    {
        printf("Limite de funcionarios atingido. Nao é possivel cadastrar mais.\n");
        return;
    }

    printf("\n=== Cadastro de Funcionario ===\n");

    // Loop para garantir que o usuário não digite uma string vazia ou apenas espaços em branco para o nome
    do {
        printf("Nome: ");
        scanf(" %[^\n]s", funcionarios[numFuncionarios].nome);
        if (strlen(funcionarios[numFuncionarios].nome) == 0 || strspn(funcionarios[numFuncionarios].nome, " ") == strlen(funcionarios[numFuncionarios].nome)) {
            printf("Digite um nome válido: ");
        }
    } while (strlen(funcionarios[numFuncionarios].nome) == 0 || strspn(funcionarios[numFuncionarios].nome, " ") == strlen(funcionarios[numFuncionarios].nome));

    // Loop para garantir que o usuário não digite uma string vazia ou apenas espaços em branco para o cargo
    do {
        printf("Cargo: ");
        scanf(" %[^\n]s", funcionarios[numFuncionarios].cargo);
        if (strlen(funcionarios[numFuncionarios].cargo) == 0 || strspn(funcionarios[numFuncionarios].cargo, " ") == strlen(funcionarios[numFuncionarios].cargo)) {
            printf("Digite um cargo válido: ");
        }
    } while (strlen(funcionarios[numFuncionarios].cargo) == 0 || strspn(funcionarios[numFuncionarios].cargo, " ") == strlen(funcionarios[numFuncionarios].cargo));

    // Adicione outras informações relevantes do funcionário
    // Criptografando nome e cargo do funcionário
    criptografar(funcionarios[numFuncionarios].nome, 3);  // Usando chave '3', por exemplo
    criptografar(funcionarios[numFuncionarios].cargo, 3); // Mesma chave para cargo

    numFuncionarios++;
    printf("Funcionario cadastrado com sucesso!\n");
}

// Função para cadastrar um novo cliente
void cadastrarDadosIndustriaCliente(DadosIndustriaCliente *dadosCliente)
{
    printf("\n=== Cadastro de Dados da Industria do Cliente ===\n");
        // Nome do Responsável
    do {
        printf("Nome do Responsavel: ");
        scanf(" %[^\n]", dadosCliente->nomeResponsavel);
    } while (strlen(dadosCliente->nomeResponsavel) == 0 || strspn(dadosCliente->nomeResponsavel, " ") == strlen(dadosCliente->nomeResponsavel));

    // Nome da Empresa
    do {
        printf("Nome da Empresa: ");
        scanf(" %[^\n]", dadosCliente->nomeEmpresa);
    } while (strlen(dadosCliente->nomeEmpresa) == 0 || strspn(dadosCliente->nomeEmpresa, " ") == strlen(dadosCliente->nomeEmpresa));

    // CNPJ
    do {
        printf("CNPJ: ");
        scanf(" %[^\n]", dadosCliente->cnpj);
    } while (strlen(dadosCliente->cnpj) == 0 || strspn(dadosCliente->cnpj, " ") == strlen(dadosCliente->cnpj));

    // Razão Social
    do {
        printf("Razao Social: ");
        scanf(" %[^\n]", dadosCliente->razaoSocial);
    } while (strlen(dadosCliente->razaoSocial) == 0 || strspn(dadosCliente->razaoSocial, " ") == strlen(dadosCliente->razaoSocial));

    // Nome Fantasia
    do {
        printf("Nome Fantasia: ");
        scanf(" %[^\n]", dadosCliente->nomeFantasia);
    } while (strlen(dadosCliente->nomeFantasia) == 0 || strspn(dadosCliente->nomeFantasia, " ") == strlen(dadosCliente->nomeFantasia));

    // Telefone
    do {
        printf("Telefone: ");
        scanf(" %[^\n]", dadosCliente->telefone);
    } while (strlen(dadosCliente->telefone) == 0 || strspn(dadosCliente->telefone, " ") == strlen(dadosCliente->telefone));

    // Endereco
    do {
        printf("Endereco: ");
        scanf(" %[^\n]", dadosCliente->endereco);
    } while (strlen(dadosCliente->endereco) == 0 || strspn(dadosCliente->endereco, " ") == strlen(dadosCliente->endereco));

    // Cidade
    do {
        printf("Cidade: ");
        scanf(" %[^\n]", dadosCliente->cidade);
    } while (strlen(dadosCliente->cidade) == 0 || strspn(dadosCliente->cidade, " ") == strlen(dadosCliente->cidade));

    // Estado
    do {
        printf("Estado: ");
        scanf(" %[^\n]", dadosCliente->estado);
    } while (strlen(dadosCliente->estado) == 0 || strspn(dadosCliente->estado, " ") == strlen(dadosCliente->estado));

    // CEP
    do {
        printf("CEP: ");
        scanf(" %[^\n]", dadosCliente->cep);
    } while (strlen(dadosCliente->cep) == 0 || strspn(dadosCliente->cep, " ") == strlen(dadosCliente->cep));

    // Email
    do {
        printf("E-mail: ");
        scanf(" %[^\n]", dadosCliente->email);
    } while (strlen(dadosCliente->email) == 0 || strspn(dadosCliente->email, " ") == strlen(dadosCliente->email));

    // Data de Abertura
    do {
        printf("Data de Abertura: ");
        scanf(" %[^\n]", dadosCliente->dataAbertura);
    } while (strlen(dadosCliente->dataAbertura) == 0 || strspn(dadosCliente->dataAbertura, " ") == strlen(dadosCliente->dataAbertura));

    // Dados Relevantes para Cadastro
    do {
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

// Craindo e setando valores de quantidade de resíduos e valores de custo
void criaValoresEdados(QuantidadeValor *dadosValores)
{
    printf("\n=== Cadastro de Valores ===\n");

    bool entradaValida = false;
    while (!entradaValida) {
        printf("Digite a quantidade de resíduos: ");
        if (scanf("%d", &dadosValores->quantidadeResiduos[0]) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            // Limpar o buffer do scanf para evitar loops infinitos
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else if (dadosValores->quantidadeResiduos[0] <= 0) {
            printf("Digite um valor maior que zero.\n");
        } else {
            entradaValida = true;
            while(getchar() != '\n'); // Limpar o buffer do scanf
        }
    }

    entradaValida = false;
    while (!entradaValida) {
        printf("Digite o valor de custo: ");
        if (scanf("%f", &dadosValores->valorCusto[0]) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            // Limpar o buffer do scanf para evitar loops infinitos
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else if (dadosValores->valorCusto[0] <= 0) {
            printf("Digite um valor maior que zero.\n");
        } else {
            entradaValida = true;
            while(getchar() != '\n'); // Limpar o buffer do scanf
        }
    }

    criptografar((char *)&dadosValores->quantidadeResiduos[0], 9);
    criptografar((char *)&dadosValores->valorCusto[0], 9);

    printf("\nCadastro realizado com sucesso!\n");
}

// Função para atualizar as quantidades de resíduos ambientais
void atualizarDadosMensais(int quantidadeResiduos, float valorCusto)
{
    // Lógica para atualizar os dados mensais (quantidade de resíduos e valor estimado de custo)

    // Aqui você pode realizar cálculos, interações com o usuário, etc.
    // Suponha que os novos valores sejam passados como parâmetros (quantidadeResiduos e valorCusto)

    // Agora, vamos salvar esses dados em um arquivo de forma criptografada
    FILE *arquivo;
    arquivo = fopen("dados_mensais.txt", "w");

    // Criptografando e salvando os dados no arquivo
    char textoCriptografado[100]; // Tamanho arbitrário para acomodar os dados
    sprintf(textoCriptografado, "Residuos: %d\nCusto: %.2f", quantidadeResiduos, valorCusto);
    criptografar(textoCriptografado, 9); // Usando uma chave de criptografia '9' (pode ser qualquer valor)

    fprintf(arquivo, "%s", textoCriptografado);
    fclose(arquivo);

    printf("Dados atualizados e salvos com sucesso!\n");
}

// Função para gerar relatório individual de um cliente
void relatorioClienteIndividual(int indiceCliente)
{
    ClienteDados cliente = clientes[indiceCliente];

    printf("\n=== Relatorio do Cliente ===\n");
    printf("Nome do Responsavel: %s\n", cliente.dados.nomeResponsavel);
    // Exibir outras informações relevantes do cliente

    printf("Quantidade de residuos tratados no ultimo semestre: %d\n", cliente.quantidadeResiduosSemestral);
    printf("Gastos mensais: %.2f\n", cliente.gastosMensais);
}

// Função para gerar relatório global
void relatorioGlobal()
{
    // Lógica para análise dos dados e geração do relatório global

    // Exemplo: Encontrar cliente com maior quantidade de resíduos tratados
    int indiceMaiorQuantidade = 0;
    for (int i = 1; i < numClientes; i++)
    {
        if (clientes[i].quantidadeResiduosSemestral > clientes[indiceMaiorQuantidade].quantidadeResiduosSemestral)
        {
            indiceMaiorQuantidade = i;
        }
    }

    printf("\n=== Relatorio Global ===\n");
    printf("Cliente com maior quantidade de residuos tratados:\n");
    printf("Nome do Responsavel: %s\n", clientes[indiceMaiorQuantidade].dados.nomeResponsavel);
    printf("Quantidade de residuos tratados: %d\n", clientes[indiceMaiorQuantidade].quantidadeResiduosSemestral);

    // Outras análises e relatórios globais podem ser gerados da mesma maneira
}

// Função para exibir o menu para o usuario logado
void exibirMenuLogado()
{
    int opcao;
    DadosIndustriaCliente novoCliente; // Declaração da variável para armazenar os dados do novo cliente
    // Declaração da variável para armazenar os dados dos novos valores
    QuantidadeValor dadosValores = {{0}, {0}}; // Inicializando com zero os valores

    printf("\n\nBem-vindo ao Menu Logado!\n");

    do
    {
        printf("\n=== Menu Logado ===\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Funcionario\n");
        printf("3. Cadastrar/Atualizar dados mensais\n");
        printf("4. Gerar relatorio do cliente\n");
        printf("5. Gerar relatorio global\n");
        printf("6. Logout\n");
        printf("Opcao: ");

        while (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida. Digite um numero das opcoes do menu.\n");
            // Limpar o buffer do scanf para evitar loops infinitos
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (opcao)
        {
        case 1:
            cadastrarDadosIndustriaCliente(&novoCliente); // Passando o endereço do novo cliente como argumento
            break;
        case 2:
            cadastrarFuncionario();
            break;
        case 3:
            if (dadosValores.quantidadeResiduos[0] != 0 && dadosValores.valorCusto[0] != 0)
            {
                descriptografar((char *)&dadosValores.quantidadeResiduos[0], 9);
                descriptografar((char *)&dadosValores.valorCusto[0], 9);
                atualizarDadosMensais(dadosValores.quantidadeResiduos[0], dadosValores.valorCusto[0]);
            }
            else
            {
                printf("Cadastre valores primeiro!\n");
                criaValoresEdados(&dadosValores);
            }
            break;
        case 4:
            printf("Ainda não disponivel...\n");
            break;
        case 5:
            printf("Ainda não disponivel...\n");
            break;
        case 6:
            printf("Saindo do menu logado...\n");
            break;
        default:
            printf("Opção invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 6);
}

// Função para exibir o menu com todas as opções possiveis
void exibirMenuTodo()
{
    int opcao;
    DadosIndustriaCliente novoCliente; // Declaração da variável para armazenar os dados do novo cliente
    // Declaração da variável para armazenar os dados dos novos valores
    QuantidadeValor dadosValores = {{0}, {0}}; // Inicializando com zero os valores

    printf("Bem-vindo ao Sistema de Gestao de Residuos!\n");

    do
    {
        printf("\n=== Menu Principal ===\n");
        printf("1. Login\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Cadastrar Funcionario\n");
        printf("4. Cadastrar/Atualizar dados mensais\n");
        printf("5. Gerar relatorio do cliente\n");
        printf("6. Gerar relatorio global\n");
        printf("7. Sair do sistema\n");
        printf("8. Mostrar dados\n");
        printf("Opcao: ");

        while (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida. Digite um numero das opções do meunu.\n");
            // Limpar o buffer do scanf para evitar loops infinitos
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
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
            if (realizarLogin() == 1)
            {
                exibirMenuLogado();
            }
            else
            {
                printf("Faca login\n");
            }
            break;
        case 7:
            printf("Saindo do sistema...\n");
            printf("Sistema e documentacao desenvolvido por Lucas Vacari e Eduardo Kenzo\n");
            printf("Versão do sistema 1.5.2\n");
            break;
        case 8:
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
            printf("Opção invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 7);
}

// Função principal
int main()
{
    // comando de regionalização
    setlocale(LC_ALL, "Portuguese_Brazil");

    exibirMenuTodo();
}