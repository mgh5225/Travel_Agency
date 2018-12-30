#include "users.h"
#include <stdio.h>
#include <cstdlib>
void save_users_file(vector<User> users){
    FILE* fp=fopen("Users/b_users.txt","wb");
    for(long int i=0;i<users.size();i++)
        fwrite(&(users[i]),sizeof(User),1,fp);
    fclose(fp);
}
vector<User> get_users(){
    vector<User> users;
    FILE* fp=fopen("Users/b_users.txt","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            User temp={};
            fread(&temp,sizeof(User),1,fp);
            if(temp.user_name[0]=='\0')break;
            users.push_back(temp);
        }
        fclose(fp);
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