#include <stdio.h>
#include <string.h>

// Estrutura para representar os dados da indústria do cliente
typedef struct {
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

int realizarLogin() {
    char usuario[20];
    char senha[20];

    printf("=== Login ===\n");
    printf("Usuário: ");
    scanf("%s", usuario);
    printf("Senha: ");
    scanf("%s", senha);

    // Lógica para verificar o usuário e a senha
    // Aqui você pode implementar a lógica de autenticação
    // Se as credenciais estiverem corretas, retorne 1 (login bem-sucedido)
    // Caso contrário, retorne 0 (falha no login)
    
    return 1; // Temporariamente retornando 1 para simular um login bem-sucedido
}

void cadastrarDadosIndustriaCliente(DadosIndustriaCliente *dadosCliente) {
    printf("\n=== Cadastro de Dados da Indústria do Cliente ===\n");
    printf("Nome do Responsável: ");
    scanf(" %[^\n]s", dadosCliente->nomeResponsavel);

    printf("Nome da Empresa: ");
    scanf(" %[^\n]s", dadosCliente->nomeEmpresa);

    printf("CNPJ: ");
    scanf(" %[^\n]s", dadosCliente->cnpj);

    printf("Razão Social: ");
    scanf(" %[^\n]s", dadosCliente->razaoSocial);

    printf("Nome Fantasia: ");
    scanf(" %[^\n]s", dadosCliente->nomeFantasia);

    printf("Telefone: ");
    scanf(" %[^\n]s", dadosCliente->telefone);

    printf("Endereço: ");
    scanf(" %[^\n]s", dadosCliente->endereco);

    printf("Cidade: ");
    scanf(" %[^\n]s", dadosCliente->cidade);

    printf("Estado: ");
    scanf(" %[^\n]s", dadosCliente->estado);

    printf("CEP: ");
    scanf(" %[^\n]s", dadosCliente->cep);

    printf("E-mail: ");
    scanf(" %[^\n]s", dadosCliente->email);

    printf("Data de Abertura: ");
    scanf(" %[^\n]s", dadosCliente->dataAbertura);

    printf("Dados Relevantes para Cadastro: ");
    scanf(" %[^\n]s", dadosCliente->dadosRelevantes);

    printf("\nCadastro realizado com sucesso!\n");
}

// Função para criptografar uma string usando a cifra de César
void criptografar(char *texto, int chave) {
    int i = 0;
    while (texto[i] != '\0') {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = 'a' + (texto[i] - 'a' + chave) % 26;
        } else if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = 'A' + (texto[i] - 'A' + chave) % 26;
        }
        i++;
    }
}

// Função para descriptografar uma string usando a cifra de César
void descriptografar(char *texto, int chave) {
    criptografar(texto, 26 - chave); // A descriptografia é o inverso da criptografia com a chave negativa
}

void atualizarDadosMensais(int quantidadeResiduos, float valorCusto) {
    // Lógica para atualizar os dados mensais (quantidade de resíduos e valor estimado de custo)

    // Aqui você pode realizar cálculos, interações com o usuário, etc.
    // Suponha que os novos valores sejam passados como parâmetros (quantidadeResiduos e valorCusto)

    // Agora, vamos salvar esses dados em um arquivo de forma criptografada
    FILE *arquivo;
    arquivo = fopen("dados_mensais.txt", "w");

    // Criptografando e salvando os dados no arquivo
    char textoCriptografado[100]; // Tamanho arbitrário para acomodar os dados
    sprintf(textoCriptografado, "Residuos: %d\nCusto: %.2f", quantidadeResiduos, valorCusto);
    criptografar(textoCriptografado, 3); // Usando uma chave de criptografia '3' (pode ser qualquer valor)

    fprintf(arquivo, "%s", textoCriptografado);
    fclose(arquivo);

    printf("Dados atualizados e salvos com sucesso!\n");
}

#define MAX_CLIENTES 100

// Estrutura para representar dados dos clientes
typedef struct {
    DadosIndustriaCliente dados; // A estrutura DadosIndustriaCliente que definimos antes
    int quantidadeResiduosSemestral;
    float gastosMensais;
} ClienteDados;

ClienteDados clientes[MAX_CLIENTES]; // Array para armazenar dados dos clientes
int numClientes = 0; // Número atual de clientes cadastrados

// Função para gerar relatório individual de um cliente
void relatorioClienteIndividual(int indiceCliente) {
    ClienteDados cliente = clientes[indiceCliente];

    printf("\n=== Relatório do Cliente ===\n");
    printf("Nome do Responsável: %s\n", cliente.dados.nomeResponsavel);
    // Exibir outras informações relevantes do cliente

    printf("Quantidade de resíduos tratados no último semestre: %d\n", cliente.quantidadeResiduosSemestral);
    printf("Gastos mensais: %.2f\n", cliente.gastosMensais);
}

// Função para gerar relatório global
void relatorioGlobal() {
    // Lógica para análise dos dados e geração do relatório global

    // Exemplo: Encontrar cliente com maior quantidade de resíduos tratados
    int indiceMaiorQuantidade = 0;
    for (int i = 1; i < numClientes; i++) {
        if (clientes[i].quantidadeResiduosSemestral > clientes[indiceMaiorQuantidade].quantidadeResiduosSemestral) {
            indiceMaiorQuantidade = i;
        }
    }

    printf("\n=== Relatório Global ===\n");
    printf("Cliente com maior quantidade de resíduos tratados:\n");
    printf("Nome do Responsável: %s\n", clientes[indiceMaiorQuantidade].dados.nomeResponsavel);
    printf("Quantidade de resíduos tratados: %d\n", clientes[indiceMaiorQuantidade].quantidadeResiduosSemestral);

    // Outras análises e relatórios globais podem ser gerados da mesma maneira
}