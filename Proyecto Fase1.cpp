#include <iostream>
using namespace std;
const char *nombre_archivo= "traductor.dat";
void Crear();
void leer();
void actualizar();
void borrar();
struct traducir{
    char palabra[20];
    char traduccion[20];
    char funcionalidad[100];
};
void Crear(){
    FILE*archivo=fopen(nombre_archivo,"a+b");
    traducir Traducir;
    char res;
    do{
        fflush(stdin);
        cout<<"Ingrese Palabra: ";
        fflush(stdin);
        cin.getline(Traducir.palabra,20);
        cout<<"Ingrese su respectiva traduccion: ";
        cin.getline(Traducir.traduccion,20);
        fflush(stdin);
        cout<<"Ingrese su respectiva funcionalidad: ";
        cin.getline(Traducir.funcionalidad,100);


        fwrite(&Traducir,sizeof(traducir),1,archivo);
        cout<<"Desea ingresar otra palabra(S/N)";
        cin>>res;
        //system("cls");
    }while(res=='s' || res=='S');
    fclose(archivo);
};
void leer(){
    system("cls");
     FILE*archivo=fopen(nombre_archivo,"rb");
     if(!archivo){
           FILE*archivo=fopen(nombre_archivo,"w+b");
     }
     traducir Traducir;
     int id=0;
     fread(&Traducir,sizeof(traducir),1,archivo);
     cout<<"=========================================="<<endl;
     cout<<"ID"<<"|"<<"PALABRA"<<"|"<<"TRADUCCION"<<"|"<<"FUNCIONALIDAD"<<endl;
     do{
        cout<<id<<"|"<<Traducir.palabra<<"|"<<Traducir.traduccion<<"|"<<Traducir.funcionalidad<<endl;
        fread(&Traducir,sizeof(traducir),1,archivo);
        id+=1;
     }while(feof(archivo)==0);
     fclose(archivo);
};

void actualizar(){
    FILE* archivo = fopen(nombre_archivo,"r+b");
	traducir Traducir;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(traducir),SEEK_SET);
		fflush(stdin);
		cout<<"Ingrese Palabra: ";
		cin.getline(Traducir.palabra,20);
		fflush(stdin);
		cout<<"Ingrese Traduccion: ";
		cin.getline(Traducir.traduccion,20);
        fflush(stdin);
		cout<<"Ingrese su respectiva funcionalidad: ";
		cin.getline(Traducir.funcionalidad,100);
		fwrite(&Traducir,sizeof(traducir),1,archivo);
	fclose(archivo);
	leer();

};
void borrar(){
    const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	traducir Traducir;
	int id=0,id_n=0;
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	while(fread(&Traducir,sizeof(traducir),1,archivo)){
		if (id_n !=id ){
			fwrite(&Traducir,sizeof(traducir),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);

	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&Traducir,sizeof(traducir),1,archivo_temp)){
		fwrite(&Traducir,sizeof(traducir),1,archivo);

	}
    fclose(archivo);
	fclose(archivo_temp);
	leer();
};
