#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "mainFunctions.h"
#include "utilityFunctions.h"

typedef struct auxiliar{
	int optMain;
    int optCad;
    int optEdit;
    char *auxChar;
    char *ptr;
    int auxInt;
    int auxInt2;
    Data *auxData;
    l_leito *auxLeito;
    l_equipamentos *auxEquip;
    l_paciente *auxPaciente;
}auxiliar;

int main (void){

    setlocale (LC_ALL, "portuguese");

    //Cria Variaveis
    l_leito *BD_leitos = NULL;
    l_equipamentos *BD_equipamentos = NULL;
    l_paciente *BD_paciente = NULL;
    l_paciente *BD_histPaciente = NULL;
    matrizChar *busca = NULL;
    leito dados_leitos;
    equipamentos dados_equip;
    paciente dados_pacientes;
    controls autoincrement;
    auxiliar aux;
    aux.optCad = 0;
    aux.optMain = 0;
    aux.auxChar = (char *) malloc(sizeof(char) * 100);

    //Carrega os controles de ID
    if(fexiste("controles.bin") == 0){
        fCriaBD("controles.bin");
        autoincrement.id_equips = 0;
        autoincrement.id_leitos = 0;
        autoincrement.id_pacientes = 0;
        fsavedata(&autoincrement, sizeof(controls), "controles.bin");
    }
    else{
        fcarrega_dados_controls(&autoincrement, "controles.bin");
    }

    //Cria arquivos
    fCriaBD("leitos.bin");
    fCriaBD("pacientes.bin");
    fCriaBD("pacientes_historico.bin");
    fCriaBD("equipamentos.bin");
    fCriaBD("equip_vinc.bin");

    //Carrega Arquivos

    BD_equipamentos = fcarrega_dados_equip("equipamentos.bin");
    BD_leitos = fcarrega_dados_leitos("leitos.bin");
    BD_paciente = fcarrega_dados_pacientes("pacientes.bin");
    BD_histPaciente = fcarrega_dados_pacientes("pacientes_historico.bin");
    fcarrega_vincEquips("equip_vinc.bin", BD_leitos);

    while(aux.optMain != 9){
        //Mensagem do menu principal
        printf("---------------------------------------------------\n");
        printf("              GERENCIAMENTO DE LEITOS\n");
        printf("---------------------------------------------------\n\n");
        printf(" [1] Cadastro\n [2] Busca e Edicoes\n [3] Historico de Exclusão de Pacientes\n [4] Resumo Geral\n [5] Extrair Dados\n [9] Sair\n\n");
        printf(" Resposta: ");
        strUserInput(aux.auxChar, 100);
        aux.optMain = 0;
        while(aux.optMain < 1){
            while(!userIptCtrl(aux.auxChar, "1234567890")){
                printf("\nDigite apenas numeros: ");
                strUserInput(aux.auxChar, 100);
            }
            aux.optMain = atoi(aux.auxChar);
            strcpy(aux.auxChar, " ");
        }
        clearWindowsTerminal();
        if(aux.optMain == 9){
            break;
        }
        //Opções selecionadas do menu
        switch(aux.optMain){
            case 1:
                while(aux.optCad != 9){
                    printf("---------------------------------------------------\n");
                    printf("                 SETOR DE CADASTROS\n");
                    printf("---------------------------------------------------\n\n");
                    printf(" [1] Leitos\n [2] Equipamentos\n [3] Pacientes\n [9] Voltar\n\n");
                    printf(" Resposta: ");
                    strUserInput(aux.auxChar, 100);
                    aux.optCad = 0;
                    while(aux.optCad < 1){
                        while(!userIptCtrl(aux.auxChar, "1234567890")){
                            printf("\nDigite apenas numeros: ");
                            strUserInput(aux.auxChar, 100);
                        }
                        aux.optCad = atoi(aux.auxChar);
                        strcpy(aux.auxChar, " ");
                    }
                    clearWindowsTerminal();

                    switch(aux.optCad){
                        case 1:
                            printf("---------------------------------------------------\n");
                            printf("                 CADASTRO DE LEITO\n");
                            printf("---------------------------------------------------\n");
                            printf("\n*** Preencha os dados solicitados abaixo:\n");
                            cleanLeitos(&dados_leitos);

                            autoincrement.id_leitos++;
                            dados_leitos.id = autoincrement.id_leitos;
                            printf("\nNome: ");
                            strUserInput(dados_leitos.nome, sizeof(dados_leitos.nome));

                            printf("\nQuatidade de Unidade disponiveis nesse leito: ");
                            strUserInput(aux.auxChar, 100);
                            dados_leitos.qtdLeitos = 0;
                            while(dados_leitos.qtdLeitos < 1){
                                while(!userIptCtrl(aux.auxChar, "1234567890")){
                                    printf("\nDigite apenas numeros: ");
                                    strUserInput(aux.auxChar, 100);
                                }
                                dados_leitos.qtdLeitos = (int) atoi(aux.auxChar);
                                strcpy(aux.auxChar, " ");
                            }

                            printf("\nTipos de Leitos:\n");
                            for(int i = 0; i < 15; i++){
                                printf("\n[%d] %s", i+1, tipoLeito(i+1));
                            }

                            strcpy(aux.auxChar, " ");
                            printf("\n\nDigite o numero correspondente ao tipo de leito: ");
                            strUserInput(aux.auxChar, 100);
                            dados_leitos.tipo = 0;
                            while(dados_leitos.tipo < 1 || dados_leitos.tipo > 15){
                                while(!userIptCtrl(aux.auxChar, "1234567890")){
                                    printf("\nDigite apenas numeros e que esejam entre 1 e 15!\nTipo do leito: ");
                                    strUserInput(aux.auxChar, 100);
                                }
                                dados_leitos.tipo = atoi(aux.auxChar);
                                strcpy(aux.auxChar, " ");
                            }
                            strcpy(dados_leitos.data_cadastro, dataAtual());
                            dados_leitos.qtdEquipVinculados = 0;
                            BD_leitos = inserir_leito(BD_leitos, dados_leitos);
                            fsavedata(&dados_leitos, sizeof(leito), "leitos.bin");
                            fatualiza_controls(&autoincrement, "controles.bin");
                            clearWindowsTerminal();

                            printf("---------------------------------------------------\n");
                            printf("                 CADASTRO DE LEITO\n");
                            printf("---------------------------------------------------\n");
                            printf("\n*** Cadastro realizado!\n");
                            pauseEXE("\nAperte enter para continuar!");

                            strcpy(aux.auxChar, " ");
                            clearWindowsTerminal();
                            break;
                        case 2:
                            printf("---------------------------------------------------\n");
                            printf("                 CADASTRO DE EQUIPAMENTO\n");
                            printf("---------------------------------------------------\n\n");
                            printf("*** Preencha os dados solicitados abaixo:\n");

                            cleanEquipamento(&dados_equip);

                            printf("\nNome: ");
                            strUserInput(dados_equip.nome, 100);
                            autoincrement.id_equips++;
                            dados_equip.id = autoincrement.id_equips;
                            strcpy(dados_equip.data_cadastro, dataAtual());

                            BD_equipamentos = inserir_equipamento(BD_equipamentos, dados_equip);
                            fsavedata(&dados_equip, sizeof(equipamentos), "equipamentos.bin");
                            fatualiza_controls(&autoincrement, "controles.bin");
                            clearWindowsTerminal();

                            printf("---------------------------------------------------\n");
                            printf("              CADASTRO DE EQUIPAMENTOS\n");
                            printf("---------------------------------------------------\n");
                            printf("\n*** Cadastro realizado!\n");
                            pauseEXE("\nAperte ENTER para continuar!");

                            strcpy(aux.auxChar, " ");
                            clearWindowsTerminal();
                            break;
                        case 3:
                            printf("---------------------------------------------------\n");
                            printf("                 CADASTRO DE PACIENTE\n");
                            printf("---------------------------------------------------\n\n");
                            printf("*** Preencha os dados solicitados abaixo:\n");
                            cleanPaciente(&dados_pacientes);

                            printf("\nCPF: ");
                            strUserInput(dados_pacientes.cpf, sizeof(dados_pacientes.cpf)/sizeof(char));
                            while(!ValidaCPF(dados_pacientes.cpf)){
                                printf("Digite um CPF em Formato Valido: ");
                                strUserInput(dados_pacientes.cpf, sizeof(dados_pacientes.cpf)/sizeof(char));
                            }
                            FormataCPF(dados_pacientes.cpf, aux.auxChar);
                            strcpy(dados_pacientes.cpf, aux.auxChar);
                            strcpy(aux.auxChar, " ");

                            printf("\nNome: ");
                            strUserInput(dados_pacientes.nome, 100);

                            autoincrement.id_pacientes++;
                            dados_pacientes.id = autoincrement.id_pacientes;

                            strcpy(dados_pacientes.data_entrada, dataAtual());
                            strcpy(dados_pacientes.data_saida, "");
                            dados_pacientes.cod_motivo_saida = 0;
                            dados_pacientes.id_leito_vinculado = 0;

                            printf("\nData de Nascimento: ");
                            strUserInput(dados_pacientes.data_nasc, (int) sizeof(dados_pacientes.data_nasc)/sizeof(char));
                            aux.auxInt = charUsed(dados_pacientes.data_nasc);
                            if(userIptCtrl(dados_pacientes.data_nasc, "0123456789/") && aux.auxInt == 10){
                                aux.auxInt2 = dataValida(str_to_data(dados_pacientes.data_nasc, "/"));
                            }
                            else{
                                aux.auxInt2 = 0;
                            }
                            if(!aux.auxInt2){
                                while(!userIptCtrl(dados_pacientes.data_nasc, "0123456789/") || !aux.auxInt2 || aux.auxInt < 10){
                                    printf("\nDigite uma Data de Nascimento Valida: ");
                                    strcpy(dados_pacientes.data_nasc, "");
                                    strUserInput(dados_pacientes.data_nasc, (int) sizeof(dados_pacientes.data_nasc)/sizeof(char));
                                    aux.auxInt = charUsed(dados_pacientes.data_nasc);
                                    if(userIptCtrl(dados_pacientes.data_nasc, "0123456789/") && aux.auxInt == 10){
                                        aux.auxInt2 = dataValida(str_to_data(dados_pacientes.data_nasc, "/"));
                                    }
                                }
                            }

                            BD_paciente = inserir_paciente(BD_paciente, dados_pacientes);
                            fatualiza_controls(&autoincrement, "controles.bin");
                            fsavedata(&dados_pacientes, sizeof(dados_pacientes), "pacientes.bin");
                            clearWindowsTerminal();

                            printf("---------------------------------------------------\n");
                            printf("              CADASTRO DE PACIENTES\n");
                            printf("---------------------------------------------------\n");
                            printf("\n*** Cadastro realizado!\n");
                            pauseEXE("\nAperte ENTER para continuar!");

                            clearWindowsTerminal();
                            strcpy(aux.auxChar, " ");
                            aux.auxInt2 = 0;
                            aux.auxInt = 0;
                            break;
                        default:
                            break;
                        }
                        aux.auxInt2 = 0;
                    }
            case 2:
                while(aux.optCad != 9){
                    printf("---------------------------------------------------\n");
                    printf("                   SETOR DE BUSCA\n");
                    printf("---------------------------------------------------\n\n");
                    printf(" [1] Leitos\n [2] Equipamentos\n [3] Pacientes\n [9] Voltar\n\n");
                    printf(" Resposta: ");
                    strUserInput(aux.auxChar, 100);
                    aux.optCad = 0;
                    while(aux.optCad < 1){
                        while(!userIptCtrl(aux.auxChar, "1234567890")){
                            printf("\nDigite apenas numeros: ");
                            strUserInput(aux.auxChar, 100);
                        }
                        aux.optCad = atoi(aux.auxChar);
                        strcpy(aux.auxChar, " ");
                    }
                    clearWindowsTerminal();
                    if(aux.optCad == 9){
                        aux.auxLeito = NULL;
                        aux.optCad = 0;
                        strcpy(aux.auxChar, " ");
                        clearWindowsTerminal();
                        break;
                    }
                    switch(aux.optCad){
                        case 1:
                            printf("---------------------------------------------------\n");
                            printf("                 BUSCA DE LEITOS\n");
                            printf("---------------------------------------------------\n");
                            printf("\nDigite o Nome do Leito(* lista todos): ");
                            strUserInput(aux.auxChar, 100);

                            printf("\n");
                            busca = FilterByName_leitos(BD_leitos, aux.auxChar, 100);
                            print_matrizChar(busca);
                            printf("\n\n");
                            if(busca != (matrizChar *) NULL){
                                deleteMatrizChar(busca);
                                printf("Digite um ID para alteracao de um leito(0 para sair): ");
                                strUserInput(aux.auxChar, 100);
                                aux.auxInt = -1;
                                while(aux.auxInt < 0){
                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                        printf("\nDigite apenas numeros: ");
                                        strUserInput(aux.auxChar, 100);
                                    }
                                    aux.auxInt = atoi(aux.auxChar);
                                    strcpy(aux.auxChar, " ");
                                }
                                clearWindowsTerminal();
                                if(aux.auxInt == 0){
                                    aux.auxLeito = NULL;
                                    aux.optCad = 0;
                                    strcpy(aux.auxChar, " ");
                                    clearWindowsTerminal();
                                    break;
                                }
                                if(aux.auxInt != 0){
                                    aux.auxLeito = busca_por_id_leito(BD_leitos, aux.auxInt);
                                    printf("---------------------------------------------------\n");
                                    printf("                 BUSCA DE LEITOS\n");
                                    printf("---------------------------------------------------\n");
                                    if(aux.auxLeito != (l_leito *) NULL){
                                        printf("\n***Dados Gerais\n\n");
                                        printf("Nome: %s\nQuantidade de Unidades: %d\n", aux.auxLeito->nome, aux.auxLeito->qtdLeitos);
                                        printf("Tipo: %s", tipoLeito(aux.auxLeito->tipo));
                                        printf("\nData de Cadastro: %s", aux.auxLeito->data_cadastro);

                                        aux.auxPaciente = BD_paciente;
                                        aux.auxInt = 0;
                                        while(aux.auxPaciente != (l_paciente *) NULL){
                                            if(aux.auxPaciente->id_leito_vinculado == aux.auxLeito->id){
                                                aux.auxInt++;
                                            }
                                            aux.auxPaciente = aux.auxPaciente->next;
                                        }
                                        printf("\nQuantidade de Pacientes Vinculados: %d", aux.auxInt);

                                        printf("\n\n***Equipamentos Vinculados\n");
                                        if(aux.auxLeito->id_equip_vinculado != NULL && BD_equipamentos != (l_equipamentos *) NULL){
                                            aux.auxEquip = BD_equipamentos;

                                            while(aux.auxEquip != (l_equipamentos *) NULL){
                                                for(int i = 0; i < aux.auxLeito->qtdEquipVinculados; i++){
                                                    if(aux.auxEquip->id == aux.auxLeito->id_equip_vinculado[i]){
                                                        printf("\n- %s", aux.auxEquip->nome);
                                                    }
                                                }
                                                aux.auxEquip = aux.auxEquip->next;
                                            }
                                        }
                                        else{
                                            printf("\nNada para Exibir!\n");
                                        }
                                        printf("\n");
                                        printf("---------------------------------------------------\n");
                                        printf("      [1] EXCLUIR / [2] EDITAR / [9] SAIR\n");
                                        printf("---------------------------------------------------\n");
                                        printf("\nResposta: ");
                                        strcpy(aux.auxChar, "");
                                        strUserInput(aux.auxChar, 100);
                                        aux.optEdit = 0;
                                        while(aux.optEdit < 1){
                                            while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                printf("\nDigite apenas numeros: ");
                                                strUserInput(aux.auxChar, 100);
                                            }
                                            aux.optEdit = atoi(aux.auxChar);
                                            strcpy(aux.auxChar, " ");
                                        }

                                        switch(aux.optEdit){
                                            case 1:
                                                //Exclusão
                                                printf("\nTem certeza que deseja continuar? Todos os pacientes\ntambem serao desvinculados([1] SIM / [0] NAO)! ");
                                                aux.auxInt = -1;
                                                strcpy(aux.auxChar, " ");
                                                strUserInput(aux.auxChar, 100);
                                                while(aux.auxInt < 0 || aux.auxInt > 1){
                                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                        printf("\nDigite apenas numeros: ");
                                                        strUserInput(aux.auxChar, 100);
                                                    }
                                                    aux.auxInt = atoi(aux.auxChar);
                                                    strcpy(aux.auxChar, " ");
                                                }
                                                if(aux.auxInt){
                                                    if(BD_paciente != (l_paciente *) NULL){
                                                        aux.auxPaciente = BD_paciente;
                                                        while(aux.auxPaciente != (l_paciente *) NULL){
                                                            if(aux.auxPaciente->id == aux.auxLeito->id){
                                                                aux.auxPaciente->id_leito_vinculado = 0;
                                                            }
                                                            aux.auxPaciente = aux.auxPaciente->next;
                                                        }
                                                        fatualiza_pacientes("pacientes.bin", BD_paciente);
                                                    }
                                                    BD_leitos = free_leito(BD_leitos, aux.auxLeito->id);
                                                    fatualiza_leitos("leitos.bin", BD_leitos);
                                                    printf("\nLeito Excluido!\n\n");
                                                }
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 BUSCA DE LEITOS\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nLeito Excluido!");
                                                pauseEXE("\n\nAperte ENTER para continuar!");
                                                aux.auxInt = 0;
                                                break;
                                            case 2:
                                                //Edição
                                                printf("\nTem certeza que deseja Editar?([1] SIM / [0] NAO)! ");
                                                aux.auxInt = -1;
                                                strcpy(aux.auxChar, " ");
                                                strUserInput(aux.auxChar, 100);
                                                while(aux.auxInt < 0 || aux.auxInt > 1){
                                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                        printf("\nDigite apenas numeros: ");
                                                        strUserInput(aux.auxChar, 100);
                                                    }
                                                    aux.auxInt = atoi(aux.auxChar);
                                                    strcpy(aux.auxChar, " ");
                                                }
                                                if(aux.auxInt){
                                                    clearWindowsTerminal();
                                                    printf("---------------------------------------------------\n");
                                                    printf("                 EDICAO DE LEITO\n");
                                                    printf("---------------------------------------------------\n");
                                                    aux.auxInt = 0;
                                                    printf("\n***Insira os novos dados:\n\nNome: ");
                                                    strUserInput(aux.auxLeito->nome, sizeof(dados_leitos.nome));

                                                    printf("\nQuatidade de Unidade disponiveis nesse leito: ");
                                                    strUserInput(aux.auxChar, 100);
                                                    aux.auxLeito->qtdLeitos = 0;
                                                    while(aux.auxLeito->qtdLeitos < 1){
                                                        while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                            printf("\nDigite apenas numeros: ");
                                                            strUserInput(aux.auxChar, 100);
                                                        }
                                                        aux.auxLeito->qtdLeitos = (int) atoi(aux.auxChar);
                                                        strcpy(aux.auxChar, " ");
                                                    }

                                                    printf("\nTipos de Leitos:\n");
                                                    for(int i = 0; i < 15; i++){
                                                        strcpy(aux.auxChar, tipoLeito(i+1));
                                                        printf("\n[%d] %s", i+1, aux.auxChar);
                                                    }

                                                    strcpy(aux.auxChar, " ");
                                                    printf("\n\nDigite o numero correspondente ao tipo de leito: ");
                                                    strUserInput(aux.auxChar, 100);
                                                    aux.auxLeito->tipo = 0;
                                                    while(aux.auxLeito->tipo < 1 || aux.auxLeito->tipo > 15){
                                                        while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                            printf("\nDigite apenas numeros e que esejam entre 1 e 15!\nTipo do leito: ");
                                                            strUserInput(aux.auxChar, 100);
                                                        }
                                                        aux.auxLeito->tipo = atoi(aux.auxChar);
                                                        strcpy(aux.auxChar, " ");
                                                    }

                                                    dados_leitos.qtdEquipVinculados = 0;
                                                    fatualiza_leitos("leitos.bin", BD_leitos);
                                                }
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 EDICAO DE LEITO\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\n*** Cadastro Atualizado!\n");
                                                pauseEXE("\nAperte enter para continuar!");
                                                aux.auxInt = 0;
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                    else{
                                        printf("\nID Nao existe!\n");
                                        pauseEXE("Tecle enter para continuar!");
                                    }
                                }
                            }
                            else{
                                clearWindowsTerminal();
                                printf("---------------------------------------------------\n");
                                printf("                 BUSCA DE LEITOS\n");
                                printf("---------------------------------------------------\n");
                                printf("\nNenhum leito Cadastrado!\n");
                                pauseEXE("\nTecle enter para continuar");
                            }
                            aux.auxLeito = NULL;
                            aux.optCad = 0;
                            strcpy(aux.auxChar, " ");
                            clearWindowsTerminal();
                            break;
                        case 2:
                            printf("---------------------------------------------------\n");
                            printf("                 BUSCA DE EQUIPAMENTOS\n");
                            printf("---------------------------------------------------\n");
                            printf("\nDigite o Nome do Equipamento(* lista todos): ");
                            strUserInput(aux.auxChar, 100);
                            printf("\n");
                            busca = FilterByName_equipamentos(BD_equipamentos, aux.auxChar, 100);
                            print_matrizChar(busca);
                            printf("\n");

                            if(busca != (matrizChar *) NULL){
                                deleteMatrizChar(busca);
                                printf("Digite o id do Equipamento para mais opcoes(0 para sair): ");
                                aux.auxInt = -1;
                                strcpy(aux.auxChar, " ");
                                strUserInput(aux.auxChar, 100);
                                while(aux.auxInt < 0){
                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                        printf("\nDigite apenas numeros: ");
                                        strUserInput(aux.auxChar, 100);
                                    }
                                    aux.auxInt = atoi(aux.auxChar);
                                    strcpy(aux.auxChar, " ");
                                }

                                if(aux.auxInt == 0){
                                    aux.auxInt = 0;
                                    aux.optEdit = 0;
                                    aux.optCad = 0;
                                    strcpy(aux.auxChar, " ");
                                    clearWindowsTerminal();
                                    break;
                                }

                                clearWindowsTerminal();
                                printf("---------------------------------------------------\n");
                                printf("                 BUSCA DE EQUIPAMENTOS\n");
                                printf("---------------------------------------------------\n");

                                aux.auxEquip = busca_por_id_equipamento(BD_equipamentos, aux.auxInt);
                                if(aux.auxEquip != (l_equipamentos *) NULL){
                                    printf("\n***Dados Gerais\n\n");
                                    printf("Nome: %s", aux.auxEquip->nome);
                                    printf("\nData de Cadastro: %s", aux.auxEquip->data_cadastro);
                                    printf("\n\n***Leitos Vinculados\n");
                                    aux.auxInt = 0;
                                    if(BD_leitos != (l_leito *) NULL){
                                        aux.auxLeito = BD_leitos;
                                        while(aux.auxLeito != (l_leito *) NULL){
                                            if(aux.auxLeito->id_equip_vinculado != NULL){
                                                for(int i = 0; i < aux.auxLeito->qtdEquipVinculados; i++){
                                                    if(aux.auxLeito->id_equip_vinculado[i] == aux.auxEquip->id){
                                                        printf("\n- %s", aux.auxLeito->nome);
                                                        //Contador de Linhas impressas:
                                                        aux.auxInt++;
                                                    }
                                                }
                                            }
                                            aux.auxLeito = aux.auxLeito->next;
                                        }
                                        if(aux.auxInt == 0){
                                            printf("\n- Nenhum leito vinculado!\n");
                                        }
                                    }
                                    else{
                                        printf("\n- Nenhum Leito Vinculado!\n");
                                    }
                                    printf("\n");
                                    printf("---------------------------------------------------\n");
                                    printf("     [1] EXCLUIR/ [2] EDITAR / [3] VINCULAR\n");
                                    printf("            [4] DESVINCULAR [9] SAIR\n");
                                    printf("---------------------------------------------------\n");
                                    printf("\nResposta: ");
                                    strcpy(aux.auxChar, "");
                                    strUserInput(aux.auxChar, 100);
                                    aux.optEdit = 0;
                                    while(aux.optEdit < 1){
                                        while(!userIptCtrl(aux.auxChar, "1234567890")){
                                            printf("\nDigite apenas numeros: ");
                                            strUserInput(aux.auxChar, 100);
                                        }
                                        aux.optEdit = atoi(aux.auxChar);
                                        strcpy(aux.auxChar, " ");
                                    }
                                    if(aux.optEdit == 9){
                                        aux.auxInt = 0;
                                        aux.optEdit = 0;
                                        aux.optCad = 0;
                                        strcpy(aux.auxChar, " ");
                                        clearWindowsTerminal();
                                        break;
                                    }
                                    switch(aux.optEdit){
                                        case 1:
                                            printf("\nTem certeza que deseja Excluir esse equipamento?\n([1] SIM / [0] NAO) ");
                                            aux.auxInt = -1;
                                            strcpy(aux.auxChar, " ");
                                            strUserInput(aux.auxChar, 100);
                                            while(aux.auxInt < 0 || aux.auxInt > 1){
                                                while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                    printf("\nDigite apenas 0 ou 1: ");
                                                    strUserInput(aux.auxChar, 100);
                                                }
                                                aux.auxInt = atoi(aux.auxChar);
                                                strcpy(aux.auxChar, " ");

                                            }

                                            if(aux.auxInt){
                                                BD_equipamentos = free_equipamentos(BD_equipamentos, BD_leitos, aux.auxEquip->id);
                                                fatualiza_equips("equipamentos.bin", BD_equipamentos);
                                                fatualiza_vincEquips("leitos.bin", BD_leitos);
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 BUSCA DE EQUIPAMENTOS\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nEquipamento Excluido!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }
                                            else{
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 BUSCA DE EQUIPAMENTOS\n");
                                                printf("---------------------------------------------------\n\n");
                                                printf("Processo Abortado!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }
                                            break;
                                        case 2:
                                            printf("\nTem certeza que deseja Editar esse \nequipamento?([1] SIM / [0] NAO) ");
                                            aux.auxInt = -1;
                                            strcpy(aux.auxChar, " ");
                                            strUserInput(aux.auxChar, 100);
                                            while(aux.auxInt < 0 || aux.auxInt > 1){
                                                while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                    printf("\nDigite apenas 0 ou 1: ");
                                                    strUserInput(aux.auxChar, 100);
                                                }
                                                aux.auxInt = atoi(aux.auxChar);
                                                strcpy(aux.auxChar, " ");
                                            }

                                            if(aux.auxInt){
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 EDICAO DE LEITO\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\n***Digite os dados abaixo solicitadaos:\n\nNome: ");
                                                strUserInput(aux.auxEquip->nome, 100);
                                                fatualiza_equips("equipamentos.bin", BD_equipamentos);
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 BUSCA DE EQUIPAMENTOS\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nProcesso concluido!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }
                                            else{
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 BUSCA DE EQUIPAMENTOS\n");
                                                printf("---------------------------------------------------\n\n");
                                                printf("Processo Abortado!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }
                                            break;
                                        case 3:
                                            clearWindowsTerminal();
                                            printf("---------------------------------------------------\n");
                                            printf("              VINCULAÇÃO DE EQUIPAMENTOS\n");
                                            printf("---------------------------------------------------\n");
                                            printf("\n***PRIMEIRO BUSQUE UM LEITO:\n\nDigite o Nome do Leito(* lista todos): ");
                                            strUserInput(aux.auxChar, 100);
                                            printf("\n");
                                            busca = FilterByName_leitos(BD_leitos, aux.auxChar, 100);
                                            print_matrizChar(busca);
                                            printf("\n");

                                            if(busca != (matrizChar *) NULL){
                                                deleteMatrizChar(busca);
                                                printf("Digite um ID para Vincular: ");
                                                aux.auxInt = -1;
                                                strcpy(aux.auxChar, " ");
                                                strUserInput(aux.auxChar, 100);
                                                while(aux.auxInt < 0){
                                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                        printf("\nDigite apenas 0 ou 1: ");
                                                        strUserInput(aux.auxChar, 100);
                                                    }
                                                    aux.auxInt = atoi(aux.auxChar);
                                                    strcpy(aux.auxChar, " ");
                                                }

                                                if(aux.auxInt != 0){
                                                    aux.auxLeito = busca_por_id_leito(BD_leitos, aux.auxInt);
                                                    if(aux.auxLeito != (l_leito *) NULL){
                                                        VinculaEquipamento(BD_leitos, aux.auxLeito->id, aux.auxEquip->id);
                                                        fatualiza_leitos("leitos.bin", BD_leitos);
                                                        fatualiza_vincEquips("equip_vinc.bin", BD_leitos);
                                                        clearWindowsTerminal();
                                                        printf("---------------------------------------------------\n");
                                                        printf("             VINCULICAO DE EQUIPAMENTOS\n");
                                                        printf("---------------------------------------------------\n");
                                                        printf("\nEquipamento Vinculado!\n");
                                                        pauseEXE("\nAperte ENTER para continuar!");
                                                    }
                                                    else{
                                                        clearWindowsTerminal();
                                                        printf("---------------------------------------------------\n");
                                                        printf("             VINCULICAO DE EQUIPAMENTOS\n");
                                                        printf("---------------------------------------------------\n");
                                                        printf("\nProcesso Abortado, ID de Leito não encontrado!\n");
                                                        pauseEXE("\nAperte ENTER para continuar!");
                                                    }
                                                }

                                            }
                                            break;
                                        case 4:
                                            clearWindowsTerminal();
                                            printf("---------------------------------------------------\n");
                                            printf("            DESVINCULAÇÃO DE EQUIPAMENTOS\n");
                                            printf("---------------------------------------------------\n");
                                            printf("\n***PRIMEIRO BUSQUE UM LEITO:\n\nDigite o Nome do Leito(* lista todos): ");
                                            strUserInput(aux.auxChar, 100);
                                            printf("\n");
                                            busca = FilterByName_leitos(BD_leitos, aux.auxChar, 100);
                                            print_matrizChar(busca);
                                            printf("\n");

                                            if(busca != (matrizChar *) NULL){
                                                deleteMatrizChar(busca);
                                                printf("Digite um ID para Desvincular: ");
                                                aux.auxInt = -1;
                                                strcpy(aux.auxChar, " ");
                                                strUserInput(aux.auxChar, 100);
                                                while(aux.auxInt < 0){
                                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                        printf("\nDigite apenas 0 ou 1: ");
                                                        strUserInput(aux.auxChar, 100);
                                                    }
                                                    aux.auxInt = atoi(aux.auxChar);
                                                    strcpy(aux.auxChar, " ");
                                                }

                                                if(aux.auxInt != 0){
                                                    aux.auxLeito = busca_por_id_leito(BD_leitos, aux.auxInt);
                                                    if(aux.auxLeito != (l_leito *) NULL){
                                                        desvinc_equip(BD_leitos, aux.auxLeito->id, aux.auxEquip->id);
                                                        fatualiza_leitos("leitos.bin", BD_leitos);
                                                        fatualiza_vincEquips("equip_vinc.bin", BD_leitos);
                                                        clearWindowsTerminal();
                                                        printf("---------------------------------------------------\n");
                                                        printf("            DESVINCULAÇÃO DE EQUIPAMENTOS\n");
                                                        printf("---------------------------------------------------\n");
                                                        printf("\nEquipamento Desvinculado!\n");
                                                        pauseEXE("\nAperte ENTER para continuar!");
                                                    }
                                                    else{
                                                        clearWindowsTerminal();
                                                        printf("---------------------------------------------------\n");
                                                        printf("            DESVINCULAÇÃO DE EQUIPAMENTOS");
                                                        printf("---------------------------------------------------\n");
                                                        printf("\nProcesso Abortado, ID de Leito não encontrado!\n");
                                                        pauseEXE("\nAperte ENTER para continuar!");
                                                }
                                            }
                                            break;
                                        default:
                                            break;
                                        }
                                    }
                                }
                                else{
                                    clearWindowsTerminal();
                                    printf("---------------------------------------------------\n");
                                    printf("               BUSCA DE EQUIPAMENTOS\n");
                                    printf("---------------------------------------------------\n");
                                    printf("\nID nao encontrado!\n");
                                    pauseEXE("\nAperte ENTER para continuar!");
                                    }
                            }
                            else{
                                clearWindowsTerminal();
                                printf("---------------------------------------------------\n");
                                printf("               BUSCA DE EQUIPAMENTOS\n");
                                printf("---------------------------------------------------\n");
                                printf("\nNenhum Equipamento Cadastrado!\n");
                                pauseEXE("\nAperte ENTER para continuar!");
                            }
                            aux.auxInt = 0;
                            aux.optEdit = 0;
                            aux.optCad = 0;
                            strcpy(aux.auxChar, " ");
                            clearWindowsTerminal();
                            break;
                        case 3:
                            printf("---------------------------------------------------\n");
                            printf("                 BUSCA DE PACIENTES\n");
                            printf("---------------------------------------------------\n");
                            printf("\nDigite o Nome dos Pacientes(* lista todos): ");
                            strUserInput(aux.auxChar, 100);
                            printf("\n");
                            busca = FilterByName_pacientes(BD_paciente, BD_leitos, aux.auxChar, 100);
                            print_matrizChar(busca);
                            printf("\n");

                            if(busca != (matrizChar *) NULL){
                                deleteMatrizChar(busca);
                                printf("\nDigite o id do Paciente para mais opcoes(0 para sair): ");
                                aux.auxInt = -1;
                                strcpy(aux.auxChar, " ");
                                strUserInput(aux.auxChar, 100);
                                while(aux.auxInt < 0){
                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                        printf("\nDigite apenas numeros: ");
                                        strUserInput(aux.auxChar, 100);
                                    }
                                    aux.auxInt = atoi(aux.auxChar);
                                    strcpy(aux.auxChar, " ");
                                }

                                if(aux.auxInt == 0){
                                    clearWindowsTerminal();
                                    aux.auxPaciente = NULL;
                                    aux.optEdit = 0;
                                    aux.auxInt = 0;
                                    aux.optCad = 0;
                                    strcpy(aux.auxChar, " ");
                                    break;
                                }

                                clearWindowsTerminal();
                                printf("---------------------------------------------------\n");
                                printf("                 BUSCA DE PACIENTES\n");
                                printf("---------------------------------------------------\n");

                                aux.auxPaciente = busca_por_id_paciente(BD_paciente, aux.auxInt);
                                if(aux.auxPaciente != (l_paciente *) NULL){
                                    printf("\n***** DADOS GERAIS:\n");
                                    printf("\nNome: %s", aux.auxPaciente->nome);
                                    printf("\nCPF: %s", aux.auxPaciente->cpf);
                                    printf("\nData Nascimento: %s\nData de Entrada: %s\nData de Saida: %s", aux.auxPaciente->data_nasc, aux.auxPaciente->data_entrada, aux.auxPaciente->data_saida);
                                    strcpy(aux.auxChar, dataAtual());
                                    printf("Dias em Acompanhamento: %lu", dist_dias(str_to_data(aux.auxPaciente->data_entrada, "/"), str_to_data(aux.auxChar, "/")));
                                    strcpy(aux.auxChar, " ");
                                    printf("\n\nLeito Vinculado: \n\n");
                                    aux.auxLeito = busca_por_id_leito(BD_leitos, aux.auxPaciente->id_leito_vinculado);
                                    if(aux.auxLeito != (l_leito *) NULL){
                                        printf("- %s", aux.auxLeito->nome);
                                    }
                                    else{
                                        printf("- Usuario nao esta vinculado a um leito!");
                                    }
                                    printf("\n---------------------------------------------------\n");
                                    printf("     [1] EXCLUIR/ [2] EDITAR / [3] VINCULAR\n");
                                    printf("            [4] DESVINCULAR [9] SAIR\n");
                                    printf("---------------------------------------------------\n");
                                    printf("\nResposta: ");
                                    strcpy(aux.auxChar, "");
                                    strUserInput(aux.auxChar, 100);
                                    aux.optEdit = 0;
                                    while(aux.optEdit < 1){
                                        while(!userIptCtrl(aux.auxChar, "1234567890")){
                                            printf("\nDigite apenas numeros: ");
                                            strUserInput(aux.auxChar, 100);
                                        }
                                        aux.optEdit = atoi(aux.auxChar);
                                        strcpy(aux.auxChar, " ");
                                    }

                                    if(aux.optEdit == 9){
                                        clearWindowsTerminal();
                                        aux.auxPaciente = NULL;
                                        aux.optEdit = 0;
                                        aux.auxInt = 0;
                                        aux.optCad = 0;
                                        strcpy(aux.auxChar, " ");
                                        break;
                                    }

                                    switch(aux.optEdit){
                                        case 1:
                                            printf("\nTem certeza que deseja Excluir esse Paciente?\n([1] SIM / [0] NAO) ");
                                            aux.auxInt = -1;
                                            strcpy(aux.auxChar, " ");
                                            strUserInput(aux.auxChar, 100);
                                            while(aux.auxInt < 0 || aux.auxInt > 1){
                                                while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                    printf("\nDigite apenas 0 ou 1: ");
                                                    strUserInput(aux.auxChar, 100);
                                                }
                                                aux.auxInt = atoi(aux.auxChar);
                                                strcpy(aux.auxChar, " ");

                                            }

                                            if(aux.auxInt){
                                                cleanPaciente(&dados_pacientes);

                                                strcpy(dados_pacientes.cpf, aux.auxPaciente->cpf);
                                                strcpy(dados_pacientes.data_entrada, aux.auxPaciente->data_entrada);
                                                strcpy(dados_pacientes.data_nasc, aux.auxPaciente->data_nasc);
                                                strcpy(dados_pacientes.data_saida, dataAtual());
                                                strcpy(dados_pacientes.nome, aux.auxPaciente->nome);
                                                dados_pacientes.id = aux.auxPaciente->id;
                                                dados_pacientes.id_leito_vinculado = aux.auxPaciente->id_leito_vinculado;

                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 EXCLUSÃO DE PACIENTE\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nMotivos de Saida de um Paciente:\n");
                                                for(int i = 0; i < 4; i++){
                                                    printf("\n[%d] %s", i+1, MotivoSaida_Paciente(i+1));
                                                }

                                                printf("\n\nDigite o Codigo do Motivo da Saida: ");
                                                strUserInput(aux.auxChar, 100);
                                                aux.auxInt = 0;
                                                while(aux.auxInt < 1 || aux.auxInt > 4){
                                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                        printf("\nDigite apenas numeros entre 1 e 4: ");
                                                        strUserInput(aux.auxChar, 100);
                                                    }
                                                    aux.auxInt = atoi(aux.auxChar);
                                                    strcpy(aux.auxChar, " ");
                                                }
                                                dados_pacientes.cod_motivo_saida = aux.auxInt;

                                                fsavedata(&dados_pacientes, sizeof(paciente), "pacientes_historico.bin");
                                                BD_histPaciente = inserir_paciente(BD_histPaciente, dados_pacientes);
                                                BD_paciente = free_paciente(BD_paciente, aux.auxPaciente->id);
                                                fatualiza_pacientes("pacientes.bin", BD_paciente);
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("               EXCLUSÃO DE PACIENTES\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nPaciente Excluido!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }
                                            else{
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                EXCLUSÃO DE PACIENTES\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nProcesso Abortado!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }
                                            break;
                                        case 2:
                                            clearWindowsTerminal();
                                            printf("---------------------------------------------------\n");
                                            printf("               EXCLUSÃO DE PACIENTES\n");
                                            printf("---------------------------------------------------\n\n");
                                            printf("*** Preencha os dados solicitados abaixo:\n");

                                            printf("\nNome: ");
                                            strUserInput(aux.auxPaciente->nome, 100);

                                            printf("\nData de Nascimento: ");
                                            strUserInput(aux.auxPaciente->data_nasc, (int) sizeof(aux.auxPaciente->data_nasc)/sizeof(char));
                                            aux.auxInt = charUsed(aux.auxPaciente->data_nasc);
                                            if(userIptCtrl(aux.auxPaciente->data_nasc, "0123456789/") && aux.auxInt == 10){
                                                aux.auxInt2 = dataValida(str_to_data(aux.auxPaciente->data_nasc, "/"));
                                            }
                                            else{
                                                aux.auxInt2 = 0;
                                            }
                                            if(!aux.auxInt2){
                                                while(!userIptCtrl(aux.auxPaciente->data_nasc, "0123456789/") || !aux.auxInt2 || aux.auxInt < 10){
                                                    printf("\nDigite uma Data de Nascimento Valida: ");
                                                    strcpy(aux.auxPaciente->data_nasc, "");
                                                    strUserInput(aux.auxPaciente->data_nasc, (int) sizeof(aux.auxPaciente->data_nasc)/sizeof(char));
                                                    aux.auxInt = charUsed(aux.auxPaciente->data_nasc);
                                                    if(userIptCtrl(aux.auxPaciente->data_nasc, "0123456789/") && aux.auxInt == 10){
                                                        aux.auxInt2 = dataValida(str_to_data(aux.auxPaciente->data_nasc, "/"));
                                                    }
                                                }
                                            }

                                            fatualiza_pacientes("pacientes.bin", BD_paciente);

                                            clearWindowsTerminal();
                                            printf("---------------------------------------------------\n");
                                            printf("              EDICAO DE PACIENTES\n");
                                            printf("---------------------------------------------------\n");
                                            printf("\n*** Cadastro realizado!\n\n");
                                            pauseEXE("Aperte ENTER para continuar!");
                                            break;
                                        case 3:
                                            clearWindowsTerminal();
                                            printf("---------------------------------------------------\n");
                                            printf("                 VINCULAR EM UM LEITO\n");
                                            printf("---------------------------------------------------\n\n");
                                            printf("*** Digite o Nome do leito(* para todos): ");

                                            strUserInput(aux.auxChar, 100);
                                            printf("\n");
                                            busca = FilterByName_leitos(BD_leitos, aux.auxChar, 100);
                                            print_matrizChar(busca);
                                            printf("\n\n");
                                            if(busca != (matrizChar *) NULL){
                                                deleteMatrizChar(busca);
                                                printf("Digite um ID para busca de um leito(0 para sair): ");
                                                strUserInput(aux.auxChar, 100);
                                                aux.auxInt = -1;
                                                while(aux.auxInt < 0){
                                                    while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                        printf("\nDigite apenas numeros: ");
                                                        strUserInput(aux.auxChar, 100);
                                                    }
                                                    aux.auxInt = atoi(aux.auxChar);
                                                    strcpy(aux.auxChar, " ");
                                                }

                                                if(aux.auxInt != 0){
                                                    aux.auxLeito = busca_por_id_leito(BD_leitos, aux.auxInt);
                                                    aux.auxPaciente->id_leito_vinculado = aux.auxLeito->id;
                                                    fatualiza_pacientes("pacientes.bin", BD_paciente);
                                                    clearWindowsTerminal();
                                                    printf("---------------------------------------------------\n");
                                                    printf("                 VINCULAR EM UM LEITO\n");
                                                    printf("---------------------------------------------------\n");
                                                    printf("\nPaciente vinculado a %s", aux.auxLeito->nome);
                                                    pauseEXE("\n\nAperte ENTER para continuar!");
                                                }
                                                else{
                                                    clearWindowsTerminal();
                                                    printf("---------------------------------------------------\n");
                                                    printf("                 VINCULAR EM UM LEITO\n");
                                                    printf("---------------------------------------------------\n");
                                                    printf("\nID não encontrado!\n");
                                                    pauseEXE("\nAperte ENTER para continuar!");
                                                }
                                            }
                                            else{
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("                 VINCULAR EM UM LEITO\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nResultados para a Palavra Chave não encontrados!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }

                                            aux.auxInt = 0;
                                            clearWindowsTerminal();
                                            break;
                                        case 4:
                                            clearWindowsTerminal();
                                            printf("---------------------------------------------------\n");
                                            printf("            DESVINCULAR UM PACIENTE\n");
                                            printf("---------------------------------------------------\n");
                                            printf("\nTem certeza que deseja Desvincular esse Paciente?\n([1] SIM / [0] NAO) ");
                                            aux.auxInt = -1;
                                            strcpy(aux.auxChar, " ");
                                            strUserInput(aux.auxChar, 100);
                                            while(aux.auxInt < 0 || aux.auxInt > 1){
                                                while(!userIptCtrl(aux.auxChar, "1234567890")){
                                                    printf("\nDigite apenas 0 ou 1: ");
                                                    strUserInput(aux.auxChar, 100);
                                                }
                                                aux.auxInt = atoi(aux.auxChar);
                                                strcpy(aux.auxChar, " ");

                                            }

                                            if(aux.auxInt){
                                                aux.auxLeito = busca_por_id_leito(BD_leitos, aux.auxInt);
                                                aux.auxPaciente->id_leito_vinculado = 0;
                                                fatualiza_pacientes("pacientes.bin", BD_paciente);
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("              DESVINCULAR UM PACIENTE\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nPessoa Desvinculada!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }
                                            else{
                                                clearWindowsTerminal();
                                                printf("---------------------------------------------------\n");
                                                printf("              DESVINCULAR UM PACIENTE\n");
                                                printf("---------------------------------------------------\n");
                                                printf("\nProcesso Cancelado!\n");
                                                pauseEXE("\nAperte ENTER para continuar!");
                                            }

                                            aux.auxInt = 0;
                                            clearWindowsTerminal();
                                            break;
                                        default:
                                            break;
                                    }

                                }
                                else{
                                    printf("\nNenhum ID Encontrado!\n");
                                    pauseEXE("\nAperte enter para continuar!");
                                }
                            }
                            else{
                                clearWindowsTerminal();
                                printf("---------------------------------------------------\n");
                                printf("                 BUSCA DE PACIENTES\n");
                                printf("---------------------------------------------------\n");
                                printf("\nNenhum Resultado Encontrado!\n");
                                pauseEXE("\nAperte enter para continuar!");
                            }

                            clearWindowsTerminal();
                            aux.auxPaciente = NULL;
                            aux.optEdit = 0;
                            aux.auxInt = 0;
                            aux.optCad = 0;
                            strcpy(aux.auxChar, " ");
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 3:
                printf("---------------------------------------------------\n");
                printf("               HISTORICO DE PACIENTES\n");
                printf("---------------------------------------------------\n");
                printf("\nDigite o Nome dos Pacientes(* lista todos): ");
                strUserInput(aux.auxChar, 100);
                printf("\n");
                busca = FilterByName_HistPacientes(BD_histPaciente, BD_leitos, aux.auxChar, 100);
                print_matrizChar(busca);
                printf("\n");

                if(busca != (matrizChar *) NULL){
                    deleteMatrizChar(busca);
                    printf("\n\nDigite o id do Paciente para mais opcoes(0 para sair): ");
                    aux.auxInt = -1;
                    strcpy(aux.auxChar, " ");
                    strUserInput(aux.auxChar, 100);
                    while(aux.auxInt < 0){
                        while(!userIptCtrl(aux.auxChar, "1234567890")){
                            printf("\nDigite apenas numeros: ");
                            strUserInput(aux.auxChar, 100);
                        }
                        aux.auxInt = atoi(aux.auxChar);
                        strcpy(aux.auxChar, " ");
                    }

                    if(aux.auxInt == 0){
                        clearWindowsTerminal();
                        aux.auxInt = 0;
                        aux.auxLeito = NULL;
                        aux.optCad = 0;
                        strcpy(aux.auxChar, " ");
                        clearWindowsTerminal();
                        break;
                    }
                    clearWindowsTerminal();
                    printf("---------------------------------------------------\n");
                    printf("              HISTORICO DE PACIENTES\n");
                    printf("---------------------------------------------------\n");

                    aux.auxPaciente = busca_por_id_paciente(BD_histPaciente, aux.auxInt);
                    if(aux.auxPaciente != (l_paciente *) NULL){
                        printf("\n***** DADOS GERAIS:\n");
                        printf("\nNome: %s", aux.auxPaciente->nome);
                        printf("\nCPF: %s", aux.auxPaciente->cpf);
                        printf("\nData Nascimento: %s\nData de Entrada: %s\nData de Saida: %s", aux.auxPaciente->data_nasc, aux.auxPaciente->data_entrada, aux.auxPaciente->data_saida);
                        printf("\nMotivo da Saida: %s", MotivoSaida_Paciente(aux.auxPaciente->cod_motivo_saida));
                        printf("\n\nLeitos Anteriormente Vinculado: \n\n");
                        aux.auxLeito = busca_por_id_leito(BD_leitos, aux.auxPaciente->id_leito_vinculado);
                        if(aux.auxLeito != (l_leito *) NULL){
                            printf("- %s", aux.auxLeito->nome);
                        }
                        else{
                            printf("- Usuario nao estava vinculado a um leito!");
                        }
                    }
                    else{
                        printf("\nNenhum Registro encontrado!");
                    }
                }
                else{
                    clearWindowsTerminal();
                    printf("---------------------------------------------------\n");
                    printf("              HISTORICO DE PACIENTES\n");
                    printf("---------------------------------------------------\n");
                    printf("\nNenhum Registro encontrado!");
                }
                pauseEXE("\n\nTecle ENTER para voltar ao menu anterior!");

                aux.auxInt = 0;
                aux.auxLeito = NULL;
                aux.optCad = 0;
                strcpy(aux.auxChar, " ");
                clearWindowsTerminal();
                break;
            case 4:
                clearWindowsTerminal();
                printf("---------------------------------------------------\n");
                printf("            RESUMOS GERAIS DO SISTEMA\n");
                printf("---------------------------------------------------\n");
                aux.auxLeito = BD_leitos;
                aux.auxInt= 0;
                while(aux.auxLeito != (l_leito *) NULL){
                    aux.auxInt++;
                    aux.auxLeito = aux.auxLeito->next;
                }
                printf("\nLeitos Cadastrados: %d", aux.auxInt);
                aux.auxLeito = NULL;

                aux.auxPaciente = BD_paciente;
                aux.auxInt= 0;
                while(aux.auxPaciente != (l_paciente *) NULL){
                    aux.auxInt++;
                    aux.auxPaciente = aux.auxPaciente->next;
                }
                printf("\nPacientes Cadastrados: %d", aux.auxInt);
                aux.auxPaciente = NULL;

                aux.auxPaciente = BD_histPaciente;
                aux.auxInt= 0;
                while(aux.auxPaciente != (l_paciente *) NULL){
                    aux.auxInt++;
                    aux.auxPaciente = aux.auxPaciente->next;
                }
                printf("\nPacientes Excluidos: %d", aux.auxInt);
                aux.auxPaciente = NULL;

                aux.auxEquip = BD_equipamentos;
                aux.auxInt= 0;
                while(aux.auxEquip != (l_equipamentos *) NULL){
                    aux.auxInt++;
                    aux.auxEquip = aux.auxEquip->next;
                }
                printf("\nEquipamentos Cadastrados: %d", aux.auxInt);
                aux.auxEquip = NULL;

                pauseEXE("\n\nAperte ENTER para continuar!");
                aux.optCad = 0;
                strcpy(aux.auxChar, " ");
                clearWindowsTerminal();
                break;
            case 5:
                while(aux.optEdit != 9){
                    clearWindowsTerminal();
                    printf("---------------------------------------------------\n");
                    printf("               EXTRAIR RELATÓRIOS CSV\n");
                    printf("---------------------------------------------------\n\n");
                    printf(" [1] Leitos\n [2] Equipamentos\n [3] Pacientes Cadastrados\n [4] Excluidos \n [9] Voltar\n\n");
                    printf(" Resposta: ");
                    strUserInput(aux.auxChar, 100);
                    aux.optEdit = 0;
                    while(aux.optEdit < 1){
                        while(!userIptCtrl(aux.auxChar, "123456789")){
                            printf("\nDigite apenas numeros: ");
                            strUserInput(aux.auxChar, 100);
                        }
                        aux.optEdit = atoi(aux.auxChar);
                        strcpy(aux.auxChar, " ");
                    }

                    FILE * temp = NULL;

                    switch(aux.optEdit){
                    case 1:
                        temp = fopen("leitos.csv", "w");
                        if(!temp){
                            printf("\nProblema ao Criar o Arquivo!\n");
                        }
                        else{
                            busca = FilterByName_leitos(BD_leitos, "*", 100);

                            if(busca != (matrizChar *) NULL){
                                for(int i = 0; i < busca->qtdLin; i++){
                                    fprintf(temp, "%s,%s,%s,%s\n", busca->dados[i][0], busca->dados[i][1], busca->dados[i][2], busca->dados[i][3]);
                                }
                                fclose(temp);
                                deleteMatrizChar(busca);
                                printf("\nO arquivo foi gerado na mesma pasta desse programa!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                            else{
                                fclose(temp);
                                printf("\nNao foram encontrados dados para gerar o arquivo!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                        }
                        break;
                    case 2:
                        temp = fopen("equipamentos.csv", "w");
                        if(!temp){
                            printf("\nProblema ao Criar o Arquivo!\n");
                            pauseEXE("\n\nAperte ENTER para continuar!");
                        }
                        else{
                            busca = FilterByName_equipamentos(BD_equipamentos, "*", 100);

                            if(busca != (matrizChar *) NULL){
                                for(int i = 0; i < busca->qtdLin; i++){
                                    fprintf(temp, "%s,%s\n", busca->dados[i][0], busca->dados[i][1]);
                                }
                                fclose(temp);
                                deleteMatrizChar(busca);
                                printf("\nO arquivo foi gerado na mesma pasta desse programa!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                            else{
                                fclose(temp);
                                printf("\nNao foram encontrados dados para gerar o arquivo!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                        }
                        break;
                    case 3:
                        temp = fopen("pacientes.csv", "w");
                        if(!temp){
                            printf("\nProblema ao Criar o Arquivo!\n");
                            pauseEXE("\n\nAperte ENTER para continuar!");
                        }
                        else{
                            busca = FilterByName_pacientes(BD_paciente, BD_leitos, "*", 100);

                            if(busca != (matrizChar *) NULL){
                                for(int i = 0; i < busca->qtdLin; i++){
                                    fprintf(temp, "%s,%s,%s,%s\n", busca->dados[i][0], busca->dados[i][1], busca->dados[i][2], busca->dados[i][3]);
                                }
                                fclose(temp);
                                deleteMatrizChar(busca);
                                printf("\nO arquivo foi gerado na mesma pasta desse programa!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                            else{
                                fclose(temp);
                                printf("\nNao foram encontrados dados para gerar o arquivo!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                        }
                        break;
                    case 4:
                        temp = fopen("pacientesExcluidos.csv", "w");
                        if(!temp){
                            printf("\nProblema ao Criar o Arquivo!\n");
                            pauseEXE("\n\nAperte ENTER para continuar!");
                        }
                        else{
                            busca = FilterByName_HistPacientes(BD_histPaciente, BD_leitos, "*", 100);

                            if(busca != (matrizChar *) NULL){
                                for(int i = 0; i < busca->qtdLin; i++){
                                    fprintf(temp, "%s,%s,%s,%s\n", busca->dados[i][0], busca->dados[i][1], busca->dados[i][2], busca->dados[i][3]);
                                }
                                fclose(temp);
                                deleteMatrizChar(busca);
                                printf("\nO arquivo foi gerado na mesma pasta desse programa!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                            else{
                                fclose(temp);
                                printf("\nNao foram encontrados dados para gerar o arquivo!\n");
                                pauseEXE("\n\nAperte ENTER para continuar!");
                            }
                        }
                        break;
                    default:
                        break;
                    }
                }
                aux.optCad = 0;
                strcpy(aux.auxChar, " ");
                clearWindowsTerminal();
                break;
            default:
                break;
        }
        aux.optCad = 0;
        strcpy(aux.auxChar, " ");
        aux.auxData = NULL;
        aux.auxEquip = NULL;
        aux.auxInt2 = 0;
        aux.auxInt = 0;
        aux.auxLeito = NULL;
        aux.auxPaciente = NULL;
        aux.optCad = 0;
        aux.optEdit = 0;
        aux.ptr = NULL;
    }

    printf("---------------------------------------------------\n");
    printf("              GERENCIAMENTO DE LEITOS\n");
    printf("---------------------------------------------------\n\n");
    printf("Programa encerrado!\n\nDesenvolvido por Harllem Alves,\nEmerson Rodrigues e Renato\n\n");

    free(aux.auxChar);
    freeAll_Leitos(BD_leitos);
    freeAll_equipamentos(BD_equipamentos);
    freeAll_paciente(BD_paciente);
    freeAll_paciente(BD_histPaciente);
    deleteMatrizChar(busca);
    return 0;
}
