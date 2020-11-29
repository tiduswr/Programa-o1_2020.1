#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utilityFunctions.h"
/*--------------------- STRUCTS ---------------------*/
typedef struct controls{
    int id_leitos;
    int id_pacientes;
    int id_equips;
}controls;

typedef struct matrizChar{
    char ***dados;
    int sizeChar;
    int qtdCol;
    int qtdLin;
} matrizChar;

typedef struct l_leito{
    int id;
    int tipo;
    char nome[100];
    int qtdLeitos;
    int qtdEquipVinculados;
    char data_cadastro[20];
    int *id_equip_vinculado;
    struct l_leito *next;
}l_leito;

typedef struct l_paciente{
    int id;
    int id_leito_vinculado;
    char cpf[20];
    char nome[100];
    char data_nasc[20];
    char data_entrada[20];
    char data_saida[20];
    int cod_motivo_saida;
    struct l_paciente *next;
}l_paciente;

typedef struct l_equipamentos{
    int id;
    char nome[100];
    char data_cadastro[20];
    struct l_equipamentos *next;
}l_equipamentos;

typedef struct leito{
    int id;
    int tipo;
    char nome[100];
    char data_cadastro[20];
    int qtdLeitos;
    int qtdEquipVinculados;
}leito;

typedef struct paciente{
    int id;
    int id_leito_vinculado;
    char cpf[20];
    char nome[100];
    char data_nasc[20];
    char data_entrada[20];
    char data_saida[20];
    int cod_motivo_saida;
}paciente;

typedef struct equipamentos{
    int id;
    char nome[100];
    char data_cadastro[20];
}equipamentos;

/*--------------------- FUNÇÕES PRINCIPAIS ---------------------*/

l_leito * new_l_leito(){
    return NULL;
}

l_equipamentos * new_l_equipamentos(){
    return NULL;
}

l_paciente * new_l_paciente(){
    return NULL;
}

l_leito * inserir_leito(l_leito *ref, leito node){
    l_leito *new = (l_leito *) malloc(sizeof(l_leito));

    new->id = node.id;
    strcpy(new->nome,node.nome);
    new->qtdLeitos = node.qtdLeitos;
    new->tipo = node.tipo;
    new->qtdEquipVinculados = node.qtdEquipVinculados;
    new->id_equip_vinculado = (int *) NULL;
    strcpy(new->data_cadastro, node.data_cadastro);

    if(ref == (l_leito *) NULL){
        new->next = new_l_leito();
        return new;
    }
    else{
        l_leito *aux = ref;
        while(aux->next != (l_leito *) NULL){
            aux = aux->next;
        }
        aux->next = new;
        new->next = new_l_leito();
        return ref;
    }
    return ref;
}

l_paciente * inserir_paciente(l_paciente *ref, paciente dados){
    l_paciente *new = (l_paciente *) malloc(sizeof(l_paciente));

    strcpy(new->cpf, dados.cpf);
    strcpy(new->data_entrada, dados.data_entrada);
    strcpy(new->data_nasc, dados.data_nasc);
    strcpy(new->data_saida, dados.data_saida);
    strcpy(new->nome, dados.nome);
    new->id = dados.id;
    new->id_leito_vinculado = dados.id_leito_vinculado;
    new->cod_motivo_saida = dados.cod_motivo_saida;

    if(ref == (l_paciente *) NULL){
        new->next = new_l_paciente();
        return new;
    }
    else{
        l_paciente *aux = ref;

        while(aux->next != (l_paciente *) NULL){
            aux = aux->next;
        }

        aux->next = new;
        new->next = new_l_paciente();
        return ref;
    }
    return ref;
}

l_equipamentos * inserir_equipamento(l_equipamentos *ref, equipamentos dados){
    l_equipamentos *new = (l_equipamentos *) malloc(sizeof(l_equipamentos));

    new->id = dados.id;
    strcpy(new->nome, dados.nome);
    strcpy(new->data_cadastro, dados.data_cadastro);

    if(ref == (l_equipamentos *) NULL){
        new->next = new_l_equipamentos();
        return new;
    }
    else{
        l_equipamentos *aux = ref;
        while(aux->next != (l_equipamentos *) NULL){
            aux = aux->next;
        }
        aux->next = new;
        new->next = new_l_equipamentos();
        return ref;
    }
    return ref;
}

