#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

int jumlah_data = 0;
struct data{
    int harga_kue,stock_kue;
    char jenis_kue[20];
    char nama_kue[20];
    bool visibilitas;
    struct data *next;
}*head = NULL,*tail = NULL;

void pushtail(int harga_kue,int stock_kue,char nama_kue[50],char jenis_kue[50],bool visibilitas)
{
    // temp = (struct data *)malloc(sizeof(struct data));/ /<-- extensi C 
    data *temp = (data *)malloc(sizeof(data)); //<-- ekstensi cpp
    //Data Int
    temp->harga_kue = harga_kue;
    temp->stock_kue = stock_kue;
    //Data Char
    strcpy(temp->nama_kue, nama_kue);
    strcpy(temp->jenis_kue, jenis_kue);
    //Data Bool
    temp->visibilitas =  visibilitas;

    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    ++jumlah_data;
    tail->next = NULL;
}
//###################### view_data part
void view()
{
	data *temp = head;
    int nomor = 1;
    
    system("clear");
    printf("\n| %2s | %-20s | %-9s | %-10s | %-6s | %-11s |\n","NO","NAMA KUE","JENIS KUE","HARGA","STOCK","VISIBILITAS");
	while (temp != NULL)
	{
        if(temp->visibilitas==true){
            printf("| %-2d | %-20s | %-9s | Rp.%-7d | %-6d | %-11s |",nomor,temp->nama_kue,temp->jenis_kue,temp->harga_kue,temp->stock_kue,"TRUE");
        }
        else{
            printf("| %-2d | %-20s | %-9s | Rp.%-7d | %-6d | %-11s |",nomor,temp->nama_kue,temp->jenis_kue,temp->harga_kue,temp->stock_kue,"FALSE");
        }
        puts(" ");
        ++nomor;
		temp = temp -> next;
	}
}
void view_result(){
    data *temp = head;
    int nomor = 1;
    
    system("clear");
    printf("\n| %2s | %-20s | %-9s | %-10s | %-6s |\n","NO","NAMA KUE","JENIS KUE","HARGA","STOCK");
	while (temp != NULL)
	{
        if(temp->visibilitas==true){
            printf("| %-2d | %-20s | %-9s | Rp.%-7d | %-6d |",nomor,temp->nama_kue,temp->jenis_kue,temp->harga_kue,temp->stock_kue);
            ++nomor;
            puts(" ");
        }
		temp = temp -> next;
	}   
}

int main_menu(){
    printf ("-----------------------------------------------------\n");
    printf ("PROGRAM STOCK KUE\n");
    printf ("-----------------------------------------------------\n");
    printf ("1. Menambahkan data\n");
    printf ("2. Mengedit data\n"); 
    printf ("3. Sortir\n");
    printf ("4. Visibilitas Data\n");
    printf ("5. Tampilan Data yang akan dimasukan di file\n");
    printf ("Selain itu, keluar\n");
    printf ("----------------------------------------------------\n");
    int masukan;
    printf("Pilih angka 1 - 5 = ");scanf("%d",&masukan);
    return masukan;
}
//###################### add_data part
bool tambah(){
    char nama_kue[50];
    char merit[50];
    char jenis_kue[50];
    int harga_kue,stock_kue,visibilitas_tanya;
    bool ulang,visibilitas_hasil;
    char ulang_edit_tanya[1];

    system("clear");
    printf(" ");fgets(nama_kue,20,stdin);fflush(stdin); //<-- Tumbal ... entah kenapa tidak mau mengambil string nya
    printf("Masukan nama kue = ");scanf("%[^\n]s",merit);
    printf("Masukan jenis kue (Ex. kering/basah) = ");scanf("%s",jenis_kue);
    printf("Masukan harga kue = ");scanf("%d",&harga_kue);
    printf("Masukan stock kue = ");scanf("%d",&stock_kue);
    do{
        printf("Masukan visibilitas data (1 True / 2 False) = ");
        scanf("%d",&visibilitas_tanya);
        if(visibilitas_tanya == 1){
            visibilitas_hasil = true;
        }else if(visibilitas_tanya == 2){
            visibilitas_hasil = false;
        }else{
            printf("Data hanya range 1 - 2 saja\n");
        }
    }while(visibilitas_tanya < 1 || visibilitas_tanya > 2 );
    printf("Setujukah dengan Masukan tersebut ?(Y/y untuk lanjut)");
    scanf("%s",ulang_edit_tanya);
    if(strcmp(ulang_edit_tanya,"y")==0 ||strcmp(ulang_edit_tanya,"Y")==0){
        ulang = false;
        pushtail(harga_kue,stock_kue,merit,jenis_kue,visibilitas_hasil);
        system("clear");
        printf("\n\nData Berhasil Ditambahkan !\n");
        getchar();
    }else{
        ulang = true;
    }
    return ulang;
}

