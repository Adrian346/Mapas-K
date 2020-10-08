#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datos{
    char var1[3], var2[3], var3[3], var4[3];
    int val[4];
}Datos;

void menu();

void Variables_2();
void capturar_2(char [100], char [2], char [3], char [2], char [3]);
void llenartabla_2(Datos *, int [4], int [4][2], int [], int, char [2], char [2]);
void mapa_2_Variables(int [2][2], int [4], char [2], char [2]);
void Var2_Grupos_de_2(int [2][2], char [100]);
void Var2_Grupos_de_1(int [2][2], char [100]);
void mostrarReduccion_2(char [100], char [100], char [2], char [2]);

void Variables_3();
void capturar_3(char [100], char [2], char [3], char [2], char [3], char [2], char [3]);
void llenartabla_3(Datos *, int [8], int [8][3], int [], int, char [2], char [2], char [2]);
void mapa_3_Variables(int [2][4], int [8], char [2], char [2], char [2]);
void Var3_Grupos_de_4(int [2][4], int [20], char [100]);
void Var3_Grupos_de_2(int [2][4], int [20], char [100]);
void Var3_Grupos_de_1(int [2][4], char [100]);
void mostrarReduccion_3(char [100], char [100], char [2], char [2], char [2]);

void Variables_4();
void capturar_4(char [100], char [2], char [3], char [2], char [3], char [2], char [3], char [2], char [3]);
void llenartabla_4(Datos *, int [16], int [16][4], int [], int, char [2], char [2], char [2], char [2]);
void mapa4variables(int [4][4], int [16], char [2], char [2], char [2], char [2]);
void Var4_Reducir_Expresion_8(int [4][4], char [100], int [100]);
void Var4_Reducir_Expresion_4(int [4][4], char [100], int [100]);
void Var4_Reducir_Expresion_2(int [4][4], char [100], int [100]);
void Var4_Reducir_Expresion_1(int [4][4], char [100]);
void mostrarReduccion_4(char [100], char [100], char [2], char [2], char [2], char [2]);

int main()
{
    menu();
    return 0;
}
void menu()
{
    char opc, salir;
    printf("\n\n\n\n\n\n\n\n\t\t\tBIENVENIDO A MAPAS DE KARNAUGH!\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    do{

            printf("\n\n\t\t\t\t\tPresiona una tecla para continuar...\n");
            getchar();
            system("cls");
            do{
                    printf("De cuantas variables es su mapa k (2, 3 o 4)? ");
                    scanf("%c", &opc);
                    getchar();
                    if(opc=='2')
                    {
                        printf("\t\tMAPA DE KARNAUGH DE 2 VARIABLES\n");
                        Variables_2();
                    }
                    if(opc=='3')
                    {
                        printf("\t\tMAPA DE KARNAUGH DE 3 VARIABLES\n");
                        Variables_3();
                    }
                    if(opc=='4')
                    {
                        printf("\t\tMAPA DE KARNAUGH DE 4 VARIABLES\n");
                        Variables_4();
                    }
                    if(opc!='2' && opc !='3' && opc!='4')
                        printf("Ingrese una opcion correcta \n");
            }while(opc!='2' && opc !='3' && opc!='4');
            printf("\n");
            system("PAUSE");
            system("cls");
        getchar();
        printf("Si desea continuar presione la tecla 1\n");
        printf("Si desea salir presione cualquier otra tecla\n ");
        scanf("%c", &salir);
        system("cls");
    }while(salir=='1');
}

