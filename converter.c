char *comp_Un(char*string){
    
    int len = strlen(deDeci(string));
    char comp_un[len];
    char res[] = deDeci(string);

    for (int i = 0; i < len; i++)
        {
            
            if (res[i]=='0')
            {
                
                comp_un[i]='1';
            }
            else {
            
                comp_un[i]='0';
            }
            
        }
        comp_un[len] = '\0';
        printf("Complement a un: %s\n", comp_un);
        return comp_un;
        
}
char* champ_deux(char* comp_un){
    int reste=1;
    int len = strlen(comp_Un(comp_un));
    char comp_deux[len];

    for(int i=len-1; i>=0; i--)  
        {  
            if(comp_un[i] == '1' && reste == 1)  
            {  
                comp_deux[i] = '0';  
            }  
            else if(comp_un[i] == '0' && reste == 1)  
            {  
                comp_deux[i] = '1';  
                reste = 0;  
            }  
            else  
            {  
                comp_deux[i] = comp_un[i];  
            }  
        }  
        comp_deux[len]='\0';  
        printf("Complement a deux: %s",comp_deux);
    
    return champ_deux;
}