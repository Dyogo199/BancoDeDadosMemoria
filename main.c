// **Roadmap: Banco de Dados em Memória**

// 1. Estrutura Inicial do Projeto
// - Criar a estrutura de pastas.
// - Criar os arquivos principais: `main.c`, `data_structures.c`, `database.c`, `user_management.c` e seus headers.

// 2. Implementação da Estrutura de Dados
// - Desenvolver a Árvore B+ para organização e pesquisa eficiente (ou tabela hash, se preferir simplicidade).
// - Testar as operações de inserção, remoção, e busca.

// 3. CRUD no Banco de Dados
// - Implementar funções para criar tabelas, inserir, buscar, atualizar e deletar registros.
// - Usar a estrutura de dados desenvolvida para armazenar os registros.

// 4. Gerenciamento de Usuários
// - Criar um sistema básico de gerenciamento de múltiplos usuários.
// - Adicionar sessões e permissões simples.

// 5. Interface e Testes
// - Desenvolver uma interface de texto para interagir com o banco.
// - Testar todas as funções em diferentes cenários.

// 6. Extras
// - Adicionar suporte para salvar e carregar dados de arquivos.
// - Implementar logs para operações importantes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura básica para um registro
typedef struct Record {
    int id;
    char name[50];
    int age;
    char email[100];
    char cpf[15];
    char mother_name[50];
    char country[50];
    char state[50];
    char city[50];
} Record;

// Nó para a Árvore B+
typedef struct Node {
    int is_leaf;
    int num_keys;
    int keys[4]; // Max 4 chaves por simplicidade
    struct Node *children[5]; // Max 5 ponteiros
    Record *records[4];
} Node;

Node *root = NULL;

// Funções da Árvore B+
Node *create_node(int is_leaf) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->is_leaf = is_leaf;
    new_node->num_keys = 0;
    for (int i = 0; i < 5; i++) {
        new_node->children[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
        new_node->records[i] = NULL;
    }
    return new_node;
}

void insert_record(int key, Record *record) {
    // Implementar inserção na Árvore B+
    // Placeholder para demonstração
    printf("Inserindo registro com chave %d\n", key);
}

// Funções CRUD
void create_table() {
    // Placeholder para criar uma nova tabela
    printf("Tabela criada com sucesso!\n");
}

void insert(int id, const char *name, int age, const char *email, const char *cpf, const char *mother_name, const char *country, const char *state, const char *city) {
    Record *new_record = (Record *)malloc(sizeof(Record));
    new_record->id = id;
    strncpy(new_record->name, name, 50);
    new_record->age = age;
    strncpy(new_record->email, email, 100);
    strncpy(new_record->cpf, cpf, 15);
    strncpy(new_record->mother_name, mother_name, 50);
    strncpy(new_record->country, country, 50);
    strncpy(new_record->state, state, 50);
    strncpy(new_record->city, city, 50);
    insert_record(id, new_record);
    printf("Registro inserido: ID=%d, Nome=%s, Idade=%d, Email=%s, CPF=%s, Nome da Mãe=%s, País=%s, Estado=%s, Cidade=%s\n", id, name, age, email, cpf, mother_name, country, state, city);
}

void display_menu() {
    printf("\nBanco de Dados em Memoria\n");
    printf("1. Criar Tabela\n");
    printf("2. Inserir Registro\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int option;
    do {
        display_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                create_table();
                break;
            case 2:
                {
                    int id;
                    char name[50];
                    int age;
                    char email[100];
                    char cpf[15];
                    char mother_name[50];
                    char country[50];
                    char state[50];
                    char city[50];
                    printf("Digite o ID: ");
                    scanf("%d", &id);
                    printf("Digite o Nome: ");
                    scanf("%s", name);
                    printf("Digite a Idade: ");
                    scanf("%d", &age);
                    printf("Digite o Email: ");
                    scanf("%s", email);
                    printf("Digite o CPF: ");
                    scanf("%s", cpf);
                    printf("Digite o Nome da Mae: ");
                    scanf("%s", mother_name);
                    printf("Digite o Pais: ");
                    scanf("%s", country);
                    printf("Digite o Estado: ");
                    scanf("%s", state);
                    printf("Digite a Cidade: ");
                    scanf("%s", city);
                    insert(id, name, age, email, cpf, mother_name, country, state, city);
                }
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 3);
    return 0;
}