l_leito * free_leito(l_leito *ref, int id){
    l_leito *aux = ref;
    l_leito *previous = NULL;
    while(aux != (l_leito *) NULL && aux->id != id){
        previous = aux;
        aux = aux->next;
    }
    if(aux == (l_leito *) NULL){
        return ref;
    }
    else if(previous == (l_leito *) NULL){
        ref = aux->next;
        free(aux);
    }
    else{
        previous->next = aux->next;
        free(aux);
    }
    return ref;
}

l_leito * freeAll_Leitos(l_leito *ref){
    l_leito *aux = ref;
    while(aux != (l_leito *) NULL){
        ref = ref->next;
        free(aux);
        aux = ref;
    }
    ref = NULL;
    return ref;
}

void cleanLeitos(leito * ref){
    ref->id = 0;
    strcpy(ref->nome, "");
    strcpy(ref->data_cadastro, "");
    ref->qtdEquipVinculados = 0;
    ref->qtdLeitos = 0;
    ref->tipo = 0;
}

l_leito * fcarrega_dados_leitos(char *nomearq){
    l_leito *lista = NULL;
    FILE * arq = NULL;
    int i = 0;

    arq = fopen(nomearq, "rb");
    if(!arq){
        fclose(arq);
    }
    else{
        rewind(arq);

        leito dados;
        int continua = fread(&dados, sizeof(dados), 1, arq);
        while(continua){
            lista = inserir_leito(lista, dados);
            continua = fread(&dados, sizeof(dados), 1, arq);
            i++;
        }
        if(i == 0){
            return NULL;
        }
        fclose(arq);
    }
    return lista;
}

void fatualiza_leitos(char * nomearq, l_leito *ref){
    FILE * arq = NULL;
    l_leito * aux = ref;
    leito dados;

    arq = fopen(nomearq, "wb");
    while(aux != (l_leito *) NULL){
        dados.id = aux->id;
        strcpy(dados.nome, aux->nome);
        dados.qtdEquipVinculados = aux->qtdEquipVinculados;
        dados.qtdLeitos = aux->qtdLeitos;
        dados.tipo = aux->tipo;
        strcpy(dados.data_cadastro, aux->data_cadastro);

        fwrite(&dados, sizeof(dados), 1, arq);
        aux = aux->next;
    }
    fclose(arq);
}

