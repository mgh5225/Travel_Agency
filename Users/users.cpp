#include "users.h"
#include <stdio.h>
#include <cstdlib>
#include <string>
void save_def_file(User _user){
    FILE* fp_d=fopen("Users/usrs/default.dat","ab");
    fwrite(&(_user.user_name),sizeof(char),9,fp_d);
    fclose(fp_d);
}
void save_user_file(User _user){
    string file_addr="Users/usrs/"+(string)_user.user_name+".usr";
    FILE* fp_u=fopen(file_addr.c_str(),"wb");
    fwrite(&_user,sizeof(User),1,fp_u);
    fclose(fp_u);

}
vector<User> get_users(){
    vector<User> users;
    FILE* fp_d=fopen("Users/usrs/default.dat","rb");
    if(fp_d!=NULL){
        while (true){
            char user_name[9]={};
            fread(&user_name,sizeof(char),9,fp_d);
            if(feof(fp_d))break;
            string file_addr="Users/usrs/"+(string)user_name+".usr";
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
        save_user_file(_user);
        save_def_file(_user);
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
        save_user_file(users[point]);
    }
}
//--------------------------------------------------------------------------