void add_data(){
    bool ulang_tambah = true;
    bool ulang_edit = true;
    char  ulang_edit_tanya[1];
    //insert str counter
    while (ulang_edit != false){
        while (ulang_tambah != false){
            ulang_tambah=tambah();
        }
        printf("\n\nApakah ingin menambahkan data baru lagi ?(Y/y untuk lagi)");
        scanf("%s",ulang_edit_tanya);
        if (strcmp(ulang_edit_tanya,"y")==0 || strcmp(ulang_edit_tanya,"Y")==0){
            ulang_edit = true;
            ulang_tambah = true;
        }else{
            ulang_edit = false;
        }
    }
}
//###################### edit_data part
void tambah_kurang(){
    bool ulang_pilihan = true;
    int pilihan_data;
    while (ulang_pilihan == true){
        system("clear");
        view();
        printf("Pilih data ke berapa ?");
        scanf("%d",&pilihan_data);
        if (pilihan_data > jumlah_data|| pilihan_data < 1){
            system("clear");
            printf("Data tidak ada");
            getchar();
        }else{
            bool ulang_tambah_kurang = true;
            while(ulang_tambah_kurang == true){
                int pilihan_edit;
                system("clear");
                printf("1. Tambah stock\n");
                printf("2. Kurangi Stock\n");
                printf("Nomor selain itu keluar \n");
                scanf("%d",&pilihan_edit);
                data *temp = head;
                for(int i = 1;i<jumlah_data;++i){
                    temp = temp->next;
                }
                if(pilihan_edit == 1){
                    int jumlah_tambah = 1;
                    while (jumlah_tambah != 0){
                        printf("Masukan jumlah tambah (0 untuk keluar) = ");
                        scanf("%d",&jumlah_tambah);
                        temp->stock_kue = temp->stock_kue + jumlah_tambah;
                        printf("Jumlah kue = %d\n\n",temp->stock_kue);
                        }
                }else if(pilihan_edit == 2){
                    int jumlah_kurang = 1;
                    while(jumlah_kurang != 0){
                        printf("Masukan jumlah tambah (0 untuk keluar) = ");
                        scanf("%d",&jumlah_kurang);
                        temp->stock_kue = temp->stock_kue - jumlah_kurang;
                        printf("Jumlah kue = %d\n\n",temp->stock_kue);
                    }
                }else{
                    ulang_tambah_kurang = false;
                }
            }
            char ulang_pilihan_tanya[1];
            system("clear");
            printf("Kembali ke menu edit ?(Y/y untuk kembali) ");
            scanf("%s",ulang_pilihan_tanya);
            if(strcmp(ulang_pilihan_tanya,"y") == 0 || strcmp(ulang_pilihan_tanya,"Y") == 0){
                ulang_pilihan = false;
            }else{
                ulang_pilihan = true;
            }
        }
    }
}

