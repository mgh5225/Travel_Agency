#include "cities.h"
#include <stdio.h>
void save_cities_file(vector<City> cities){
    FILE* fp=fopen("Cities/b_cities.txt","wb");
    for(long int i=0;i<cities.size();i++)
        fwrite(&(cities[i]),sizeof(City),1,fp);
    fclose(fp);
}
void xchange_cities(){
    vector<City> cities;
    FILE* fp=fopen("Cities/cities.txt","r");
    if(fp==NULL){
        return;
    }
    while (!feof(fp)){
        City temp={};
        fscanf(fp,"%d\t%d\t%d",&temp.id,&temp.X,&temp.Y);
        if(temp.id==0)break;
        cities.push_back(temp);
    }
    fclose(fp);
    save_cities_file(cities);
}
vector<City> get_cities(){
    vector<City> cities;
    FILE* fp=fopen("Cities/b_cities.txt","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            City temp={};
            fread(&temp,sizeof(City),1,fp);
            if(temp.id==0)break;
            cities.push_back(temp);
        }
        fclose(fp);
    }
    return cities;
}
