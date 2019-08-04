#include <stdio.h>
#include <stdlib.h>
#define METHOD_2 0

typedef enum
{
    SRC_FILE,
    DES_FILE
}file_type;

#if METHOD_2
typedef struct
{
    char* src_file;
    char* des_file;
    void(*copy_func_ptr)();
}copy_file_struct;
#endif // METHOD_2

int check_file_exist(const char* file_name);
void copy_file(const char* desti_file, const char* in_file_name);
void _main_copy_1();
//void set_file_name(char enumtype,char* file_name);
#if METHOD_2
void intitiate_struct();
void print_file();
copy_file_struct copy_struct;
#endif // METHOD_2


int main()
{
    _main_copy_1();
#if METHOD_2
    intitiate_struct();
    copy_struct.copy_func_ptr();
#endif // METHOD_2
    return 0;
}
void _main_copy_1()
{
    char* input_file_name = "test.txt";
    char* desti_file__name = "copy_name.txt";
    /*
    set_file_name(SRC_FILE,"test.txt");
    set_file_name(DES_FILE,"copy_name.txt");
    */
    if(0==check_file_exist(input_file_name))return;
    if(0==check_file_exist(desti_file__name))return;

    copy_file(desti_file__name,input_file_name);
}
int check_file_exist(const char* file_name)
{
    //int access(const char *pathname, int mode)
    //0:present
    //1:exe permission
    //2:write permission
    //4:read permission
    printf("Finding %s ....\n",file_name);
    int ret = 0;
    if(access(file_name,0)<0)
    {
        puts("The file doesn't exist!");
        puts("End the program!");
    }
    else
    {
        puts("The file exist!");
        ret=1;
    }
    return ret;
}
void copy_file(const char* desti_file, const char* in_file_name)
{
    FILE* desti_ptr ;
    FILE* source_ptr ;

    void *in_buffer;
    char char_buf;

    source_ptr = fopen(in_file_name,"r");
    desti_ptr = fopen(desti_file,"w");

    if(!source_ptr)
    {
        puts("Open source-file failed\n");
        return;
    }
    if(!desti_ptr)
    {
        puts("Open desti-file failed\n");
        return;
    }

    while(1)
    {
        fread(&char_buf,1,1,source_ptr);
        if(feof(source_ptr))
        {
            break;
        }
        fwrite(&char_buf,1,1,desti_ptr);
    }

    fclose(source_ptr);
    fclose(desti_ptr);

    printf("Copy File Successfully!");
}
/*
void set_file_name(char enumtype,char* file_name)
{
    if(enumtype==SRC_FILE)
    {
        input_file_name = file_name;
    }
    else
    {
        desti_file__name = file_name;
    }
}
*/
#if METHOD_2
void print_file()
{
    printf("src str = %s",copy_struct.src_file);
    printf("des str = %s",copy_struct.des_file);
}
void intitiate_struct()
{
    copy_struct.des_file = "";
    copy_struct.src_file = "";
    copy_struct.copy_func_ptr = print_file;
}
#endif