void Variables_2()
{
    Datos *var;
    int i, n=0, z[4], mapa[2][2], numero_de_1s=0, j;
    int tabla[4][2]={0, 0,
                      0, 1,
                      1, 0,
                      1, 1};
    var=(Datos *) calloc(25, sizeof(Datos));
    char expresion[100], expresion_final[100], Reduccion[100];
    char varnormal_1[2], varnegada_1[3], varnormal_2[2], varnegada_2[3];
    capturar_2(expresion, varnormal_1, varnegada_1, varnormal_2, varnegada_2);
    strcpy(expresion_final, "");
    strcpy(Reduccion, "");
    for(i=0; i<strlen(expresion); i++)
    {
        if(expresion[i]==varnormal_1[0] && expresion[i-1]=='-')
            strcpy(var[n].var1, varnegada_1);
        if(expresion[i]==varnormal_1[0] && expresion[i-1]!='-')
            strcpy(var[n].var1, varnormal_1);
        if(expresion[i]=='-' && expresion[i+1]==varnormal_2[0])
            strcpy(var[n].var2, varnegada_2);
        if(expresion[i]==varnormal_2[0] && expresion[i-1]!='-')
            strcpy(var[n].var2, varnormal_2);
        if(expresion[i]=='+')
            n++;
    }
    n++;
    int numero_variables[n];
    for(i=0; i<n; i++)
        numero_variables[i]=2;

    for(i=0; i<n; i++)
    {
        if(strcmp(var[i].var1, varnormal_1)==0)
            var[i].val[0]=1;
        if(strcmp(var[i].var1, varnegada_1)==0)
            var[i].val[0]=0;
        if(strcmp(var[i].var2, varnormal_2)==0)
            var[i].val[1]=1;
        if(strcmp(var[i].var2, varnegada_2)==0)
            var[i].val[1]=0;
        if(strcmp(var[i].var1, "")==0)
        {
            numero_variables[i]--;
            var[i].val[0]=2;
        }
        if(strcmp(var[i].var2, "")==0)
        {
            numero_variables[i]--;
            var[i].val[1]=2;
        }
    }
    printf("\t\tTABLA DE VERDAD \n\n");
    llenartabla_2(var, z, tabla, numero_variables, n, varnormal_1, varnormal_2);
    printf("\t\tMAPA DE KARNAUGH \n\n");
    mapa_2_Variables(mapa, z, varnormal_1, varnormal_2);
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            if(mapa[i][j]==1)
                numero_de_1s++;
        }
    }
    if(numero_de_1s==4)
    {
        strcat(Reduccion, "1");
        printf("\t\tEXPRESION SIMPLIFICADA\n");
        printf("Z = ");
        printf("%s\n", Reduccion);
    }
    else{
            Var2_Grupos_de_2(mapa, expresion_final);
            Var2_Grupos_de_1(mapa, expresion_final);
            printf("\t\tEXPRESION SIMPLIFICADA\n");
            mostrarReduccion_2(expresion_final, Reduccion, varnormal_1, varnormal_2);
    }
}
void capturar_2(char expresion[100], char varnormal_1[2], char varnegada_1[3], char varnormal_2[2], char varnegada_2[3])
{
    int i, cont=0;
    printf("A continuacion ingresara la variables que va a usar...\n");
    printf("(Por favor ingresar las variables a usar en orden para que obtenga resultados correctos)\n");
    do{
            printf("Ingrese primera variable a usar: ");
            scanf("%s", varnormal_1);
            for(i=0; varnormal_1[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
    }while(i!=1);
    do{
            printf("Ingrese segunda variable a usar: ");
            scanf("%s", varnormal_2);
            for(i=0; varnormal_2[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
            if(strcmp(varnormal_2, varnormal_1)==0)
                printf("La variables no pueden ser iguales\n");
    }while(i!=1 || strcmp(varnormal_2, varnormal_1)==0);
    system("PAUSE");
    system("cls");
    printf("Las variables a usar son: \n%s y %s\n", varnormal_1, varnormal_2);
    strcpy(varnegada_1, "");
    strcpy(varnegada_2, "");
    strcat(varnegada_1, "-");
    strcat(varnegada_1, varnormal_1);
    strcat(varnegada_2, "-");
    strcat(varnegada_2, varnormal_2);
    do{
            printf("Ingresa la expresion (Aqui no importa el orden las variables) :\n");
            scanf("%s", expresion);
            cont=0;
            for(i=0; expresion[i]!='\0'; i++)
            {
                if(expresion[i]!='-' && expresion[i]!='+' && expresion[i]!=varnormal_1[0] && expresion[i]!=varnormal_2[0])
                    cont++;
            }
            if(cont!=0)
                printf("Ingresaste algun caracter invalido. Por favor vuelve a ingresar la expresion\n");
    }while(cont!=0);
    printf("\nZ = %s\n", expresion);
}
void llenartabla_2(Datos *var, int z[4], int tabla[4][2], int numero_variables[], int n, char v1[2], char v2[2])
{
    int cont, k, i, j, contador=0;
    printf("\n");
    printf("  %s   %s    Z\n\n", v1, v2);
    for(i=0; i<4; i++)
    {
        z[i]=0;
        for(k=0; k<n; k++)
        {
            cont=0;
            for(j=0; j<2; j++)
            {
                if(var[k].val[j]==0 && tabla[i][j]==0)
                    cont++;
                if(var[k].val[j]==1 && tabla[i][j]==1)
                    cont++;
            }
            if(cont==numero_variables[k])
            {
                z[i]=1;
                k=n;
            }
        }
        for(j=0; j<2; j++)
            printf("%3d ", tabla[i][j]);
        printf("|%3d", z[i]);
        printf("\n");
    }
}
void mapa_2_Variables(int mapa[2][2], int z[4], char v1[2], char v2[2])
{
    int i, j, cont=0;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
                mapa[i][j]=z[cont];
                cont++;
        }
    }
    printf("\n%s/%s   0    1\n\n", v1, v2);
    for(i=0; i<2; i++)
    {
        if(i==0)
            printf("0   ");
        if(i==1)
            printf("1   ");
        for(j=0; j<2; j++)
        {
            printf("%3d  ", mapa[i][j]);
        }
        printf("\n");
    }
printf("\n\n");
}
void Var2_Grupos_de_2(int mapa[2][2], char expresion_final[100])
{
       if(mapa[0][0]==1 && mapa[0][1]==1)
            strcat(expresion_final, "-A+");
        if(mapa[0][0]==1 && mapa[1][0]==1)
            strcat(expresion_final, "-B+");
        if(mapa[0][1]==1 && mapa[1][1]==1)
            strcat(expresion_final, "B+");
        if(mapa[1][0]==1 && mapa[1][1]==1)
            strcat(expresion_final, "A+");
}
void Var2_Grupos_de_1(int mapa[2][2], char expresion_final[100])
{
    if(mapa[0][1]==0 && mapa[1][0]==0 && mapa[0][0]==1)
        strcat(expresion_final, "-A-B+");
    if(mapa[0][1]==1 && mapa[1][1]==0 && mapa[0][0]==0)
        strcat(expresion_final, "-AB+");
    if(mapa[0][0]==0 && mapa[1][0]==1 && mapa[1][1]==0)
        strcat(expresion_final, "A-B+");
    if(mapa[0][1]==0 && mapa[1][0]==0 && mapa[1][1]==1)
        strcat(expresion_final, "AB+");
}
void mostrarReduccion_2(char expresion_final[100], char Reduccion[100], char v1[2], char v2[2])
{
    int i;
    char aux[100];
    strcpy(aux, "");
    for(i=0; expresion_final[i]!='\0'; i++)
    {
        if(expresion_final[i]=='-')
            strcat(aux, "-");
        if(expresion_final[i]=='+')
            strcat(aux, "+");
        if(expresion_final[i]=='A')
            strcat(aux, v1);
        if(expresion_final[i]=='B')
            strcat(aux, v2);
    }
    printf("\nZ = ");
    for(i=0; aux[i]!='\0'; i++)
    {
        if(aux[i+1]!='\0')
        {
            Reduccion[i]=aux[i];
            printf("%c", Reduccion[i]);
        }
    }
}


void Variables_3()
{
    Datos *var;
    int i, n=0, z[8], mapa[2][4], contador[20], numero_de_1s=0, j;
    int tabla[8][3]={0, 0, 0,
                      0, 0, 1,
                      0, 1, 0,
                      0, 1, 1,
                      1, 0, 0,
                      1, 0, 1,
                      1, 1, 0,
                      1, 1, 1};
    var=(Datos *) calloc(25, sizeof(Datos));
    char expresion[100], expresion_final[100], Reduccion[100];
    char varnormal_1[2], varnegada_1[3], varnormal_2[2], varnegada_2[3], varnormal_3[2], varnegada_3[3];
    capturar_3(expresion, varnormal_1, varnegada_1, varnormal_2, varnegada_2, varnormal_3, varnegada_3);
    strcpy(expresion_final, "");
    strcpy(Reduccion, "");
    for(i=0; i<strlen(expresion); i++)
    {
        if(expresion[i]==varnormal_1[0] && expresion[i-1]=='-')
            strcpy(var[n].var1, varnegada_1);
        if(expresion[i]==varnormal_1[0] && expresion[i-1]!='-')
            strcpy(var[n].var1, varnormal_1);
        if(expresion[i]=='-' && expresion[i+1]==varnormal_2[0])
            strcpy(var[n].var2, varnegada_2);
        if(expresion[i]==varnormal_2[0] && expresion[i-1]!='-')
            strcpy(var[n].var2, varnormal_2);
        if(expresion[i]=='-' && expresion[i+1]==varnormal_3[0])
            strcpy(var[n].var3, varnegada_3);
        if(expresion[i]==varnormal_3[0] && expresion[i-1]!='-')
            strcpy(var[n].var3, varnormal_3);
        if(expresion[i]=='+')
            n++;
    }
    n++;
    int numero_variables[n];
    for(i=0; i<n; i++)
        numero_variables[i]=3;

    for(i=0; i<n; i++)
    {
        if(strcmp(var[i].var1, varnormal_1)==0)
            var[i].val[0]=1;
        if(strcmp(var[i].var1, varnegada_1)==0)
            var[i].val[0]=0;
        if(strcmp(var[i].var2, varnormal_2)==0)
            var[i].val[1]=1;
        if(strcmp(var[i].var2, varnegada_2)==0)
            var[i].val[1]=0;
        if(strcmp(var[i].var3, varnormal_3)==0)
            var[i].val[2]=1;
        if(strcmp(var[i].var3, varnegada_3)==0)
            var[i].val[2]=0;
        if(strcmp(var[i].var1, "")==0)
        {
            numero_variables[i]--;
            var[i].val[0]=2;
        }
        if(strcmp(var[i].var2, "")==0)
        {
            numero_variables[i]--;
            var[i].val[1]=2;
        }
        if(strcmp(var[i].var3, "")==0)
        {
            numero_variables[i]--;
            var[i].val[2]=2;
        }
    }
    printf("\t\tTABLA DE VERDAD \n\n");
    llenartabla_3(var, z, tabla, numero_variables, n, varnormal_1, varnormal_2, varnormal_3);
    printf("\t\tMAPA DE KARNAUGH \n\n");
    mapa_3_Variables(mapa, z, varnormal_1, varnormal_2, varnormal_3);
    for(i=0; i<20; i++)
        contador[i]=0;
    for(i=0; i<2; i++)
    {
        for(j=0; j<4; j++)
        {
            if(mapa[i][j]==1)
                numero_de_1s++;
        }
    }
    if(numero_de_1s==8)
    {
        strcat(Reduccion, "1");
        printf("\t\tEXPRESION SIMPLIFICADA\n");
        printf("Z = ");
        printf("%s\n", Reduccion);
    }
    else{
            Var3_Grupos_de_4(mapa, contador, expresion_final);
            Var3_Grupos_de_2(mapa, contador, expresion_final);
            Var3_Grupos_de_1(mapa, expresion_final);
            printf("\t\tEXPRESION SIMPLIFICADA\n");
            mostrarReduccion_3(expresion_final, Reduccion, varnormal_1, varnormal_2, varnormal_3);
    }
}
void capturar_3(char expresion[100], char varnormal_1[2], char varnegada_1[3], char varnormal_2[2], char varnegada_2[3], char varnormal_3[2], char varnegada_3[3])
{
    int i, cont=0;
    printf("A continuacion ingresara la variables que va a usar...\n");
    printf("(Por favor ingresar las variables a usar en orden para que obtenga resultados correctos)\n");
    do{
            printf("Ingrese primera variable a usar: ");
            scanf("%s", varnormal_1);
            for(i=0; varnormal_1[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
    }while(i!=1);
    do{
            printf("Ingrese segunda variable a usar: ");
            scanf("%s", varnormal_2);
            for(i=0; varnormal_2[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
            if(strcmp(varnormal_2, varnormal_1)==0)
                printf("La variables no pueden ser iguales\n");
    }while(i!=1 || strcmp(varnormal_2, varnormal_1)==0);
    do{
            printf("Ingrese tercera variable a usar: ");
            scanf("%s", varnormal_3);
            for(i=0; varnormal_3[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
            if(strcmp(varnormal_3, varnormal_1)==0 || strcmp(varnormal_3, varnormal_2)==0)
                printf("La variables no pueden ser iguales\n");
    }while(i!=1 || strcmp(varnormal_3, varnormal_1)==0 || strcmp(varnormal_3, varnormal_2)==0);
    system("PAUSE");
    system("cls");
    printf("Las variables a usar son: \n%s, %s y %s\n", varnormal_1, varnormal_2, varnormal_3);
    strcpy(varnegada_1, "");
    strcpy(varnegada_2, "");
    strcpy(varnegada_3, "");
    strcat(varnegada_1, "-");
    strcat(varnegada_1, varnormal_1);
    strcat(varnegada_2, "-");
    strcat(varnegada_2, varnormal_2);
    strcat(varnegada_3, "-");
    strcat(varnegada_3, varnormal_3);
    do{
            printf("Ingresa la expresion (Aqui no importa el orden las variables) :\n");
            scanf("%s", expresion);
            cont=0;
            for(i=0; expresion[i]!='\0'; i++)
            {
                if(expresion[i]!='-' && expresion[i]!='+' && expresion[i]!=varnormal_1[0] && expresion[i]!=varnormal_2[0] && expresion[i]!=varnormal_3[0])
                    cont++;
            }
            if(cont!=0)
                printf("Ingresaste algun caracter invalido. Por favor vuelve a ingresar la expresion\n");
    }while(cont!=0);
    printf("\nZ = %s\n", expresion);
}
void llenartabla_3(Datos *var, int z[8], int tabla[8][3], int numero_variables[], int n, char v1[2], char v2[2], char v3[2])
{
    int cont, k, i, j, contador=0;
    printf("\n");
    printf("  %s   %s   %s    Z\n\n", v1, v2, v3);
    for(i=0; i<8; i++)
    {
        z[i]=0;
        for(k=0; k<n; k++)
        {
            cont=0;
            for(j=0; j<3; j++)
            {
                if(var[k].val[j]==0 && tabla[i][j]==0)
                    cont++;
                if(var[k].val[j]==1 && tabla[i][j]==1)
                    cont++;
            }
            if(cont==numero_variables[k])
            {
                z[i]=1;
                k=n;
            }
        }
        for(j=0; j<3; j++)
            printf("%3d ", tabla[i][j]);
        printf("|%3d", z[i]);
        printf("\n");
    }
}
void mapa_3_Variables(int mapa[2][4], int z[8], char v1[2], char v2[2], char v3[2])
{
    int i, j, cont=0;
    for(i=0; i<2; i++)
    {
        for(j=0; j<4; j++)
        {
            if(j!=2 && j!=3)
            {
                mapa[i][j]=z[cont];
            }
            if(j==2)
                mapa[i][j]=z[cont+1];
            if(j==3)
                mapa[i][j]=z[cont-1];
            cont++;
        }
    }
    printf("\n%s/%s%s  00   01   11   10\n\n", v1, v2, v3);
    for(i=0; i<2; i++)
    {
        if(i==0)
            printf("0   ");
        if(i==1)
            printf("1   ");
        for(j=0; j<4; j++)
        {
            printf("%3d  ", mapa[i][j]);
        }
        printf("\n");
    }
printf("\n\n");
}
void Var3_Grupos_de_4(int mapa[2][4], int contador[20], char expresion_final[100])
{
       if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[1][0]==1 && mapa[1][1]==1)
       {
            contador[0]=1;
            strcat(expresion_final, "-B+");
       }
       if(mapa[0][3]==1 && mapa[0][2]==1 && mapa[1][3]==1 && mapa[1][2]==1)
       {
            contador[1]=1;
            strcat(expresion_final, "B+");
       }

       if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[0][3]==1 && mapa[0][2]==1)
       {
            contador[2]=1;
            strcat(expresion_final, "-A+");
       }
       if(mapa[1][0]==1 && mapa[1][1]==1 && mapa[1][3]==1 && mapa[1][2]==1)
       {
            contador[3]=1;
            strcat(expresion_final, "A+");
       }
       if(mapa[0][0]==1 && mapa[0][3]==1 && mapa[1][0]==1 && mapa[1][3]==1)
       {
            contador[4]=1;
            strcat(expresion_final, "-C+");
       }
       if(mapa[0][1]==1 && mapa[0][2]==1 && mapa[1][2]==1 && mapa[1][1]==1)
       {
            contador[5]=1;
            strcat(expresion_final, "C+");
       }
}
void Var3_Grupos_de_2(int mapa[2][4], int contador[20], char expresion_final[100])
{
       if(mapa[0][0]==1 && mapa[1][0]==1 && contador[4]!=1 && contador[0]!=1)
       {
            contador[6]=1;
            strcat(expresion_final, "-B-C+");
       }
       if(mapa[0][1]==1 && mapa[1][1]==1 && contador[5]!=1 && contador[0]!=1)
       {
            contador[7]=1;
            strcat(expresion_final, "-BC+");
       }
       if(mapa[0][2]==1 && mapa[1][2]==1 && contador[5]!=1 && contador[1]!=1)
       {
            contador[8]=1;
            strcat(expresion_final, "BC+");
       }
       if(mapa[0][3]==1 && mapa[1][3]==1 && contador[4]!=1 && contador[1]!=1)
       {
            contador[9]=1;
            strcat(expresion_final, "B-C+");
       }
       if(mapa[0][0]==1 && mapa[0][1]==1 && contador[2]!=1 && contador[0]!=1)
       {
            contador[10]=1;
            strcat(expresion_final, "-A-B+");
       }
       if(mapa[0][2]==1 && mapa[0][3]==1 && contador[2]!=1 && contador[1]!=1)
       {
            contador[11]=1;
            strcat(expresion_final, "-AB+");
       }
       if(mapa[1][2]==1 && mapa[1][3]==1 && contador[3]!=1 && contador[1]!=1)
       {
            contador[12]=1;
            strcat(expresion_final, "AB+");
       }
       if(mapa[1][0]==1 && mapa[1][1]==1 && contador[3]!=1 && contador[0]!=1)
       {
            contador[13]=1;
            strcat(expresion_final, "A-B+");
       }
       if(mapa[0][2]==1 && mapa[0][1]==1 && contador[2]!=1 && contador[5]!=1)
       {
           strcat(expresion_final, "-AC+");
       }
       if(mapa[1][1]==1 && mapa[1][2]==1 && contador[3]!=1 && contador[5]!=1)
       {
           strcat(expresion_final, "AC+");
       }
       if(mapa[0][0]==1 && mapa[0][3]==1 && contador[2]!=1 && contador[4]!=1)
       {
           strcat(expresion_final, "-A-C+");
       }
       if(mapa[1][3]==1 && mapa[1][0]==1 && contador[3]!=1 && contador[4]!=1)
       {
           strcat(expresion_final, "A-C+");
       }
}
void Var3_Grupos_de_1(int mapa[2][4], char expresion_final[100])
{
    if(mapa[0][1]==0 && mapa[1][0]==0 && mapa[0][0]==1 && mapa[0][3]==0)
    {
        strcat(expresion_final, "-A-B-C+");
    }
       if(mapa[0][0]==0 && mapa[1][1]==0 && mapa[0][1]==1 && mapa[0][2]==0)
       {
           strcat(expresion_final, "-A-BC+");
       }
       if(mapa[0][1]==0 && mapa[0][3]==0 && mapa[0][2]==1 && mapa[1][2]==0)
       {
           strcat(expresion_final, "-ABC+");
       }
       if(mapa[0][2]==0 && mapa[1][3]==0 && mapa[0]==0 && mapa[0][3]==1)
       {
           strcat(expresion_final, "-AB-C+");
       }
       if(mapa[0][0]==0 && mapa[1][0]==1 && mapa[1][3]==0 && mapa[1][1]==0)
       {
           strcat(expresion_final, "A-B-C+");
       }
       if(mapa[0][1]==0 && mapa[1][0]==0 && mapa[1][1]==1 && mapa[1][2]==0)
       {
           strcat(expresion_final, "A-BC+");
       }
       if(mapa[0][2]==0 && mapa[1][1]==0 && mapa[1][3]==0 && mapa[1][2]==1)
       {
           strcat(expresion_final, "ABC+");
       }
       if(mapa[0][3]==0 && mapa[1][0]==0 && mapa[1][3]==1 && mapa[1][2]==0)
       {
           strcat(expresion_final, "AB-C+");
       }
}
void mostrarReduccion_3(char expresion_final[100], char Reduccion[100], char v1[2], char v2[2], char v3[2])
{
    int i;
    char aux[100];
    strcpy(aux, "");
    for(i=0; expresion_final[i]!='\0'; i++)
    {
        if(expresion_final[i]=='-')
            strcat(aux, "-");
        if(expresion_final[i]=='+')
            strcat(aux, "+");
        if(expresion_final[i]=='A')
            strcat(aux, v1);
        if(expresion_final[i]=='B')
            strcat(aux, v2);
        if(expresion_final[i]=='C')
            strcat(aux, v3);
    }
    printf("\nZ = ");
    for(i=0; aux[i]!='\0'; i++)
    {
        if(aux[i+1]!='\0')
        {
            Reduccion[i]=aux[i];
            printf("%c", Reduccion[i]);
        }
    }
}



void Variables_4()
{
    Datos *var;
    int i, n=0, z[16], mapa[4][4];
    int tabla[16][4]={0, 0, 0, 0,
                      0, 0, 0, 1,
                      0, 0, 1, 0,
                      0, 0, 1, 1,
                      0, 1, 0, 0,
                      0, 1, 0, 1,
                      0, 1, 1, 0,
                      0, 1, 1, 1,
                      1, 0, 0, 0,
                      1, 0, 0, 1,
                      1, 0, 1, 0,
                      1, 0, 1, 1,
                      1, 1, 0, 0,
                      1, 1, 0, 1,
                      1, 1, 1, 0,
                      1, 1, 1, 1};
    var=(Datos *) calloc(25, sizeof(Datos));
    char expresion[100], expresion_final[100], Reduccion[100];
    char varnormal_1[2], varnegada_1[3], varnormal_2[2], varnegada_2[3], varnormal_3[2], varnegada_3[3], varnormal_4[2], varnegada_4[3];
    capturar_4(expresion, varnormal_1, varnegada_1, varnormal_2, varnegada_2, varnormal_3, varnegada_3, varnormal_4, varnegada_4);
    strcpy(Reduccion, "");
    strcpy(expresion_final, "");
    for(i=0; i<strlen(expresion); i++)
    {
        if(expresion[i]==varnormal_1[0] && expresion[i-1]=='-')
            strcpy(var[n].var1, varnegada_1);
        if(expresion[i]==varnormal_1[0] && expresion[i-1]!='-')
            strcpy(var[n].var1, varnormal_1);
        if(expresion[i]=='-' && expresion[i+1]==varnormal_2[0])
            strcpy(var[n].var2, varnegada_2);
        if(expresion[i]==varnormal_2[0] && expresion[i-1]!='-')
            strcpy(var[n].var2, varnormal_2);
        if(expresion[i]=='-' && expresion[i+1]==varnormal_3[0])
            strcpy(var[n].var3, varnegada_3);
        if(expresion[i]==varnormal_3[0] && expresion[i-1]!='-')
            strcpy(var[n].var3, varnormal_3);
        if(expresion[i]=='-' && expresion[i+1]==varnormal_4[0])
            strcpy(var[n].var4, varnegada_4);
        if(expresion[i]==varnormal_4[0] && expresion[i-1]!='-')
            strcpy(var[n].var4, varnormal_4);
        if(expresion[i]=='+')
            n++;
    }
    n++;
    int numero_variables[n];
    for(i=0; i<n; i++)
        numero_variables[i]=4;

    for(i=0; i<n; i++)
    {
        if(strcmp(var[i].var1, varnormal_1)==0)
            var[i].val[0]=1;
        if(strcmp(var[i].var1, varnegada_1)==0)
            var[i].val[0]=0;
        if(strcmp(var[i].var2, varnormal_2)==0)
            var[i].val[1]=1;
        if(strcmp(var[i].var2, varnegada_2)==0)
            var[i].val[1]=0;
        if(strcmp(var[i].var3, varnormal_3)==0)
            var[i].val[2]=1;
        if(strcmp(var[i].var3, varnegada_3)==0)
            var[i].val[2]=0;
        if(strcmp(var[i].var4, varnormal_4)==0)
            var[i].val[3]=1;
        if(strcmp(var[i].var4, varnegada_4)==0)
            var[i].val[3]=0;
        if(strcmp(var[i].var1, "")==0)
        {
            numero_variables[i]--;
            var[i].val[0]=2;
        }
        if(strcmp(var[i].var2, "")==0)
        {
            numero_variables[i]--;
            var[i].val[1]=2;
        }
        if(strcmp(var[i].var3, "")==0)
        {
            numero_variables[i]--;
            var[i].val[2]=2;
        }
        if(strcmp(var[i].var4, "")==0)
         {
             numero_variables[i]--;
             var[i].val[3]=2;
         }
    }
    int contador[100], num_de_1s=0, j;
    for(i=0; i<100; i++)
            contador[i]=0;
    printf("\t\tTABLA DE VERDAD \n\n");
    llenartabla_4(var, z, tabla, numero_variables, n, varnormal_1, varnormal_2, varnormal_3, varnormal_4);
    printf("\t\tMAPA DE KARNAUGH \n\n");
    mapa4variables(mapa, z, varnormal_1, varnormal_2, varnormal_3, varnormal_4);
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(mapa[i][j]==1)
            num_de_1s++;
        }
    }
    if(num_de_1s==16)
    {
        strcat(Reduccion, "1");
        printf("\t\tEXPRESION SIMPLIFICADA\n");
        printf("Z = ");
        printf("%s", Reduccion);
    }
    if(num_de_1s!=16)
    {
        Var4_Reducir_Expresion_8(mapa, expresion_final, contador);
        Var4_Reducir_Expresion_4(mapa, expresion_final, contador);
        Var4_Reducir_Expresion_2(mapa, expresion_final, contador);
        Var4_Reducir_Expresion_1(mapa, expresion_final);
        printf("\t\tEXPRESION SIMPLIFICADA\n");
        mostrarReduccion_4(expresion_final, Reduccion, varnormal_1, varnormal_2, varnormal_3, varnormal_4);
    }

}
void capturar_4(char expresion[100], char varnormal_1[2], char varnegada_1[3], char varnormal_2[2], char varnegada_2[3], char varnormal_3[2], char varnegada_3[3], char varnormal_4[2], char varnegada_4[3])
{
    int i, cont=0;
    printf("A continuacion ingresara la variables que va a usar...\n");
    printf("(Por favor ingresar las variables a usar en orden para que obtenga resultados correctos)\n");
    do{
            printf("Ingrese primera variable a usar: ");
            scanf("%s", varnormal_1);
            for(i=0; varnormal_1[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
    }while(i!=1);
    do{
            printf("Ingrese segunda variable a usar: ");
            scanf("%s", varnormal_2);
            for(i=0; varnormal_2[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
            if(strcmp(varnormal_2, varnormal_1)==0)
                printf("La variables no puede ser iguales\n");
    }while(i!=1 || strcmp(varnormal_2, varnormal_1)==0);
    do{
            printf("Ingrese tercera variable a usar: ");
            scanf("%s", varnormal_3);
            for(i=0; varnormal_3[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
            if(strcmp(varnormal_3, varnormal_1)==0 || strcmp(varnormal_3, varnormal_2)==0)
                printf("La variables no puede ser iguales\n");
    }while(i!=1 || strcmp(varnormal_3, varnormal_1)==0 || strcmp(varnormal_3, varnormal_2)==0);
    do{
            printf("Ingrese cuarta variable a usar: ");
            scanf("%s", varnormal_4);
            for(i=0; varnormal_4[i]!='\0'; i++)
                continue;
            if(i!=1)
                printf("Solo puede usar un caracter para representar la variable \n");
            if(strcmp(varnormal_4, varnormal_1)==0 || strcmp(varnormal_4, varnormal_2)==0 || strcmp(varnormal_4, varnormal_3)==0)
                printf("La variables no puede ser iguales\n");
    }while(i!=1 || strcmp(varnormal_4, varnormal_1)==0 || strcmp(varnormal_4, varnormal_2)==0 || strcmp(varnormal_4, varnormal_3)==0);
    system("PAUSE");
    system("cls");
    printf("Las variables a usar son: \n%s, %s, %s y %s\n", varnormal_1, varnormal_2, varnormal_3, varnormal_4);
    strcpy(varnegada_1, "");
    strcpy(varnegada_2, "");
    strcpy(varnegada_3, "");
    strcpy(varnegada_4, "");
    strcat(varnegada_1, "-");
    strcat(varnegada_1, varnormal_1);
    strcat(varnegada_2, "-");
    strcat(varnegada_2, varnormal_2);
    strcat(varnegada_3, "-");
    strcat(varnegada_3, varnormal_3);
    strcat(varnegada_4, "-");
    strcat(varnegada_4, varnormal_4);
    do{
            printf("Ingresa la expresion (Aqui no importa el orden las variables) :\n");
            scanf("%s", expresion);
            cont=0;
            for(i=0; expresion[i]!='\0'; i++)
            {
                if(expresion[i]!='-' && expresion[i]!='+' && expresion[i]!=varnormal_1[0] && expresion[i]!=varnormal_2[0] && expresion[i]!=varnormal_3[0] && expresion[i]!=varnormal_4[0])
                    cont++;
            }
            if(cont!=0)
                printf("Ingresaste algun caracter invalido. Por favor vuelve a ingresar la expresion\n");
    }while(cont!=0);
    printf("\nZ = %s\n", expresion);
}
void llenartabla_4(Datos *var, int z[16], int tabla[16][4], int numero_variables[], int n, char v1[2], char v2[2], char v3[2], char v4[2])
{
    int cont, k, i, j, contador=0;
    printf("\n");
    printf("  %s   %s   %s   %s    Z\n\n", v1, v2, v3, v4);
    for(i=0; i<16; i++)
    {
        z[i]=0;
        for(k=0; k<n; k++)
        {
            cont=0;
            for(j=0; j<4; j++)
            {
                if(var[k].val[j]==0 && tabla[i][j]==0)
                    cont++;
                if(var[k].val[j]==1 && tabla[i][j]==1)
                    cont++;
            }
            if(cont==numero_variables[k])
            {
                k=n;
                z[i]=1;
            }
        }
        for(j=0; j<4; j++)
            printf("%3d ", tabla[i][j]);
        printf("|%3d", z[i]);
        printf("\n");
    }
}
void mapa4variables(int mapa[4][4], int z[16], char v1[2], char v2[2], char v3[2], char v4[2])
{
    int i, j, cont=0;
    printf("\n\n\n");
    printf("%s%s/%s%s  00  01  11  10\n\n", v1, v2, v3, v4);
    for(i=0; i<4; i++)
    {
        if(i==0)
            printf("00  ");
        if(i==1)
            printf("01  ");
        if(i==2)
            printf("11  ");
        if(i==3)
            printf("10  ");
        for(j=0; j<4; j++)
        {
            if(i!=2 && i!=3)
            {
                if(j!=2 && j!=3)
                    mapa[i][j]=z[cont];
                if(j==2)
                    mapa[i][j]=z[cont+1];
                if(j==3)
                    mapa[i][j]=z[cont-1];
            }
            if(i==2)
            {
                if(j!=3 && j!=2)
                    mapa[i][j]=z[cont+4];
                if(j==2)
                    mapa[i][j]=z[15];
                if(j==3)
                    mapa[i][j]=z[14];
            }
            if(i==3)
            {
                if(j!=3 && j!=2)
                    mapa[i][j]=z[cont-4];
                if(j==2)
                    mapa[i][j]=z[11];
                if(j==3)
                    mapa[i][j]=z[10];
            }
            cont++;
            printf("%3d  ", mapa[i][j]);
        }
        printf("\n");
    }
}
void Var4_Reducir_Expresion_8(int mapa[4][4], char expresion_final[100], int contador[100])
{
    if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[0][3]==1 && mapa[0][2]==1 && mapa[1][0]==1 && mapa[1][1]==1 && mapa[1][3]==1 && mapa[1][2]==1)
       {
            contador[0]=1;
            strcat(expresion_final, "-A+");
       }
       if(mapa[3][0]==1 && mapa[3][1]==1 && mapa[3][3]==1 && mapa[3][2]==1 && mapa[2][0]==1 && mapa[2][1]==1 && mapa[2][3]==1 && mapa[2][2]==1)
       {
            contador[1]=1;
            strcat(expresion_final, "A+");
        }
       if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[0][3]==1 && mapa[0][2]==1 && mapa[3][0]==1 && mapa[3][1]==1 && mapa[3][3]==1 && mapa[3][2]==1)
       {
            contador[2]=1;
            strcat(expresion_final, "-B+");
        }
       if(mapa[1][0]==1 && mapa[1][1]==1 && mapa[1][3]==1 && mapa[1][2]==1 && mapa[2][0]==1 && mapa[2][1]==1 && mapa[2][3]==1 && mapa[2][2]==1)
       {
            contador[3]=1;
            strcat(expresion_final, "B+");
       }
       if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[1][0]==1 && mapa[1][1]==1 && mapa[2][0]==1 && mapa[2][1]==1 && mapa[3][0]==1 && mapa[3][1]==1)
       {
            contador[4]=1;
            strcat(expresion_final, "-C+");
        }
       if(mapa[0][3]==1 && mapa[0][2]==1 && mapa[1][3]==1 && mapa[1][2]==1 && mapa[3][3]==1 && mapa[3][2]==1 && mapa[2][3]==1 && mapa[2][2]==1)
       {
            contador[5]=1;
            strcat(expresion_final, "C+");
       }
       if(mapa[0][0]==1 && mapa[0][3]==1 && mapa[1][0]==1 && mapa[1][3]==1 && mapa[3][0]==1 && mapa[3][3]==1 && mapa[2][0]==1 && mapa[2][3]==1)
       {
            contador[6]=1;
            strcat(expresion_final, "-D+");
       }
       if(mapa[0][1]==1 && mapa[0][2]==1 && mapa[1][1]==1 && mapa[1][2]==1 && mapa[3][1]==1 && mapa[3][2]==1 && mapa[2][1]==1 && mapa[2][2]==1)
       {
            contador[7]=1;
            strcat(expresion_final, "D+");
       }
}
void Var4_Reducir_Expresion_4(int mapa[4][4], char expresion_final[100], int contador[100])
{
    if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[0][3]==1 && mapa[0][2]==1 && contador[0]!=1 && contador[2]!=1)
    {
        contador[8]=1;
        strcat(expresion_final, "-A-B+");
    }
       if(mapa[1][0]==1 && mapa[1][1]==1 && mapa[1][3]==1 && mapa[1][2]==1 &&contador[0]!=1 && contador[3]!=1)
       {
            contador[9]=1;
            strcat(expresion_final, "-AB+");
       }
       if(mapa[2][0]==1 && mapa[2][1]==1 && mapa[2][3]==1 && mapa[2][2]==1 && contador[1]!=1 && contador[3]!=1)
       {
            contador[10]=1;
            strcat(expresion_final, "AB+");
       }
       if(mapa[3][0]==1 && mapa[3][1]==1 && mapa[3][3]==1 && mapa[3][2]==1 && contador[1]!=1 && contador[2]!=1)
       {
            contador[11]=1;
            strcat(expresion_final, "A-B+");
       }
       if(mapa[0][0]==1 && mapa[1][0]==1 && mapa[3][0]==1 && mapa[2][0]==1 && contador[4]!=1 && contador[6]!=1)
       {
            contador[12]=1;
            strcat(expresion_final, "-C-D+");
       }
       if(mapa[0][1]==1 && mapa[1][1]==1 && mapa[3][1]==1 && mapa[2][1]==1 && contador[4]!=1 && contador[7]!=1)
       {
            contador[13]=1;
            strcat(expresion_final, "-CD+");
       }
       if(mapa[0][2]==1 && mapa[1][2]==1 && mapa[3][2]==1 && mapa[2][2]==1 && contador[7]!=1 && contador[5]!=1)
       {
            contador[14]=1;
            strcat(expresion_final, "CD+");
       }
       if(mapa[0][3]==1 && mapa[1][3]==1 && mapa[3][3]==1 && mapa[2][3]==1 && contador[5]!=1&&contador[6]!=1)
       {
            contador[15]=1;
            strcat(expresion_final, "C-D+");
       }
       if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[1][0]==1 && mapa[1][1]==1 && contador[0]!=1 && contador[4]!=1)
       {
            contador[16]=1;
            strcat(expresion_final, "-A-C+");
       }
       if(mapa[0][1]==1 && mapa[0][2]==1 && mapa[1][1]==1 && mapa[1][2]==1 && contador[0]!=1 && contador[7]!=1)
       {
            contador[17]=1;
            strcat(expresion_final, "-AD+");
       }
       if(mapa[0][3]==1 && mapa[0][2]==1 && mapa[1][3]==1 && mapa[1][2]==1 && contador[0]!=1 && contador[5]!=1)
       {
            contador[18]=1;
            strcat(expresion_final, "-AC+");
       }
       if(mapa[0][0]==1 && mapa[0][3]==1 && mapa[1][0]==1 && mapa[1][3]==1 && contador[0]!=1 && contador[6]!=1)
       {
            contador[19]=1;
            strcat(expresion_final, "-A-D+");
       }
       if(mapa[1][0]==1 && mapa[1][1]==1 && mapa[2][0]==1 && mapa[2][1]==1 &&contador[3]!=1 && contador[4]!=1)
       {
            contador[20]=1;
            strcat(expresion_final, "B-C+");
       }
       if(mapa[1][1]==1 && mapa[1][2]==1 && mapa[2][1]==1 && mapa[2][2]==1 && contador[3]!=1 && contador[7]!=1)
       {
            contador[21]=1;
            strcat(expresion_final, "BD+");
       }
       if(mapa[1][3]==1 && mapa[1][2]==1 && mapa[2][3]==1 && mapa[2][2]==1 && contador[3]!=1 && contador[5]!=1)
       {
            contador[22]=1;
            strcat(expresion_final, "BC+");
       }
       if(mapa[1][0]==1 && mapa[1][3]==1 && mapa[2][0]==1 && mapa[2][3]==1 && contador[3]!=1 && contador[6]!=1)
       {
            contador[23]=1;
            strcat(expresion_final, "B-D+");
       }
       if(mapa[3][0]==1 && mapa[3][1]==1 && mapa[2][0]==1 && mapa[2][1]==1 && contador[1]!=1 && contador[4]!=1)
       {
            contador[24]=1;
            strcat(expresion_final, "A-C+");
       }
       if(mapa[3][1]==1 && mapa[3][2]==1 && mapa[2][1]==1 && mapa[2][2]==1 && contador[1]!=1 && contador[7]!=1)
       {
            contador[25]=1;
            strcat(expresion_final, "AD+");
       }
       if(mapa[3][3]==1 && mapa[3][2]==1 && mapa[2][3]==1 && mapa[2][2]==1 && contador[1]!=1 && contador[5]!=1)
       {
            contador[26]=1;
            strcat(expresion_final, "AC+");
       }
       if(mapa[3][0]==1 && mapa[3][3]==1 && mapa[2][0]==1 && mapa[2][3]==1 && contador[1]!=1 && contador[6]!=1)
       {
            contador[27]=1;
            strcat(expresion_final, "A-D+");
       }
       if(mapa[0][0]==1 && mapa[0][1]==1 && mapa[3][0]==1 && mapa[3][1]==1 && contador[2]!=1 && contador[4]!=1)
       {
            contador[28]=1;
            strcat(expresion_final, "-B-C+");
       }
       if(mapa[0][1]==1 && mapa[0][2]==1 && mapa[3][1]==1 && mapa[3][2]==1 && contador[2]!=1&&contador[7]!=1)
       {
            contador[29]=1;
            strcat(expresion_final, "-BD+");
       }
       if(mapa[0][3]==1 && mapa[0][2]==1 && mapa[3][3]==1 && mapa[3][2]==1 && contador[2]!=1 && contador[5]!=1)
       {
            contador[30]=1;
            strcat(expresion_final, "-BC+");
       }
       if(mapa[0][0]==1 && mapa[0][3]==1 && mapa[3][0]==1 && mapa[3][3]==1 && contador[2]!=1 && contador[6]!=1)
       {
            contador[31]=1;
            strcat(expresion_final, "-B-D+");
       }
}
void Var4_Reducir_Expresion_2(int mapa[4][4], char expresion_final[100], int contador[100])
{
    if(mapa[0][0]==1 && mapa[0][1]==1 && contador[8]!=1 && contador[16]!=1 && contador[28]!=1 && contador[0]!=1 && contador[2]!=1 && contador[4]!=1)
       {
            contador[32]=1;
            strcat(expresion_final, "-A-B-C+");
        }
       if(mapa[0][1]==1 && mapa[0][2]==1 && contador[8]!=1 && contador[17]!=1 && contador[29]!=1 && contador[0]!=1 && contador[2]!=1 && contador[7]!=1)
       {
            contador[33]=1;
            strcat(expresion_final, "-A-BD+");
       }
       if(mapa[0][3]==1 && mapa[0][2]==1 && contador[8]!=1 && contador[18]!=1 && contador[30]!=1 && contador[0]!=1 && contador[2]!=1 && contador[5]!=1)
       {
            contador[34]=1;
            strcat(expresion_final, "-A-BC+");
       }
        if(mapa[0][0]==1 && mapa[0][3]==1 && contador[8]!=1 && contador[19]!=1 && contador[31]!=1 && contador[0]!=1 && contador[2]!=1 && contador[6]!=1)
       {
            contador[35]=1;
            strcat(expresion_final, "-A-B-D+");
       }
        if(mapa[1][0]==1 && mapa[1][1]==1 && contador[9]!=1 && contador[16]!=1 && contador[20]!=1 && contador[0]!=1 && contador[3]!=1 && contador[4]!=1)
       {
            contador[36]=1;
            strcat(expresion_final, "-AB-C+");
       }
       if(mapa[1][1]==1 && mapa[1][2]==1 && contador[9]!=1 && contador[17]!=1 && contador[21]!=1 && contador[0]!=1 && contador[3]!=1 && contador[7]!=1)
       {
            contador[37]=1;
            strcat(expresion_final, "-ABD+");
       }
       if(mapa[1][3]==1 && mapa[1][2]==1 && contador[9]!=1 && contador[18]!=1 && contador[22]!=1 && contador[0]!=1 && contador[3]!=1 && contador[5]!=1)
       {
            contador[38]=1;
            strcat(expresion_final, "-ABC+");
       }
       if(mapa[1][0]==1 && mapa[1][3]==1 && contador[9]!=1 && contador[19]!=1&&contador[23]!=1&&contador[0]!=1&&contador[3]!=1&&contador[6]!=1)
       {
            contador[39]=1;
            strcat(expresion_final, "-AB-D+");
       }
       if(mapa[2][0]==1 && mapa[2][1]==1 && contador[10]!=1 && contador[20]!=1 && contador[24]!=1 && contador[1]!=1 && contador[3]!=1 && contador[4]!=1)
       {
            contador[40]=1;
            strcat(expresion_final, "AB-C+");
       }
       if(mapa[2][1]==1 && mapa[2][2]==1 && contador[10]!=1 && contador[21]!=1 && contador[25]!=1 && contador[1]!=1 && contador[3]!=1 && contador[7]!=1)
       {
            contador[41]=1;
            strcat(expresion_final, "ABD+");
       }
       if(mapa[2][3]==1 && mapa[2][2]==1 && contador[10]!=1&&contador[22]!=1&&contador[26]!=1&&contador[5]!=1&&contador[3]!=1&&contador[1]!=1)
       {
            contador[42]=1;
            strcat(expresion_final, "ABC+");
       }
       if(mapa[2][0]==1 && mapa[2][3]==1 && contador[10]!=1&&contador[23]!=1&&contador[27]!=1&&contador[1]!=1&&contador[6]!=1&&contador[3]!=1)
       {
            contador[43]=1;
            strcat(expresion_final, "AB-D+");
       }
       if(mapa[3][0]==1 && mapa[3][1]==1 && contador[11]!=1&&contador[24]!=1&&contador[28]!=1&&contador[1]!=1&&contador[2]!=1&&contador[4]!=1)
       {
            contador[44]=1;
            strcat(expresion_final, "A-B-C+");
       }
       if(mapa[3][1]==1 && mapa[3][2]==1 && contador[11]!=1 && contador[25]!=1 && contador[29]!=1 && contador[7]!=1 && contador[2]!=1 && contador[1]!=1)
       {
            contador[45]=1;
            strcat(expresion_final, "A-BD+");
       }
       if(mapa[3][3]==1 && mapa[3][2]==1 && contador[11]!=1&&contador[26]!=1&&contador[30]!=1&&contador[1]!=1&&contador[2]!=1&&contador[5]!=1)
       {
            contador[46]=1;
            strcat(expresion_final, "A-BC+");
       }
       if(mapa[3][0]==1 && mapa[3][3]==1 && contador[11]!=1&&contador[27]!=1&&contador[31]!=1&&contador[6]!=1&&contador[2]!=1&&contador[1]!=1)
       {
            contador[47]=1;
            strcat(expresion_final, "A-B-D+");
       }
       if(mapa[0][0]==1 && mapa[1][0]==1 && contador[12]!=1 && contador[16]!=1 && contador[19]!=1 && contador[0]!=1 && contador[6]!=1 && contador[4]!=1)
       {
            contador[48]=1;
            strcat(expresion_final, "-A-C-D+");
       }
       if(mapa[1][0]==1 && mapa[2][0]==1 && contador[12]!=1&&contador[20]!=1&&contador[23]!=1&&contador[3]!=1&&contador[6]!=1&&contador[4]!=1)
       {
            contador[49]=1;
            strcat(expresion_final, "B-C-D+");
       }
       if(mapa[3][0]==1 && mapa[2][0]==1 && contador[12]!=1 && contador[24]!=1 && contador[27]!=1 && contador[1]!=1 && contador[6]!=1 && contador[4]!=1)
       {
            contador[50]=1;
            strcat(expresion_final, "A-C-D+");
       }
       if(mapa[0][0]==1 && mapa[3][0]==1 && contador[12]!=1 && contador[28]!=1 && contador[31]!=1 && contador[6]!=1 && contador[2]!=1 && contador[4]!=1)
       {
            contador[51]=1;
            strcat(expresion_final, "-B-C-D+");
       }
       if(mapa[0][1]==1 && mapa[1][1]==1 && contador[13]!=1 && contador[16]!=1 && contador[17]!=1 && contador[0]!=1 && contador[7]!=1 && contador[4]!=1)
       {
            contador[52]=1;
            strcat(expresion_final, "-A-CD+");
       }
       if(mapa[1][1]==1 && mapa[2][1]==1 && contador[13]!=1 && contador[20]!=1 && contador[21]!=1 && contador[3]!=1 && contador[7]!=1 && contador[4]!=1)
       {
            contador[53]=1;
            strcat(expresion_final, "B-CD+");
       }
       if(mapa[3][1]==1 && mapa[2][1]==1 && contador[13]!=1 && contador[24]!=1 && contador[25]!=1 && contador[1]!=1 && contador[7]!=1 && contador[4]!=1)
       {
            contador[54]=1;
            strcat(expresion_final, "A-CD+");
       }
       if(mapa[0][1]==1 && mapa[3][1]==1 && contador[13]!=1 && contador[28]!=1 && contador[29]!=1 && contador[7]!=1 && contador[2]!=1 && contador[4]!=1)
       {
            contador[55]=1;
            strcat(expresion_final, "-B-CD+");
       }
       if(mapa[0][2]==1 && mapa[1][2]==1 && contador[14]!=1 && contador[17]!=1 && contador[18]!=1 && contador[5]!=1 && contador[7]!=1 && contador[0]!=1)
       {
            contador[56]=1;
            strcat(expresion_final, "-ACD+");
       }
       if(mapa[1][2]==1 && mapa[2][2]==1 && contador[14]!=1 && contador[21]!=1 && contador[22]!=1 && contador[5]!=1 && contador[7]!=1 && contador[3]!=1)
       {
            contador[57]=1;
            strcat(expresion_final, "BCD+");
       }
       if(mapa[3][2]==1 && mapa[2][2]==1 && contador[14]!=1 && contador[25]!=1 && contador[26]!=1 && contador[5]!=1 && contador[7]!=1 && contador[1]!=1)
       {
            contador[58]=1;
            strcat(expresion_final, "ACD+");
       }
       if(mapa[0][2]==1 && mapa[3][2]==1 && contador[14]!=1 && contador[29]!=1 && contador[30]!=1 && contador[5]!=1 && contador[2]!=1 && contador[7]!=1)
       {
            contador[59]=1;
            strcat(expresion_final, "-BCD+");
       }
       if(mapa[0][3]==1 && mapa[1][3]==1 && contador[15]!=1 && contador[18]!=1 && contador[19]!=1 && contador[0]!=1 && contador[6]!=1 && contador[5]!=1)
       {
            contador[60]=1;
            strcat(expresion_final, "-AC-D+");
       }
       if(mapa[1][3]==1 && mapa[2][3]==1 && contador[15]!=1 && contador[22]!=1 && contador[23]!=1 && contador[5]!=1 && contador[6]!=1 && contador[3]!=1)
       {
            contador[61]=1;
            strcat(expresion_final, "BC-D+");
       }
       if(mapa[3][3]==1 && mapa[2][3]==1 && contador[15]!=1 && contador[26]!=1 && contador[27]!=1 && contador[1]!=1 && contador[6]!=1 && contador[5]!=1)
       {
            contador[62]=1;
            strcat(expresion_final, "AC-D+");
       }
       if(mapa[0][3]==1 && mapa[3][3]==1 && contador[15]!=1 && contador[30]!=1 && contador[31]!=1 && contador[5]!=1 && contador[2]!=1 && contador[6]!=1)
       {
            contador[63]=1;
            strcat(expresion_final, "-BC-D+");
       }
}
void Var4_Reducir_Expresion_1(int mapa[4][4], char expresion_final[100])
{
       if(mapa[0][0]==1 && mapa[0][1]==0 && mapa[0][3]==0 && mapa[1][0]==0 && mapa[3][0]==0)
            strcat(expresion_final, "-A-B-C-D+");
       if(mapa[0][1]==1 && mapa[0][0]==0 && mapa[0][2]==0 && mapa[1][1]==0 && mapa[3][1]==0)
            strcat(expresion_final, "-A-B-CD+");
       if(mapa[0][3]==1 && mapa[0][0]==0 && mapa[0][2]==0 && mapa[1][3]==0 && mapa[3][3]==0)
            strcat(expresion_final, "-A-BC-D+");
       if(mapa[0][2]==1 && mapa[0][1]==0 && mapa[0][3]==0 && mapa[1][2]==0 && mapa[3][2]==0)
            strcat(expresion_final, "-A-BCD+");
       if(mapa[1][0]==1 && mapa[0][0]==0 && mapa[1][1]==0 && mapa[1][3]==0 && mapa[2][0]==0)
            strcat(expresion_final, "-AB-C-D+");
       if(mapa[1][1]==1 && mapa[0][1]==0 && mapa[1][0]==0 && mapa[1][2]==0 && mapa[2][1]==0)
            strcat(expresion_final, "-AB-CD+");
       if(mapa[1][3]==1 && mapa[0][3]==0 && mapa[1][0]==0 && mapa[1][2]==0 && mapa[2][3]==0)
            strcat(expresion_final, "-ABC-D+");
       if(mapa[1][2]==1 && mapa[0][2]==0 && mapa[1][1]==0 && mapa[1][3]==0 && mapa[2][2]==0)
            strcat(expresion_final, "-ABCD+");
       if(mapa[3][0]==1 && mapa[0][0]==0 && mapa[3][1]==0 && mapa[3][3]==0 && mapa[2][0]==0)
            strcat(expresion_final, "A-B-C-D+");
       if(mapa[3][1]==1 && mapa[0][1]==0 && mapa[3][0]==0 && mapa[3][2]==0 && mapa[2][1]==0)
            strcat(expresion_final, "A-B-CD+");
       if(mapa[3][3]==1 && mapa[0][3]==0 && mapa[3][0]==0 && mapa[3][2]==0 && mapa[2][3]==0)
            strcat(expresion_final, "A-BC-D+");
       if(mapa[3][2]==1 && mapa[0][2]==0 && mapa[3][1]==0 && mapa[3][3]==0 && mapa[2][2]==0)
            strcat(expresion_final, "A-BCD+");
       if(mapa[2][0]==1 && mapa[1][0]==0 && mapa[3][0]==0 && mapa[2][1]==0 && mapa[2][3]==0)
            strcat(expresion_final, "AB-C-D+");
       if(mapa[2][1]==1 && mapa[1][1]==0 && mapa[3][1]==0 && mapa[2][0]==0 && mapa[2][2]==0)
            strcat(expresion_final, "AB-CD+");
       if(mapa[2][3]==1 && mapa[1][3]==0 && mapa[3][3]==0 && mapa[2][0]==0 && mapa[2][2]==0)
            strcat(expresion_final, "ABC-D+");
       if(mapa[2][2]==1 && mapa[1][2]==0 && mapa[3][2]==0 && mapa[2][1]==0 && mapa[2][3]==0)
            strcat(expresion_final, "ABCD+");
}
mostrarReduccion_4(char expresion_final[100], char Reduccion[100], char v1[2], char v2[2], char v3[2], char v4[2])
{
    int i;
    char aux[100];
    strcpy(aux, "");
    for(i=0; expresion_final[i]!='\0'; i++)
    {
        if(expresion_final[i]=='-')
            strcat(aux, "-");
        if(expresion_final[i]=='+')
            strcat(aux, "+");
        if(expresion_final[i]=='A')
            strcat(aux, v1);
        if(expresion_final[i]=='B')
            strcat(aux, v2);
        if(expresion_final[i]=='C')
            strcat(aux, v3);
        if(expresion_final[i]=='D')
            strcat(aux, v4);
    }
    printf("\nZ = ");
    for(i=0; aux[i]!='\0'; i++)
    {
        if(aux[i+1]!='\0')
        {
            Reduccion[i]=aux[i];
            printf("%c", Reduccion[i]);
        }
    }
}
