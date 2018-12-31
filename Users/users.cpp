#include "users.h"
#include <stdio.h>
#include <cstdlib>
string create_file_addr(string user_name,string file_type){
    char file_addr[20]="Users/";
    int j;
    for(j=0;j<9 &&user_name[j]!='\0';j++){
        file_addr[j+6]=user_name[j];
    }
    for(int k=0;k<5;k++){
        file_addr[j+6+k]=file_type[k];
    }
    return file_addr;
}
void save_users_file(vector<User> users){
    FILE* fp_d=fopen("Users/default.dat","wb");
    for(long int i=0;i<users.size();i++) {
        string file_addr=create_file_addr(users[i].user_name,".dat");
        FILE* fp_u=fopen(file_addr.c_str(),"wb");
        fwrite(&(users[i]),sizeof(User),1,fp_u);
        fclose(fp_u);
        fwrite(&(users[i].user_name),sizeof(char),9,fp_d);
    }
    fclose(fp_d);
}
vector<User> get_users(){
    vector<User> users;
    FILE* fp_d=fopen("Users/default.dat","rb");
    if(fp_d!=NULL){
        while (!feof(fp_d)){
            char user_name[9]={};
            fread(&user_name,sizeof(char),9,fp_d);
            if(user_name[0]=='\0')break;
            string file_addr=create_file_addr(user_name,".dat");
            User temp={};
            FILE* fp_u=fopen(file_addr.c_str(),"rb");
            fread(&temp, sizeof(User),1,fp_u);
            fclose(fp_u);
            users.push_back(temp);
        }
        fclose(fp_d);
    }
    return users;
}
long int find_user(vector<User> users,User _user){
    for(long int i=0;i<users.size();i++){
        int j;
        for(j=0;j<9 && users[i].user_name[j]==_user.user_name[j];j++);
        if(j==9){
            return i;
        }
    }
    return -1;
}
void add_user(User _user){
    vector<User> users=get_users();
    if(find_user(users,_user)==-1) {
        users.push_back(_user);
        save_users_file(users);
    }

}
User user_login(char user_name[9],char user_pass[9]){
    vector<User> users=get_users();
    for(long int i=0;i<users.size();i++){
        int j;
        for(j=0;j<9 && users[i].user_name[j]==user_name[j];j++);
        if(j==9){
            int k;
            for(k=0;k<9 && users[i].user_pass[k]==user_pass[k];k++);
            if(k==9){
                return users[i];
            }
        }
    }
    return User{};
}
void edit_user_profile(User _user){
    vector<User> users=get_users();
    long int point=find_user(users,_user);
    if(point!=-1) {
        for (int i = 0; i <9; i++) {
            users[point].user_pass[i] = _user.user_pass[i];
        }
        for (int i = 0; i < 21; i++) {
            users[point].fname[i] = _user.fname[i];
            users[point].lname[i] = _user.lname[i];
            users[point].reference[i] = _user.reference[i];
        }
        for (int i = 0; i < 11; i++) {
            users[point].bank_account[i] = _user.bank_account[i];
        }
        for (int i = 0; i < 12; i++) {
            users[point].phone_number[i] = _user.phone_number[i];
        }
        save_users_file(users);
    }
}
//--------------------------------------------------------------------------