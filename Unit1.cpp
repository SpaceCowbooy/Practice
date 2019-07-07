//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include "Registry.hpp"
#pragma hdrstop
using namespace std;
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
AnsiString global;
TRegistry *reg = new TRegistry;
reg->RootKey = HKEY_CURRENT_USER;
//reg->OpenKey("Lab",false);
//reg->WriteString("Test", "123");
//reg->CloseKey();
char str[100];
while (1){
        cin.getline(str, 100);
        char *tmp = strtok(str, " ");
        while (tmp != NULL){
                if (strcmp(tmp, "EXIT") == 0){
                        exit(0);
                }
                if (strcmp(tmp, "OPEN") == 0){
                        reg->CloseKey();
                        tmp = strtok(NULL, " ");
                        global = tmp;
                        if(reg->KeyExists(global)){
                                reg->OpenKey(global, false);
                                cout<<"Current folder: "<<tmp<<endl;
                                }
                        else cout<<"Error! Non existing folder"<<endl;
                }
                if (strcmp(tmp, "SHOW") == 0){
                        tmp = strtok(NULL, " ");
                        if (tmp){
                        AnsiString a;
                        reg->OpenKey(a, false);
                        TStringList* list = new TStringList;
                        cout<<"Inner keys:"<<endl;
                        reg->GetKeyNames(list);
                        cout<<list->Text.c_str()<<endl;
                        cout<<"Values:"<<endl;
                        reg->GetValueNames(list);
                        for (int i = 0; i < list->Count; i++)
                        cout<<list->Strings[i].c_str()<<":"<<reg->ReadString(list->Strings[i]).c_str()<<endl;
                        }
                        else{
                        TStringList* list = new TStringList;
                        cout<<"Inner keys:"<<endl;
                        reg->GetKeyNames(list);
                        cout<<list->Text.c_str()<<endl;
                        cout<<"Values:"<<endl;
                        reg->GetValueNames(list);
                        for (int i = 0; i < list->Count; i++)
                        cout<<list->Strings[i].c_str()<<":"<<reg->ReadString(list->Strings[i]).c_str()<<endl;
                        }
                }
                if (strcmp(tmp, "NEW") == 0){
                tmp = strtok(NULL, " ");
                AnsiString name = tmp;
                tmp = strtok(NULL, " ");
                if (name == '='){
                AnsiString val = tmp;
                reg->WriteString("py", val);
                }
                else{
                tmp = strtok(NULL, " ");
                AnsiString p_type = tmp;
                tmp = strtok(NULL, " ");
                tmp = strtok(NULL, " ");
                AnsiString value = tmp;
                if (p_type == "int"){
                        int v = atoi(value.c_str());
                        reg->WriteInteger(name, v);
                }
                if (p_type == "float"){
                        float v = atof(value.c_str());
                        reg->WriteFloat(name, v);
                }
                if (p_type == "string"){
                        reg->WriteString(name, value);
                }
                }
                }
                tmp = strtok(NULL, " ");
        }
}
system ("pause");
        return 0;
}
//---------------------------------------------------------------------------
 