void edit_kue_status(){
    bool ulang_pilihan = true;
    char ulang_pilihan_tanya[1],nama_kue[50];
    int pilihan_data,counter,nomor,visibilitas;
    while (ulang_pilihan == true){
        system("clear");
        view();
        printf("Pilih data ke berapa ?");
        scanf("%d",&pilihan_data);
        if (pilihan_data > jumlah_data || pilihan_data < 1){
            printf("Data tidak ada");
        }else{
            bool ulang_edit = true;
            char ulang_edit_tanya[1];
            data *temp = head;
            int visibilitas_tanya;
            for(int i = 1;i<pilihan_data;++i){
                temp = temp->next;
            }
            while (ulang_edit == true){
                printf(" ");fgets(nama_kue,50,stdin);fflush(stdin); //<-- Tumbal ... entah kenapa tidak mau mengambil string nya
                printf("Nama Kue = ");scanf("%[^\n]s",temp->nama_kue);
                printf("Jenis Kue = ");scanf("%s",temp->jenis_kue);
                printf("Harga Kue = ");scanf("%d",&temp->harga_kue);
                printf("Stock Kue = ");scanf("%d",&temp->stock_kue);
                do{
                    printf("Visibilitas (1.True 2.False) = ");scanf("%d",&visibilitas_tanya);
                    if (visibilitas_tanya < 1 || visibilitas_tanya > 2){
                        printf("Data hanya range 1 - 2 saja\n");
                    }else{
                        if(visibilitas_tanya == 1){
                        temp->visibilitas = true;
                        }else{
                            temp->visibilitas = false;
                        }
                    }
                }while (visibilitas_tanya < 1 || visibilitas_tanya > 2);
                printf ("Setuju Dengan perubahan di atas? (y/Y untuk setuju) ");scanf("%s",ulang_edit_tanya);
                if(strcmp(ulang_edit_tanya,"y")==0 || strcmp(ulang_edit_tanya,"Y") == 0){
                    ulang_edit = false;
                    puts("Data telah dirubah !");
                    system("clear");
                }
            }
            printf("Mau ulang program ini ?(y/Y untuk mengulang) ");scanf("%s",ulang_pilihan_tanya);
            if (strcmp(ulang_edit_tanya,"y")==0 || strcmp(ulang_edit_tanya,"Y") == 0){
                ulang_pilihan = true;
            }else{
                ulang_pilihan = false;
            }
        }
    }
}   

void edit_data(){
    bool ulang_pilihan = true;

    while (ulang_pilihan == true){
        int pilihan;
        char ulang_program_tanya[1],ulang_menu_tanya[1];
        system("clear");
        printf("1. Tambah Kurang Stock\n");
        printf("2. Edit Status Kue\n");
        printf("Nomor lain untuk kembali ke menu utama\n");
        scanf("%d",&pilihan);
        if(pilihan == 1){
            tambah_kurang();
        }else if(pilihan ==2){
            edit_kue_status();
        }else{
            ulang_pilihan = false;
        }
    }
}
//###################### sortir_data part
void termurah(){
    data *temp = (data *)malloc(sizeof(data));
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->harga_kue > temp->next->harga_kue){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("Press Enter ");
    getchar(); 
}
 
