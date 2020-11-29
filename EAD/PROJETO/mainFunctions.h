#ifndef MAINFUNCTIONS_H
    #define MAINFUNCTIONS_H

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

    l_leito * new_l_leito();
    l_equipamentos * new_l_equipamentos();
    l_paciente * new_l_paciente();
    l_leito * inserir_leito(l_leito *ref, leito node);
    l_paciente * inserir_paciente(l_paciente *ref, paciente dados);
    l_equipamentos * inserir_equipamento(l_equipamentos *ref, equipamentos dados);
    l_leito * free_leito(l_leito *ref, int id);
    l_leito * freeAll_Leitos(l_leito *ref);
    void cleanLeitos(leito * ref);
    l_leito * fcarrega_dados_leitos(char *nomearq);
    void fatualiza_leitos(char * nomearq, l_leito *ref);
    l_leito * busca_por_id_leito(l_leito *ref, int id);
    char * tipoLeito(int cod);
    matrizChar * FilterByName_leitos(l_leito *ref, char value[], int tamStr);
    l_equipamentos * freeAll_equipamentos(l_equipamentos *ref);
    void cleanEquipamento(equipamentos * ref);
    l_equipamentos * busca_por_id_equipamento(l_equipamentos *ref, int id);
    int VinculaEquipamento(l_leito *ref, int id_leito, int id_equipamento);
    void desvinc_equip(l_leito *ref, int id_leito, int id_equipamento);
    l_equipamentos * free_equipamentos(l_equipamentos *ref, l_leito *vinculos, int id);
    l_equipamentos * fcarrega_dados_equip(char *nomearq);
    void fcarrega_vincEquips(char * nomearq, l_leito *ref);
    void fatualiza_equips(char * nomearq, l_equipamentos *ref);
    void fatualiza_vincEquips(char * nomearq, l_leito *ref);
    matrizChar * FilterByName_equipamentos(l_equipamentos *ref, char value[], int tamStr);
    l_paciente * freeAll_paciente(l_paciente *ref);
    l_paciente * busca_por_id_paciente(l_paciente *ref, int id);
    l_paciente * free_paciente(l_paciente *ref, int id);
    void cleanPaciente(paciente * ref);
    l_paciente * fcarrega_dados_pacientes(char *nomearq);
    void fatualiza_pacientes(char * nomearq, l_paciente *ref);
    char *MotivoSaida_Paciente(int codigo);
    matrizChar * FilterByName_pacientes(l_paciente *ref, l_leito *lista, char value[], int tamStr);
    matrizChar * FilterByName_HistPacientes(l_paciente *ref, l_leito *lista, char value[], int tamStr);
    void deleteMatrizChar(matrizChar *ref);
    void print_matrizChar(matrizChar *ref);
    void matChar_sort(matrizChar *ref, int criteriaCol);
    void fcarrega_dados_controls(controls *ref, char *nomearq);
    void fatualiza_controls(controls *ref, char *nomearq);

#endif
