#include "cities.h"
#include <stdio.h>
void fill_cities(){
    vector<City> cities;
    FILE* ftxt=fopen("Cities/cities.txt","r");
    FILE* fp=fopen("Cities/b_cities.txt","wb");
    if(ftxt==NULL){
        return;
    }
    while (!feof(ftxt)){
        City temp={};
        fscanf(ftxt,"%d\t%d\t%d",&temp.id,&temp.X,&temp.Y);
        cities.push_back(temp);
    }
    for(int i=0;i<cities.size();i++)
        fwrite(&(cities[i]), sizeof(City),1,fp);
    fclose(ftxt);
    fclose(fp);
}
vector<City> get_cities(){
    vector<City> cities;
    FILE* fp=fopen("Cities/b_cities.txt","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            City temp={};
            fread(&temp,sizeof(City),1,fp);
            cities.push_back(temp);
        }
    }
    return cities;
}