void termahal(){
    data *temp = (data *)malloc(sizeof(data));
    
    for(int i = 1; i<jumlah_data;++i){
        int temp_harga,temp_stock;
        char temp_nama[50],temp_jenis[50];
        bool temp_visibilitas;
        temp = head;
        while (temp->next != NULL){
            //data int
            temp_harga = temp->harga_kue;
            temp_stock = temp->stock_kue;
            //data char
            strcpy(temp_nama,temp->nama_kue);
            strcpy(temp_jenis,temp->jenis_kue);
            //data bool
            temp_visibilitas = temp->visibilitas;

            if(temp->harga_kue < temp->next->harga_kue){
                //switch place data temp ke temp selanjutnya
                //data int
                temp->harga_kue = temp->next->harga_kue;
                temp->stock_kue = temp->next->stock_kue;
                //data char
                strcpy(temp->nama_kue,temp->next->nama_kue);
                strcpy(temp->jenis_kue,temp->next->jenis_kue);
                //data bool
                temp->visibilitas = temp->next->visibilitas;
                
                //data temp next dengan data awal
                //data int
                temp->next->harga_kue = temp_harga;
                temp->next->stock_kue = temp_stock;
                //data char
                strcpy(temp->next->nama_kue,temp_nama);
                strcpy(temp->next->jenis_kue,temp_jenis);
                //data bool
                temp->next->visibilitas = temp_visibilitas;
            }
            //pemindahan ke data selanjutnya
            temp = temp -> next;
        }
    }
    puts("Data Berhasil di urutkan !\n");
    view();
    printf("Press Enter ");
    getchar(); 
}

void sortir_data(){
    bool ulang = true;
    int pilihan;
    char ulang_tanya[1];
    while (ulang == true){
        system("clear");
        printf("Sortir data menurut harga ter-\n");
        printf("1.Murah\n");
        printf("2.Mahal\n");
        printf("Nomor selain di atas maka kembali ke menu utama\n");
        printf("Pilihan anda = ");scanf("%d",&pilihan);
        if (pilihan == 1){
            termurah();
        }else if(pilihan == 2){
            termahal();
        }else{
            break;
        }
        printf("Kembali ke menu sortir ? (Y / y untuk kembali) ");scanf("%s",ulang_tanya);
        if(strcmp(ulang_tanya,"y") == 0 || strcmp(ulang_tanya,"Y")==0){
            ulang = true;
        }else{
            ulang = false;
        }
    }
}
//################### visibilitas part
void visibilitas(){
    bool ulang_pilihan = true;
    char ulang_pilihan_tanya[1];
    int pilihan_data;

    while (ulang_pilihan == true){
        view();
        printf("Pilih data keberapa yang ingin di edit visibilitas nya ? ");scanf("%d",&pilihan_data);
        if (pilihan_data > jumlah_data|| pilihan_data < 1){
            printf("Data tidak ada");
            system("clear");
        }else{
            bool ulang_program = true;
            int pilihan_visibilitas;
            data *temp = head;
            for(int i = 1;i<jumlah_data;++i){
                temp = temp->next;
            }
            while (ulang_program == true){
                printf("1. Visibilitas True\n");
                printf("2.Visibilitas False\n");
                printf("Pilihan anda = ");scanf("%d",&pilihan_visibilitas);
                if (pilihan_visibilitas < 1 || pilihan_visibilitas > 2){
                    printf("Nomor pilihan salah\n");
                }else if(pilihan_visibilitas == 1){
                    temp->visibilitas = true;
                    printf("Visibilitas telah diganti !\n");
                    view();
                    ulang_program = false;
                }else{
                    temp->visibilitas = false;
                    printf("Visibilitas telah diganti !\n");
                    view();
                    ulang_program = false;
                }
            }
            printf("Ingin mengulang ke menu utama ? (y/Y untuk kembali) ");scanf("%s",ulang_pilihan_tanya);
            if (strcmp(ulang_pilihan_tanya,"y") == 0 || strcmp(ulang_pilihan_tanya,"Y") == 0 ){
                ulang_pilihan = true;
            }else{
                ulang_pilihan = false;
            }
        }
    }
}
//################### main part
int main(){
    int pilihan = 1;
    
    while (pilihan >= 1 && pilihan <= 5){
        system("clear");
        view();
        puts("\n");
        pilihan = main_menu();
        if (pilihan == 1){
            add_data();
        }else if(pilihan == 2){
            edit_data();
        }else if(pilihan == 3){
            sortir_data();
        }else if(pilihan == 4){
            visibilitas();
        }else if (pilihan == 5){
            view_result();
            puts("Press Enter");
            getchar();getchar();
        }
    }
}
