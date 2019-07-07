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
TRegistry *reg = new TRegistry;
reg->RootKey = HKEY_CURRENT_USER;
reg->OpenKey("Lab",false);
reg->WriteString("Test", "123");
reg->CloseKey();
char str[100];
while (1){
        cin.getline(str, 100);
        char *tmp = strtok(str, " ");
        while (tmp != NULL){
                if (strcmp(tmp, "EXIT") == 0){
                        exit(0);
                }
                if (strcmp(tmp, "OPEN") == 0){
                        tmp = strtok(NULL, " ");
                        AnsiString a = tmp;
                        if(reg->KeyExists(a)){
                                reg->OpenKey(a, false);
                                cout<<"Current folder: "<<tmp<<endl;
                                }
                        else cout<<"Error! Non existing folder"<<endl;
                reg->CloseKey();
                }
                if (strcmp(tmp, "SHOW") == 0){
                        tmp = strtok(NULL, " ");
                        AnsiString a = tmp;
                        if (reg->KeyExists(a)){
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
                        else cout<<"Error! Non existing folder"<<endl;
                reg->CloseKey();
                }
                tmp = strtok(NULL, " ");
        }
}
system ("pause");
        return 0;
}
//---------------------------------------------------------------------------
 