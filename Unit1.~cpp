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
AnsiString current;
TRegistry *reg = new TRegistry;
reg->RootKey = HKEY_CURRENT_USER;
char str[100];
while (1){
        cin.getline(str, 100);
        char *tmp = strtok(str, " ");
        while (tmp != NULL){
                if (strcmp(strlwr(tmp), "exit") == 0){
                        exit(0);
                }
                if (strcmp(strlwr(tmp), "open") == 0){
                        reg->CloseKey();
                        tmp = strtok(NULL, " ");
                        if (!tmp)
                            break;
                        current = tmp;
                        if(reg->KeyExists(current)){
                                reg->OpenKey(current, false);
                                cout<<"Current folder: "<<tmp<<endl;
                                }
                        else cout<<"Error! Non existing folder"<<endl;
                }
                if (strcmp(strlwr(tmp), "show") == 0){
                        tmp = strtok(NULL, " ");
                        if (tmp){
                        AnsiString a;
                        a = tmp;
                        reg->OpenKey(a, false);
                        TStringList* list = new TStringList;
                        cout<<"--Inner keys--"<<endl;
                        reg->GetKeyNames(list);
                        for (int i = 0; i < list->Count; i++)
                            cout<<list->Strings[i].c_str()<<endl;
                        cout<<"--Values--"<<endl;
                        reg->GetValueNames(list);
                        for (int i = 0; i < list->Count; i++){
                            int p_type = reg->GetDataType(list->Strings[i]);
                            switch (p_type){
                                case 3:{
                                    cout<<list->Strings[i].c_str()<<":"<<reg->ReadInteger(list->Strings[i])<<endl;
                                    break;
                                }
                                case 1:{
                                    cout<<list->Strings[i].c_str()<<":"<<reg->ReadString(list->Strings[i]).c_str()<<endl;
                                    break;
                                }
                                    case 4:{
                                    cout<<list->Strings[i].c_str()<<":"<<reg->ReadFloat(list->Strings[i])<<endl;
                                }
                            }
                        }
                        }
                        else{
                        TStringList* list = new TStringList;
                        cout<<"--Inner keys--"<<endl;
                        reg->GetKeyNames(list);
                        for (int i = 0; i < list->Count; i++)
                            cout<<list->Strings[i].c_str()<<endl;
                        reg->GetValueNames(list);
                        cout<<"--Values---"<<endl;
                        for (int i = 0; i < list->Count; i++){
                            int p_type = reg->GetDataType(list->Strings[i]);
                            switch (p_type){
                                case 3:{
                                cout<<list->Strings[i].c_str()<<":"<<reg->ReadInteger(list->Strings[i])<<endl;
                                break;
                                }
                                case 1:{
                                cout<<list->Strings[i].c_str()<<":"<<reg->ReadString(list->Strings[i]).c_str()<<endl;
                                break;
                                }
                                case 4:{
                                cout<<list->Strings[i].c_str()<<":"<<reg->ReadFloat(list->Strings[i])<<endl;
                                }
                            }
                        }
                        }
                //reg->CloseKey();
                break;
                }
                if (strcmp(strlwr(tmp), "new") == 0){
                    tmp = strtok(NULL, " ");
                    AnsiString name = tmp;
                    tmp = strtok(NULL, " ");
                    if (name == '='){
                        AnsiString val = tmp;
                        reg->WriteString("py", val);
                    }
                    else{
                        tmp = strtok(NULL, "+ ");
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