l_leito * busca_por_id_leito(l_leito *ref, int id){
    l_leito *aux = ref;
    while(aux != (l_leito *) NULL){
        if(aux->id == id){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

char * tipoLeito(int cod){
    switch(cod){
        case 1:
            return "Leito de internacao";
            break;
        case 2:
            return "Leito Complementar de internacao";
            break;
        case 3:
            return "Leito de Hospital Dia";
            break;
        case 4:
            return "Leito de Observacao";
            break;
        case 5:
            return "Leito Clinico";
            break;
        case 6:
            return "Leito Cirurgico";
            break;
        case 7:
            return "Leito Obstetrico";
            break;
        case 8:
            return "Leito Pediatrico";
            break;
        case 9:
            return "Leito de Isolamento";
            break;
        case 10:
            return "Leito de Isolamento Reverso";
            break;
        case 11:
            return "Leito de Cuidados Intensivos (UTI)";
            break;
        case 12:
            return "Leito de Cuidados Intermediarios (UCI)";
            break;
        case 13:
            return "Leito de Recuperação Pos-Anestesica (RPA)";
            break;
        case 14:
            return "Leito de Urgencia e Emergencia";
            break;
        case 15:
            return "Leito de Pre-Parto";
            break;
        default:
            return NULL;
            break;
    }
}

matrizChar * FilterByName_leitos(l_leito *ref, char value[], int tamStr){
    if(ref == (l_leito *) NULL){
        return NULL;
    }
    l_leito * aux = ref;
    matrizChar * array = (matrizChar *) malloc(sizeof(matrizChar));
    array->qtdLin = 0;
    array->sizeChar = tamStr;
    int cabecalho = 1;
    unsigned int i = 0, match = 0, value_len = 0;
    value_len = charUsed(value);

    while(aux != (l_leito *) NULL){
        if(strcmp(value, "*") != 0){
            for(i = 0; i < (int) sizeof(aux->nome)/sizeof(char); i++){
                if(toupper(aux->nome[i]) == toupper(value[match])){
                    if(match < value_len){
                        match++;
                    }
                }
                else if(match < value_len){
                    match = 0;
                }
            }
        }
        if(match == value_len || strcmp(value, "*") == 0){
            if(cabecalho == 1){
                array->qtdLin = 2;
                array->dados = (char ***) malloc(array->qtdLin * sizeof(char **));
                array->qtdCol = 4;
                for(int j = 0; j < array->qtdLin; j++){
                    array->dados[j] = (char **) malloc(array->qtdCol * sizeof(char *));
                    for(int k = 0; k < array->qtdCol; k++){
                        array->dados[j][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                    }
                }

                strcpy(array->dados[0][0], "ID");
                strcpy(array->dados[0][1], "Nome do Leito");
                strcpy(array->dados[0][2], "Tipo de Leito");
                strcpy(array->dados[0][3], "QTD LEITO");
                strcpy(array->dados[1][0], int_to_str(aux->id));
                strcpy(array->dados[1][1], aux->nome);
                strcpy(array->dados[1][2], tipoLeito(aux->tipo));
                strcpy(array->dados[1][3], int_to_str(aux->qtdLeitos));
                cabecalho = 0;
            }
            else{
                array->qtdLin++;
                array->dados = (char ***) realloc(array->dados, array->qtdLin * sizeof(char **));
                array->dados[array->qtdLin - 1] = (char **) malloc(array->qtdCol * sizeof(char *));

                for(int k = 0; k < array->qtdCol; k++){
                    array->dados[array->qtdLin - 1][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                }
                strcpy(array->dados[array->qtdLin - 1][0], int_to_str(aux->id));
                strcpy(array->dados[array->qtdLin - 1][1], aux->nome);
                strcpy(array->dados[array->qtdLin - 1][2], tipoLeito(aux->tipo));
                strcpy(array->dados[array->qtdLin - 1][3], int_to_str(aux->qtdLeitos));
            }
        }
        match = 0;
        aux = aux->next;
    }
    if(array->qtdLin == 0){
        return NULL;
    }
    return array;
}

l_equipamentos * freeAll_equipamentos(l_equipamentos *ref){
    l_equipamentos *aux = ref;
    while(aux != (l_equipamentos *) NULL){
        ref = ref->next;
        free(aux);
        aux = ref;
    }
    return ref;
}

void cleanEquipamento(equipamentos * ref){
    ref->id = 0;
    strcpy(ref->nome, "");
    strcpy(ref->data_cadastro, "");
}

l_equipamentos * busca_por_id_equipamento(l_equipamentos *ref, int id){
    l_equipamentos *aux = ref;
    while(aux != (l_equipamentos *) NULL){
        if(aux->id == id){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

int VinculaEquipamento(l_leito *ref, int id_leito, int id_equipamento){
    int status = 0;
    if(ref != (l_leito *) NULL){
        l_leito *aux = ref;
        while(aux != (l_leito *) NULL && aux->id != id_leito){
            aux = aux->next;
        }

        if(aux != (l_leito *) NULL){
            if(aux->id_equip_vinculado == (int *)NULL){
                aux->id_equip_vinculado = (int *) malloc(sizeof(int));
                aux->id_equip_vinculado[0] = id_equipamento;
                aux->qtdEquipVinculados++;
                status = 1;
            }
            else{
                aux->qtdEquipVinculados++;
                aux->id_equip_vinculado = (int *) realloc(aux->id_equip_vinculado, sizeof(int)*aux->qtdEquipVinculados);
                aux->id_equip_vinculado[aux->qtdEquipVinculados - 1] = id_equipamento;
                status = 1;
            }
        }
    }
    return status;
}

void desvinc_equip(l_leito *ref, int id_leito, int id_equipamento){
    if(ref != (l_leito *) NULL){
        l_leito *aux = ref;
        while(aux != (l_leito *) NULL && aux->id != id_leito){
            aux = aux->next;
        }
        if(aux != (l_leito *) NULL){
            int *temp = aux->id_equip_vinculado;
            int equipVinc = aux->qtdEquipVinculados;
            aux->id_equip_vinculado = NULL;
            aux->qtdEquipVinculados = 0;

            for(int i = 0; i < equipVinc; i++){
                if(temp[i] != id_equipamento){
                    if(aux->qtdEquipVinculados == 0){
                        aux->id_equip_vinculado = (int *) malloc(sizeof(int));
                        aux->id_equip_vinculado[0] = temp[i];
                        aux->qtdEquipVinculados++;
                    }
                    else{
                        aux->qtdEquipVinculados++;
                        aux->id_equip_vinculado = (int *) realloc(aux->id_equip_vinculado, sizeof(int)*aux->qtdEquipVinculados);
                        aux->id_equip_vinculado[aux->qtdEquipVinculados - 1] = temp[i];
                    }
                }

            }
            free(temp);
        }

    }
}

l_equipamentos * free_equipamentos(l_equipamentos *ref, l_leito *vinculos, int id){
    l_equipamentos *aux = ref;
    l_leito *vinculos_aux = vinculos;
    l_equipamentos *previous = NULL;
    while(aux != (l_equipamentos *) NULL && aux->id != id){
        previous = aux;
        aux = aux->next;
    }
    if(aux == (l_equipamentos *) NULL){
        return ref;
    }
    else if(previous == (l_equipamentos *) NULL){
        ref = aux->next;
        while(vinculos_aux != (l_leito *) NULL){
            desvinc_equip(vinculos_aux, vinculos_aux->id, id);
            vinculos_aux = vinculos_aux->next;
        }
        free(aux);
    }
    else{
        previous->next = aux->next;
        while(vinculos_aux != (l_leito *) NULL){
            desvinc_equip(vinculos_aux, vinculos_aux->id, id);
            vinculos_aux = vinculos_aux->next;
        }
        free(aux);
    }
    return ref;
}

l_equipamentos * fcarrega_dados_equip(char *nomearq){
    l_equipamentos *lista = NULL;
    FILE * arq = NULL;
    int i = 0;

    arq = fopen(nomearq, "rb");
    if(!arq){
        fclose(arq);
    }
    else{
        rewind(arq);

        equipamentos dados;
        int continua = fread(&dados, sizeof(dados), 1, arq);
        while(continua){
            lista = inserir_equipamento(lista, dados);
            continua = fread(&dados, sizeof(dados), 1, arq);
            i++;
        }
        if(i == 0){
            return NULL;
        }
    }
    fclose(arq);
    return lista;
}

void fcarrega_vincEquips(char * nomearq, l_leito *ref){
    if(ref != (l_leito *) NULL){

        FILE * arq = NULL;
        l_leito * aux = ref;
        int * equips = NULL;
        int id, qtdEquips;

        arq = fopen(nomearq, "rb");
        int continua = fread(&id, sizeof(int), 1, arq);

        while(continua){
            aux = busca_por_id_leito(ref, id);
            fread(&qtdEquips, sizeof(int), 1, arq);

            if(aux == (l_leito *) NULL){
                fread(equips, sizeof(int) * qtdEquips, 1, arq);
            }
            else if(aux != (l_leito *) NULL && aux->id == id){

                equips = (int *) realloc(equips,sizeof(int) * qtdEquips);

                fread(equips, sizeof(int) * qtdEquips, 1, arq);
                for(int i = 0; i < qtdEquips; i++){
                    VinculaEquipamento(ref, id, equips[i]);

                }
            }
            id = 0;
            qtdEquips = 0;
            equips = NULL;
            continua = fread(&id, sizeof(int), 1, arq);
        }
        fclose(arq);
    }
}

void fatualiza_equips(char * nomearq, l_equipamentos *ref){
    FILE * arq = NULL;
    l_equipamentos * aux = ref;
    equipamentos dados;

    arq = fopen(nomearq, "wb");
    while(aux != (l_equipamentos *) NULL){
        dados.id = aux->id;
        strcpy(dados.nome, aux->nome);
        strcpy(dados.data_cadastro, aux->data_cadastro);
        fwrite(&dados, sizeof(dados), 1, arq);
        aux = aux->next;
    }
    fclose(arq);
}

void fatualiza_vincEquips(char * nomearq, l_leito *ref){
    FILE * arq = NULL;
    l_leito * aux = ref;

    arq = fopen(nomearq, "wb");
    while(aux != (l_leito *) NULL){
        if(aux->id_equip_vinculado != NULL){
            fwrite(&aux->id, sizeof(int), 1, arq);
            fwrite(&aux->qtdEquipVinculados, sizeof(int), 1, arq);
            fwrite(aux->id_equip_vinculado, sizeof(int) * aux->qtdEquipVinculados, 1, arq);
        }
        aux = aux->next;
    }
    fclose(arq);
}

matrizChar * FilterByName_equipamentos(l_equipamentos *ref, char value[], int tamStr){
    if(ref == (l_equipamentos *) NULL){
        return NULL;
    }
    l_equipamentos * aux = ref;
    matrizChar * array = (matrizChar *) malloc(sizeof(matrizChar));
    array->qtdLin = 0;
    array->sizeChar = tamStr;
    int cabecalho = 1;
    unsigned int i = 0, match = 0, value_len = 0;

    value_len = charUsed(value);

    while(aux != (l_equipamentos *) NULL){
        if(strcmp(value, "*") != 0){
            for(i = 0; i < (int) sizeof(aux->nome)/sizeof(char); i++){
                if(toupper(aux->nome[i]) == toupper(value[match])){
                    if(match < value_len){
                        match++;
                    }
                }
                else if(match < value_len){
                    match = 0;
                }
            }
        }
        if(match == value_len || strcmp(value, "*") == 0){
            if(cabecalho == 1){
                array->qtdLin = 2;
                array->dados = (char ***) malloc(array->qtdLin * sizeof(char **));
                array->qtdCol = 2;

                for(int j = 0; j < array->qtdLin; j++){
                    array->dados[j] = (char **) malloc(array->qtdCol * sizeof(char *));
                    for(int k = 0; k < array->qtdCol; k++){
                        array->dados[j][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                    }
                }
                strcpy(array->dados[0][0], "ID");
                strcpy(array->dados[0][1], "Nome do Paciente");
                strcpy(array->dados[1][0], int_to_str(aux->id));
                strcpy(array->dados[1][1], aux->nome);
                cabecalho = 0;
            }
            else{
                array->qtdLin++;
                array->dados = (char ***) realloc(array->dados, array->qtdLin * sizeof(char **));
                array->dados[array->qtdLin - 1] = (char **) malloc(array->qtdCol * sizeof(char *));

                for(int k = 0; k < array->qtdCol; k++){
                    array->dados[array->qtdLin - 1][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                }
                strcpy(array->dados[array->qtdLin - 1][0], int_to_str(aux->id));
                strcpy(array->dados[array->qtdLin - 1][1], aux->nome);
            }
        }
        match = 0;
        aux = aux->next;
    }
    if(array->qtdLin == 0){
        return NULL;
    }
    return array;
}

l_paciente * freeAll_paciente(l_paciente *ref){
    l_paciente *aux = ref;
    while(aux != (l_paciente *) NULL){
        ref = ref->next;
        free(aux);
        aux = ref;
    }
    ref = NULL;
    return ref;
}

l_paciente * busca_por_id_paciente(l_paciente *ref, int id){
    l_paciente *aux = ref;
    while(aux != (l_paciente *) NULL){
        if(aux->id == id){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

l_paciente * free_paciente(l_paciente *ref, int id){
    l_paciente *aux = ref;
    l_paciente *previous = NULL;
    while(aux != (l_paciente *) NULL && aux->id != id){
        previous = aux;
        aux = aux->next;
    }
    if(aux == (l_paciente *) NULL){
        return ref;
    }
    else if(previous == (l_paciente *) NULL){
        ref = aux->next;
        free(aux);
    }
    else{
        previous->next = aux->next;
        free(aux);
    }
    return ref;
}

void cleanPaciente(paciente * ref){
    ref->cod_motivo_saida = 0;
    strcpy(ref->cpf, "");
    strcpy(ref->data_entrada, "");
    strcpy(ref->data_nasc, "");
    strcpy(ref->data_saida, "");
    ref->id = 0;
    ref->id_leito_vinculado = 0;
    strcpy(ref->nome, "");
}

l_paciente * fcarrega_dados_pacientes(char *nomearq){
    l_paciente *lista = NULL;
    FILE * arq = NULL;
    int i = 0;
    arq = fopen(nomearq, "rb");
    if(!arq){
        fclose(arq);
    }
    else{
        rewind(arq);

        paciente dados;
        int continua = fread(&dados, sizeof(dados), 1, arq);
        while(continua){
            lista = inserir_paciente(lista, dados);
            continua = fread(&dados, sizeof(dados), 1, arq);
            i++;
        }
        if(i == 0){
            fclose(arq);
            return NULL;
        }
        fclose(arq);
    }
    return lista;
}

void fatualiza_pacientes(char * nomearq, l_paciente *ref){
    FILE * arq = NULL;
    l_paciente * aux = ref;
    paciente dados;

    arq = fopen(nomearq, "wb");
    while(aux != (l_paciente *) NULL){
        dados.id = aux->id;
        strcpy(dados.nome, aux->nome);
        dados.id_leito_vinculado = aux->id_leito_vinculado;
        strcpy(dados.data_nasc, aux->data_nasc);
        strcpy(dados.data_entrada, aux->data_entrada);
        strcpy(dados.data_saida, aux->data_saida);
        strcpy(dados.cpf, aux->cpf);
        dados.cod_motivo_saida = aux->cod_motivo_saida;

        fwrite(&dados, sizeof(dados), 1, arq);
        aux = aux->next;
    }
    fclose(arq);
}

char *MotivoSaida_Paciente(int codigo){
    switch(codigo){
    case 1:
        return "Obito";
        break;

    case 2:
        return "Alta";
        break;

    case 3:
        return "Transferencia para Infermaria";
        break;

    case 4:
        return "Transferencia para Casa";
        break;
    default:
        return NULL;
        break;
    }
}

matrizChar * FilterByName_pacientes(l_paciente *ref, l_leito *lista, char value[], int tamStr){
    if(ref == (l_paciente *) NULL){
        return NULL;
    }
    l_paciente * aux = ref;
    l_leito * busca = NULL;
    matrizChar * array = (matrizChar *) malloc(sizeof(matrizChar));
    array->qtdLin = 0;
    array->sizeChar = tamStr;
    int cabecalho = 1;
    unsigned int i = 0, match = 0, value_len = 0;

    value_len = charUsed(value);

    while(aux != (l_paciente *) NULL){
        if(strcmp(value, "*") != 0){
            for(i = 0; i < (int) sizeof(aux->nome)/sizeof(char); i++){
                if(toupper(aux->nome[i]) == toupper(value[match])){
                    if(match < value_len){
                        match++;
                    }
                }
                else if(match < value_len){
                    match = 0;
                }
            }
        }
        if(match == value_len || strcmp(value, "*") == 0){
            if(cabecalho == 1){
                array->qtdLin = 2;
                array->dados = (char ***) malloc(array->qtdLin * sizeof(char **));
                array->qtdCol = 4;

                for(int j = 0; j < array->qtdLin; j++){
                    array->dados[j] = (char **) malloc(array->qtdCol * sizeof(char *));
                    for(int k = 0; k < array->qtdCol; k++){
                        array->dados[j][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                    }
                }
                strcpy(array->dados[0][0], "ID");
                strcpy(array->dados[0][1], "Nome do Paciente");
                strcpy(array->dados[0][2], "Leito");
                strcpy(array->dados[0][3], "Data de Entrada");
                strcpy(array->dados[1][0], int_to_str(aux->id));
                strcpy(array->dados[1][1], aux->nome);
                busca = busca_por_id_leito(lista, aux->id_leito_vinculado);
                if(busca != (l_leito *) NULL){
                    strcpy(array->dados[1][2], busca->nome);
                }
                else{
                    strcpy(array->dados[1][2], "Sem Leito");
                }
                strcpy(array->dados[1][3], aux->data_entrada);
                cabecalho = 0;
            }
            else{
                array->qtdLin++;
                array->dados = (char ***) realloc(array->dados, array->qtdLin * sizeof(char **));
                array->dados[array->qtdLin - 1] = (char **) malloc(array->qtdCol * sizeof(char *));

                for(int k = 0; k < array->qtdCol; k++){
                    array->dados[array->qtdLin - 1][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                }
                strcpy(array->dados[array->qtdLin - 1][0], int_to_str(aux->id));
                strcpy(array->dados[array->qtdLin - 1][1], aux->nome);
                busca = busca_por_id_leito(lista, aux->id_leito_vinculado);
                if(busca != (l_leito *) NULL){
                    strcpy(array->dados[array->qtdLin - 1][2], busca->nome);
                }else{
                    strcpy(array->dados[array->qtdLin - 1][2], "Sem Leito");
                }
                strcpy(array->dados[array->qtdLin - 1][3], aux->data_entrada);
            }
        }
        match = 0;
        aux = aux->next;
    }
    busca = NULL;
    if(array->qtdLin == 0){
        return NULL;
    }
    return array;
}

matrizChar * FilterByName_HistPacientes(l_paciente *ref, l_leito *lista, char value[], int tamStr){
    if(ref == (l_paciente *) NULL){
        return NULL;
    }
    l_paciente * aux = ref;
    l_leito * busca = NULL;
    matrizChar * array = (matrizChar *) malloc(sizeof(matrizChar));
    array->qtdLin = 0;
    array->sizeChar = tamStr;
    int cabecalho = 1;
    unsigned int i = 0, match = 0, value_len = 0;

    value_len = charUsed(value);

    while(aux != (l_paciente *) NULL){
        if(strcmp(value, "*") != 0){
            for(i = 0; i < (int) sizeof(aux->nome)/sizeof(char); i++){
                if(toupper(aux->nome[i]) == toupper(value[match])){
                    if(match < value_len){
                        match++;
                    }
                }
                else if(match < value_len){
                    match = 0;
                }
            }
        }
        if(match == value_len || strcmp(value, "*") == 0){
            if(cabecalho == 1){
                array->qtdLin = 2;
                array->dados = (char ***) malloc(array->qtdLin * sizeof(char **));
                array->qtdCol = 4;

                for(int j = 0; j < array->qtdLin; j++){
                    array->dados[j] = (char **) malloc(array->qtdCol * sizeof(char *));
                    for(int k = 0; k < array->qtdCol; k++){
                        array->dados[j][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                    }
                }
                strcpy(array->dados[0][0], "ID");
                strcpy(array->dados[0][1], "Nome do Paciente");
                strcpy(array->dados[0][2], "Leito");
                strcpy(array->dados[0][3], "Data de Saida");
                strcpy(array->dados[1][0], int_to_str(aux->id));
                strcpy(array->dados[1][1], aux->nome);
                busca = busca_por_id_leito(lista, aux->id_leito_vinculado);
                if(busca != (l_leito *) NULL){
                    strcpy(array->dados[1][2], busca->nome);
                }
                else{
                    strcpy(array->dados[1][2], "Sem Leito");
                }
                strcpy(array->dados[1][3], aux->data_saida);
                cabecalho = 0;
            }
            else{
                array->qtdLin++;
                array->dados = (char ***) realloc(array->dados, array->qtdLin * sizeof(char **));
                array->dados[array->qtdLin - 1] = (char **) malloc(array->qtdCol * sizeof(char *));

                for(int k = 0; k < array->qtdCol; k++){
                    array->dados[array->qtdLin - 1][k] = (char *) malloc(sizeof(char) * array->sizeChar);
                }
                strcpy(array->dados[array->qtdLin - 1][0], int_to_str(aux->id));
                strcpy(array->dados[array->qtdLin - 1][1], aux->nome);
                busca = busca_por_id_leito(lista, aux->id_leito_vinculado);
                if(busca != (l_leito *) NULL){
                    strcpy(array->dados[array->qtdLin - 1][2], busca->nome);
                }else{
                    strcpy(array->dados[array->qtdLin - 1][2], "Sem Leito");
                }
                strcpy(array->dados[array->qtdLin - 1][3], aux->data_saida);
            }
        }
        match = 0;
        aux = aux->next;
    }
    busca = NULL;
    if(array->qtdLin == 0){
        return NULL;
    }
    return array;
}

void deleteMatrizChar(matrizChar *ref){
    if(ref != (matrizChar *) NULL){
        for(int i = 0; i < ref->qtdLin; i++){
            for(int j = 0; j < ref->qtdCol; j++){
                free(ref->dados[i][j]);
            }
            free(ref->dados[i]);
        }
        free(ref->dados);
        ref->dados = NULL;
        ref->qtdCol = 0;
        ref->qtdLin = 0;
        ref->sizeChar = 0;
    }
}

void print_matrizChar(matrizChar *ref){
    if(ref != (matrizChar *) NULL){
        /*Verifica o tamanho de cada coluna*/
        int *lenStr = malloc(ref->qtdCol * sizeof(int));
        int aux;
        for(int j = 0; j < ref->qtdCol; j++){
            for(int i = 0; i < ref->qtdLin; i++){
                if(i == 0){
                    lenStr[j] = charUsed(ref->dados[i][j]);
                }
                else{
                    if(charUsed(ref->dados[i][j]) > lenStr[j]){
                        lenStr[j] = charUsed(ref->dados[i][j]);
                    }
                }
            }
        }
        /*Imprime Matriz*/
        for(int i = 0; i < ref->qtdLin; i++){
            for(int j = 0; j < ref->qtdCol; j++){
                if(i == 0){
                    aux = lenStr[j] - charUsed(ref->dados[i][j]);
                    if(aux % 2 == 0){
                        printEspacos(aux/2);
                        printf("%s", ref->dados[i][j]);
                        printEspacos(aux/2);
                    }
                    else{
                        aux++;
                        lenStr[j]++;

                        printEspacos(aux/2);
                        printf("%s", ref->dados[i][j]);
                        printEspacos(aux/2);
                    }
                    printf("|");
                    aux = 0;
                }
                else{
                    aux = lenStr[j] - charUsed(ref->dados[i][j]);
                    printf("%s", ref->dados[i][j]);
                    printEspacos(aux);
                    printf("|");
                    aux = 0;
                }
            }
            printf("\n");
            for(int l = 0; l < ref->qtdCol; l++){
                for(int k = 0; k < lenStr[l]; k++){
                    printf("-");
                }
                printf("+");
            }
            printf("\n");
        }
        free(lenStr);
    }
}

void matChar_sort(matrizChar *ref, int criteriaCol){
    if(ref != (matrizChar *) NULL){
        for(int h = 1; h < ref->qtdLin - 1; h++){
            for(int i = 1; i < ref->qtdLin - 1; i++){
                if(strcmp(ref->dados[i][criteriaCol], ref->dados[i+1][criteriaCol]) > 0){
                    for(int j = 0; j < ref->qtdCol; j++){
                        swapStr(ref->dados[i][j], ref->dados[i+1][j], ref->sizeChar);
                    }
                }
            }
        }
    }
}

void fcarrega_dados_controls(controls *ref, char *nomearq){
    FILE * arq = NULL;

    arq = fopen(nomearq, "rb");
    if(!arq){
        fclose(arq);
    }
    else{
        rewind(arq);
        fread(ref, sizeof(controls), 1, arq);
    }
    fclose(arq);
}

void fatualiza_controls(controls *ref, char *nomearq){
    FILE * arq = NULL;

    arq = fopen(nomearq, "wb");
    if(!arq){
        fclose(arq);
    }
    else{
        rewind(arq);
        fwrite(ref, sizeof(controls), 1, arq);
    }
    fclose(arq);
}
