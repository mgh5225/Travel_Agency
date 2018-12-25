#include "users.h"
#include <stdio.h>
void save_users_file(vector<User> users){
    FILE* fp=fopen("Users/b_users.txt","wb");
    for(long int i=0;i<users.size();i++)
        fwrite(&(users[i]),sizeof(User),1,fp);
    fclose(fp);
}
void add_user(User new_user){
    vector<User> users=get_users();
    if(!users.empty()){
        for(long int i=0;i<users.size();i++){
            int j;
            for(j=0;j<101 && users[i].user_name[j]==new_user.user_name[j];j++);
            if(j==101) return;
        }
    }
    users.push_back(new_user);
    save_users_file(users);

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