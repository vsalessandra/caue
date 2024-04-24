#include <stdio.h>
#include <string.h>

struct Notebook
{
    int numeroNot;
    int isReservado;
    int isRetirado;
    int isEstragado;
    int raAluno;
};

int main()
{
    int quantNotebooks = 10;
    struct Notebook notebook[quantNotebooks];

    // Inicializando dados falsos nos notebooks
    for (int i = 0; i < quantNotebooks; i++)
    {
        notebook[i].numeroNot = i + 1; // Números de notebook de 1 a 10
        notebook[i].isReservado = 0;   // Todos os notebooks estão inicialmente disponíveis
        notebook[i].isRetirado = 0;    // Nenhum notebook foi retirado
        notebook[i].isEstragado = 0;   // Nenhum notebook está estragado
        notebook[i].raAluno = 0;       // Nenhum aluno atribuído inicialmente
    }
    // falando que um notebook esta estragado
    notebook[0].isEstragado = 1;

    // simulando que o notebook 3 e 6 estao reservados, e os r.a ficticio dos alunos
    notebook[3].isReservado = 1;
    notebook[3].raAluno = 12345;
    notebook[6].isReservado = 1;
    notebook[6].raAluno = 7654321;

    // Variáveis globais
    int isAdm;

    // Variáveis para controlar o sistema de ADM
    int senhaAdmCorreta, tentarSenhaAdmNovamente, escolhaAdm,codigo_notebook,nota_funcionamento;
    char loginAdm[10], senhaAdm[10];

    // Variáveis para controlar o sistema de aluno
    int senhaAluno, tentarSenha = 1, raAluno;

    // Loop principal do programa
    do
    {
        printf("------- BEM VINDO AO SISTEMA DE RESERVA DE NOTEBOOK -------\n");

        printf("Digite 0 para sair \n");
        printf("Digite 1 para acessar como aluno e realizar sua reserva \n");
        printf("Digite 2 para acessar como ADM e gerenciar as reservas \n");
        scanf("%d", &isAdm);

        switch (isAdm)
        { // Verificando qual opção o usuário selecionou
        case 0:
            printf("\n \n Muito obrigado por usar o sistema de notebooks ");
            return 0;
            break;

        case 1:
        {
            printf("Bem vindo à área de alunos do sistema de notebooks \n");

            while (tentarSenha == 1)
            {
                printf("Informe seu RA: \n");
                scanf("%d", &raAluno);
                printf("Insira a senha: \n");
                scanf("%d", &senhaAluno);

                // simulação de ra e senha
                if (raAluno == 123456 && senhaAluno == 1234567)
                {
                    printf("Login bem sucedido!\n");

                    // reservando os notebooks
                    // verifica se ja reservou
                    int alunoJaReservou = 0;
                    for (int i = 0; i < quantNotebooks; i++)
                    {
                        if (notebook[i].raAluno == raAluno)
                        {
                            alunoJaReservou = 1;
                            printf("Voce ja reservou um notebook, não pode reservar outro!\n");
                            break;
                        }
                    }
                    if (alunoJaReservou == 0)
                    {
                        printf("Notebooks disponiveis para reserva: \n");
                        // nots disponiveis
                        for (int i = 0; i < quantNotebooks; i++)
                        {
                            if (notebook[i].isReservado == 0 && notebook[i].isEstragado == 0)
                            {
                                printf("%d\n", notebook[i].numeroNot);
                            }
                        }
                        int numeroNot;
                        printf("Digite qual o numero do notebook que deseja reservar:");
                        scanf("%d", &numeroNot);

                        notebook[numeroNot - 1].isReservado = 1;
                        notebook[numeroNot - 1].raAluno = raAluno;

                        printf("Notebook %d reservado com sucesso para o aluno %d\n", numeroNot, raAluno);

                    }else{
                        break;
                    }
                }
                else
                {
                    printf("Login ou senha incorretos\n");
                    printf("Digite 0 para sair e 1 para tentar novamente\n");
                    scanf("%d", &tentarSenha);

                    if (tentarSenha == 0)
                    {
                        break;
                    }
                    
                }
                
            }
        }
        break;
        case 2:
        {
            printf("Bem vindo à área administrativa do sistema de notebooks \n");

            do
            {
                printf("Por favor, informe seu login: ");
                scanf("%s", loginAdm);
                printf("Por favor, informe sua senha: ");
                scanf("%s", senhaAdm);

                // Comparando o login e a senha com valores predefinidos (simulando o banco de dados)
                if (strcmp(loginAdm, "admin") == 0 && strcmp(senhaAdm, "123456") == 0)
                {
                    senhaAdmCorreta = 1;
                    printf("\n------- Login bem-sucedido! -------- \n");

                    do
                    {
                        printf("Digite 1 para verificar quantos notebooks estão disponíveis: \n");
                        printf("Digite 2 para mostrar os dados dos alunos que pegaram os notebooks: \n");
                        printf("Digite 3 para confirmar a retirada de um notebook: \n");
                        printf("Digite 4 para confirmar a devolução de um notebook: \n");
                        printf("Digite 5 para registrar notebook com defeito: \n");
                        printf("Digite 6 para sair: \n");
                        scanf("%d", &escolhaAdm);

                        switch (escolhaAdm)
                        {
                        case 1:
                            // Funcionalidade 1: Verificar quantos notebooks estão disponíveis
                            printf("Funcionalidade 1: Verificar quantos notebooks estão disponíveis\n");
                            for (int i = 0; i < quantNotebooks; i++)
                            {
                                if (notebook[i].isReservado == 0 && notebook[i].isEstragado == 0)
                                {
                                    printf("Notebook %d disponível \n", notebook[i].numeroNot);
                                }
                            }
                            break;

                        case 2:
                            // Funcionalidade 2: Mostrar os dados dos alunos que pegaram os notebooks
                            printf("Funcionalidade 2: Mostrar os dados dos alunos que pegaram os notebooks\n");
                            // Implemente esta funcionalidade
                            break;

                        case 3:
                            // Funcionalidade 3: Confirmar a retirada de um notebook
                            printf("Funcionalidade 3: Confirmar a retirada de um notebook\n");
                            // Implemente esta funcionalidade
                            break;

                        case 4:
                            printf("Funcionalidade 4: Confirmar a devolução de um notebook\n");

                            printf("Digite o código do notebook devolvido: ");
                            scanf("%d", &codigo_notebook);

                            printf("Digite uma nota de 0 a 5 para o funcionamento da máquina: ");
                            scanf("%d", &nota_funcionamento);

                            if (nota_funcionamento < 0 || nota_funcionamento > 5) {
                                printf("Por favor, digite uma nota de 0 a 5.\n");
                            } else {
                                // Verificar se o notebook devolvido está reservado por algum aluno
                                int notebookDevolvidoEncontrado = 0;
                                for (int i = 0; i < quantNotebooks; i++) {
                                    if (notebook[i].numeroNot == codigo_notebook && notebook[i].isReservado == 1) {
                                        printf("Devolução confirmada para o notebook de código %d com nota de funcionamento %d.\n", codigo_notebook, nota_funcionamento);
                                        // Liberar o notebook para reserva novamente
                                        notebook[i].isReservado = 0;
                                        notebook[i].raAluno = 0;
                                        notebookDevolvidoEncontrado = 1;
                                        break;
                                    }
                                }
                                if (!notebookDevolvidoEncontrado) {
                                    printf("O notebook de código %d não estava reservado ou não foi encontrado.\n", codigo_notebook);
                                }
                            }

                            break;



                        case 5:
                            // Funcionalidade 5: Registrar notebook com defeito
                            for (int i = 1; i > 0; i++)
                            {
           
                                printf("Selecione o Notebook com defeito\n");
                                for (int j = 0; j < quantNotebooks; j++)
                                {
                                    if (notebook[j].isEstragado == 0)
                                    {   
                                        printf("Notebook %d\n", notebook[j].numeroNot);
                                    }
                                
                                }
                                int numeroNot;
                                scanf("%d", &numeroNot);
                                notebook[numeroNot - 1].isEstragado = 1;
                                printf("O notebook %d foi registrado com defeito\n", numeroNot);
                                int n;
                                printf("Deseja continuar registrando notebook com defeito\n");
                                printf("Digite 1 para sim\n");
                                printf("Digite 2 para nao\n");
                                scanf("%d", &n);
                                switch (n)
                                {
                                case 1:
                                    printf("Continue registrando os notebook\n");
                                    break;
                                case 2:
                                    i = -1;
                                    printf("Voce foi redirecionado para a home \n");
                                break;
                                default:
                                    i = -1;
                                    printf("Voce foi redirecionado para a home \n");
                                    break;
                                }
                                
                            
                            }   
                            // Implemente esta funcionalidade
                            break;

                        default:
                            printf("Escolha incorreta. Por favor, escolha uma opção válida.\n");
                            break;
                        }

                    } while (escolhaAdm != 6);

                    // Adicione aqui as funcionalidades para o ADM
                }
                else
                {
                    printf("\nLogin ou senha incorretos. Por favor, tente novamente.\n");
                    printf("Digite 0 para sair e 1 para tentar novamente: ");
                    scanf("%d", &tentarSenhaAdmNovamente);

                    if (tentarSenhaAdmNovamente == 0)
                    {
                        break;
                    }

                    senhaAdmCorreta = 0;
                }

            } while (senhaAdmCorreta == 0);

            break;
        }
        default:
            break;
        }
    } while (isAdm != 0);

    return 0;
}